/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_inheritance_struct_tc_empty_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 0);
    test_assertint(obj->super.b, 0);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 0);
    test_assertint(obj->d, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {10, 20, 30, 40, 50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {10, 20, 30, 40}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_member_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:10, super.b:20, super.c:30, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_member_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {a:40, b:20, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 0);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_member_same_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:20, a:40}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 20);
    test_assertint(obj->super.b, 0);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_mixed_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:10, 20, 30, a:40, 50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_mixed_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:10, 20, a:40, 50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_mixed_partial_init_mixed_same_name(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {10, 20, a:40, 50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_empty_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{}}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 0);
    test_assertint(obj->super.b, 0);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 0);
    test_assertint(obj->d, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:10, super.b:20, super.c:30, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_full_init_reverse_order(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {d:50, a:40, super.c:30, super.b:20, super.a:10}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super.a:10, super.b:20, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_nested_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{10, 20, 30}, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_nested_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{10, 20}, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_nested_member_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{a:10, b:20, c:30}, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_nested_member_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{a:10, c:30}, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 0);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_nested_member_mixed_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{b:20, 30}, a:40, d:50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 0);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_mixed_full_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{a:10, b:20, c:30}, 40, 50}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 30);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 50);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_inheritance_struct_tc_super_mixed_partial_init(
    test_inheritance_struct this)
{
    const char *input = "test/s_sub obj = {super:{a:10, b:20}, 40}";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_s_sub *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sub_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->super.a, 10);
    test_assertint(obj->super.b, 20);
    test_assertint(obj->super.c, 0);
    test_assertint(obj->a, 40);
    test_assertint(obj->d, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
