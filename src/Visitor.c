/* This is a managed file. Do not delete this comment. */

#include <corto/script/declare/declare.h>

int16_t declare_prepare_initializer(
    ast_Visitor this,
    corto_script_ast_Initializer node);

int16_t declare_Visitor_construct(
    declare_Visitor this)
{
    if (this->from) {
        corto_set_ref(&this->current_scope, this->from);
    } else {
        corto_set_ref(&this->current_scope, root_o);
    }

    if (!this->typesystem) {
        corto_set_ref(&this->typesystem, corto_lang_o);
    }

    return corto_super_construct(this);
}

static
char* declare_visitor_arglist_to_string(
    ast_FunctionArgumentList args)
{
    corto_buffer buff = CORTO_BUFFER_INIT;

    corto_buffer_appendstr(&buff, "(");
    uint32_t count = 0;

    corto_iter it = corto_ll_iter(args);
    while (corto_iter_hasNext(&it)) {
        ast_FunctionArgument arg = corto_iter_next(&it);

        if (count) {
            corto_buffer_appendstr(&buff, ",");
        }

        if (arg->inout == CORTO_OUT) {
            corto_buffer_appendstr(&buff, "out:");
        } else if (arg->inout == CORTO_INOUT) {
            corto_buffer_appendstr(&buff, "inout:");
        }

        corto_type type = ast_Storage_get_object(arg->type);
        if (!type) {
            corto_throw(
                "missing type for argument '%s' in function declaration",
                arg->name);
            goto error;
        }

        corto_buffer_appendstr(&buff, corto_fullpath(NULL, type));

        if (arg->is_reference) {
            corto_buffer_appendstr(&buff, "&");
        }

        corto_buffer_appendstr(&buff, " ");

        corto_buffer_appendstr(&buff, arg->name);

        count ++;
    }

    corto_buffer_appendstr(&buff, ")");

    return corto_buffer_str(&buff);
error:
    return NULL;
}

static
int16_t declare_Visitor_setDelegateParameters(
    declare_Visitor this,
    corto_delegate object,
    ast_FunctionArgumentList args)
{
    uint32_t i, count = corto_ll_count(args);

    object->parameters.length = count;
    object->parameters.buffer = corto_calloc(sizeof(corto_parameter) * count);

    for (i = 0; i < count; i ++) {
        ast_FunctionArgument arg = corto_ll_get(args, i);
        corto_parameter *param = &object->parameters.buffer[i];
        corto_object type = ast_Storage_get_object(arg->type);
        if (!type) {
            goto error;
        }

        if (!corto_instanceof(corto_type_o, type)) {
            corto_throw("expected type for parameter '%s', got '%s'",
                arg->name,
                corto_fullpath(NULL, corto_typeof(type)));
            goto error;
        }

        corto_set_str(&param->name, arg->name);
        param->is_reference = arg->is_reference;
        param->inout = arg->inout;
        param->type = type;
    }

    return 0;
error:
    return -1;
}

