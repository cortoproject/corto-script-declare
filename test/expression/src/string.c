/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_string_op_add(
    test_string this)
{
    const char *input = "'foo' + 'bar'";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "foobar");
}

void test_string_op_add_null_null(
    test_string this)
{
    const char *input = "null + null";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type == NULL);

    void *lit = corto_value_ptrof(&value);
    test_assert(lit == NULL);
}

void test_string_op_add_string_null(
    test_string this)
{
    const char *input = "'foo' + null";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "foo");
}

void test_string_op_cond_and_false(
    test_string this)
{
    const char *input = "'foo' && null";
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


void test_string_op_cond_and_kw_false(
    test_string this)
{
    const char *input = "'foo' and null";
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


void test_string_op_cond_and_kw_true(
    test_string this)
{
    const char *input = "'foo' and 'bar'";
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


void test_string_op_cond_and_true(
    test_string this)
{
    const char *input = "'foo' && 'bar'";
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


void test_string_op_cond_eq_false(
    test_string this)
{
    const char *input = "'foo' == 'bar'";
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


void test_string_op_cond_eq_true(
    test_string this)
{
    const char *input = "'foo' == 'foo'";
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


void test_string_op_cond_neq_false(
    test_string this)
{
    const char *input = "'foo' != 'foo'";
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


void test_string_op_cond_neq_true(
    test_string this)
{
    const char *input = "'foo' != 'bar'";
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


void test_string_op_cond_not_false(
    test_string this)
{
    const char *input = "!'foo'";
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


void test_string_op_cond_not_kw_false(
    test_string this)
{
    const char *input = "not 'foo'";
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


void test_string_op_cond_not_kw_true(
    test_string this)
{
    const char *input = "not null";
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


void test_string_op_cond_not_true(
    test_string this)
{
    const char *input = "!null";
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


void test_string_op_cond_or_false(
    test_string this)
{
    const char *input = "null || null";
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


void test_string_op_cond_or_kw_false(
    test_string this)
{
    const char *input = "null or null";
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


void test_string_op_cond_or_kw_true(
    test_string this)
{
    const char *input = "'foo' or null";
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


void test_string_op_cond_or_true(
    test_string this)
{
    const char *input = "'foo' || null";
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

void test_string_op_cond_or_true_string_string(
    test_string this)
{
    const char *input = "'foo' || 'bar'";
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

void test_string_op_ternary_false(
    test_string this)
{
    const char *input = "null ? 'foo' : 'bar'";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "bar");
}


void test_string_op_ternary_true(
    test_string this)
{
    const char *input = "'hello' ? 'foo' : 'bar'";
    int16_t ret;
    corto_value value = corto_value_init();

    ret = cortoscript_parse_expr(NULL, input, &value);
    test_assert(ret == 0);

    /* Validate contents of value */
    test_assert(value.kind == CORTO_LITERAL);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_string_o);

    char **lit = corto_value_ptrof(&value);
    test_assertstr(*lit, "foo");
}
