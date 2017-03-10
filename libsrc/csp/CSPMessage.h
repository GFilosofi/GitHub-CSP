/*
 * CSP library
 * Copyright (C) 2017, Cosmed s.r.l. <http://www.cosmed.com/>
 * Author: Gabriele Filosofi <gabrielef@cosmed.it>
 */

#ifndef CSP_MESSAGE_H
#define CSP_MESSAGE_H

/////////////////////////////////////////////////////////////////////////////
// Message Format
//
// $ S G nn -------- * cs1 cs0 CR LF
//
// where: 
//  	$     is the 1 byte Preamble ('$')
//	S     is the 1 byte Sender ID ('P','D')
//	G     is the 1 byte Message Group ID ('C','R','D','E')
//	nn    is the 2 byte string Message Number ("00".."99")
//	----- is the 0-1500 byte data Payload (0 or more repetition of ",<subfield>")
//	*     is the 1 byte Postamble ('*')
//	cs1   is the 2 byte string of the Checksum's MSB ("00".."ff")
//	cs0   is the 2 byte string of the Checksum's LSB ("00".."ff")
//	CR    is the 1 byte terminator carriege-return "\d" (0x0d)
//	LF    is the 1 byte terminator line feed "\r" (0x0d)
//
// example:
//		$DC01*e86a<CRLF>
/////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

#define CSP_MSG_PRE_TX		((uint8_t)0x24)
#define CSP_MSG_PRE_RX		((uint8_t)0x24)
#define CSP_MSG_PRE_SIZE	((uint8_t)1)
#define CSP_MSG_SENDER_SIZE	((uint8_t)1)
#define CSP_MSG_GROUP_SIZE	((uint8_t)1)
#define CSP_MSG_NUM_SIZE	((uint8_t)2)
#define CSP_MSG_PAYLOAD_SIZE	((uint8_t)1)
#define CSP_MSG_POST_SIZE	((uint8_t)1)
#define CSP_MSG_CHECKSUM_SIZE	((uint8_t)4)
#define CSP_MSG_TERM1		((uint8_t)0x0D)
#define CSP_MSG_TERM0		((uint8_t)0x0A)

#define CSP_MSG_MAX_DATA_SIZE	1500
#define CSP_MSG_HEADER_SIZE	(CSP_MSG_PRE_SIZE + CSP_MSG_SENDER_SIZE + CSP_MSG_GROUP_SIZE + CSP_MSG_NUM_SIZE)
#define CSP_MSG_FRAME_SIZE	(CSP_MSG_HEADER_SIZE + CSP_MSG_POST_SIZE + CSP_MSG_CHECKSUM_SIZE)
#define CSP_MSG_MAX_SIZE	(CSP_MSG_MAX_DATA_SIZE + CSP_MSG_FRAME_SIZE)
#define CSP_MSG_SENDER_OFFSET	(CSP_MSG_PRE_SIZE)
#define CSP_MSG_GROUP_OFFSET	(CSP_MSG_PRE_SIZE + CSP_MSG_SENDER_SIZE)
#define CSP_MSG_NUM_OFFSET	(CSP_MSG_PRE_SIZE + CSP_MSG_SENDER_SIZE + CSP_MSG_GROUP_SIZE)
#define CSP_MSG_PAYLOAD_OFFSET	(CSP_MSG_HEADER_SIZE)
#define CSP_MSG_RECOMMENDED_BUF_SIZE	(CSP_MSG_MAX_SIZE)
 
/* Set to response timeout (s) */
#define CSP_RESP_TIMEOUT	5

/* Set to 1 to add a checksum to output message */
#define CSP_USE_CS		1

