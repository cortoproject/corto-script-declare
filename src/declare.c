/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/declare/declare.h>

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

corto_object declare_object_from_storage(
    corto_object typesystem,
    corto_object from,
    declare_search_elementList search_scopes,
    corto_script_ast_Storage storage)
{
    corto_object result = NULL;

    if (corto_instanceof(ast_Identifier_o, storage)) {
        ast_Identifier identifier = ast_Identifier(storage);
        corto_type type = ast_Expression(storage)->type;
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
        if (!result && corto_ll_count(search_scopes)) {
            corto_iter it = corto_ll_iter(search_scopes);
            while (corto_iter_hasNext(&it)) {
                declare_search_element *el = corto_iter_next(&it);
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
            corto_throw("unresolved identifier '%s'", id);
            goto error;
        }

    } else {
        corto_throw("cannot declare object from %s expression",
            corto_idof(corto_typeof(storage)));
        goto error;
    }

    return result;
error:
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
        corto_throw("failed to parse script");
        goto error;
    }

    ast_Expression folded = ast_Expression_fold(ast);

    /* Convert expression to value */
    if (cortoscript_ast_to_value(ast_Node(folded), out)) {
        corto_throw("failed to convert expression to corto_value");
        goto error;
    }

    if (corto_delete(ast)) {
        corto_throw("failed to cleanup AST");
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
