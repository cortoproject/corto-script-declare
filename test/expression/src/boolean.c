/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_boolean_op_and_false(
    test_boolean this)
{
    const char *input = "true & false";
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

void test_boolean_op_and_true(
    test_boolean this)
{
    const char *input = "true & true";
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

void test_boolean_op_cond_and_false(
    test_boolean this)
{
    const char *input = "true && false";
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

void test_boolean_op_cond_and_kw_false(
    test_boolean this)
{
    const char *input = "true and false";
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

void test_boolean_op_cond_and_kw_true(
    test_boolean this)
{
    const char *input = "true and true";
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

void test_boolean_op_cond_and_true(
    test_boolean this)
{
    const char *input = "true && true";
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

void test_boolean_op_cond_eq_false(
    test_boolean this)
{
    const char *input = "true == false";
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

void test_boolean_op_cond_eq_true(
    test_boolean this)
{
    const char *input = "false == false";
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

void test_boolean_op_cond_neq_false(
    test_boolean this)
{
    const char *input = "true != true";
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

void test_boolean_op_cond_neq_true(
    test_boolean this)
{
    const char *input = "true != false";
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

void test_boolean_op_cond_not_false(
    test_boolean this)
{
    const char *input = "!true";
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

void test_boolean_op_cond_not_kw_false(
    test_boolean this)
{
    const char *input = "not true";
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

void test_boolean_op_cond_not_kw_true(
    test_boolean this)
{
    const char *input = "not false";
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

void test_boolean_op_cond_not_true(
    test_boolean this)
{
    const char *input = "!false";
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

void test_boolean_op_cond_or_false(
    test_boolean this)
{
    const char *input = "false || false";
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

void test_boolean_op_cond_or_kw_false(
    test_boolean this)
{
    const char *input = "false or false";
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

void test_boolean_op_cond_or_kw_true(
    test_boolean this)
{
    const char *input = "false or true";
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

void test_boolean_op_cond_or_true(
    test_boolean this)
{
    const char *input = "false || true";
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

void test_boolean_op_or_false(
    test_boolean this)
{
    const char *input = "false | false";
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

void test_boolean_op_or_true(
    test_boolean this)
{
    const char *input = "true | false";
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

void test_boolean_op_xor_false(
    test_boolean this)
{
    const char *input = "true ^ true";
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

void test_boolean_op_xor_true(
    test_boolean this)
{
    const char *input = "true ^ false";
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

void test_boolean_op_ternary_false(
    test_boolean this)
{
    const char *input = "false ? true : false";
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

void test_boolean_op_ternary_true(
    test_boolean this)
{
    const char *input = "true ? true : false";
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
