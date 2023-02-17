#include "can_tables.h"

// pgn, se?al, start bit, mux (-1==255)
const can_message_signal_st_t can_message_signal_st[MAX_CAN_MESSAGES_SIGNALS] = {
	{PGN_PB_KeepAlive,	SIG_CANRXCounter,	0,	255},	// 0
	{PGN_PB_KeepAlive,	SIG_CANTXCounter,	8,	255},	// 1
	{PGN_AddressClaimed,	SIG_NAME,	0,	255},	// 2
	{PGN_PB_DiagConfig,	SIG_DiagConfigCmd,	0,	255},	// 3
	{PGN_PB_DiagConfig,	SIG_DiagConfigOverride,	2,	255},	// 4
	{PGN_PB_DiagConfig,	SIG_DiagConfigSignalId,	8,	255},	// 5
	{PGN_PB_DiagOverride,	SIG_DiagOverrideSignalId,	0,	255},	// 6
	{PGN_PB_DiagOverride,	SIG_DiagOverrideValue,	32,	255},	// 7
	{PGN_RequestPGN,	SIG_RequestedPGN,	0,	255},	// 8
	{PGN_TP_CM,	SIG_TPCMCtrlByte,	0,	255},	// 9
	{PGN_TP_CM,	SIG_AckMsgSize,	8,	19},	// 10
	{PGN_TP_CM,	SIG_BamMsgSize,	8,	32},	// 11
	{PGN_TP_CM,	SIG_RtsMsgSize,	8,	16},	// 12
	{PGN_TP_CM,	SIG_SendPackets,	8,	17},	// 13
	{PGN_TP_CM,	SIG_AbortReason,	8,	160},	// 14
	{PGN_TP_CM,	SIG_NextPacket,	16,	17},	// 15
	{PGN_TP_CM,	SIG_AckNoPackets,	24,	19},	// 16
	{PGN_TP_CM,	SIG_BamNoPackets,	24,	32},	// 17
	{PGN_TP_CM,	SIG_RtsNoPackets,	24,	16},	// 18
	{PGN_TP_CM,	SIG_TPCMPGN,	40,	255},	// 19
	{PGN_TP_DT,	SIG_SeqNumber,	0,	255},	// 20
	{PGN_TP_DT,	SIG_Byte1,	8,	255},	// 21
	{PGN_TP_DT,	SIG_Byte2,	16,	255},	// 22
	{PGN_TP_DT,	SIG_Byte3,	24,	255},	// 23
	{PGN_TP_DT,	SIG_Byte4,	32,	255},	// 24
	{PGN_TP_DT,	SIG_Byte5,	40,	255},	// 25
	{PGN_TP_DT,	SIG_Byte6,	48,	255},	// 26
	{PGN_TP_DT,	SIG_Byte7,	56,	255},	// 27
	{PGN_ACKN,	SIG_ACKNCtrlByte,	0,	255},	// 28
	{PGN_ACKN,	SIG_ACKReserved,	8,	255},	// 29
	{PGN_ACKN,	SIG_ACKNPGN,	40,	255},	// 30
	{PGN_PB_ECUInfo,	SIG_AlarmWhenGone,	0,	0},	// 31
	{PGN_PB_ECUInfo,	SIG_HWID,	8,	0},	// 32
	{PGN_PB_ECUInfo,	SIG_VersionMajor,	24,	0},	// 33
	{PGN_PB_ECUInfo,	SIG_VersionMinor,	32,	0},	// 34
	{PGN_PB_ECUInfo,	SIG_VersionBuild,	40,	0},	// 35
	{PGN_PB_ECUInfo,	SIG_VersionRevision,	56,	0},	// 36
	{PGN_PB_ECUInfo,	SIG_ECUDescription,	72,	0},	// 37
	{PGN_PB_AlarmInfo,	SIG_AlarmInfoAlarmID,	0,	0},	// 38
	{PGN_PB_AlarmInfo,	SIG_AlarmInfoCauseID,	32,	0},	// 39
	{PGN_PB_AlarmInfo,	SIG_AlarmInfoCommand,	40,	0},	// 40
	{PGN_PB_AlarmInfo,	SIG_AlarmInfoInstanceString,	48,	0},	// 41
	{PGN_SignalValueChangeRequest,	SIG_SignalValueChangeRequestSignalID,	0,	0},	// 42
	{PGN_SignalValueChangeRequest,	SIG_SignalValueChangeRequestNewValue,	32,	0},	// 43
	{PGN_SignalActualValue,	SIG_SignalActualValueSignalID,	0,	0},	// 44
	{PGN_SignalActualValue,	SIG_SignalActualValueValue,	32,	0},	// 45
	{PGN_PB_ProcessCommandRequest,	SIG_PCR_ProcessID,	0,	0},	// 46
	{PGN_PB_ProcessCommandRequest,	SIG_PCR_CommandID,	16,	0},	// 47
	{PGN_PB_ProcessCommandStatus,	SIG_PCS_ProcessID,	0,	0},	// 48
	{PGN_PB_ProcessCommandStatus,	SIG_PCS_CommandID,	16,	0},	// 49
	{PGN_PB_ProcessCommandStatus,	SIG_PCS_Status,	32,	0},	// 50
	{PGN_PA1_BL_UpdateCommand,	SIG_BL_UpdateType,	0,	0},	// 51
	{PGN_PB_BL_UpdateRequest,	SIG_BL_UpdateType,	0,	0},	// 52
	{PGN_PB_BL_UpdateRequest,	SIG_HWID,	8,	0},	// 53
	{PGN_PA1_RequestInstanceID,	SIG_InstanceMethod,	0,	0},	// 54
	{PGN_PB_InstanceID,	SIG_InstanceID,	0,	0},	// 55
	{PGN_PA1_BL_Data,	SIG_BL_Data,	0,	0},	// 56
	{PGN_SignalActualValueRequest,	SIG_SignalActualValueRequestSignalID,	0,	0},	// 57
	{PGN_SignalActualValueExtended,	SIG_SignalActualValueExtendedSignalID,	0,	0},	// 58
	{PGN_SignalActualValueExtended,	SIG_SignalActualValueExtendedValue,	32,	0},	// 59
	{PGN_SignalValueChangeRequestExtended,	SIG_SignalValueChangeRequestExtendedSignalID,	0,	0},	// 60
	{PGN_SignalValueChangeRequestExtended,	SIG_SignalValueChangeRequestExtendedNewValue,	32,	0},	// 61
	{PGN_SignalActualValueArray,	SIG_SignalActualValueArraySignalID,	0,	0},	// 62
	{PGN_SignalActualValueArray,	SIG_SignalActualValueArrayValue,	32,	0},	// 63
	{PGN_SignalValueChangeRequestArray,	SIG_SignalValueChangeRequestArraySignalID,	0,	0},	// 64
	{PGN_SignalValueChangeRequestArray,	SIG_SignalValueChangeRequestArrayValue,	32,	0},	// 65
	{PGN_EngFluidLevPres1,	SIG_EngineOilLevel,	16,	0},	// 66
	{PGN_EngFluidLevPres1,	SIG_EngineOilPressure,	24,	0},	// 67
	{PGN_EngFluidLevPres1,	SIG_EngineCoolantLevel1,	56,	0},	// 68
	{PGN_ElectronicEngineController1,	SIG_ActEnginePercentTorque,	16,	255},	// 69
	{PGN_ElectronicEngineController1,	SIG_EngineSpeed,	24,	255},	// 70
	{PGN_ElectronicEngineController1,	SIG_EngineStarterMode,	48,	255},	// 71
	{PGN_EngineTemperature1,	SIG_EngineCoolantTemp,	0,	255},	// 72
	{PGN_EngineTemperature1,	SIG_FuelTemperature,	8,	255},	// 73
	{PGN_EngineTemperature1,	SIG_EngineOilTemperature,	16,	255},	// 74
	{PGN_VehicleElectricalPower1,	SIG_BatteryPotentialPowerInput1,	32,	255},	// 75
	{PGN_VehicleElectricalPower1,	SIG_KeySwitchBatteryPotential,	48,	255},	// 76
	{PGN_DashDisplay,	SIG_FuelLevel,	8,	255},	// 77
	{PGN_CruiseControlVehicleSpeed,	SIG_ParkingBrakeSwitch,	3,	0},	// 78
	{PGN_CruiseControlVehicleSpeed,	SIG_BrakeSwitch,	28,	0},	// 79
	{PGN_CruiseControlVehicleSpeed,	SIG_EngineDiagnosticTestModeSwitch,	60,	0},	// 80
	{PGN_CruiseControlVehicleSpeed,	SIG_EngineShutdownOverrideSwitch,	62,	0},	// 81
	{PGN_Brakes,	SIG_ParkingBrakeActuator,	24,	0},	// 82
	{PGN_ElectronicTransmissionController5,	SIG_TransmissionReverseDirectionSwitch,	8,	0},	// 83
	{PGN_ElectronicTransmissionController5,	SIG_TransmissionNeutralSwitch,	10,	0},	// 84
	{PGN_AirSupplyPressure,	SIG_PneumaticSupplyPressure,	0,	0},	// 85
	{PGN_Shutdown,	SIG_EngineProtectionSystemHasShutdownEngine,	32,	0},	// 86
	{PGN_Shutdown,	SIG_EngineProtectionSystemApproachingShutdown,	34,	0},	// 87
	{PGN_EngineOperatingInformation,	SIG_EngineOperatingState,	0,	0},	// 88
	{PGN_EngineOperatingInformation,	SIG_EngineEmergencyShutdownIndication,	44,	0},	// 89
	{PGN_AlternatorInformation,	SIG_Alternator1Status,	16,	0},	// 90
	{PGN_EngineHoursRevolutions,	SIG_EngineTotalHoursOfOperation,	0,	255},	// 91
	{PGN_GroundBasedSpeedAndDistance,	SIG_GroundBasedImplementDirection,	0,	0},	// 92
	{PGN_GroundBasedSpeedAndDistance,	SIG_GroundBasedImplementSpeed,	8,	0},	// 93
	{PGN_VehicleFluids,	SIG_HydraulicTemperature,	0,	255},	// 94
	{PGN_VehicleFluids,	SIG_HydraulicOilLevel,	16,	255},	// 95
};

