/**
*******************************************************************************
* @file           : delay.c
* @brief          : 
* @author         : 
* @date           : 18/01/2023
*******************************************************************************
* @attention
*
* Copyright (c) 18/01/2023 Abelardo Cuffia S.A. All rights reserved.
*
*/
/******************************************************************************
    Includes
******************************************************************************/
#include <stddef.h>

#include "delay.h"
#include "hal.h"

/******************************************************************************
    Defines and constants
******************************************************************************/
static const char * MODULE_NAME = "DELAY";
static const char * DRIVER_VERSION = "v1.0.0";

/******************************************************************************
    Data types
******************************************************************************/

/******************************************************************************
    Local variables
******************************************************************************/

/******************************************************************************
    Local function prototypes
******************************************************************************/

/******************************************************************************
    Local function definitions
******************************************************************************/

/******************************************************************************
    Public function definitions
******************************************************************************/

delay_ret_t delay_init(delay_t *delay, uint32_t duration)
{
    delay_ret_t ret_val = DELAY_ERROR;

    if (delay != NULL)
    {
        delay->start = hal_get_ticks();
        delay->duration = duration;

        ret_val = DELAY_OK;
    }

    return ret_val;
}

delay_ret_t delay_get_status(delay_t *delay)
{
    delay_ret_t ret_val = DELAY_ERROR;
    uint32_t delta = 0;

    if (delay != NULL)
    {
        delta = hal_get_ticks() - delay->start;

        if (delta > delay->duration)
        {
            ret_val = DELAY_EXPIRED;
        }
        else
        {
            ret_val = DELAY_RUNNING;
        }
    }

    return ret_val;
}

delay_ret_t delay_reset(delay_t *delay)
{
    delay_ret_t ret_val = DELAY_ERROR;

    if (delay != NULL)
    {
        delay->start = hal_get_ticks();

        ret_val = DELAY_OK;
    }

    return ret_val;
}
