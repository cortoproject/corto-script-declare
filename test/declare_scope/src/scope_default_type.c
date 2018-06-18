/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_scope_default_type_tc_full_id_1stmt(
    test_scope_default_type this)
{
    const char *input = "int32 /obj { float64 child: 10.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 3);
    test_assertint(corto_scope_size(obj), 1);
    test_assertint(*obj, 0);

    double *child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assert(corto_countof(child) == 2);
    test_assertint(corto_scope_size(child), 0);
    test_assert(*child == 10.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_full_id_2stmt(
    test_scope_default_type this)
{
    const char *input = "int32 /obj { float64 child_1: 10.5; child_2: 20.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == 10.5);

    double *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == 20.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_full_nested_id_1stmt(
    test_scope_default_type this)
{
    const char *input = "int32 /foo/obj { float64 child: 10.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 3);
    test_assertint(corto_scope_size(obj), 1);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    double *child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assert(corto_countof(child) == 2);
    test_assertint(corto_scope_size(child), 0);
    test_assert(*child == 10.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_full_nested_id_2stmt(
    test_scope_default_type this)
{
    const char *input = "int32 /foo/obj { float64 child_1: 10.5; child_2: 20.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == 10.5);

    double *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == 20.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_id_1stmt(
    test_scope_default_type this)
{
    const char *input = "int32 obj { float64 child: 10.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 3);
    test_assertint(corto_scope_size(obj), 1);
    test_assert(*obj == 0);

    double *child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assert(corto_countof(child) == 2);
    test_assertint(corto_scope_size(child), 0);
    test_assert(*child == 10.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_id_2stmt(
    test_scope_default_type this)
{
    const char *input = "int32 obj { float64 child_1: 10.5; child_2: 20.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == 10.5);

    double *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == 20.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_nested_id_1stmt(
    test_scope_default_type this)
{
    const char *input = "int32 foo/obj { float64 child: 10.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 3);
    test_assertint(corto_scope_size(obj), 1);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    double *child = corto_lookup(obj, "child");
    test_assert(child != NULL);
    test_assert(corto_typeof(child) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child, CORTO_VALID));
    test_assert(corto_countof(child) == 2);
    test_assertint(corto_scope_size(child), 0);
    test_assert(*child == 10.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 2);
    test_assert(corto_delete(obj) == 0);
}


void test_scope_default_type_tc_nested_id_2stmt(
    test_scope_default_type this)
{
    const char *input = "int32 foo/obj { float64 child_1: 10.5; child_2: 20.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "foo/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    corto_object parent = corto_parentof(obj);
    test_assert(corto_typeof(parent) == corto_unknown_o);
    test_assert(!corto_check_state(parent, CORTO_VALID));
    test_assertstr(corto_idof(parent), "foo");
    test_assert(corto_countof(parent) == 1);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == 10.5);

    double *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == 20.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}

void test_scope_default_type_tc_anonymous_type(
    test_scope_default_type this)
{
    const char *input = "int32 /obj { float[width_64] child_1: 10.5; child_2: 20.5; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    corto_type type_1 = corto_typeof(child_1);
    test_assert(!corto_check_attr(type_1, CORTO_ATTR_NAMED));
    test_assert(type_1->kind == CORTO_PRIMITIVE);
    test_assert(corto_primitive(type_1)->kind == CORTO_FLOAT);
    test_assert(corto_primitive(type_1)->width == CORTO_WIDTH_64);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assertflt(*child_1, 10.5);

    double *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    corto_type type_2 = corto_typeof(child_2);
    test_assert(type_1 == type_2);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assertflt(*child_2, 20.5);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}

void test_scope_default_type_tc_override_default_type(
    test_scope_default_type this)
{
    const char *input = "int32 obj { float64 child_1: 10.5; uint32 child_2: 20; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    double *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)corto_float64_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == 10.5);

    uint32_t *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == 20);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}

void test_scope_default_type_tc_type_relative_to_scope(
    test_scope_default_type this)
{
    const char *input = "int32 /test/obj { Color child_1: Red; child_2: Black; }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    int32_t *obj = corto_lookup(NULL, "test/obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 4);
    test_assertint(corto_scope_size(obj), 2);
    test_assert(*obj == 0);

    test_Color *child_1 = corto_lookup(obj, "child_1");
    test_assert(child_1 != NULL);
    test_assert(corto_typeof(child_1) == (corto_type)test_Color_o);
    test_assert(corto_check_state(child_1, CORTO_VALID));
    test_assert(corto_countof(child_1) == 2);
    test_assertint(corto_scope_size(child_1), 0);
    test_assert(*child_1 == Test_Red);

    test_Color *child_2 = corto_lookup(obj, "child_2");
    test_assert(child_2 != NULL);
    test_assert(corto_typeof(child_2) == (corto_type)test_Color_o);
    test_assert(corto_check_state(child_2, CORTO_VALID));
    test_assert(corto_countof(child_2) == 2);
    test_assertint(corto_scope_size(child_2), 0);
    test_assert(*child_2 == Test_Black);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 3);
    test_assert(corto_delete(obj) == 0);
}
