#include "can_tables.h"

uint16_t map_pgn_id_to_index(uint32_t pgn_id)
{
    uint16_t i = 0;

	for (i = 0; i < MAX_CAN_MESSAGES; i++)
	{
		if (can_message_st[i].PGN_ID == pgn_id)
        {
		    break;
        }
	}

	return i;
}


uint32_t map_index_to_pgn_id(uint16_t index)
{
    return can_message_st[index].PGN_ID;
}


uint16_t map_signal_id_to_index(uint16_t signal_id)
{
    uint16_t i = 0;

    for (i = 0; i < MAX_CAN_MESSAGES; i++)
    {
        if (can_signal_st[i].SIG_ID == signal_id)
        {
            break;
        }
    }

    return i;
}


uint16_t map_index_to_signal_id(uint16_t index)
{
    return can_signal_st[index].SIG_ID;
}


bool is_valid_signal_index(uint16_t index)
{
    bool ret_val = false;

    if (index < MAX_CAN_SIGNALS)
    {
        ret_val = true;
    }

    return ret_val;
}