// pgn, dlc, priority, periodicidad (0=no periodico, otro=milisegundos), se?al multiplexora (-1 ninguno), indice primer se?al que pertenece a este mensaje en _CanMessageSignal, source, sink
const can_message_st_t can_message_st[MAX_CAN_MESSAGES]=
{
	{65401,	2,	6,	1000,	 -1,	0,	true,	true},	// 0	PB_KeepAlive
	{60928,	8,	6,	0,	 -1,	2,	true,	true},	// 1	AddressClaimed
	{65403,	5,	6,	0,	 -1,	3,	false,	true},	// 2	PB_DiagConfig
	{65402,	8,	6,	0,	 -1,	6,	true,	true},	// 3	PB_DiagOverride
	{59904,	3,	6,	0,	 -1,	8,	true,	true},	// 4	RequestPGN
	{60416,	8,	6,	0,	SIG_TPCMCtrlByte,	9,	true,	true},	// 5	TP_CM
	{60160,	8,	6,	0,	 -1,	20,	true,	true},	// 6	TP_DT
	{59392,	8,	6,	0,	 -1,	28,	true,	true},	// 7	ACKN
	{65400,	9,	6,	0,	 -1,	31,	true,	true},	// 8	PB_ECUInfo
	{65468,	6,	6,	0,	 -1,	38,	true,	true},	// 9	PB_AlarmInfo
	{65472,	8,	6,	0,	 -1,	42,	true,	true},	// 10	SignalValueChangeRequest
	{65473,	8,	6,	0,	 -1,	44,	true,	true},	// 11	SignalActualValue
	{65476,	4,	6,	0,	 -1,	46,	true,	true},	// 12	PB_ProcessCommandRequest
	{65477,	8,	6,	0,	 -1,	48,	true,	true},	// 13	PB_ProcessCommandStatus
	{126208,	1,	6,	0,	 -1,	51,	false,	true},	// 14	PA1_BL_UpdateCommand
	{65501,	3,	6,	0,	 -1,	52,	true,	false},	// 15	PB_BL_UpdateRequest
	{126720,	1,	6,	0,	 -1,	54,	false,	true},	// 16	PA1_RequestInstanceID
	{65503,	1,	6,	0,	 -1,	55,	true,	false},	// 17	PB_InstanceID
	{126464,	0,	6,	0,	 -1,	56,	false,	true},	// 18	PA1_BL_Data
	{65474,	4,	6,	0,	 -1,	57,	true,	true},	// 19	SignalActualValueRequest
	{65478,	12,	6,	0,	 -1,	58,	true,	true},	// 20	SignalActualValueExtended
	{65479,	12,	6,	0,	 -1,	60,	true,	true},	// 21	SignalValueChangeRequestExtended
	{65475,	4,	6,	0,	 -1,	62,	true,	true},	// 22	SignalActualValueArray
	{65480,	4,	6,	0,	 -1,	64,	true,	true},	// 23	SignalValueChangeRequestArray
	{65263,	8,	6,	500,	 -1,	66,	true,	false},	// 24	EngFluidLevPres1
	{61444,	8,	3,	500,	 -1,	69,	true,	false},	// 25	ElectronicEngineController1
	{65262,	8,	6,	1000,	 -1,	72,	true,	false},	// 26	EngineTemperature1
	{65271,	8,	6,	1000,	 -1,	75,	true,	false},	// 27	VehicleElectricalPower1
	{65276,	8,	6,	1000,	 -1,	77,	true,	false},	// 28	DashDisplay
	{65265,	8,	6,	100,	 -1,	78,	false,	true},	// 29	CruiseControlVehicleSpeed
	{65274,	8,	6,	1000,	 -1,	82,	true,	false},	// 30	Brakes
	{65219,	8,	7,	0,	 -1,	83,	false,	true},	// 31	ElectronicTransmissionController5
	{65198,	8,	6,	1000,	 -1,	85,	true,	false},	// 32	AirSupplyPressure
	{65252,	8,	6,	1000,	 -1,	86,	true,	false},	// 33	Shutdown
	{64914,	8,	3,	250,	 -1,	88,	true,	false},	// 34	EngineOperatingInformation
	{65237,	8,	6,	1000,	 -1,	90,	true,	false},	// 35	AlternatorInformation
	{65253,	8,	6,	0,	 -1,	91,	true,	false},	// 36	EngineHoursRevolutions
	{65097,	8,	3,	100,	 -1,	92,	false,	true},	// 37	GroundBasedSpeedAndDistance
	{65128,	8,	6,	1000,	 -1,	94,	true,	false},	// 38	VehicleFluids
};

