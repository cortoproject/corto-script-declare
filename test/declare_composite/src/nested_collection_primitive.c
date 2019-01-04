/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_nested_collection_primitive_tc_array_empty_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_array obj = {[], []}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_array *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_array_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a[0], 0);
    test_assertint(obj->a[1], 0);
    test_assertint(obj->a[2], 0);
    test_assertint(obj->b[0], 0);
    test_assertint(obj->b[1], 0);
    test_assertint(obj->b[2], 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_array_full_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_array obj = {[10, 20, 30], [40, 50, 60]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_array *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_array_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a[0], 10);
    test_assertint(obj->a[1], 20);
    test_assertint(obj->a[2], 30);
    test_assertint(obj->b[0], 40);
    test_assertint(obj->b[1], 50);
    test_assertint(obj->b[2], 60);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_array_init_bitmask(
    test_nested_collection_primitive this)
{
    const char *input =
        "test/s_array_bitmask obj = {"
            "[HasSalt|HasPepper, HasSalt|HasSugar, HasSalt|HasVinegar], "
            "[HasPepper|HasSugar, HasPepper|HasVinegar, HasSugar|HasVinegar]"
        "}"
        ;

    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_array_bitmask *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_array_bitmask_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a[0], Test_HasSalt | Test_HasPepper);
    test_assertint(obj->a[1], Test_HasSalt | Test_HasSugar);
    test_assertint(obj->a[2], Test_HasSalt | Test_HasVinegar);
    test_assertint(obj->b[0], Test_HasPepper | Test_HasSugar);
    test_assertint(obj->b[1], Test_HasPepper | Test_HasVinegar);
    test_assertint(obj->b[2], Test_HasSugar | Test_HasVinegar);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_array_init_enum(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_array_enum obj = {[Red, Black, White], [Blue, Red, Black]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_array_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_array_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a[0], Test_Red);
    test_assertint(obj->a[1], Test_Black);
    test_assertint(obj->a[2], Test_White);
    test_assertint(obj->b[0], Test_Blue);
    test_assertint(obj->b[1], Test_Red);
    test_assertint(obj->b[2], Test_Black);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_array_partial_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_array obj = {[10, 20], [40, 50]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_array *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_array_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a[0], 10);
    test_assertint(obj->a[1], 20);
    test_assertint(obj->a[2], 0);
    test_assertint(obj->b[0], 40);
    test_assertint(obj->b[1], 50);
    test_assertint(obj->b[2], 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_1_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_list obj = {[10], [20]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->a != NULL);
    test_assert(obj->b != NULL);
    test_assertint(ut_ll_count(obj->a), 1);
    test_assertint(ut_ll_count(obj->b), 1);
    test_assertint(corto_int32List__get(obj->a, 0), 10);
    test_assertint(corto_int32List__get(obj->b, 0), 20);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_3_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_list obj = {[10, 20, 30], [40, 50, 60]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->a != NULL);
    test_assert(obj->b != NULL);
    test_assertint(ut_ll_count(obj->a), 3);
    test_assertint(ut_ll_count(obj->b), 3);
    test_assertint(corto_int32List__get(obj->a, 0), 10);
    test_assertint(corto_int32List__get(obj->a, 1), 20);
    test_assertint(corto_int32List__get(obj->a, 2), 30);
    test_assertint(corto_int32List__get(obj->b, 0), 40);
    test_assertint(corto_int32List__get(obj->b, 1), 50);
    test_assertint(corto_int32List__get(obj->b, 2), 60);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_empty_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_list obj = {[], []}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->a != NULL);
    test_assert(obj->b != NULL);
    test_assertint(ut_ll_count(obj->a), 0);
    test_assertint(ut_ll_count(obj->b), 0);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_init_bitmask(
    test_nested_collection_primitive this)
{
    const char *input =
        "test/s_list_bitmask obj = {"
            "[HasSalt|HasPepper, HasSalt|HasSugar, HasSalt|HasVinegar], "
            "[HasPepper|HasSugar, HasPepper|HasVinegar, HasSugar|HasVinegar]"
        "}"
        ;

    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_bitmask_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(ut_ll_count(obj->a), 3);
    test_assertint(ut_ll_count(obj->b), 3);
    test_assertint(test_RecipeList__get(obj->a, 0), Test_HasSalt | Test_HasPepper);
    test_assertint(test_RecipeList__get(obj->a, 1), Test_HasSalt | Test_HasSugar);
    test_assertint(test_RecipeList__get(obj->a, 2), Test_HasSalt | Test_HasVinegar);
    test_assertint(test_RecipeList__get(obj->b, 0), Test_HasPepper | Test_HasSugar);
    test_assertint(test_RecipeList__get(obj->b, 1), Test_HasPepper | Test_HasVinegar);
    test_assertint(test_RecipeList__get(obj->b, 2), Test_HasSugar | Test_HasVinegar);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_init_enum(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_list_enum obj = {[Red, Black, White], [Blue, Red, Black]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(ut_ll_count(obj->a), 3);
    test_assertint(ut_ll_count(obj->b), 3);
    test_assertint(test_ColorList__get(obj->a, 0), Test_Red);
    test_assertint(test_ColorList__get(obj->a, 1), Test_Black);
    test_assertint(test_ColorList__get(obj->a, 2), Test_White);
    test_assertint(test_ColorList__get(obj->b, 0), Test_Blue);
    test_assertint(test_ColorList__get(obj->b, 1), Test_Red);
    test_assertint(test_ColorList__get(obj->b, 2), Test_Black);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_list_null_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_list obj = {null, null}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_list *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_list_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assert(obj->a == NULL);
    test_assert(obj->b == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_sequence_1_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_sequence obj = {[10], [40]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_sequence *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sequence_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.length, 1);
    test_assertint(obj->b.length, 1);
    test_assertint(obj->a.buffer[0], 10);
    test_assertint(obj->b.buffer[0], 40);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_sequence_3_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_sequence obj = {[10, 20, 30], [40, 50, 60]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_sequence *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sequence_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.length, 3);
    test_assertint(obj->b.length, 3);
    test_assertint(obj->a.buffer[0], 10);
    test_assertint(obj->a.buffer[1], 20);
    test_assertint(obj->a.buffer[2], 30);
    test_assertint(obj->b.buffer[0], 40);
    test_assertint(obj->b.buffer[1], 50);
    test_assertint(obj->b.buffer[2], 60);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_sequence_empty_init(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_sequence obj = {[], []}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_sequence *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sequence_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.length, 0);
    test_assertint(obj->b.length, 0);
    test_assert(obj->a.buffer == NULL);
    test_assert(obj->b.buffer == NULL);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_sequence_init_bitmask(
    test_nested_collection_primitive this)
{
    const char *input =
        "test/s_sequence_bitmask obj = {"
            "[HasSalt|HasPepper, HasSalt|HasSugar, HasSalt|HasVinegar], "
            "[HasPepper|HasSugar, HasPepper|HasVinegar, HasSugar|HasVinegar]"
        "}"
        ;

    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_sequence_bitmask *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sequence_bitmask_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.length, 3);
    test_assertint(obj->b.length, 3);
    test_assertint(obj->a.buffer[0], Test_HasSalt | Test_HasPepper);
    test_assertint(obj->a.buffer[1], Test_HasSalt | Test_HasSugar);
    test_assertint(obj->a.buffer[2], Test_HasSalt | Test_HasVinegar);
    test_assertint(obj->b.buffer[0], Test_HasPepper | Test_HasSugar);
    test_assertint(obj->b.buffer[1], Test_HasPepper | Test_HasVinegar);
    test_assertint(obj->b.buffer[2], Test_HasSugar | Test_HasVinegar);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}


void test_nested_collection_primitive_tc_sequence_init_enum(
    test_nested_collection_primitive this)
{
    const char *input = "test/s_sequence_enum obj = {[Red, Black, White], [Blue, Red, Black]}";
    ast_Node ast = cortoscript_ast_parse(input, false);
    test_assert(ast != NULL);
    test_assert(corto_typeof(ast) == (corto_type)ast_Scope_o);
    test_assertint(ut_ll_count(ast_Scope(ast)->statements), 1);

    int16_t ret = cortoscript_ast_declare(data_o, NULL, ast);
    test_assert(ret == 0);

    test_s_sequence_enum *obj = corto_lookup(data_o, "obj");
    test_assert(obj != NULL);
    test_assert(corto_typeof(obj) == (corto_type)test_s_sequence_enum_o);
    test_assert(corto_check_state(obj, CORTO_VALID));
    test_assert(corto_countof(obj) == 2);
    test_assertint(obj->a.length, 3);
    test_assertint(obj->b.length, 3);
    test_assertint(obj->a.buffer[0], Test_Red);
    test_assertint(obj->a.buffer[1], Test_Black);
    test_assertint(obj->a.buffer[2], Test_White);
    test_assertint(obj->b.buffer[0], Test_Blue);
    test_assertint(obj->b.buffer[1], Test_Red);
    test_assertint(obj->b.buffer[2], Test_Black);

    test_assert(corto_delete(ast) == 0);
    test_assert(corto_release(obj) == 1);
    test_assert(corto_delete(obj) == 0);
}
