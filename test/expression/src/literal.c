/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_literal_boolean_false(
    test_literal this)
{
    const char *input = "false";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Boolean_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_boolean_true(
    test_literal this)
{
    const char *input = "true";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Boolean_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point(
    test_literal this)
{
    const char *input = "10.5";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 10.5);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_measurement(
    test_literal this)
{
    const char *input = "10.5ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 10.5);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_measurement_scientific_minus_e(
    test_literal this)
{
    const char *input = "10.5e-2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.1050);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_measurement_scientific_plus_e(
    test_literal this)
{
    const char *input = "10.5e+2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1050.0);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_scientific_minus_e(
    test_literal this)
{
    const char *input = "10.5e-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.1050);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_scientific_minus_e_upper(
    test_literal this)
{
    const char *input = "10.5E-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.1050);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_scientific_plus_e(
    test_literal this)
{
    const char *input = "10.5e+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1050.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_scientific_plus_e_upper(
    test_literal this)
{
    const char *input = "10.5E+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1050.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_signed_scientific_minus_e(
    test_literal this)
{
    const char *input = "-10.5e-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -0.1050);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_signed_scientific_minus_e_upper(
    test_literal this)
{
    const char *input = "-10.5E-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -0.1050);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_signed_scientific_plus_e(
    test_literal this)
{
    const char *input = "-10.5e+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -1050.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_floating_point_signed_scientific_plus_e_upper(
    test_literal this)
{
    const char *input = "-10.5E+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -1050.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_hexadecimal(
    test_literal this)
{
    const char *input = "0xFF";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Integer_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 255);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_integer(
    test_literal this)
{
    const char *input = "10";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Integer_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_integer_measurement(
    test_literal this)
{
    const char *input = "10ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Integer_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 10);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}

void test_literal_integer_scientific_minus_e(
    test_literal this)
{
    const char *input = "10e-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_integer_scientific_minus_e_upper(
    test_literal this)
{
    const char *input = "10E-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_integer_scientific_plus_e(
    test_literal this)
{
    const char *input = "10e+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1000.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_integer_scientific_plus_e_upper(
    test_literal this)
{
    const char *input = "10E+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1000.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_null_literal(
    test_literal this)
{
    const char *input = "null";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Null_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type == NULL);
    test_assert(value.is.literal.kind == CORTO_LITERAL_NULL);

    void *lit = corto_value_ptrof(&value);
    test_assert(lit == NULL);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_minus(
    test_literal this)
{
    const char *input = "-10";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_SignedInteger_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int64_o);

    int64_t *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_minus_measurement(
    test_literal this)
{
    const char *input = "-10ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_SignedInteger_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int64_o);

    int64_t *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -10);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_minus_measurement_scientific_minus_e(
    test_literal this)
{
    const char *input = "-10e-2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -0.10);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_minus_measurement_scientific_plus_e(
    test_literal this)
{
    const char *input = "-10e+2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, -1000.0);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_plus(
    test_literal this)
{
    const char *input = "+10";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_SignedInteger_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int64_o);

    int64_t *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_plus_measurement(
    test_literal this)
{
    const char *input = "+10ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_SignedInteger_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int64_o);

    int64_t *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 10);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_plus_measurement_scientific_minus_e(
    test_literal this)
{
    const char *input = "+10e-2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.10);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_plus_measurement_scientific_plus_e(
    test_literal this)
{
    const char *input = "+10e+2ft";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1000.0);

    test_assertstr(corto_value_unitof(&value), "ft");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_scientific_minus_e(
    test_literal this)
{
    const char *input = "10e-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_scientific_minus_e_upper(
    test_literal this)
{
    const char *input = "10E-2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 0.10);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_scientific_plus_e(
    test_literal this)
{
    const char *input = "10e+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1000.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_signed_integer_scientific_plus_e_upper(
    test_literal this)
{
    const char *input = "10E+2";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assertflt(*lit, 1000.0);

    test_assert(corto_delete(ast) == 0);
}


void test_literal_string_double_quote(
    test_literal this)
{
    const char *input = "\"Hello World\"";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_String_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "Hello World");

    test_assert(corto_delete(ast) == 0);
}


void test_literal_string_single_quote(
    test_literal this)
{
    const char *input = "'Hello World'";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_String_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "Hello World");

    test_assert(corto_delete(ast) == 0);
}

void test_literal_nan_literal(
    test_literal this)
{
    const char *input = "nan";
    ast_Node ast = cortoscript_ast_parse(input, true);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_FloatingPoint_o);

    corto_value value = corto_value_init();
    int16_t ret = cortoscript_ast_to_value(ast, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assert(*lit != *lit);

    test_assert(corto_delete(ast) == 0);
}
