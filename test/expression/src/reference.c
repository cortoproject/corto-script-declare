/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_reference_tc_anonymous_list(
    test_reference this)
{
    const char *input = "list[int32, 10]";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_list_o);

    corto_list v = corto_value_ptrof(&value);
    test_assert(corto_collection(v)->element_type == (corto_type)corto_int32_o);
    test_assertint(corto_collection(v)->max, 10);
}

void test_reference_tc_anonymous_list_and_value(
    test_reference this)
{
    const char *input = "list[int32][10, 20, 30]";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(corto_instanceof(corto_list_o, type));
    test_assert(corto_collection(type)->element_type == (corto_type)corto_int32_o);
    test_assert(corto_collection(type)->max == 0);

    corto_ll list = *(corto_ll*)corto_value_ptrof(&value);
    test_assertint(corto_ll_count(list), 3);
    test_assertint((intptr_t)corto_ll_get(list, 0), 10);
    test_assertint((intptr_t)corto_ll_get(list, 1), 20);
    test_assertint((intptr_t)corto_ll_get(list, 2), 30);
}

void test_reference_tc_anonymous_composite(
    test_reference this)
{
    const char *input = "test.Point[10, 20]";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)test_Point_o);

    test_Point *val = corto_value_ptrof(&value);
    test_assertint(val->x, 10);
    test_assertint(val->y, 20);
}

void test_reference_tc_anonymous_primitive(
    test_reference this)
{
    const char *input = "int32[10]";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_int32_o);

    int32_t *val = corto_value_ptrof(&value);
    test_assertint(*val, 10);
}


void test_reference_tc_full_id(
    test_reference this)
{
    const char *input = "/corto";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_package_o);

    corto_package ref = corto_value_ptrof(&value);
    test_assert(ref == corto_o);
}


void test_reference_tc_full_nested_id(
    test_reference this)
{
    const char *input = "/corto/lang";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_package_o);

    corto_package ref = corto_value_ptrof(&value);
    test_assert(ref == corto_lang_o);
}


void test_reference_tc_id(
    test_reference this)
{
    const char *input = "corto";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_package_o);

    corto_package ref = corto_value_ptrof(&value);
    test_assert(ref == corto_o);
}


void test_reference_tc_nested_id(
    test_reference this)
{
    const char *input = "corto/lang";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_package_o);

    corto_package ref = corto_value_ptrof(&value);
    test_assert(ref == corto_lang_o);
}


void test_reference_tc_nested_id_dots(
    test_reference this)
{
    const char *input = "corto.lang";
    corto_value value = corto_value_init();
    int16_t ret = cortoscript_parse_expr(root_o, input, &value);
    test_assert(ret == 0);
    test_assert(value.kind == CORTO_OBJECT);

    corto_type type = corto_value_typeof(&value);
    test_assert(type != NULL);
    test_assert(type == (corto_type)corto_package_o);

    corto_package ref = corto_value_ptrof(&value);
    test_assert(ref == corto_lang_o);
}
