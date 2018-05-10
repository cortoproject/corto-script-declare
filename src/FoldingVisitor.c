/* This is a managed file. Do not delete this comment. */

#include <corto/script/ast/declare/declare.h>

int16_t declare_FoldingVisitor_visitDeclaration(
    declare_FoldingVisitor this,
    corto_script_ast_Declaration node)
{
    if (node->scope) {
        if (ast_Visitor_visit(this, node->scope)) {
            goto error;
        }
    }

    /* Expressions in initializers of declarations are folded by the declaration
     * visitor */

    return 0;
error:
    return -1;
}

int16_t declare_FoldingVisitor_visitScope(
    declare_FoldingVisitor this,
    corto_script_ast_Scope node)
{
    corto_iter it = corto_ll_iter(node->statements);

    while (corto_iter_hasNext(&it)) {
        ast_Node stmt = corto_iter_next(&it);

        if (corto_instanceof(ast_Expression_o, stmt)) {
            ast_Expression folded = ast_Expression_fold(ast_Expression(stmt));
            if (!folded) {
                goto error;
            }
            corto_ll_replace(node->statements, stmt, folded);
            corto_release(stmt);
        } else {
            if (ast_Visitor_visit(this, stmt)) {
                 goto error;
            }
        }
    }

    return 0;
error:
    return -1;
}
