#ifndef __CANTABLESBASE
#define __CANTABLESBASE

#include <stdint.h>
#include <stdbool.h>

//structure for can messages
typedef struct// CanMessageST         
{
    uint32_t	PGN_ID;		//Message PGN
    uint8_t	    bDLC;		//Message DLC
    uint8_t	    bConf;		//Bit 0,1,2 are priority from 1 to 7, Bit 7 not set means singleframe, set is more than one
    int16_t	    bRep;		//repetition time in ms
    int16_t	    bMult;		//multiplexor number
    uint16_t	firstSignalIndex;
    bool	    source;
    bool	    sink;
} can_message_st_t; // stCanMessage;

//structure for can message signal
typedef struct// CanMessageSignalST
{
    uint32_t	PGNIndex;	//Message PGN
    uint16_t	SIGIndex;	//signal ID
    uint32_t	bStartBit;	//Starting position
    uint8_t	    bMultVal;	//Multiplexor val
} can_message_signal_st_t; // stCanMessageSignal;

//structure for signals
typedef struct// CanSignalST
{
    uint16_t	SIG_ID;		//signal ID
    int16_t	    bLength;	//signal length
    int32_t	    bFactor;	//signal value divider
    int32_t	    bOffset;	//signal offset
    bool	    bLimit;		//Has a limit
    uint32_t	UI64Min;	//lower limit
    uint32_t	UI64Max;	//upper limit
    int32_t	    default_value;	//default value
    uint32_t	precision;	//
    uint32_t	duration;
    bool	    source;		//indica si la se�al se genera en la ecu o no
    uint64_t	sourceNAME;     //indica el NAME de la ecu que genera la se�al
    bool 	    persistible;	// Indica si esta variable se inicializa desde Flash o no
    bool        a2Compliment;   // Indica si la se�al est� en complemento a2
} can_signal_st_t; // stCanSignal;

uint16_t map_pgn_id_to_index(uint32_t pgn_id);
uint32_t map_index_to_pgn_id(uint16_t index);

uint16_t map_signal_id_to_index(uint16_t signal_id);
uint16_t map_index_to_signal_id(uint16_t index);


/**
 * @brief Function to check if signal index is valid.
 *
 * @param uint16_t index: signal index.
 *
 * @return true if index is valid, otherwise false.
 */
bool is_valid_signal_index(uint16_t index);

#endif