int16_t declare_Visitor_visitDeclaration(
    declare_Visitor this,
    corto_script_ast_Declaration node)
{
    corto_object scope = this->current_scope;
    corto_type type = NULL;
    char *arg_list = NULL;
    bool should_define_all = false;
    bool is_function = node->id->arguments != NULL;

    if (node->type) {
        corto_try (ast_Visitor_visit(this, node->type), NULL);
        type = ast_Storage_get_object(node->type);

        /* If type is explicitly set, the next declaration with an implicit type
         * will use this type. */
        if (is_function) {
            corto_set_ref(&this->scope_procedure_type, type);
        } else {
            corto_set_ref(&this->scope_type, type);
        }
    }

    /* If type is not explicitly set, get the default type */
    if (!type) {
        if (is_function) {
            type = this->scope_procedure_type;
        } else {
            type = this->scope_type;
        }
    }

    /* If type is still not known, get default type from type of parent */
    if (!type) {
        /* Check if declaration is procedure */
        if (is_function) {
            type = corto_typeof(scope)->scope_procedure_type;
        } else {
            type = corto_typeof(scope)->scope_type;
        }
    }

    /* If type is still not known, use builtin defaults */
    if (!type) {
        if (is_function) {
            type = (corto_type)corto_function_o;
        } else if (node->set_scope) {
            type = (corto_type)corto_package_o;
        }
    }

    /* If type is still not known, something's wrong */
    if (!type) {
        corto_throw("cannot derive type for declaration in scope '%s'",
            corto_fullpath(NULL, scope));
        goto error;
    }

    /* If the type identifier was resolved, make sure it is a type */
    if (!corto_instanceof(corto_type_o, type)) {
        corto_throw("object '%s' is not a type",
            corto_fullpath(NULL, type));
        goto error;
    }

    if (is_function) {
        should_define_all = true;

        corto_try (
          ast_Visitor_visitFunctionArguments(this, node->id->arguments), NULL);

        if (corto_instanceof(corto_procedure_o, type)) {
            arg_list = declare_visitor_arglist_to_string(node->id->arguments);
            if (!arg_list) {
                corto_throw(NULL);
                goto error;
            }
        }
    }

    if (node->initializer) {
        ast_Expression_setType(node->initializer, type);
        corto_try (
          declare_prepare_initializer(
            ast_Visitor(this), node->initializer), NULL);
    }

    corto_iter it = corto_ll_iter(node->id->ids);
    while (corto_iter_hasNext(&it)) {
        ast_Storage storage = corto_iter_next(&it);
        ast_Initializer object_initializer = NULL;
        const char *id = NULL;
        bool should_define = false;

        /* Regular identifier */
        if (corto_instanceof(ast_Identifier_o, storage)) {
            id = ast_Identifier(storage)->id;

        /* Initializer with object-specific initializer */
        } else if (corto_instanceof(ast_StorageInitializer_o, storage)) {
            ast_Storage id_expr = ast_StorageInitializer(storage)->expr;

            if (!corto_instanceof(ast_Identifier_o, id_expr)) {
                corto_throw("invalid identifier in declaration (%s)",
                    corto_idof(corto_typeof(id_expr)));
                goto error;
            }

            id = ast_Identifier(id_expr)->id;
            object_initializer = ast_StorageInitializer(storage)->initializer;

        /* Invalid storage for declaration identifier */
        } else {
            corto_throw("invalid identifier in declaration (%s)",
                corto_idof(corto_typeof(storage)));
            goto error;
        }

        /* Declare object */
        if (arg_list) {
            id = corto_asprintf("%s%s", id, arg_list);
        }

        corto_object from = scope;
        if (node->set_scope) {
            /* Identifiers in a scope-setting declaration are always resolved
             * relative to the parser scope */
            scope = this->from;
        }

        corto_object object;
        if (node->type) {
            /* If type is explicitly provided, use standard corto_declare, which
             * enforces that the returned object is of the specified type. */
            object = corto_declare(from, id, type);
        } else {
            /* If the type is implicit, make sure that the parser doesn't fail
             * when the object already exists with a different type. This call
             * provides functionality equivalent to corto_declare, minus the
             * type check. */
            object = corto(CORTO_RECURSIVE_DECLARE, {
                .parent = from,
                .id = id,
                .type = type
            });
        }
        if (!object) {
            corto_throw(
                "failed to declare object '%s' of type '%s' in scope '%s'",
                id,
                corto_fullpath(NULL, type),
                corto_fullpath(NULL, scope));
            goto error;
        }

        if (node->set_scope) {
            corto_set_ref(&this->current_scope, object);
        }

        if (arg_list) {
            /* Value is only freed when non-const value is assigned */
            free((char*)id);
        }

        ast_Storage_set_object(storage, object);

        corto_rw rw = corto_rw_init(type, object);

        /* If initializer is collection or composite, do initial push */
        if (type->kind == CORTO_COMPOSITE || type->kind == CORTO_COLLECTION) {
            corto_try( corto_rw_push(&rw, FALSE), NULL);
        }

        if (object_initializer || node->initializer) {
            should_define = true;

            /* If declaration has initializer, apply */
            if (node->initializer) {
                corto_try (
                    ast_Initializer_apply(
                      node->initializer, (uintptr_t)&rw),
                          "declaration of '%s %s' failed",
                          corto_fullpath(NULL, corto_typeof(object)),
                          corto_fullpath(NULL, object));
            }

            /* If storage is identifier + initializer, apply initializer to new
             * object after global declaration initializer is applied */
            if (object_initializer) {
                ast_Expression_setType(object_initializer, type);
                corto_try(
                  declare_prepare_initializer(
                    ast_Visitor(this), object_initializer), NULL);

                if (ast_Initializer_apply(object_initializer, (uintptr_t)&rw)) {
                    corto_throw("declaration of '%s %s' failed",
                      corto_fullpath(NULL, corto_typeof(object)),
                        corto_fullpath(NULL, object));
                    goto error;
                }
            }
        }

        /* If object is a delegate and has arguments, set arguments */
        if (is_function && corto_instanceof(corto_delegate_o, object)) {
            if (declare_Visitor_setDelegateParameters(
                this, object, node->id->arguments))
            {
                goto error;
            }
        }

        /* If initializer has scope, visit scope before defining object */
        if (node->scope) {
            should_define = true;
            corto_object current_scope = this->current_scope;
            corto_type current_scope_type = this->scope_type;
            corto_set_ref(&this->current_scope, object);
            corto_set_ref(&this->scope_type, NULL);
            corto_try (ast_Visitor_visit(this, node->scope), NULL);
            corto_set_ref(&this->current_scope, current_scope);
            corto_set_ref(&this->scope_type, current_scope_type);
        }

        /* Define object */
        if (should_define || should_define_all) {
            corto_try (corto_define(object), NULL);
        }

        corto_rw_deinit(&rw);
    }

    free (arg_list);
    return 0;
error:
    free (arg_list);
    return -1;
}

