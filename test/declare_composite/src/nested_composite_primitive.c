/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_nested_composite_primitive_tc_empty_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj ((), ())";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 0);
    test_assertint(obj->start.y, 0);
    test_assertint(obj->stop.x, 0);
    test_assertint(obj->stop.x, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_full_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj ((10, 20), (30, 40))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 10);
    test_assertint(obj->start.y, 20);
    test_assertint(obj->stop.x, 30);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_partial_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj ((10), (30))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 10);
    test_assertint(obj->start.y, 0);
    test_assertint(obj->stop.x, 30);
    test_assertint(obj->stop.y, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_member_empty_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(), stop())";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 0);
    test_assertint(obj->start.y, 0);
    test_assertint(obj->stop.x, 0);
    test_assertint(obj->stop.y, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_member_full_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(x:10, y:20), stop(x:30, y:40))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 10);
    test_assertint(obj->start.y, 20);
    test_assertint(obj->stop.x, 30);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_member_partial_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(y:20), stop(y:40))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 0);
    test_assertint(obj->start.y, 20);
    test_assertint(obj->stop.x, 0);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_mixed_empty_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(), ())";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 0);
    test_assertint(obj->start.y, 0);
    test_assertint(obj->stop.x, 0);
    test_assertint(obj->stop.y, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_mixed_full_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(10, y:20), (30, y:40))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 10);
    test_assertint(obj->start.y, 20);
    test_assertint(obj->stop.x, 30);
    test_assertint(obj->stop.y, 40);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_composite_primitive_tc_mixed_partial_init(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_line obj (start(y:20), (40))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_line *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_line_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->start.x, 0);
    test_assertint(obj->start.y, 20);
    test_assertint(obj->stop.x, 40);
    test_assertint(obj->stop.y, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_init_enum(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_nested_enum obj ((Red, Black), (White, Blue))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_nested_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_nested_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.m, Test_Red);
    test_assertint(obj->a.n, Test_Black);
    test_assertint(obj->b.m, Test_White);
    test_assertint(obj->b.n, Test_Blue);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_member_init_enum(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_nested_enum obj (a(m:Red, n:Black), b(m:White, n:Blue))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_nested_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_nested_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.m, Test_Red);
    test_assertint(obj->a.n, Test_Black);
    test_assertint(obj->b.m, Test_White);
    test_assertint(obj->b.n, Test_Blue);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_mixed_init_enum(
    test_nested_composite_primitive this)
{
    const char *input = "test/s_nested_enum obj (a(m:Red, Black), (m:White, Blue))";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_nested_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_nested_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.m, Test_Red);
    test_assertint(obj->a.n, Test_Black);
    test_assertint(obj->b.m, Test_White);
    test_assertint(obj->b.n, Test_Blue);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_nested_composite_primitive_tc_init_bitmask(
    test_nested_composite_primitive this)
{
    /* Insert implementation */
}

void test_nested_composite_primitive_tc_member_init_bitmask(
    test_nested_composite_primitive this)
{
    /* Insert implementation */
}

void test_nested_composite_primitive_tc_mixed_init_bitmask(
    test_nested_composite_primitive this)
{
    /* Insert implementation */
}
