#include "unity.h"

#include "mock_delay.h"
#include "dictionary.h"
#include "can_tables.h"
#include "can_tables_base.h"

void setUp(void)
{

}


void tearDown(void)
{

}


/**
 * Method under test: dictionary_init
 *
 * Scenario: Init dictionary
 *
 * Expected behavior: Return DICTIONARY_OK
 */
void test__dictionary_init__init(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;

    delay_init_IgnoreAndReturn(0);

    ret = dictionary_init();

    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/*****************
 * INT FUNCTIONS
******************/

/**
 * Method under test: dictionary_write_int
 *
 * Scenario: Write an int value to a valid signal index
 *
 * Expected behavior: Return DICTIONARY_OK and status equal to zero
 */
void test__dictionary_init__write_int_value_valid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 0;       //Make sure it is a valid index
    const int32_t value = 120;      //Random value
    uint16_t status = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    ret = dictionary_write_int(index, value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_write_int
 *
 * Scenario: Write an int value to a invalid signal index
 *
 * Expected behavior: Return DICTIONARY_ERROR
 */
void test__dictionary_init__write_int_value_invalid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_OK;
    const uint16_t index = MAX_CAN_SIGNALS;     //Make sure it is an invalid index
    const int32_t value = 120;                  //Random value
    uint16_t status = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    ret = dictionary_write_int(index, value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_ERROR, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an int value from an invalid signal index
 *
 * Expected behavior: Return DICTIONARY_ERROR
 */
void test__dictionary_init__read_int_value_invalid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_OK;
    const uint16_t index = MAX_CAN_SIGNALS;          //Make sure it is an invalid index
    uint16_t status = 0;
    int32_t value = 0;

    ret = dictionary_read_int(index, &value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_ERROR, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an int value from a valid signal index, no expired, duration = X and source = false, e.g. signal 165
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_int_value_valid_index_no_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 165;         //Make sure it is a valid index
    const int32_t value_w = 120;        //Random value
    uint16_t status_w = 0;
    int32_t value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_int(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_RUNNING);  //Simulates that the expiration time has not expired.

    ret = dictionary_read_int(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_INT32(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an int value from a valid signal index, expired, duration = X and source = false, e.g. signal 165
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to default signal value
 */
void test__dictionary_init__read_int_value_valid_index_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 165;         //Make sure it is a valid index
    const int32_t value_w = 120;        //Random value
    uint16_t status_w = 0;
    int32_t value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_int(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);     //Simulate that the expiration time has expired

    ret = dictionary_read_int(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_INT32(can_signal_st[165].default_value, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an int value from a valid signal index, without expiration time,
 * duration = 0 and source = false, e.g. signal 1
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_int_value_valid_index_no_expiration(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 1;           //Make sure it is a valid index
    const int32_t value_w = 120;        //Random value
    uint16_t status_w = 0;
    int32_t value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_int(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);  //Simulates that the expiration time has expired.
                                                             //It does not matter since the signal has no expiration time.

    ret = dictionary_read_int(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_INT32(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an int value from a valid signal index, duration = X and source = true, e.g. signal 140
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_int_value_valid_index_source(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 140;           //Make sure it is a valid index
    const int32_t value_w = 120;        //Random value
    uint16_t status_w = 0;
    int32_t value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_int(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);  //Simulates that the expiration time has expired.
                                                             //It does not matter since the signal is generated locally.

    ret = dictionary_read_int(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_INT32(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_int
 *
 * Scenario: Read an negative int value from a valid signal index, no expired,
 * duration = X and source = false, e.g. signal 165
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_neg_int_value_valid_index_no_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 165;         //Make sure it is a valid index
    const int32_t value_w = -120;       //Random value
    uint16_t status_w = 0;
    int32_t value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_int(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_RUNNING);  //Simulates that the expiration time has not expired.

    ret = dictionary_read_int(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_INT32(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/*****************
 * FLOAT FUNCTIONS
******************/

/**
 * Method under test: dictionary_write_float
 *
 * Scenario: Write an float value to a valid signal index
 *
 * Expected behavior: Return DICTIONARY_OK and status equal to zero
 */
void test__dictionary_init__write_float_value_valid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 18;      //Make sure it is a valid index
    const float value = 14.48;      //Random value
    uint16_t status = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    ret = dictionary_write_float(index, value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_write_float
 *
 * Scenario: Write a float value to a invalid signal index
 *
 * Expected behavior: Return DICTIONARY_ERROR
 */
void test__dictionary_init__write_float_value_invalid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_OK;
    const uint16_t index = MAX_CAN_SIGNALS;     //Make sure it is an invalid index
    const float value = 14.48;                  //Random value
    uint16_t status = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    ret = dictionary_write_float(index, value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_ERROR, ret);
}


/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a float value from an invalid signal index
 *
 * Expected behavior: Return DICTIONARY_ERROR
 */
void test__dictionary_init__read_float_value_invalid_index(void)
{
    dictionary_ret_t ret = DICTIONARY_OK;
    const uint16_t index = MAX_CAN_SIGNALS;          //Make sure it is an invalid index
    uint16_t status = 0;
    float value = 0;

    ret = dictionary_read_float(index, &value, &status);

    TEST_ASSERT_EQUAL_UINT16(0, status);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_ERROR, ret);
}


/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a float value from a valid signal index, no expired, duration = X and source = false, e.g. signal 165
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_float_value_valid_index_no_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 30;          //Make sure it is a valid index
    const float value_w = 14.48;        //Random value
    uint16_t status_w = 0;
    float value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_float(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_RUNNING);  //Simulates that the expiration time has not expired.

    ret = dictionary_read_float(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_FLOAT(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a float value from a valid signal index, expired, duration = X and source = false, e.g. signal 30
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to default signal value
 */
void test__dictionary_init__read_float_value_valid_index_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 30;          //Make sure it is a valid index
    const float value_w = 14.48;        //Random value
    uint16_t status_w = 0;
    float value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_float(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);     //Simulate that the expiration time has expired

    ret = dictionary_read_float(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_FLOAT(can_signal_st[30].default_value / (float)can_signal_st[30].precision, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}



/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a float value from a valid signal index, without expiration time,
 * duration = 0 and source = false, e.g. signal 50
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_float_value_valid_index_no_expiration(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 50;          //Make sure it is a valid index
    const float value_w = 89.6;         //Random value
    uint16_t status_w = 0;
    float value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_float(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);  //Simulates that the expiration time has expired.
                                                             //It does not matter since the signal has no expiration time.

    ret = dictionary_read_float(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_FLOAT(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a float value from a valid signal index, duration = X and source = true, e.g. signal 141
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_float_value_valid_index_source(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 141;         //Make sure it is a valid index
    const float value_w = 48.1;         //Random value
    uint16_t status_w = 0;
    float value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_float(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_EXPIRED);  //Simulates that the expiration time has expired.
                                                             //It does not matter since the signal is generated locally.

    ret = dictionary_read_float(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_FLOAT(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}


/**
 * Method under test: dictionary_read_float
 *
 * Scenario: Read a negative float value from a valid signal index, no expired,
 * duration = X and source = false, e.g. signal 165
 *
 * Expected behavior: Return DICTIONARY_OK, status equal to zero and value equal to written value
 */
void test__dictionary_init__read_neg_float_value_valid_index_no_expired(void)
{
    dictionary_ret_t ret = DICTIONARY_ERROR;
    const uint16_t index = 30;          //Make sure it is a valid index
    const float value_w = -14.48;       //Random value
    uint16_t status_w = 0;
    float value_r = 0;
    uint16_t status_r = 0;

    delay_init_IgnoreAndReturn(0);

    dictionary_init();

    delay_reset_IgnoreAndReturn(0);

    dictionary_write_float(index, value_w, &status_w);

    delay_get_status_ExpectAnyArgsAndReturn(DELAY_RUNNING);  //Simulates that the expiration time has not expired.

    ret = dictionary_read_float(index, &value_r, &status_r);

    TEST_ASSERT_EQUAL_UINT16(0, status_r);
    TEST_ASSERT_EQUAL_FLOAT(value_w, value_r);
    TEST_ASSERT_EQUAL_UINT8(DICTIONARY_OK, ret);
}
