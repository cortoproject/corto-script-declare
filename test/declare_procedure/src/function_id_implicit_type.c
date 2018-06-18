/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_function_id_implicit_type_tc_full_id_no_args(
    test_function_id_implicit_type this)
{
    const char *input = "/func() int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(NULL, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == root_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func()");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32 arg1,string arg2)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
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
    test_assert(func->returnType == (corto_type)corto_int32_o);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
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
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);
    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
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
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
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
    test_assert(func->returnType == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].passByReference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].passByReference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}
