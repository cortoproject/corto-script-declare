/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_integer_op_add(
    test_integer this)
{
    const char *input = "10 + 5";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 15);
}


void test_integer_op_and(
    test_integer this)
{
    const char *input = "12 & 6";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 4);
}


void test_integer_op_cond_and_false(
    test_integer this)
{
    const char *input = "10 && 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_and_kw_false(
    test_integer this)
{
    const char *input = "10 and 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_and_kw_true(
    test_integer this)
{
    const char *input = "10 and 2";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_and_true(
    test_integer this)
{
    const char *input = "10 && 2";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_eq_false(
    test_integer this)
{
    const char *input = "10 == 5";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_eq_true(
    test_integer this)
{
    const char *input = "10 == 10";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_neq_false(
    test_integer this)
{
    const char *input = "10 != 10";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_neq_true(
    test_integer this)
{
    const char *input = "10 != 5";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_not_false(
    test_integer this)
{
    const char *input = "!10";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_not_kw_false(
    test_integer this)
{
    const char *input = "not 10";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_not_kw_true(
    test_integer this)
{
    const char *input = "not 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_not_true(
    test_integer this)
{
    const char *input = "!0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_or_false(
    test_integer this)
{
    const char *input = "0 || 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_or_kw_false(
    test_integer this)
{
    const char *input = "0 or 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == false);
}


void test_integer_op_cond_or_kw_true(
    test_integer this)
{
    const char *input = "10 or 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_cond_or_true(
    test_integer this)
{
    const char *input = "10 || 0";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_bool_o);

    bool *lit = corto_value_ptrof(&value);
    test_assert(*lit == true);
}


void test_integer_op_div(
    test_integer this)
{
    const char *input = "10 / 2";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_float64_o);

    double *lit = corto_value_ptrof(&value);
    test_assert(*lit == 5.0);
}


void test_integer_op_mod(
    test_integer this)
{
    const char *input = "10 % 3";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assert(*lit == 1);
}


void test_integer_op_mul(
    test_integer this)
{
    const char *input = "10 * 2";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assert(*lit == 20);
}


void test_integer_op_or(
    test_integer this)
{
    const char *input = "13 | 3";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 15);
}


void test_integer_op_sub(
    test_integer this)
{
    const char *input = "10 - 2";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assert(*lit == 8);
}


void test_integer_op_ternary_false(
    test_integer this)
{
    const char *input = "0 ? 10 : 20";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 20);
}

void test_integer_op_ternary_true(
    test_integer this)
{
    const char *input = "5 ? 10 : 20";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 10);
}


void test_integer_op_xor(
    test_integer this)
{
    const char *input = "11 ^ 3";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_uint64_o);

    uint64_t *lit = corto_value_ptrof(&value);
    test_assertint(*lit, 8);
}
