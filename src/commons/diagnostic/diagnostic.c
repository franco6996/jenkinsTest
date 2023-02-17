/**
*******************************************************************************
* @file           : diagnostic.c
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
#include "diagnostic.h"
#include "can_tables.h"

/******************************************************************************
    Defines and constants
******************************************************************************/
static const char * MODULE_NAME = "DIAGNOSTIC";
static const char * DRIVER_VERSION = "v1.0.0";

#define DIAG_EMPTY_SLOT     MAX_CAN_SIGNALS             //Use MAX_CAN_SIGNALS to indicate an empty slot.

/******************************************************************************
    Data types
******************************************************************************/

/******************************************************************************
    Local variables
******************************************************************************/
static uint16_t diag_signals[MAX_DIAG_SIGS] = {0};      //diag_signals stores the IDs of the signals to be diagnosed
static uint16_t diag_signals_count = 0;

/******************************************************************************
    Local function prototypes
******************************************************************************/

/******************************************************************************
    Local function definitions
******************************************************************************/

/******************************************************************************
    Public function definitions
******************************************************************************/

diag_ret_t diag_init(void)
{
    diag_clear();

    return DIAG_OK;
}

diag_ret_t diag_add(uint16_t signal_id)
{
    diag_ret_t ret_val = DIAG_ERROR;
    bool signal_already_added = false;
    uint16_t i = 0;

    //Check if the signal is already in the diagnostic list.
    for (i = 0; i < MAX_DIAG_SIGS; i++)
    {
        if (diag_signals[i] == signal_id)
        {
            signal_already_added = true;
            ret_val = DIAG_OK;
            break;
        }
    }

    if (false == signal_already_added)
    {
        //Look for an empty slot to add the signal.
        for (i = 0; i < MAX_DIAG_SIGS; i++)
        {
            if (DIAG_EMPTY_SLOT == diag_signals[i])
            {
                diag_signals[i] = signal_id;
                diag_signals_count++;
                ret_val = DIAG_OK;
                break;
            }
        }

        if (MAX_DIAG_SIGS == i)
        {
            ret_val = DIAG_FULL;
        }
    }

    return ret_val;
}

diag_ret_t diag_remove(uint16_t signal_id)
{
    diag_ret_t ret_val = DIAG_ERROR;

    for (uint16_t i = 0; i < MAX_DIAG_SIGS; i++)
    {
        if (diag_signals[i] == signal_id)
        {
            diag_signals[i] = DIAG_EMPTY_SLOT;

            if (diag_signals_count > 0)
            {
                diag_signals_count--;
            }

            ret_val = DIAG_OK;
            break;
        }
    }

    return ret_val;
}

uint16_t diag_get_count(void)
{
    return diag_signals_count;
}

diag_ret_t diag_clear(void)
{
    for (uint16_t i = 0; i < MAX_DIAG_SIGS; i++)
    {
        diag_signals[i] = DIAG_EMPTY_SLOT;
    }

    return DIAG_OK;
}

diag_ret_t diag_get_next_signal(uint16_t *signal_id)
{
    diag_ret_t ret_val = DIAG_EMPTY;

    static uint16_t i = 0;

    if (diag_signals_count > 0)
    {
        //Look for the following signal to send
        while (DIAG_EMPTY_SLOT == diag_signals[i])      //WARNING: Possible infinite loop
        {
            i++;
            if (MAX_DIAG_SIGS == i)
            {
                i = 0;
            }
        }

        *signal_id = diag_signals[i];

        i++;
        if (MAX_DIAG_SIGS == i)
        {
            i = 0;
        }

        ret_val = DIAG_OK;
    }

    return ret_val;
}

