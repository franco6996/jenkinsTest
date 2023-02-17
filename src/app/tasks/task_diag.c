/**
*******************************************************************************
* @file           : task_diag.c
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
#include "task_diag.h"
#include "diagnostic.h"
#include "dictionary.h"
#include "can_tables.h"

/******************************************************************************
    Defines and constants
******************************************************************************/

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

void task_diag_init(void)
{
	diag_init();
}

void * task_diag_run(void *params)
{
	diag_ret_t ret = DIAG_ERROR;
	uint16_t signal_id = 0;

	uint16_t index = 0;
	uint16_t status = 0;
	int32_t value = 0;

	ret = diag_get_next_signal(&signal_id);

    if (DIAG_OK == ret)
    {
        index = map_signal_id_to_index(signal_id);

        if (true == is_valid_signal_index(index))
        {
            if (true == can_signal_st[index].source)    //Only locally generated signals can be sent
            {
                dictionary_write(SIG_DiagOverrideSignalId, can_signal_st[index].SIG_ID, &status);
                dictionary_read(index, &value, &status);
                dictionary_write(SIG_DiagOverrideValue, value, &status);

                //com_send_pgn(PGN_PB_DiagOverride);
            }
        }

    }

	return (void*)0;
}


