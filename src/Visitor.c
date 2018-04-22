/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/declare/declare.h>

int16_t declare_Visitor_construct(
    declare_Visitor this)
{
    if (this->from) {
        declare_Visitor_push_scope(this, this->from);
    } else {
        declare_Visitor_push_scope(this, root_o);
    }

    return corto_super_construct(this);
}

corto_object declare_Visitor_get_scope(
    declare_Visitor this)
{
    return corto_ll_last(this->scope_stack);
}

void declare_Visitor_pop_scope(
    declare_Visitor this)
{
    corto_ll_takeLast(this->scope_stack);
}

void declare_Visitor_push_scope(
    declare_Visitor this,
    corto_object scope)
{
    corto_ll_append(this->scope_stack, scope);
}

int16_t declare_Visitor_visitDeclaration(
    declare_Visitor this,
    corto_script_ast_Declaration node)
{
    corto_object scope = declare_Visitor_get_scope(this);
    corto_object type = NULL;

    if (ast_Visitor_visit(this, node->type)) {
        goto error;
    }
    type = ast_Storage_get_object(node->type);
    if (!type) {
        goto error;
    }

    if (!corto_instanceof(corto_type_o, type)) {
        corto_throw("object '%s' is not a type",
            corto_fullpath(NULL, type));
        goto error;
    }

    corto_iter it = corto_ll_iter(node->id->ids);
    while (corto_iter_hasNext(&it)) {
        ast_Storage storage = corto_iter_next(&it);
        ast_Initializer object_initializer = NULL;
        const char *id = NULL;

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
        corto_object object = corto_declare(scope, id, type);
        if (!object) {
            corto_throw(
                "failed to declare object '%s' of type '%s' in scope '%s'",
                id,
                corto_fullpath(NULL, type),
                corto_fullpath(NULL, scope));
            goto error;
        }

        ast_Storage_set_object(storage, object);

        if (object_initializer || node->initializer) {
            ast_StaticInitializerHelper helper =
                ast_StaticInitializerHelper__create(NULL, NULL, storage);
            if (!helper) {
                goto error;
            }

            /* If storage is identifier + initializer, apply initializer to new
             * object after global declaration initializer is applied */
            if (object_initializer) {
                if (ast_Visitor_visit(this, object_initializer)) {
                    goto error;
                }
                if (ast_Initializer_apply(object_initializer, helper)) {
                    goto error;
                }
            }

            /* If declaration has initializer, apply */
            if (node->initializer) {
                if (ast_Visitor_visit(this, node->initializer)) {
                    goto error;
                }
                if (ast_Initializer_apply(node->initializer, helper)) {
                    goto error;
                }
            }

            /* Define object */
            if (ast_StaticInitializerHelper_define_object(helper)) {
                goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}

int16_t declare_Visitor_visitExpression(
    declare_Visitor this,
    corto_script_ast_Expression node)
{
    return 0;
}

int16_t declare_Visitor_visitStatement(
    declare_Visitor this,
    corto_script_ast_Statement node)
{
    return 0;
}

int16_t declare_Visitor_visitStorage(
    declare_Visitor this,
    corto_script_ast_Storage node)
{
    corto_object scope = declare_Visitor_get_scope(this);
    corto_object obj = declare_object_from_storage(scope, node);
    if (!obj) {
        goto error;
    }

    ast_Storage_set_object(node, obj);

    return 0;
error:
    return -1;
}
