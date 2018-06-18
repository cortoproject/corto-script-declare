/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_scope_default_parent_type_tc_full_id_1stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct /obj { child: int32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 3);
    test_assertint(corto_scope_size(obj), 1);

    corto_member child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_full_id_2stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct /obj { child_1: int32; child_2: float32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);

    corto_member child = corto_lookup(obj, "child_1");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    child = corto_lookup(obj, "child_2");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_float32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_full_nested_id_1stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct /foo/obj { child: int32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct *obj = corto_lookup(NULL, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 3);
    test_assertint(corto_scope_size(obj), 1);

    corto_member child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_full_nested_id_2stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct /foo/obj { child_1: int32; child_2: float32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct obj = corto_lookup(NULL, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);

    corto_member child = corto_lookup(obj, "child_1");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    child = corto_lookup(obj, "child_2");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_float32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_id_1stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct obj { child: int32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct *obj = corto_lookup(NULL, "data/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 3);
    test_assertint(corto_scope_size(obj), 1);

    corto_member child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_id_2stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct obj { child_1: int32; child_2: float32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct obj = corto_lookup(NULL, "data/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);

    corto_member child = corto_lookup(obj, "child_1");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    child = corto_lookup(obj, "child_2");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_float32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_nested_id_1stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct foo/obj { child: int32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct *obj = corto_lookup(NULL, "data/foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 3);
    test_assertint(corto_scope_size(obj), 1);

    corto_member child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_parent_type_tc_nested_id_2stmt(
    test_scope_default_parent_type this)
{
    const char *input = "struct foo/obj { child_1: int32; child_2: float32; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_struct obj = corto_lookup(NULL, "data/foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_struct_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);

    corto_member child = corto_lookup(obj, "child_1");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_int32_o);

    child = corto_lookup(obj, "child_2");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_member_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assertint(corto_countof(child), 3);
    test_assertint(corto_scope_size(child), 0);
    test_assert(child->type == (corto_type)corto_float32_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}
