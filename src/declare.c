/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/declare/declare.h>

corto_object declare_object_from_storage(
    corto_object from,
    corto_script_ast_Storage storage)
{
    corto_object result = NULL;

    if (corto_instanceof(ast_Identifier_o, storage)) {
        ast_Identifier identifier = ast_Identifier(storage);
        corto_type type = ast_Expression(storage)->type;

        /* First, try to lookup the object from the scope of the type. This is
         * typically used for looking up enumeration constants, so a script can
         * specify 'Red' instaed 'Color/Red' */
        if (type && corto_check_attr(type, CORTO_ATTR_NAMED)) {
            result = corto_lookup(type, identifier->id);
        }

        /* If object hasn't been found yet, look it up in the provided scope */
        if (!result) {
            result = corto_resolve(from, identifier->id);
            if (!result) {
                corto_throw("unresolved identifier '%s'", identifier->id);
                goto error;
            }
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
    ast_Node ast)
{
    declare_Visitor visitor = declare_Visitor__create(NULL, NULL, from);
    if (!visitor) {
        goto error;
    }

    return ast_Visitor_visit(visitor, ast);
error:
    return -1;
}

int16_t cortoscript_parse_expr(
    corto_object from,
    const char *input,
    corto_value *out)
{
    /* Parse script */
    ast_Node ast = cortoscript_ast_parse(input);
    if (!ast) {
        corto_throw("failed to parse script");
        goto error;
    }

    /* Fold expressions */
    declare_FoldingVisitor visitor = declare_FoldingVisitor__create(NULL, NULL);
    if (!visitor) {
        corto_throw("failed to declare visitor for expression folding");
        goto error;
    }

    if (ast_Visitor_visit(visitor, ast)) {
        corto_throw("failed to fold expressions in script");
    }

    /* Convert expression to value */
    if (cortoscript_ast_to_value(ast, out)) {
        corto_throw("failed to convert expression to corto_value");
        goto error;
    }

    if (corto_delete(visitor)) {
        corto_throw("failed to delete visitor");
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
