/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_boolean_tc_constant_nonzero(
    test_boolean this)
{
    const char *input = "bool obj: test/Color/Red";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == true);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_boolean_tc_constant_zero(
    test_boolean this)
{
    const char *input = "bool obj: test/Color/Black";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == false);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_boolean_tc_false(
    test_boolean this)
{
    const char *input = "bool obj: false";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == false);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_boolean_tc_int_nonzero(
    test_boolean this)
{
    const char *input = "bool obj: 10";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == true);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_boolean_tc_int_zero(
    test_boolean this)
{
    const char *input = "bool obj: 0";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == false);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_boolean_tc_reference(
    test_boolean this)
{
    const char *input = "bool obj: corto/lang";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == true);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_boolean_tc_string(
    test_boolean this)
{
    const char *input = "bool obj: \"Foo Bar\"";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == true);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_boolean_tc_null(
    test_boolean this)
{
    const char *input = "bool obj: null";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == false);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_boolean_tc_true(
    test_boolean this)
{
    const char *input = "bool obj: true";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    bool *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_bool_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(*obj == true);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_boolean_tc_reference_value_type(
    test_boolean this)
{
    /* Insert implementation */
}
