/**
*******************************************************************************
* @file           : diagnostic.h
* @brief          :
* @author         :
* @date           : 18/01/2023
*******************************************************************************
* @attention
*
* Copyright (c) 18/01/2023 Abelardo Cuffia S.A. All rights reserved.
*
*/
#ifndef __DIAGNOSTIC_H__
#define __DIAGNOSTIC_H__
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
    DIAG_OK = 0,
    DIAG_ERROR,
    DIAG_FULL,
    DIAG_EMPTY
} diag_ret_t;

/******************************************************************************
        Public function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Function to init module.
 *
 * @return See \p diag_ret_t return codes.
 */
diag_ret_t diag_init(void);


/**
 * @brief Function to add a signal to the diagnostic list.
 *
 * @param uint32_t signal: signal id.
 *
 * @return See \p diag_ret_t return codes.
 */
diag_ret_t diag_add(uint16_t signal);


/**
 * @brief Function to remove a signal from the diagnostic list.
 *
 * @param uint32_t signal: signal id.
 *
 * @return See \p diag_ret_t return codes.
 */
diag_ret_t diag_remove(uint16_t signal);


/**
 * @brief Function to get the number of signals in the list.
 *
 * @return Number of the signals in the list.
 */
uint16_t diag_get_count(void);


/**
 * @brief Function to remove all signals from the diagnostic list.
 *
 * @return See \p diag_ret_t return codes.
 */
diag_ret_t diag_clear(void);


/**
 * @brief Function to get the next signal to send.
 *
 * @return See \p diag_ret_t return codes.
 */
diag_ret_t diag_get_next_signal(uint16_t *signal_id);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // EOF __DIAGNOSTIC_H__
