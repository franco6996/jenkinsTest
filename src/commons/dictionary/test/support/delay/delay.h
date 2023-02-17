/**
*******************************************************************************
* @file           : delay.h
* @brief          :
* @author         :
* @date           : 18/01/2023
*******************************************************************************
* @attention
*
* Copyright (c) 18/01/2023 Abelardo Cuffia S.A. All rights reserved.
*
*/
#ifndef __DELAY_H__
#define __DELAY_H__
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

typedef struct
{
    uint32_t start;
    uint32_t duration;
} delay_t;


typedef enum
{
    DELAY_OK = 0,
    DELAY_ERROR,
    DELAY_EXPIRED,
    DELAY_RUNNING
} delay_ret_t;

/******************************************************************************
        Public function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief Function to init the delay.
 *
 * @param delay_t *delay: pointer to delay instance.
 * @param uint32_t duration: timeout in ms.
 *
 * @return See \p delay_ret_t return codes.
 */
delay_ret_t delay_init(delay_t *delay, uint32_t duration);


/**
 * @brief Function to get the delay status.
 *
 * @param delay_t *delay: pointer to delay instance.
 *
 * @return See \p delay_ret_t return codes.
 */
delay_ret_t delay_get_status(delay_t *delay);


/**
 * @brief Function to reset the delay.
 *
 * @param delay_t *delay: pointer to delay instance.
 *
 * @return See \p delay_ret_t return codes.
 */
delay_ret_t delay_reset(delay_t *delay);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // EOF __DELAY_H__