int16_t declare_Visitor_visitScope(
    declare_Visitor this,
    corto_script_ast_Scope node)
{
    corto_type prev_scope_type = this->scope_type;
    corto_type prev_scope_procedure_type = this->scope_procedure_type;

    corto_set_ref(&this->scope_type, NULL);
    corto_set_ref(&this->scope_procedure_type, NULL);

    if (ast_Visitor_visitScope_v(this, node)) {
        goto error;
    }

    corto_set_ref(&this->scope_type, prev_scope_type);
    corto_set_ref(&this->scope_procedure_type, prev_scope_procedure_type);

    return 0;
error:
    return -1;
}

int16_t declare_Visitor_visitStatement(
    declare_Visitor this,
    corto_script_ast_Statement node)
{
    return 0;
}

int16_t declare_Visitor_visitExpression(
    declare_Visitor this,
    corto_script_ast_Expression node)
{
    return 0;
}

int16_t declare_Visitor_visitStorage(
    declare_Visitor this,
    corto_script_ast_Storage node)
{
    corto_object obj = declare_object_from_storage(
        this->typesystem,
        this->current_scope,
        this->search_scopes,
        node,
        ast_Visitor(this));
    if (!obj) {
        goto error;
    }

    ast_Storage_set_object(node, obj);

    return 0;
error:
    return -1;
}

int16_t declare_Visitor_visitUse(
    declare_Visitor this,
    corto_script_ast_Use node)
{
    corto_object scope = corto_lookup(this->from, node->package);
    if (!scope) {
        corto_throw("could not find '%s' in use statement", node->package);
        goto error;
    }

    if (node->as_typesystem) {
        corto_set_ref(this->typesystem, scope);
    } else {
        declare_search_element el = {
            .scope = scope,
            .alias = node->alias
        };
        declare_search_elementList__append(this->search_scopes, &el);
    }

    return 0;
error:
    return -1;
}
