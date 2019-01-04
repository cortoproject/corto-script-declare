/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_function_id_implicit_type_tc_full_id_no_args(
    test_function_id_implicit_type this)
{
    const char *input = "/func() int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_full_id_one_arg(
    test_function_id_implicit_type this)
{
    const char *input = "/func(float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_full_id_two_args(
    test_function_id_implicit_type this)
{
    const char *input = "/func(float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_full_nested_id_no_args(
    test_function_id_implicit_type this)
{
    const char *input = "/data/func() int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_full_nested_id_one_arg(
    test_function_id_implicit_type this)
{
    const char *input = "/data/func(float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_full_nested_id_two_args(
    test_function_id_implicit_type this)
{
    const char *input = "/data/func(float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_id_no_args(
    test_function_id_implicit_type this)
{
    const char *input = "func() int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_id_one_arg(
    test_function_id_implicit_type this)
{
    const char *input = "func(float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_id_two_args(
    test_function_id_implicit_type this)
{
    const char *input = "func(float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_nested_id_no_args(
    test_function_id_implicit_type this)
{
    const char *input = "nested/func() int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "nested/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == corto_unknown_o);
    test_assertstr(corto_idof(corto_parentof(func)), "nested");
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_nested_id_one_arg(
    test_function_id_implicit_type this)
{
    const char *input = "nested/func(float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "nested/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == corto_unknown_o);
    test_assertstr(corto_idof(corto_parentof(func)), "nested");
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_nested_id_two_args(
    test_function_id_implicit_type this)
{
    const char *input = "nested/func(float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "nested/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == corto_unknown_o);
    test_assertstr(corto_idof(corto_parentof(func)), "nested");
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_scope_procedure_type(
    test_function_id_implicit_type this)
{
    const char *input = "struct Point { func() int32 }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "Point/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Point");
    test_assert(corto_typeof(func) == (corto_type)corto_method_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 2);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_scope_procedure_type_mixed(
    test_function_id_implicit_type this)
{
    const char *input = "struct Point { member x: int32; func() int32 }";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "Point/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Point");
    test_assert(corto_typeof(func) == (corto_type)corto_method_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 2);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_open_close_scope(
    test_function_id_implicit_type this)
{
    const char *input =
        "struct Foo {"
        "   overridable func() int32 "
        "}\n"
        "struct Bar {"
        "   func() int32"
        "}"
        ;

    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 2);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "Foo/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Foo");
    test_assert(corto_typeof(func) == (corto_type)corto_overridable_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);
    test_assert(corto_release(func) == 2);

    func = corto_lookup(data_o, "Bar/func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Bar");
    test_assert(corto_typeof(func) == (corto_type)corto_method_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);

    test_assert(corto_release(func) == 2);
    test_assert(corto_delete(ast) == 0);
    test_assert(corto_delete(func) == 0);
}

void test_function_id_implicit_type_tc_prev_scope_type(
    test_function_id_implicit_type this)
{
    const char *input =
        "struct Foo {"
        "    overridable func1() int32\n"
        "    struct Bar {"
        "        func1() int32\n"
        "        method func2() int32\n"
        "    }\n"
        "    func2() int32"
        "}"
        ;

    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "Foo/func1");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func1()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Foo");
    test_assert(corto_typeof(func) == (corto_type)corto_overridable_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);
    test_assert(corto_release(func) == 2);

    func = corto_lookup(data_o, "Foo/Bar/func1");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func1()");
    test_assert(corto_parentof(corto_parentof(corto_parentof(func))) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Bar");
    test_assert(corto_typeof(func) == (corto_type)corto_method_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);
    test_assert(corto_release(func) == 2);

    func = corto_lookup(data_o, "Foo/Bar/func2");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func2()");
    test_assert(corto_parentof(corto_parentof(corto_parentof(func))) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Bar");
    test_assert(corto_typeof(func) == (corto_type)corto_method_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);
    test_assert(corto_release(func) == 2);

    func = corto_lookup(data_o, "Foo/func2");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func2()");
    test_assert(corto_parentof(corto_parentof(func)) == data_o);
    test_assert(corto_typeof(corto_parentof(func)) == (corto_type)corto_struct_o);
    test_assertstr(corto_idof(corto_parentof(func)), "Foo");
    test_assert(corto_typeof(func) == (corto_type)corto_overridable_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assertint(corto_countof(func), 3);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 0);
    test_assert(func->parameters.buffer == NULL);
    test_assert(corto_release(func) == 2);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_delete(func) == 0);
}
