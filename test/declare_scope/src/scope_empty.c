/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_scope_empty_tc_full_id(
    test_scope_empty this)
{
    const char *input = "int32 /obj {}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(corto_scope_size(obj) == 0);
    test_assert(*obj == 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_empty_tc_full_nested_id(
    test_scope_empty this)
{
    const char *input = "int32 /foo/obj {}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(corto_scope_size(obj) == 0);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_empty_tc_id(
    test_scope_empty this)
{
    const char *input = "int32 obj {}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(corto_scope_size(obj) == 0);
    test_assert(*obj == 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_empty_tc_nested_id(
    test_scope_empty this)
{
    const char *input = "int32 foo/obj {}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(corto_scope_size(obj) == 0);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
