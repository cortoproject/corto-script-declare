/* This is a managed file. Do not delete this comment. */

#include <corto.script.declare>

const char* match_alias(const char *alias, const char *id) {
    const char *ptr;
    char ch;
    const char *id_ptr = id;

    for (ptr = alias; (ch = *ptr); ptr ++, id_ptr ++) {
        if (id_ptr[0] != ch) {
            if (ch == '.' || ch == '/') {
                if (id_ptr[0] != '.' && id_ptr[0] != '/') {
                    break;
                }
            } else {
                break;
            }
        }
    }

    if (ptr[0] || (id_ptr[0] && (id_ptr[0] != '.' && id_ptr[0] != '/'))) {
        return NULL;
    } else {
        if (id_ptr[0] == '.' || id_ptr[0] == '/') {
            id_ptr ++;
        }
        return id_ptr;
    }
}

int16_t declare_prepare_initializer(
    ast_Visitor this,
    corto_script_ast_Initializer node)
{
    /* First propagate types to all expressions in initializer */
    ut_try (ast_Initializer_propagateType(node), NULL);

    /* Now visit expressions to resolve identifiers */
    ut_try (ast_Visitor_visit(this, node), NULL);

    /* Now fold expressions */
    ut_try (!ast_Initializer_fold(node), NULL);

    return 0;
error:
    return -1;
}

static
corto_object declare_object_from_identifier(
    corto_object typesystem,
    corto_object from,
    declare_search_elementList search_scopes,
    corto_script_ast_Identifier identifier)
{
    corto_object result = NULL;
    corto_type type = ast_Expression(identifier)->type;
    const char *id = identifier->id;

    /* First, try to lookup the object from the scope of the type. This is
     * typically used for looking up enumeration constants, so a script can
     * specify 'Red' instaed 'Color/Red' */
    if (type && corto_check_attr(type, CORTO_ATTR_NAMED)) {
        result = corto_lookup(type, id);
    }

    /* If object hasn't been found yet, look it up in the provided scope */
    if (!result) {
        result = corto_resolve(from, id);
    }

    /* If search scopes are specified, check if search string can be found
     * in any of the search scopes */
    if (!result && ut_ll_count(search_scopes)) {
        ut_iter it = ut_ll_iter(search_scopes);
        while (ut_iter_hasNext(&it)) {
            declare_search_element *el = ut_iter_next(&it);
            const char *id_ptr = id;
            if (!el->alias || (id_ptr = match_alias(el->alias, id))) {
                if (id_ptr[0]) {
                    result = corto_resolve(el->scope, id_ptr);
                } else {
                    result = el->scope;
                    corto_claim(result);
                }
                if (result) {
                    break;
                }
            }
        }
    }

    if (!result) {
        ut_throw("unresolved identifier '%s'", id);
        goto error;
    }

    return result;
error:
    return NULL;
}

static
corto_object declare_object_from_storage_initializer(
    corto_object typesystem,
    corto_object scope,
    declare_search_elementList search_scopes,
    corto_script_ast_StorageInitializer storage,
    ast_Visitor visitor_arg)
{
    corto_object obj = NULL;
    ast_Visitor visitor = visitor_arg;

    if (!visitor) {
        if (!(visitor = (ast_Visitor)declare_Visitor__create(NULL, NULL, "unknown", scope))) {
            goto error;
        }
    }

    corto_type type =
        declare_object_from_storage(
            typesystem, scope, search_scopes, storage->expr, visitor);
    if (!type) {
        ut_throw("failed to resolve type of anonymous object");
        goto error;
    }

    /* Create object with type */
    obj = corto_declare(NULL, NULL, type);

    /* Create initializer helper */
    corto_rw rw = corto_rw_init(obj, type);

    /* If initializer is collection or composite, do initial push */
    if (type->kind == CORTO_COMPOSITE || type->kind == CORTO_COLLECTION) {
        ut_try(corto_rw_push(&rw, FALSE), NULL);
    }

    /* Fold expressions in initializer */
    ast_Expression_setType(storage->initializer, type);
    ut_try (declare_prepare_initializer(visitor, storage->initializer), NULL);

    /* If visitor was created for this call, delete it */
    if (!visitor_arg) {
        corto_delete(visitor);
    }

    /* Apply initializer to object */
    ut_try (
        ast_Initializer_apply(
            storage->initializer, (uintptr_t)&rw), NULL);

    /* Define object */
    ut_try( corto_define(obj), NULL);

    /* Cleanup */
    corto_rw_deinit(&rw);

    return obj;
error:
    return NULL;
}

corto_object declare_object_from_storage(
    corto_object typesystem,
    corto_object from,
    declare_search_elementList search_scopes,
    corto_script_ast_Storage storage,
    corto_script_ast_Visitor visitor)
{
    if (corto_instanceof(ast_Identifier_o, storage)) {
        return declare_object_from_identifier(
          typesystem,
          from,
          search_scopes,
          ast_Identifier(storage));
    } else if (corto_instanceof(ast_StorageInitializer_o, storage)) {
        return declare_object_from_storage_initializer(
            typesystem,
            from,
            search_scopes,
            ast_StorageInitializer(storage),
            visitor);
    } else {
        ut_throw(
            "cannot convert node of type '%s' to object",
            corto_fullpath(NULL, storage));
    }

    return NULL;
}

int16_t cortoscript_ast_declare(
    corto_object from,
    const char *file,
    ast_Node ast)
{
    declare_Visitor visitor = declare_Visitor__create(NULL, NULL, file, from);
    if (!visitor) {
        goto error;
    }

    return ast_Visitor_visit(visitor, ast);;
error:
    return -1;
}

int16_t cortoscript_parse_expr(
    corto_object from,
    const char *input,
    corto_value *out)
{
    /* Parse script */
    ast_Expression ast = ast_Expression(cortoscript_ast_parse(input, true));
    if (!ast) {
        ut_throw("failed to parse script");
        goto error;
    }

    ast_Expression folded = ast_Expression_fold(ast);

    if (corto_instanceof(ast_Storage_o, folded)) {
        corto_object obj = declare_object_from_storage(
            corto_lang_o,
            from,
            NULL,
            ast_Storage(folded),
            NULL);
        if (!obj) {
            goto error;
        }
        ast_Storage_set_object(folded, obj);
    }

    /* Convert expression to value */
    if (cortoscript_ast_to_value(ast_Node(folded), out)) {
        ut_throw("failed to convert expression to corto_value");
        goto error;
    }

    if (corto_delete(ast)) {
        ut_throw("failed to cleanup AST");
        goto error;
    }

    return 0;
error:
    return -1;
}


int cortomain(int argc, char *argv[]) {

    /* Insert implementation */

    return 0;
}
