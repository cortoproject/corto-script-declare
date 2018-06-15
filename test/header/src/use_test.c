/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_use_test_tc_use_alias_full_id(
    test_use_test this)
{
    const char *input =
        "use /data as hello\n"
        "array[object,3] obj: hello/obj_1, hello/obj_1/obj_2, hello\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object obj_1 = corto_create(data_o, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_alias_full_nested_id(
    test_use_test this)
{
    const char *input =
        "use /data/foo as hello\n"
        "array[object,3] obj: hello/obj_1, hello/obj_1/obj_2, hello\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    corto_object obj_1 = corto_create(foo, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == foo);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_alias_id(
    test_use_test this)
{
    const char *input =
        "use data as hello\n"
        "array[object,3] obj: hello/obj_1, hello/obj_1/obj_2, hello\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object obj_1 = corto_create(data_o, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_alias_mixed_scope_operator(
    test_use_test this)
{
    const char *input =
        "use data/foo as hello.world\n"
        "array[object,3] obj: hello/world.obj_1, hello.world.obj_1.obj_2, hello.world\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    corto_object obj_1 = corto_create(foo, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == foo);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_alias_nested_id(
    test_use_test this)
{
    const char *input =
        "use data/foo as hello\n"
        "array[object,3] obj: hello/obj_1, hello/obj_1/obj_2, hello\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    corto_object obj_1 = corto_create(foo, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == foo);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_full_id(
    test_use_test this)
{
    const char *input =
        "use /data\n"
        "array[object,3] obj: obj_1, obj_1/obj_2, data\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object obj_1 = corto_create(data_o, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_full_nested_id(
    test_use_test this)
{
    const char *input =
        "use /data/foo\n"
        "array[object,3] obj: obj_1, obj_1/obj_2, data\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    corto_object obj_1 = corto_create(data_o, "foo/obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_use_test_tc_use_id(
    test_use_test this)
{
    const char *input =
        "use data\n"
        "array[object,3] obj: obj_1, obj_1/obj_2, data\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object obj_1 = corto_create(data_o, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_use_test_tc_use_nested_id(
    test_use_test this)
{
    const char *input =
        "use data/foo\n"
        "array[object,3] obj: obj_1, obj_1/obj_2, data\n"
        ;

    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 2);

    corto_object foo = corto_create(data_o, "foo", corto_void_o);
    test_assert(foo != NULL);

    corto_object obj_1 = corto_create(foo, "obj_1", corto_void_o);
    test_assert(obj_1 != NULL);

    corto_object obj_2 = corto_create(obj_1, "obj_2", corto_void_o);
    test_assert(obj_2 != NULL);

    int16_t ret = cortoscript_ast_declare(root_o, ast);
    test_assert(ret == 0);

    corto_object *obj = corto_lookup(NULL, "obj");
    test_assert(obj != NULL);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assertint(corto_countof(obj), 2);
    test_assertint(corto_scope_size(obj), 0);
    test_assert(obj[0] == obj_1);
    test_assert(obj[1] == obj_2);
    test_assert(obj[2] == data_o);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
