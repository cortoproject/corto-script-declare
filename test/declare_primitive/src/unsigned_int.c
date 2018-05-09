/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_unsigned_int_tc_floating_point(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 10.5";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 10);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_unsigned_int_tc_floating_point_scientific(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 1.5e+2";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 150);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_unsigned_int_tc_hexadecimal(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 0x100";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 256);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_lower_limit_16bit(
    test_unsigned_int this)
{
    const char *input = "uint16 obj: 0";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint16_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint16_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_lower_limit_32bit(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 0";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_lower_limit_64bit(
    test_unsigned_int this)
{
    const char *input = "uint64 obj: 0";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint64_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint64_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_lower_limit_8bit(
    test_unsigned_int this)
{
    const char *input = "uint8 obj: 0";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint8_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint8_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_negative_floating_point(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: -1.5";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 4294967295);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_signed(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: -1";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 4294967295);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_unsigned(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 10";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 10);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_upper_limit_16bit(
    test_unsigned_int this)
{
    const char *input = "uint16 obj: 65535";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint16_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint16_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 65535);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_unsigned_int_tc_upper_limit_32bit(
    test_unsigned_int this)
{
    const char *input = "uint32 obj: 4294967295";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint32_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint32_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 4294967295);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_unsigned_int_tc_upper_limit_64bit(
    test_unsigned_int this)
{
    const char *input = "uint64 obj: 18446744073709551615";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint64_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint64_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 18446744073709551615u);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}

void test_unsigned_int_tc_upper_limit_8bit(
    test_unsigned_int this)
{
    const char *input = "uint8 obj: 255";
    ast_Node ast = cortoscript_ast_parse(input);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(corto_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, ast);
    test_assert(ret == 0);

    uint8_t *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)corto_uint8_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(*obj, 255);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
