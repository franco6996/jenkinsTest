#include "delay.h"
#include "mock_hal.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void setUp(void)

{



}





void tearDown(void)

{



}

void test__delay_init__null_instance(void)

{

    const uint32_t duration = 10;

    delay_ret_t ret = DELAY_OK;



    ret = delay_init(

                    ((void *)0)

                        , duration);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_UINT8);

}

void test__delay_init__randon_duration(void)

{

    const uint32_t duration = 10;

    const uint32_t start = 100;

    delay_ret_t ret = DELAY_ERROR;

    delay_t delay = {0};



    hal_get_ticks_CMockExpectAndReturn(51, start);



    ret = delay_init(&delay, duration);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)((duration)), (UNITY_INT)(UNITY_UINT32)((delay.duration)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_UINT32);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)((start)), (UNITY_INT)(UNITY_UINT32)((delay.start)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_UINT32);

}

void test__delay_get_status__null_instance(void)

{

    delay_ret_t ret = DELAY_OK;



    ret = delay_get_status(

                          ((void *)0)

                              );



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_UINT8);

}

void test__delay_get_status__delay_running(void)

{

    const uint32_t duration = 10;

    const uint32_t start = 100;

    const uint32_t end = 106;

    delay_ret_t ret = DELAY_ERROR;

    delay_t delay = {0};



    hal_get_ticks_CMockExpectAndReturn(93, start);



    delay_init(&delay, duration);



    hal_get_ticks_CMockExpectAndReturn(97, end);



    ret = delay_get_status(&delay);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_RUNNING)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_UINT8);

}

void test__delay_get_status__delay_expired(void)

{

    const uint32_t duration = 10;

    const uint32_t start = 100;

    const uint32_t end = 112;

    delay_ret_t ret = DELAY_ERROR;

    delay_t delay = {0};



    hal_get_ticks_CMockExpectAndReturn(120, start);



    delay_init(&delay, duration);



    hal_get_ticks_CMockExpectAndReturn(124, end);



    ret = delay_get_status(&delay);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_EXPIRED)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_UINT8);

}

void test__delay_reset__null_instance(void)

{

    delay_ret_t ret = DELAY_OK;



    ret = delay_reset(

                     ((void *)0)

                         );



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_ERROR)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_UINT8);

}

void test__delay_reset__reset(void)

{

    const uint32_t duration = 10;

    const uint32_t start = 100;

    const uint32_t restart = 200;

    delay_ret_t ret = DELAY_ERROR;

    delay_t delay = {0};



    hal_get_ticks_CMockExpectAndReturn(164, start);



    delay_init(&delay, duration);



    hal_get_ticks_CMockExpectAndReturn(168, restart);



    ret = delay_reset(&delay);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((DELAY_OK)), (UNITY_INT)(UNITY_UINT8 )((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT32)((restart)), (UNITY_INT)(UNITY_UINT32)((delay.start)), (

   ((void *)0)

   ), (UNITY_UINT)(173), UNITY_DISPLAY_STYLE_UINT32);

}
