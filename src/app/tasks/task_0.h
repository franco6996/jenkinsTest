/**
*******************************************************************************
* @file           : task_0.h
* @brief          :
* @author         :
* @date           : 18/01/2023
*******************************************************************************
* @attention
*
* Copyright (c) 18/01/2023 Abelardo Cuffia S.A. All rights reserved.
*
*/
#ifndef __TASK_0_H__
#define __TASK_0_H__
/******************************************************************************
        Includes
 ******************************************************************************/

/******************************************************************************
        Constants
 ******************************************************************************/

/******************************************************************************
        Data types
 ******************************************************************************/

/******************************************************************************
        Public function prototypes
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @brief Function to perform task initialization.
 *
 * @return None
 */
void task_0_init(void);

/**
 * @brief Function that represents the task or process. It should be added to the scheduler.
 *
 * @param void *params: Pointer for generic purposes.
 *
 * @return void *: Pointer for generic purposes.
 */
void * task_0_run(void *params);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // EOF __TASK_0_H__
