/* This is a managed file. Do not delete this comment. */

#include <include/test.h>


void test_args_tc_full_id(
    test_args this)
{
    corto_object my_int = corto_create(root_o, "my_int", corto_int_o);
    test_assert(my_int != NULL);

    const char *input = "func(/my_int arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(/my_int arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)my_int);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_full_id_nested(
    test_args this)
{
    const char *input = "func(/corto/vstore/time arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(/corto/vstore/time arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)corto_time_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_id(
    test_args this)
{
    corto_object my_int = corto_create(data_o, "my_int", corto_int_o);
    test_assert(my_int != NULL);

    const char *input = "func(my_int arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(/data/my_int arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)my_int);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_id_nested(
    test_args this)
{
    corto_object my_int = corto_create(data_o, "nested/my_int", corto_int_o);
    test_assert(my_int != NULL);

    const char *input = "func(nested/my_int arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(/data/nested/my_int arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    test_assert(func->parameters.buffer[0].type == (corto_type)my_int);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_in(
    test_args this)
{
    const char *input = "func(in float32 arg) int32";
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


void test_args_tc_in_anonymous(
    test_args this)
{
    const char *input = "func(in list[float32] arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(list[float32,0] arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_inout(
    test_args this)
{
    const char *input = "func(inout float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(inout:float32 arg)");
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
    test_assert(func->parameters.buffer[0].inout == CORTO_INOUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_inout_anonymous(
    test_args this)
{
    const char *input = "func(inout list[float32] arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(inout:list[float32,0] arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_INOUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_inout_mixed(
    test_args this)
{
    const char *input = "func(inout float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(inout:float32 arg1,string arg2)");
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
    test_assert(func->parameters.buffer[0].inout == CORTO_INOUT);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}

void test_args_tc_out_mixed(
    test_args this)
{
    const char *input = "func(out float32 arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(out:float32 arg1,string arg2)");
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
    test_assert(func->parameters.buffer[0].inout == CORTO_OUT);

    test_assertstr(func->parameters.buffer[1].name, "arg2");
    test_assert(func->parameters.buffer[1].type != NULL);
    test_assert(func->parameters.buffer[1].type == (corto_type)corto_string_o);
    test_assert(func->parameters.buffer[1].is_reference == false);
    test_assert(func->parameters.buffer[1].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_out(
    test_args this)
{
    const char *input = "func(out float32 arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(out:float32 arg)");
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
    test_assert(func->parameters.buffer[0].inout == CORTO_OUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_out_anonymous(
    test_args this)
{
    const char *input = "func(out list[float32] arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(out:list[float32,0] arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_OUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref(
    test_args this)
{
    const char *input = "func(float32& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32& arg)");
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
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_in(
    test_args this)
{
    const char *input = "func(in float32& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32& arg)");
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
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_in_anonymous(
    test_args this)
{
    const char *input = "func(in list[float32]& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(list[float32,0]& arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_inout(
    test_args this)
{
    const char *input = "func(inout float32& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(inout:float32& arg)");
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
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_INOUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_inout_anonymous(
    test_args this)
{
    const char *input = "func(inout list[float32]& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(inout:list[float32,0]& arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_INOUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_mixed(
    test_args this)
{
    const char *input = "func(float32& arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(float32& arg1,string arg2)");
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
    test_assert(func->parameters.buffer[0].is_reference == true);
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


void test_args_tc_ref_out(
    test_args this)
{
    const char *input = "func(out float32& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(out:float32& arg)");
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
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_OUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_ref_out_anonymous(
    test_args this)
{
    const char *input = "func(out list[float32]& arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(out:list[float32,0]& arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == true);
    test_assert(func->parameters.buffer[0].inout == CORTO_OUT);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_type_anonymous(
    test_args this)
{
    const char *input = "func(list[float32] arg) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(list[float32,0] arg)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 1);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
    test_assert(func->parameters.buffer[0].is_reference == false);
    test_assert(func->parameters.buffer[0].inout == CORTO_IN);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(func) == 1);
    test_assert(corto_delete(func) == 0);
}


void test_args_tc_type_mixed_anonymous(
    test_args this)
{
    const char *input = "func(in list[float32] arg1, string arg2) int32";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    corto_function func = corto_lookup(data_o, "func");
    test_assert(func != NULL);
    test_assertstr(corto_idof(func), "func(list[float32,0] arg1,string arg2)");
    test_assert(corto_parentof(func) == data_o);
    test_assert(corto_typeof(func) == (corto_type)corto_function_o);
    test_assert(corto_check_state(func, CORTO_VALID));
    test_assert(corto_countof(func) == 2);
    test_assert(func->return_type == (corto_type)corto_int32_o);
    test_assertint(func->parameters.length, 2);
    test_assert(func->parameters.buffer != NULL);

    test_assertstr(func->parameters.buffer[0].name, "arg1");
    test_assert(func->parameters.buffer[0].type != NULL);
    corto_type type = func->parameters.buffer[0].type;
    test_assert(type->kind == CORTO_COLLECTION);
    test_assert(corto_collection(type)->kind == CORTO_LIST);
    test_assert(corto_collection(type)->element_type == (corto_type)corto_float32_o);
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
