/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_expr_tc_bool(
    test_expr this)
{
    /* Insert implementation */
}

void test_expr_tc_bitmask_1(
    test_expr this)
{
    const char *input = "test/Recipe obj: HasSugar";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_Recipe *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_Recipe_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == Test_HasSugar);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_expr_tc_bitmask_2(
    test_expr this)
{
    const char *input = "test/Recipe obj: HasSalt|HasPepper";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_Recipe *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_Recipe_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, (Test_HasSalt | Test_HasPepper));

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_expr_tc_bitmask_3(
    test_expr this)
{
    const char *input = "test/Recipe obj: HasSalt|HasPepper|HasVinegar";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_Recipe *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_Recipe_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, (Test_HasSalt | Test_HasPepper | Test_HasVinegar));

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
