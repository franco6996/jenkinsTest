#include "unity.h"

#include "mock_hal.h"
#include "delay.h"


void setUp(void)
{

}


void tearDown(void)
{

}


/**
 * Method under test: delay_init
 *
 * Scenario: Init null instance
 *
 * Expected behavior: Return DELAY_ERROR
 */
void test__delay_init__null_instance(void)
{
    const uint32_t duration = 10;
    delay_ret_t ret = DELAY_OK;

    ret = delay_init(NULL, duration);

    TEST_ASSERT_EQUAL_UINT8(DELAY_ERROR, ret);
}


/**
 * Method under test: delay_init
 *
 * Scenario: Init an instance with a random duration
 *
 * Expected behavior: Return DELAY_OK and the instance is loaded with duration
 */
void test__delay_init__random_duration(void)
{
    const uint32_t duration = 10;
    const uint32_t start = 100;
    delay_ret_t ret = DELAY_ERROR;
    delay_t delay = {0};

    hal_get_ticks_ExpectAndReturn(start);

    ret = delay_init(&delay, duration);

    TEST_ASSERT_EQUAL_UINT8(DELAY_OK, ret);
    TEST_ASSERT_EQUAL_UINT32(duration, delay.duration);
    TEST_ASSERT_EQUAL_UINT32(start, delay.start);
}


/**
 * Method under test: delay_get_status
 *
 * Scenario: Get status of null instance
 *
 * Expected behavior: Return DELAY_ERROR
 */
void test__delay_get_status__null_instance(void)
{
    delay_ret_t ret = DELAY_OK;

    ret = delay_get_status(NULL);

    TEST_ASSERT_EQUAL_UINT8(DELAY_ERROR, ret);
}


/**
 * Method under test: delay_get_status
 *
 * Scenario: Get status of running delay instance
 *
 * Expected behavior: Return DELAY_RUNNING
 */
void test__delay_get_status__delay_running(void)
{
    const uint32_t duration = 10;
    const uint32_t start = 100;
    const uint32_t end = 106;
    delay_ret_t ret = DELAY_ERROR;
    delay_t delay = {0};

    hal_get_ticks_ExpectAndReturn(start);

    delay_init(&delay, duration);

    hal_get_ticks_ExpectAndReturn(end);

    ret = delay_get_status(&delay);

    TEST_ASSERT_EQUAL_UINT8(DELAY_RUNNING, ret);
}


/**
 * Method under test: delay_get_status
 *
 * Scenario: Get status of running delay instance
 *
 * Expected behavior: Return DELAY_EXPIRED
 */
void test__delay_get_status__delay_expired(void)
{
    const uint32_t duration = 10;
    const uint32_t start = 100;
    const uint32_t end = 112;
    delay_ret_t ret = DELAY_ERROR;
    delay_t delay = {0};

    hal_get_ticks_ExpectAndReturn(start);

    delay_init(&delay, duration);

    hal_get_ticks_ExpectAndReturn(end);

    ret = delay_get_status(&delay);

    TEST_ASSERT_EQUAL_UINT8(DELAY_EXPIRED, ret);
}


/**
 * Method under test: delay_reset
 *
 * Scenario: Reset null instance
 *
 * Expected behavior: Return DELAY_ERROR
 */
void test__delay_reset__null_instance(void)
{
    delay_ret_t ret = DELAY_OK;

    ret = delay_reset(NULL);

    TEST_ASSERT_EQUAL_UINT8(DELAY_ERROR, ret);
}


/**
 * Method under test: delay_reset
 *
 * Scenario: Reset delay instance
 *
 * Expected behavior: Return DELAY_OK and the instance is loaded with start
 */
void test__delay_reset__reset(void)
{
    const uint32_t duration = 10;
    const uint32_t start = 100;
    const uint32_t restart = 200;
    delay_ret_t ret = DELAY_ERROR;
    delay_t delay = {0};

    hal_get_ticks_ExpectAndReturn(start);

    delay_init(&delay, duration);

    hal_get_ticks_ExpectAndReturn(restart);

    ret = delay_reset(&delay);

    TEST_ASSERT_EQUAL_UINT8(DELAY_OK, ret);
    TEST_ASSERT_EQUAL_UINT32(restart, delay.start);
}
