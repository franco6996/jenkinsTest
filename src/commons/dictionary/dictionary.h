/**
*******************************************************************************
* @file           : dictionary.h
* @brief          :
* @author         :
* @date           : 18/01/2023
*******************************************************************************
* @attention
*
* Copyright (c) 18/01/2023 Abelardo Cuffia S.A. All rights reserved.
*
*/
#ifndef __DICIONARY_H__
#define __DICIONARY_H__
/******************************************************************************
        Includes
 ******************************************************************************/
#include <stdint.h>

/******************************************************************************
        Constants
 ******************************************************************************/

/******************************************************************************
        Data types
 ******************************************************************************/

typedef enum
{
    DICTIONARY_OK = 0,
    DICTIONARY_ERROR
} dictionary_ret_t;

/******************************************************************************
        Public function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Function to init the dictionary.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_init(void);


/**
 * @brief Function to read raw value from dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_read(uint16_t index, int32_t *value, uint16_t *status);


/**
 * @brief Function to read int value from dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_read_int(uint16_t index, int32_t *value, uint16_t *status);


/**
 * @brief Function to read float value from dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_read_float(uint16_t index, float *value, uint16_t *status);


/**
 * @brief Function to write raw value to dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_write(uint16_t index, int32_t value, uint16_t *status);


/**
 * @brief Function to write int value to dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_write_int(uint16_t index, int32_t value, uint16_t *status);


/**
 * @brief Function to write float value to dictionary.
 *
 * @param uint16_t index: signal index.
 * @param int32_t *value: signal value.
 * @param uint16_t *status: signal status.
 *
 * @return See \p dictionary_ret_t return codes.
 */
dictionary_ret_t dictionary_write_float(uint16_t index, float value, uint16_t *status);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // EOF __DICIONARY_H__