#ifdef  __cplusplus
extern "C" {
#endif

#pragma pack(push,1)
typedef struct {
	uint8_t		preamble;
	uint8_t		sender;
	uint8_t		group;
	uint16_t	number;
	uint8_t 	data [CSP_MSG_MAX_DATA_SIZE];
	uint8_t		postamble;
	uint16_t	cs1;
	uint16_t	cs0;
	uint16_t	term;
} CSPMsg_t;
#pragma pack(pop)

typedef enum
{
	kCSPTypeProduct,
	kCSPTypeDevice
} CSPType_t;

typedef enum
{
	kCSPStateDisconnected,	/* Product or Device. Transport link not available */
	kCSPStateIdle,		/* Product. No CSP task is running. The system is available to run CSP tasks */
	kCSPStateInactive,	/* Device. The app is running in foreground but is currently not receiving events */
	kCSPStateActive,	/* Product or Device. The CSP task (app) is running on Product (Device) */
	kCSPStateBusy,		/* Product. A program execution makes the system unavailable to run any other CSP task */
	kCSPStateBackground,	/* Device. The app is in background and executing code */
	kCSPStateSuspended	/* Device. The app is in background but is not executing code */
} CSPState_t;

/* Table 5-3 */
typedef enum
{
	kCSPMsgGroupCommand,
	kCSPMsgGroupResponse,
	kCSPMsgGroupData,
	kCSPMsgGroupEvent
} CSPMsgGroup_t;

/* Table 6-1 */
typedef enum
{
	kCSPMsgCmdTestLink	= 0,	/* Test the communication link */
	kCSPMsgCmdReset 	= 1,	/* Abort any initiated task and return to IDLE state */
	kCSPMsgCmdRtDataEnable	= 2,	/* Enable/Disable sending real time data during a test */
	kCSPMsgCmdLoopBackEnable= 3, 	/* Enable/Disable loopback mode */
	kCSPMsgCmdGetIdentity	= 5, 	/* Request peer's identity */
	kCSPMsgCmdGetStatus	= 6, 	/* Request peer's status */
	kCSPMsgCmdSetTimeAndDate= 7, 	/* Set current UTC time and date */
	kCSPMsgCmdGetParamID	= 8, 	/* Get data parameters ID */
	kCSPMsgCmdGetParamType	= 9, 	/* Get data parameters type */
	kCSPMsgCmdGetParamName	= 10, 	/* Get data parameters name */
	kCSPMsgCmdGetParamUM	= 11, 	/* Get data parameters unit od measurement */
	kCSPMsgCmdGetParamDec	= 12, 	/* Get data parameter decimal positions */
	kCSPMsgCmdGetCalibData	= 20, 	/* Get data value of calibration factors */
	kCSPMsgCmdSetMarker	= 40, 	/* Set a marker during a test */
	kCSPMsgCmdStartTask	= 41, 	/* Start a task (future version) */
	kCSPMsgCmdStartRec	= 42, 	/* Start test recording (future version) */
	kCSPMsgCmdEndTask	= 43, 	/* End a task */
	kCSPMsgCmdCreateSubject	= 50, 	/* Create a new subject registy (future version) */
	kCSPMsgCmdDeleteSubject	= 51, 	/* Delete a subject registry (future version) */
	kCSPMsgCmdCreateVisit	= 52, 	/* Create a new visit (future version) */
	kCSPMsgCmdDeleteVisit	= 53, 	/* Delete a visit (future version) */
	kCSPMsgCmdGetSubjList	= 54, 	/* Get the list of all subjects (future version) */
	kCSPMsgCmdGetVisitList	= 55, 	/* Get the list of all visit for a given subject (future version) */
	kCSPMsgCmdGetTestList	= 56, 	/* Get the list of all test for a given subject (future version) */
	kCSPMsgCmdGetArchData	= 60 	/* Get the entire archive of tests (future version) */
} CSPMsgCmd_t;

/* Table 7-1 */
typedef enum
{
	kCSPMsgRespTestLink	= 0,	/* Link integrity feedback */
	kCSPMsgRespAck 		= 1,	/* Message Acknowledges, either positive or negative */
	kCSPMsgRespIdentity 	= 5,	/* Peer identity information */
	kCSPMsgRespStatus	= 6, 	/* Durrent status of peer */
	kCSPMsgRespParamID	= 8, 	/* Data parameters ID */
	kCSPMsgRespParamType	= 9, 	/* Data parameters type */
	kCSPMsgRespParamName	= 10, 	/* Data parameters name */
	kCSPMsgRespParamUM	= 11, 	/* Units of measurement of data parameters */
	kCSPMsgRespParamDec	= 12, 	/* Decimal positions of data parameters */
	kCSPMsgRespSubjList	= 54, 	/* List of all subjects (future version) */
	kCSPMsgRespVisitList	= 55, 	/* List of all visit for a given subject (future version) */
	kCSPMsgRespTestList	= 56, 	/* List of all test for a given subject (future version) */
	kCSPMsgRespArchiveData	= 60 	/* Entire archive of tests (future version) */
} CSPMsgResp_t;

/* Table 8-1 */
typedef enum
{
	kCSPMsgDataCalibData,	/* Calibration factors */
	kCSPMsgDataErgoStep	/* Step data (single or multiple breath depending on test type) */
} CSPMsgData_t;

/* Table 9-1 */
typedef enum
{
	kCSPMsgEvent		/* Event message */
} CSPMsgEvent_t;

/* Table 6-3 */
typedef enum
{
	kCSPDataCalib,		/* Calibration Data */
	kCSPDataBxB,		/* Breath-by-Breath ErgoStep Data */
	kCSPDataMix		/* Mixing Chamber ErgoStep Data */
} CSPDataType_t;

/* Table 6-4 */
typedef enum {
	kCSPCalUnspecified,
	kCSPCalBxB,
	kCSPCalMix
} CSPCalType_t;

/*  Table 6-5 */
typedef enum
{
	kCSPContNone,		/* The marker's content field is empty */
	kCSPContText,		/* Text label */
	kCSPContImage,		/* Image pathname and/or filename (with extension) */
	kCSPContAudio,		/* Audio pathname and/or filename (with extension) */
	kCSPContVideo		/* Video pathname and/or filename (with extension) */
} CSPContType_t;

/* Table 7-2 */
typedef enum
{
	kCSPAckFlagInvalid,	/* Invalid message (e.g. missing parameter) */
	kCSPAckFlagUnsupported,	/* Unsupported message */
	kCSPAckFailed,		/* Supported message, but action failed */
	kCSPAckSucceeded	/* Supported message, and action succeeeded */
} CSPAckFlag_t;

/* Table 7-3 */
typedef enum
{
	kCSPStsUnspecified,	/* Unspecified */
	kCSPStsIdle,		/* Product. No CSP task is running. The system is available to run CSP tasks */
	kCSPStsInactive,	/* Device. The app is running in foreground but is currently not receiving events */
	kCSPStsActive,		/* Product or Device. The CSP task (app) is running on Product (Device) */
	kCSPStsBusy,		/* Product. A program execution makes the system unavailable to run any other CSP task */
	kCSPStsBackground	/* Device. The app is in background and executing code */
} CSPSts_t;

/* Table 7-4 */
typedef enum {
	kCSPTskNameUnspecified,	/* Unspecified */
	kCSPTskNameCalib,	/* Product is running a calibration */
	kCSPTskNameHolterBxB,	/* Product is running a BxB test in Holter mode */
	kCSPTskNameHolterMix,	/* Product is running a Mixing Chamber test in Holter mode */
	kCSPTskNamePcBxB,	/* Product is running a BxB test in PC mode */
	kCSPTskNamePcMix,	/* Product is running a Mixing Chamber test in PC mode */
	kCSPTskNameTestLog	/* Product is running a File Logging of test events */
} CSPTskName_t;

/* Table 9-2 */
typedef enum {
	kCSPEventBatteryLow,		/* Battery remaining capacity < 10% */
	kCSPEventBatteryFull,		/* Battery fully charged (100%) */
	kCSPEventBatteryFailure,	/* Battery failure */
	kCSPEventHwFailure,		/* Hardware failure */
	kCSPEventFwFailure,		/* Firmware failure */
	kCSPEventUnspecifiedFailure,	/* Unspecified failure */
	kCSPEventShutdown,		/* Shutdown in progress */
	kCSPEventPoorLink,		/* Poor link conditions */
	kCSPEventBufferOverflow,	/* Buffer overflow condition */
	kCSPEventAutocalStart,		/* Start of autocalibration during test */
	kCSPEventAutocalDone,		/* End of autocalibration during test */
	kCSPEventTaskExecStart,		/* Start of task execution */
	kCSPEventRecStart,		/* Start of test recording (REC) */
	kCSPEventWillBecomeActive,	/* Entering ACTIVE state */
	kCSPEventWillBecomeBusy,	/* Entering BUSY state */
	kCSPEventDidEnterBackground,	/* Running in BACKGROUND state */
	kCSPEventWillTerminate,		/* The current task or app is going to be closed */
	kCSPEventWillBecomeIdle,	/* Entering IDLE state */
	kCSPEventWillDisconnect		/* Disconnecting */
} CSPEventType_t;

/* Table 10-1 */
typedef uint8_t		U1;	/* nnn, unsigned decimal value, 0..255 */
typedef int8_t		S1;	/* [-]nnn, signed decimal value, -128..127 */
typedef uint8_t		H1;	/* hh, hex value without 0x, 0..ff */
typedef uint8_t		X1;	/* nnnnnnnn, bifield value, 0..11111111 */
typedef uint16_t	U2;	/* nnnnn, unsigned decimal value, 0..65535 */
typedef int16_t		S2;	/* [-]nnnnn, signed decimal value, -32768..32767 */
typedef uint16_t	H2;	/* hhhh, hex value without 0x, 0..ffff */
typedef uint16_t	X2;	/* bifield value, 0..1111111111111111 */
typedef uint32_t	U4;	/* nnnnnnnnnn, unsigned decimal value, 0..4294967295 */
typedef int32_t		S4;	/* [-]nnnnnnnnnn, signed decimal value, -2147483648..2147483647 */
typedef const char* 	ASC;	/* character string */
typedef uint32_t	DAT;	/* yyyymmdd date, 19700101..21000101 */
typedef uint32_t	TIM;	/* hhmmss time, 0..235959 */
typedef uint16_t	VER;	/* MMmm version, M:1..99, m:0..99 */

#pragma pack(push,1)
/* Table 10-2 */
typedef struct {
	int	id;
	ASC	name;
	ASC	type;
	ASC	um;
	int	decimals;
	int	min;
	int	max;
} CSPParam_t;
#pragma pack(pop)

static CSPParam_t ergoStepParams [3] = {
{ 18,	"N",		"U2",	"",	0,	0,	16383 },		/* Step count. Resets on REC start. Rollover at 16384 */
{ 4097,	"Time",		"TIM",	"",	0,	0,	40000 },	/* Elapsed time from start. Resets on REC start */
{ 17,	"Marker",	"U1",	"",	0,	0,	1 }		/*  Marker indicator */

};


static CSPParam_t calibParams [4] = {
{ 5120,	"GasCDat",	"DAT",	"",	0,	19700101,	21000101 },	/* UTC date of gas calibration */
{ 5121,	"GasCTim",	"TIM",	"",	0,	0,		235959 },	/* UTC time of gas calibration */
{ 5122,	"FlwmCDat",	"DAT",	"",	0,	19700101,	21000101 },	/* UTC date of flowmeter calibration */
{ 5123,	"FlwmCTim",	"TIM",	"",	0,	0,		235959 }	/* UTC time of flowmeter calibration */

};

/* Callback function to signal a data buffer has been processed and sent out
 */
//typedef void (*CSPDataSentCB_t) (struct CSP_st* csp, void* context);

#ifdef  __cplusplus
}
#endif
#endif /* CSP_MESSAGE_H */
