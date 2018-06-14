/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void test_reference_tc_ref_anonymous(
    test_reference this)
{
    const char *input = "object obj: int32[10]";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_object_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    corto_object o = *obj;
    test_assert(corto_typeof(o) == (corto_type)corto_int32_o);
    test_assert(corto_check_state(o, CORTO_VALID));
    test_assert(!corto_check_attr(o, CORTO_ATTR_NAMED));
    test_assertint(*(int32_t*)o, 10);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_reference_tc_ref_full_id(
    test_reference this)
{
    const char *input = "object obj: /corto/lang";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_object_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == corto_lang_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_reference_tc_ref_id(
    test_reference this)
{
    const char *input = "object obj: foo";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_object_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == foo);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_reference_tc_ref_null(
    test_reference this)
{
    const char *input = "object obj: null";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_object_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_reference_tc_ref_type_equal(
    test_reference this)
{
    const char *input = "test/struct_w_ref obj: my_ref";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    test_base_class my_ref = corto_create(
        data_o, "my_ref", test_base_class_o);
    test_assert(my_ref != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_struct_w_ref *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_struct_w_ref_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->m == my_ref);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_reference_tc_ref_type_inherit(
    test_reference this)
{
    const char *input = "test/struct_w_ref obj: my_ref";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    test_base_class my_ref = corto_create(
        data_o, "my_ref", test_sub_class_o);
    test_assert(my_ref != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_struct_w_ref *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_struct_w_ref_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->m == my_ref);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_reference_tc_ref_implements(
    test_reference this)
{
    const char *input = "test/struct_w_interface_ref obj: my_ref";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    test_base_class my_ref = corto_create(
        data_o, "my_ref", test_base_class_o);
    test_assert(my_ref != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_struct_w_ref *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_struct_w_interface_ref_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->m == my_ref);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_reference_tc_ref_base_not_sub(
    test_reference this)
{
    const char *input = "test/struct_w_ref obj: my_ref";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    test_base_class my_ref = corto_create(
        data_o, "my_ref", test_base_of_base_o);
    test_assert(my_ref != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(corto_delete(ast) == 0);
}

void test_reference_tc_ref_implements_sub(
    test_reference this)
{
    const char *input = "test/struct_w_interface_ref obj: my_ref";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    test_base_class my_ref = corto_create(
        data_o, "my_ref", test_sub_class_o);
    test_assert(my_ref != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    test_struct_w_ref *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_struct_w_interface_ref_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->m == my_ref);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_reference_tc_ref_nomatch(
    test_reference this)
{
    const char *input = "test/struct_w_ref obj: corto/lang";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret != 0);
    test_assert(corto_catch() != 0);

    test_assert(corto_delete(ast) == 0);
}