// SignalID, bits, factor, offset, limite, min, max, valor por defecto, precision (10^decimales), validez, source (true si esta ecu genera esta se?al), NAME source ECU, persistible (agregar!!!!)
const can_signal_st_t can_signal_st[MAX_CAN_SIGNALS]=
{
	{0, 1,	1,	0,	1,	0,	1,	0,	0,	1000,	true,	2309220708934221902,	false,	false},	// dummy signal
	{846, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309365878828826703,	false,	false},	// 1	OutTransferPumpOwn
	{993, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 2	ActivacionAlaIzqSube45
	{994, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 3	ActivacionAlaIzqBaja45
	{995, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 4	ActivacionAlaDerSube45
	{996, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 5	ActivacionAlaDerBaja45
	{997, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 6	ActivacionBajarBotalon
	{998, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309261390864449619,	false,	false},	// 7	ActivacionSubirBotalon
	{1001, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 8	ActivacionTrabaTransporte
	{1072, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 9	ActivacionDestrabaTransporte
	{1084, 32,	1,	0,	true,	0,	4294967295,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 10	EnginePartialTimeOfOperationOwn
	{1301, 16,	1,	0,	false,	0,	3000,	750,	1,	0,	true,	2309220708934221902,	true,	false},	// 11	EngineNominalSpeed
	{1450, 8,	4,	0,	true,	0,	250,	25,	1,	0,	true,	2309220708934221902,	true,	false},	// 12	EngineOilPressureMinimum
	{1456, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 13	EngineCylinder2HighTemperature
	{1457, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 14	EngineCylinder3HighTemperature
	{1458, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 15	EngineCylinder4HighTemperature
	{1459, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 16	EngineCylinder5HighTemperature
	{1460, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 17	EngineCylinder6HighTemperature
	{1462, 16,	1,	0,	true,	0,	3000,	1150,	100,	0,	true,	2309220708934221902,	true,	false},	// 18	BatteryPotentialMinimum
	{1463, 16,	1,	0,	true,	0,	3600,	1520,	100,	0,	true,	2309220708934221902,	true,	false},	// 19	BatteryPotentialMaximum
	{1464, 8,	1,	0,	true,	0,	50,	10,	1,	0,	true,	2309220708934221902,	true,	false},	// 20	FuelLevelMinimum
	{1465, 16,	1,	0,	true,	1000,	3000,	3000,	1,	0,	true,	2309220708934221902,	false,	false},	// 21	EngineMaximumSpeed
	{1466, 8,	1,	0,	true,	90,	200,	150,	1,	0,	true,	2309220708934221902,	true,	false},	// 22	EngineCylinderTemperatureMaximum
	{1467, 16,	1,	0,	true,	10,	20000,	2000,	10,	0,	true,	2309220708934221902,	true,	false},	// 23	EngineSpeedFactor
	{1468, 1,	1,	0,	true,	0,	1,	1,	1,	0,	true,	2309220708934221902,	true,	false},	// 24	TemperatureEngineShutdown
	{1469, 1,	1,	0,	true,	0,	1,	1,	1,	0,	true,	2309220708934221902,	true,	false},	// 25	OilPressureEngineShutdown
	{1470, 1,	1,	0,	true,	0,	1,	1,	1,	0,	true,	2309220708934221902,	true,	false},	// 26	OilTemperatureEngineShutdown
	{1471, 32,	1,	0,	true,	0,	1000000,	200000,	1,	0,	true,	2309220708934221902,	true,	false},	// 27	AirMinimumPressureOwn
	{1472, 32,	1,	0,	true,	0,	1000000,	900000,	1,	0,	true,	2309220708934221902,	true,	false},	// 28	AirMaximumPressureOwn
	{1473, 32,	1,	0,	true,	0,	1000000,	300000,	1,	0,	true,	2309220708934221902,	true,	false},	// 29	AirMinimumPressureForActuatorsOwn
	{1479, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 30	ActivacionAperturaAlinDerecho
	{1480, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 31	ActivacionAperturaAlinIzquierdo
	{1481, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 32	ActivacionCierreAlinDerecho
	{1482, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 33	ActivacionCierreAlinIzquierdo
	{1483, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 34	ActivacionAperturaAlaDerecha
	{1484, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 35	ActivacionAperturaAlaIzquierda
	{1485, 0,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 36	ActivacionCierreAlaDerecha
	{1486, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 37	ActivacionCierreAlaIzquierda
	{1498, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 38	ActivacionDestrabaBasculanteBotalon
	{1499, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 39	ActivacionTrabaBasculanteBotalon
	{1503, 8,	1,	0,	true,	60,	120,	100,	1,	0,	true,	2309220708934221902,	true,	false},	// 40	HydraulicOilTemperatureMaximum
	{1631, 8,	1,	0,	true,	0,	255,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 41	AutomaticHydraMovsCurrentStateOwn
	{1632, 8,	1,	0,	true,	0,	255,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 42	AutomaticHydraMovsTargetStateOwn
	{1633, 8,	1,	0,	true,	0,	100,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 43	AutomaticHydraMovsOverallProgressOwn
	{1634, 2,	1,	0,	true,	0,	3,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 44	AutomaticHydraMovsCurrentMovDirectionOwn
	{1635, 2,	1,	0,	true,	0,	3,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 45	AutomaticHydraMovsCurrentModeOwn
	{1637, 8,	1,	0,	true,	1,	100,	1,	1,	0,	true,	2309220708934221902,	true,	false},	// 46	AutomaticHydraMovsFuncCurrentStepOwn
	{1638, 8,	1,	0,	true,	0,	100,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 47	AutomaticHydraMovsStepProgressOwn
	{1639, 8,	1,	0,	true,	0,	8,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 48	AutomaticHydraMovsLastFunctionIDOwn
	{1640, 16,	1,	0,	true,	0,	3000,	1500,	1,	0,	true,	2309220708934221902,	true,	false},	// 49	EngineNominalSpeedForHydraMovs
	{1642, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	false,	false},	// 50	HydraulicsForcedMode
	{1654, 1,	1,	0,	true,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 51	AutomaticHydraMovsCancelRequestOwn
	{1662, 1,	1,	0,	true,	0,	1,	1,	1,	0,	true,	2309220708934221902,	false,	false},	// 52	AutomaticHydraMovsPressureOK
	{1763, 16,	1,	0,	true,	0,	13888,	1388,	1000,	0,	true,	2309220708934221902,	true,	false},	// 53	MaxSpeedForParkingBrakeOwn
	{1914, 1,	1,	0,	true,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 54	LowFuelOwn
	{2824, 2,	1,	0,	true,	0,	2,	0,	1,	0,	false,	2309253694283055185,	false,	false},	// 55	HydraulicOilLevelOwn
	{2830, 8,	1,	0,	true,	0,	20,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 56	TimeOfStairMovementOwn
	{2837, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	true,	false},	// 57	BoomStatePositionAOwn
	{2838, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	true,	false},	// 58	BoomStatePositionBOwn
	{2839, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	true,	false},	// 59	BoomStatePositionCOwn
	{2840, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309252594771427408,	true,	false},	// 60	BoomStatePositionDOwn
	{2841, 1,	1,	0,	true,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 61	AutomaticHydraMovsExecutingOwn
	{2945, 8,	1,	0,	false,	0,	10,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 62	AutomaticHydraMovsBoomModelNumberOwn
	{2946, 1,	1,	0,	true,	0,	1,	0,	1,	0,	true,	2309220708934221902,	true,	false},	// 63	JoystickHydraulicMovementEnabledOwn
	{3121, 2,	1,	0,	true,	0,	3,	3,	1,	0,	false,	2309253694283055185,	false,	false},	// 64	EngineStarterSwitchValueOwn
	{3475, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309253694283055185,	false,	false},	// 65	HydraulicMovementsEnableRequest1Own
	{3476, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309253698578022482,	false,	false},	// 66	HydraulicMovementsEnableRequest2Own
	{3638, 16,	1,	0,	false,	0,	0,	256,	1,	0,	true,	2309220708934221902,	true,	false},	// 67	AutomaticHydraMovsBarWidgetAOwn
	{3639, 16,	1,	0,	false,	0,	0,	256,	1,	0,	true,	2309220708934221902,	true,	false},	// 68	AutomaticHydraMovsBarWidgetCOwn
	{3640, 16,	1,	0,	false,	0,	0,	256,	1,	0,	true,	2309220708934221902,	true,	false},	// 69	AutomaticHydraMovsBarWidgetDOwn
	{3641, 16,	1,	0,	false,	0,	0,	256,	1,	0,	true,	2309220708934221902,	true,	false},	// 70	AutomaticHydraMovsBarWidgetBOwn
	{3717, 8,	1,	0,	false,	0,	0,	255,	1,	0,	true,	2309220708934221902,	true,	false},	// 71	TransmissionModelOwn
	{3720, 3,	1,	0,	true,	0,	4,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 72	AirPressureStatusOwn
	{3721, 16,	25,	0,	true,	0,	400,	48,	1000,	0,	true,	2309220708934221902,	true,	false},	// 73	TimeToLiftWingsOwn
	{3797, 1,	1,	0,	true,	0,	1,	0,	1,	0,	false,	2309365878828826703,	false,	false},	// 74	HydraulicMovementsEnableRequest3Own
	{191, 8,	1,	0,	false,	0,	0,	0,	1,	1000,	false,	0,	false,	false},	// 75	CANRXCounter
	{192, 8,	1,	0,	false,	0,	0,	0,	1,	1000,	false,	0,	false,	false},	// 76	CANTXCounter
	{200, 64,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 77	NAME
	{212, 2,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 78	DiagConfigCmd
	{213, 1,	1,	0,	false,	0,	1,	0,	1,	0,	false,	0,	false,	false},	// 79	DiagConfigOverride
	{214, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 80	DiagConfigSignalId
	{210, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 81	DiagOverrideSignalId
	{211, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 82	DiagOverrideValue
	{202, 24,	1,	0,	true,	0,	16777200,	0,	1,	0,	false,	0,	false,	false},	// 83	RequestedPGN
	{208, 8,	1,	0,	true,	0,	255,	0,	1,	0,	false,	0,	false,	false},	// 84	TPCMCtrlByte
	{176, 16,	1,	0,	true,	9,	1785,	0,	1,	0,	false,	0,	false,	false},	// 85	AckMsgSize
	{182, 16,	1,	0,	true,	9,	1785,	0,	1,	0,	false,	0,	false,	false},	// 86	BamMsgSize
	{204, 16,	1,	0,	true,	9,	1785,	0,	1,	0,	false,	0,	false,	false},	// 87	RtsMsgSize
	{206, 8,	1,	0,	true,	1,	255,	0,	1,	0,	false,	0,	false,	false},	// 88	SendPackets
	{1862, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 89	AbortReason
	{201, 8,	1,	0,	true,	1,	255,	0,	1,	0,	false,	0,	false,	false},	// 90	NextPacket
	{178, 8,	1,	0,	true,	1,	255,	0,	1,	0,	false,	0,	false,	false},	// 91	AckNoPackets
	{183, 8,	1,	0,	true,	1,	255,	0,	1,	0,	false,	0,	false,	false},	// 92	BamNoPackets
	{205, 8,	1,	0,	true,	1,	255,	0,	1,	0,	false,	0,	false,	false},	// 93	RtsNoPackets
	{209, 24,	1,	0,	true,	0,	16777200,	0,	1,	0,	false,	0,	false,	false},	// 94	TPCMPGN
	{207, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 95	SeqNumber
	{184, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 96	Byte1
	{185, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 97	Byte2
	{186, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 98	Byte3
	{187, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 99	Byte4
	{188, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 100	Byte5
	{189, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 101	Byte6
	{190, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 102	Byte7
	{177, 8,	1,	0,	true,	0,	255,	0,	1,	0,	false,	0,	false,	false},	// 103	ACKNCtrlByte
	{180, 32,	1,	0,	true,	0,	4294967295,	4294967295,	1,	0,	false,	0,	false,	false},	// 104	ACKReserved
	{179, 24,	1,	0,	true,	0,	16777216,	0,	1,	0,	false,	0,	false,	false},	// 105	ACKNPGN
	{181, 1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 106	AlarmWhenGone
	{542, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 107	HWID
	{548, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 108	VersionMajor
	{549, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 109	VersionMinor
	{550, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 110	VersionBuild
	{551, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 111	VersionRevision
	{196, -1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 112	ECUDescription
	{345, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 113	AlarmInfoAlarmID
	{346, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 114	AlarmInfoCauseID
	{347, 2,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 115	AlarmInfoCommand
	{348, -1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 116	AlarmInfoInstanceString
	{356, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 117	SignalValueChangeRequestSignalID
	{357, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 118	SignalValueChangeRequestNewValue
	{358, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 119	SignalActualValueSignalID
	{359, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 120	SignalActualValueValue
	{377, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 121	PCR_ProcessID
	{378, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 122	PCR_CommandID
	{379, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 123	PCS_ProcessID
	{380, 16,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 124	PCS_CommandID
	{381, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 125	PCS_Status
	{541, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 126	BL_UpdateType
	{543, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 127	InstanceMethod
	{546, 8,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 128	InstanceID
	{547, -1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 129	BL_Data
	{1219, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 130	SignalActualValueRequestSignalID
	{1873, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 131	SignalActualValueExtendedSignalID
	{1874, 64,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 132	SignalActualValueExtendedValue
	{1876, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 133	SignalValueChangeRequestExtendedSignalID
	{1877, 64,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 134	SignalValueChangeRequestExtendedNewValue
	{2431, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 135	SignalActualValueArraySignalID
	{2432, -1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 136	SignalActualValueArrayValue
	{2433, 32,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 137	SignalValueChangeRequestArraySignalID
	{2434, -1,	1,	0,	false,	0,	0,	0,	1,	0,	false,	0,	false,	false},	// 138	SignalValueChangeRequestArrayValue
	{3162, 8,	4,	0,	false,	0,	250,	0,	10,	750,	true,	2309220708934221902,	false,	false},	// 139	EngineOilLevel
	{388, 8,	4,	0,	false,	0,	250,	0,	1,	750,	true,	2309220708934221902,	false,	false},	// 140	EngineOilPressure
	{3161, 8,	4,	0,	false,	0,	250,	0,	10,	750,	true,	2309220708934221902,	false,	false},	// 141	EngineCoolantLevel1
	{394, 8,	1,	-125,	false,	0,	250,	125,	1,	750,	true,	2309220708934221902,	false,	false},	// 142	ActEnginePercentTorque
	{389, 16,	125,	0,	false,	0,	64255,	0,	1000,	750,	true,	2309220708934221902,	false,	false},	// 143	EngineSpeed
	{1446, 4,	1,	0,	false,	0,	7,	0,	1,	750,	true,	2309220708934221902,	false,	false},	// 144	EngineStarterMode
	{390, 8,	1,	-40,	false,	0,	250,	40,	1,	1750,	true,	2309220708934221902,	false,	false},	// 145	EngineCoolantTemp
	{391, 8,	1,	-40,	false,	0,	250,	40,	1,	1750,	true,	2309220708934221902,	false,	false},	// 146	FuelTemperature
	{392, 16,	0,	-273,	false,	0,	64256,	8736,	1,	1750,	true,	2309220708934221902,	false,	false},	// 147	EngineOilTemperature
	{393, 16,	5,	0,	true,	0,	64255,	0,	100,	1750,	true,	2309220708934221902,	false,	false},	// 148	BatteryPotentialPowerInput1
	{3563, 16,	5,	0,	true,	0,	64255,	0,	100,	1750,	true,	2309220708934221902,	false,	false},	// 149	KeySwitchBatteryPotential
	{927, 8,	4,	0,	false,	0,	250,	0,	10,	0,	true,	2309220708934221902,	false,	false},	// 150	FuelLevel
	{1058, 2,	1,	0,	false,	0,	3,	0,	1,	150,	false,	2309253698578022482,	false,	false},	// 151	ParkingBrakeSwitch
	{1517, 2,	1,	0,	true,	0,	4,	0,	1,	150,	false,	2309253698578022482,	false,	false},	// 152	BrakeSwitch
	{2941, 2,	1,	0,	true,	0,	3,	0,	1,	500,	false,	2309253698578022482,	false,	false},	// 153	EngineDiagnosticTestModeSwitch
	{2942, 2,	1,	0,	true,	0,	3,	0,	1,	500,	false,	2309253698578022482,	false,	false},	// 154	EngineShutdownOverrideSwitch
	{1061, 2,	1,	0,	false,	0,	3,	0,	1,	1500,	true,	2309220708934221902,	false,	false},	// 155	ParkingBrakeActuator
	{1065, 2,	1,	0,	false,	0,	3,	0,	1,	0,	false,	2309253698578022482,	false,	false},	// 156	TransmissionReverseDirectionSwitch
	{1064, 2,	1,	0,	false,	0,	3,	3,	1,	0,	false,	2309253698578022482,	false,	false},	// 157	TransmissionNeutralSwitch
	{1080, 8,	8,	0,	false,	0,	250,	0,	1,	1750,	true,	2309220708934221902,	false,	false},	// 158	PneumaticSupplyPressure
	{1081, 2,	1,	0,	true,	0,	3,	0,	1,	1750,	true,	2309220708934221902,	false,	false},	// 159	EngineProtectionSystemHasShutdownEngine
	{1082, 2,	1,	0,	true,	0,	3,	0,	1,	1750,	true,	2309220708934221902,	false,	false},	// 160	EngineProtectionSystemApproachingShutdown
	{1445, 4,	1,	0,	false,	0,	15,	0,	1,	375,	true,	2309220708934221902,	false,	false},	// 161	EngineOperatingState
	{1447, 2,	1,	0,	false,	0,	3,	0,	1,	375,	true,	2309220708934221902,	false,	false},	// 162	EngineEmergencyShutdownIndication
	{1448, 2,	1,	0,	false,	0,	3,	0,	1,	1500,	true,	2309220708934221902,	false,	false},	// 163	Alternator1Status
	{1449, 32,	5,	0,	true,	0,	4211081215,	0,	100,	0,	true,	2309220708934221902,	true,	false},	// 164	EngineTotalHoursOfOperation
	{1657, 2,	1,	0,	true,	0,	3,	1,	1,	175,	false,	2309238301120266324,	false,	false},	// 165	GroundBasedImplementDirection
	{1656, 16,	1,	0,	true,	0,	64255,	0,	1000,	500,	false,	2309238301120266324,	false,	false},	// 166	GroundBasedImplementSpeed
	{3210, 8,	1,	-40,	true,	0,	250,	40,	1,	3000,	true,	2309220708934221902,	false,	false},	// 167	HydraulicTemperature
	{3211, 8,	4,	0,	true,	0,	250,	0,	10,	3000,	true,	2309220708934221902,	false,	false},	// 168	HydraulicOilLevel
	{3588, 16,	1,	0,	false,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 169	EngineOilPressureSensorVoltageOwn
	{3822, 8,	1,	0,	true,	0,	50,	45,	1000,	0,	true,	2309220708934221902,	false,	false},	// 170	EngineOilPressureSensorPullUpCurrentOwn
	{3594, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 171	PneumaticSupplyPressureSensorVoltageOwn
	{1513, 8,	1,	0,	true,	0,	50,	45,	1,	0,	true,	2309220708934221902,	false,	false},	// 172	PPUVDO5031_45mA
	{3642, 16,	1,	0,	false,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 173	HydraulicOilTemperatureSensorVoltage
	{1514, 8,	1,	0,	true,	0,	50,	20,	1,	0,	true,	2309220708934221902,	false,	false},	// 174	PPUMD24710_20mA
	{2989, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 175	FuelLevelSensorVoltageOwn
	{3825, 8,	1,	0,	true,	0,	50,	45,	1000,	0,	true,	2309220708934221902,	false,	false},	// 176	FuelLevelSensorPullUpCurrentOwn
	{3591, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 177	EngineCoolantTemperatureSensorVoltageOwn
	{3719, 8,	1,	0,	true,	0,	50,	20,	1000,	0,	true,	2309220708934221902,	true,	false},	// 178	EngineCoolantTemperatureSensorPullUpCurrentOwn
	{2988, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 179	AirFilterCloggedSensorValueOwn
	{3592, 32,	1,	0,	true,	0,	5000000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 180	EngineSpeedSensorFrecuencyOwn
	{3821, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 181	AlternatorChargeStatusValueOwn
	{2995, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 182	Instance1PinAValueOwn
	{3823, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 183	EngineOilHighTemperatureDigitalSensorValueOwn
	{3824, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 184	EngineOilPressureDigitalSensorValueOwn
	{1455, 2,	1,	0,	true,	0,	3,	3,	1,	0,	true,	2309220708934221902,	false,	false},	// 185	EngineCylinder1HighTemperature
	{872, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 186	SalSubirBotalon
	{3619, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 187	BoomUpValveVoltageOwn
	{3601, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 188	BoomUpValveOutFailureFlagOwn
	{858, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 189	SalBajarBotalon
	{3620, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 190	BoomDownValveVoltageOwn
	{3602, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 191	BoomDownValveOutFailureFlagOwn
	{844, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 192	SalAlaIzqSube45
	{3621, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 193	LeftArmUpValveVoltageOwn
	{3605, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 194	LeftArmUpValveOutFailureFlagOwn
	{854, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 195	SalAlaIzqBaja45
	{3622, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 196	LeftArmDownValveVoltageOwn
	{3606, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 197	LeftArmDownValveOutFailureFlagOwn
	{862, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 198	SalAlaDerSube45
	{3623, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 199	RightArmUpValveVoltageOwn
	{3603, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 200	RightArmUpValveOutFailureFlagOwn
	{848, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 201	SalAlaDerBaja45
	{3624, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 202	RightArmDownValveVoltageOwn
	{3604, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 203	RightArmDownValveOutFailureFlagOwn
	{1495, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 204	SalAlinIzquierdoBajar
	{3625, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 205	LeftEndBraceOpenValveVoltageOwn
	{3616, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 206	LeftEndBraceOpenValveOutFailureFlagOwn
	{1492, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 207	SalAlinIzquierdoSubir
	{3626, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 208	LeftEndBraceCloseValveVoltageOwn
	{3615, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 209	LeftEndBraceCloseValveOutFailureFlagOwn
	{1494, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 210	SalAlinDerechoBajar
	{3627, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 211	RightEndBraceOpenValveVoltageOwn
	{3614, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 212	RightEndBraceOpenValveOutFailureFlagOwn
	{1491, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 213	SalAlinDerechoSubir
	{3628, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 214	RightEndBraceCloseValveVoltageOwn
	{3613, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 215	RightEndBraceCloseValveOutFailureFlagOwn
	{1489, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 216	SalAbreAlaDerecha
	{3629, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 217	OpenRightArmValveVoltageOwn
	{3607, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 218	OpenRightArmValveOutFailureFlagOwn
	{1487, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 219	SalCierraAlaDerecha
	{3630, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 220	CloseRightArmValveVoltageOwn
	{3608, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 221	CloseRightArmValveOutFailureFlagOwn
	{1496, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 222	SalTrabaBasculanteBotalon
	{3631, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 223	BoomLockValveVoltageOwn
	{3611, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 224	BoomLockValveOutFailureFlagOwn
	{1497, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 225	SalDestrabaBasculanteBotalon
	{3632, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 226	BoomUnlockValveVoltageOwn
	{3612, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 227	BoomUnlockValveOutFailureFlagOwn
	{122, 1,	1,	0,	true,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 228	SalVenteo
	{3014, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 229	GeneralEnableHydraulicValveVoltageOwn
	{3477, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 230	GeneralEnableHydraulicValveOutFailureFlagOwn
	{1490, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 231	SalAbreAlaIzquierda
	{3633, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 232	OpenLeftArmValveVoltageOwn
	{3609, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 233	OpenLeftArmValveOutFailureFlagOwn
	{1488, 1,	1,	0,	false,	0,	1,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 234	SalCierraAlaIzquierda
	{3634, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 235	CloseLeftArmValveVoltageOwn
	{3610, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 236	CloseLeftArmValveOutFailureFlagOwn
	{2893, 1,	1,	0,	true,	0,	1,	1,	1,	0,	true,	2309220708934221902,	false,	false},	// 237	ParkingBrakeActuatorOwn
	{3107, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 238	ParkingActivationValveVoltageOwn
	{3268, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 239	ParkingActivationValveOutFailureFlagOwn
	{842, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 240	SalTrabaAlas
	{3635, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 241	WingsLockValveVoltageOwn
	{3617, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 242	WingsLockValveOutFailureFlagOwn
	{850, 1,	1,	0,	false,	0,	1,	0,	1,	500,	true,	2309220708934221902,	false,	false},	// 243	SalDestrabaAlas
	{3636, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 244	WingsUnlockValveVoltageOwn
	{3618, 16,	1,	0,	false,	0,	0,	0,	1,	0,	true,	2309220708934221902,	false,	false},	// 245	WingsUnlockValveOutFailureFlagOwn
	{2993, 16,	1,	0,	true,	0,	30000,	0,	1000,	0,	true,	2309220708934221902,	false,	false},	// 246	VCC_SYS_ECU1C_I1_Own
};


