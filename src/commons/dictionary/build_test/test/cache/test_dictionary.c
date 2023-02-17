#include "test/support/communication/can_tables_base.h"
#include "test/support/generated_tables/can_tables.h"
#include "dictionary.h"
#include "build_test/test/mocks/mock_delay.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{



}





void tearDown(void)

{



}

void test__dictionary_init__init(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;



    delay_init_CMockIgnoreAndReturn(31, 0);



    ret = dictionary_init();



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__write_int_value_valid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 0;

    const int32_t value = 120;

    uint16_t status = 0;



    delay_init_CMockIgnoreAndReturn(57, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(61, 0);



    ret = dictionary_write_int(index, value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__write_int_value_invalid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_OK;

    const uint16_t index = 247;

    const int32_t value = 120;

    uint16_t status = 0;



    delay_init_CMockIgnoreAndReturn(84, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(88, 0);



    ret = dictionary_write_int(index, value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_int_value_invalid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_OK;

    const uint16_t index = 247;

    uint16_t status = 0;

    int32_t value = 0;



    ret = dictionary_read_int(index, &value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_int_value_valid_index_no_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 165;

    const int32_t value_w = 120;

    uint16_t status_w = 0;

    int32_t value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(134, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(138, 0);



    dictionary_write_int(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(142, DELAY_RUNNING);



    ret = dictionary_read_int(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((value_w)), (UNITY_INT)(UNITY_INT32)((value_r)), (

   ((void *)0)

   ), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_int_value_valid_index_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 165;

    const int32_t value_w = 120;

    uint16_t status_w = 0;

    int32_t value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(168, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(172, 0);



    dictionary_write_int(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(176, DELAY_EXPIRED);



    ret = dictionary_read_int(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((can_signal_st[165].default_value)), (UNITY_INT)(UNITY_INT32)((value_r)), (

   ((void *)0)

   ), (UNITY_UINT)(181), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(182), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_int_value_valid_index_no_expiration(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 1;

    const int32_t value_w = 120;

    uint16_t status_w = 0;

    int32_t value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(203, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(207, 0);



    dictionary_write_int(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(211, DELAY_EXPIRED);





    ret = dictionary_read_int(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(216), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((value_w)), (UNITY_INT)(UNITY_INT32)((value_r)), (

   ((void *)0)

   ), (UNITY_UINT)(217), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(218), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_int_value_valid_index_source(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 140;

    const int32_t value_w = 120;

    uint16_t status_w = 0;

    int32_t value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(238, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(242, 0);



    dictionary_write_int(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(246, DELAY_EXPIRED);





    ret = dictionary_read_int(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(251), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((value_w)), (UNITY_INT)(UNITY_INT32)((value_r)), (

   ((void *)0)

   ), (UNITY_UINT)(252), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(253), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_neg_int_value_valid_index_no_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 165;

    const int32_t value_w = -120;

    uint16_t status_w = 0;

    int32_t value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(274, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(278, 0);



    dictionary_write_int(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(282, DELAY_RUNNING);



    ret = dictionary_read_int(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(286), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((value_w)), (UNITY_INT)(UNITY_INT32)((value_r)), (

   ((void *)0)

   ), (UNITY_UINT)(287), UNITY_DISPLAY_STYLE_INT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(288), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__write_float_value_valid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 18;

    const float value = 14.48;

    uint16_t status = 0;



    delay_init_CMockIgnoreAndReturn(310, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(314, 0);



    ret = dictionary_write_float(index, value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(318), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(319), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__write_float_value_invalid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_OK;

    const uint16_t index = 247;

    const float value = 14.48;

    uint16_t status = 0;



    delay_init_CMockIgnoreAndReturn(337, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(341, 0);



    ret = dictionary_write_float(index, value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(345), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(346), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_float_value_invalid_index(void)

{

    dictionary_ret_t ret = DICTIONARY_OK;

    const uint16_t index = 247;

    uint16_t status = 0;

    float value = 0;



    ret = dictionary_read_float(index, &value, &status);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status)), (

   ((void *)0)

   ), (UNITY_UINT)(366), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(367), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_float_value_valid_index_no_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 30;

    const float value_w = 14.48;

    uint16_t status_w = 0;

    float value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(387, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(391, 0);



    dictionary_write_float(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(395, DELAY_RUNNING);



    ret = dictionary_read_float(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(399), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((value_w)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((value_w))), (UNITY_FLOAT)((UNITY_FLOAT)((value_r))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(400)));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(401), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_float_value_valid_index_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 30;

    const float value_w = 14.48;

    uint16_t status_w = 0;

    float value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(421, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(425, 0);



    dictionary_write_float(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(429, DELAY_EXPIRED);



    ret = dictionary_read_float(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(433), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((can_signal_st[30].default_value / (float)can_signal_st[30].precision)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((can_signal_st[30].default_value / (float)can_signal_st[30].precision))), (UNITY_FLOAT)((UNITY_FLOAT)((value_r))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(434)));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(435), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_float_value_valid_index_no_expiration(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 50;

    const float value_w = 89.6;

    uint16_t status_w = 0;

    float value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(457, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(461, 0);



    dictionary_write_float(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(465, DELAY_EXPIRED);





    ret = dictionary_read_float(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(470), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((value_w)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((value_w))), (UNITY_FLOAT)((UNITY_FLOAT)((value_r))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(471)));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(472), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_float_value_valid_index_source(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 141;

    const float value_w = 48.1;

    uint16_t status_w = 0;

    float value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(492, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(496, 0);



    dictionary_write_float(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(500, DELAY_EXPIRED);





    ret = dictionary_read_float(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(505), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((value_w)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((value_w))), (UNITY_FLOAT)((UNITY_FLOAT)((value_r))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(506)));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(507), UNITY_DISPLAY_STYLE_UINT8);

}

void test__dictionary_init__read_neg_float_value_valid_index_no_expired(void)

{

    dictionary_ret_t ret = DICTIONARY_ERROR;

    const uint16_t index = 30;

    const float value_w = -14.48;

    uint16_t status_w = 0;

    float value_r = 0;

    uint16_t status_r = 0;



    delay_init_CMockIgnoreAndReturn(528, 0);



    dictionary_init();



    delay_reset_CMockIgnoreAndReturn(532, 0);



    dictionary_write_float(index, value_w, &status_w);



    delay_get_status_CMockExpectAnyArgsAndReturn(536, DELAY_RUNNING);



    ret = dictionary_read_float(index, &value_r, &status_r);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT16)((0)), (UNITY_INT)(UNITY_UINT16)((status_r)), (

   ((void *)0)

   ), (UNITY_UINT)(540), UNITY_DISPLAY_STYLE_UINT16);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((value_w)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((value_w))), (UNITY_FLOAT)((UNITY_FLOAT)((value_r))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(541)));

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DICTIONARY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(542), UNITY_DISPLAY_STYLE_UINT8);

}
