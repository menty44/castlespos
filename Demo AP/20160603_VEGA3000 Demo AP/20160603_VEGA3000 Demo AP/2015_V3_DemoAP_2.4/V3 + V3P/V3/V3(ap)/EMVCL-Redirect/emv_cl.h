#ifndef __EMV_CL_H__
#define	__EMV_CL_H__

#ifdef	__cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
//Return Code
//------------------------------------------------------------------------------
#define d_EMVCL_NO_ERROR									0x00000000
#define d_EMVCL_PENDING										0x80000020
#define d_EMVCL_TX_CANCEL									0x80000021
#define d_EMVCL_INIT_TAGSETTING_ERROR						0x80000022
#define d_EMVCL_INIT_CAPK_ERROR								0x80000023
#define d_EMVCL_INIT_PARAMETER_ERROR						0x80000024
#define d_EMVCL_INIT_CAPABILITY								0x80000025
#define d_EMVCL_INIT_REVOCATION_ERROR						0x80000026
#define d_EMVCL_INIT_EXCEPTION_FILE_ERROR					0x80000027
#define d_EMVCL_DATA_NOT_FOUND								0x80000030
#define d_EMVCL_TRY_AGAIN									0x80000051
#define d_EMVCL_RC_DATA										0xA0000001
#define d_EMVCL_RC_SCHEME_SUPPORTED							0xA0000004
#define d_EMVCL_RC_FAILURE									0xA00000FF
#define d_EMVCL_RC_INVALID_DATA								0xA00000F8
#define d_EMVCL_RC_INVALID_PARAM							0xA00000F7
#define d_EMVCL_RC_INVALID_SCHEME							0xA00000F5
#define d_EMVCL_RC_INVALID_VISA_CA_KEY						0xA00000F4
#define d_EMVCL_RC_MORE_CARDS								0xA00000F3
#define d_EMVCL_RC_NO_CARD									0xA00000F2
#define d_EMVCL_RC_FALLBACK									0xA00000E9
#define d_EMVCL_RC_DEK_SIGNAL								0xA00000E0
	
//------------------------------------------------------------------------------
//Definition
//------------------------------------------------------------------------------

//Used for EMVCL_ACT_DATA --> bStart
#define d_EMVCL_ACT_DATA_START_A							0x00
#define d_EMVCL_ACT_DATA_START_B							0x01

//Scheme ID : Used for EMVCL_RC_DATA_EX --> bSID
#define d_EMVCL_SID_VISA_OLD_US								0x13
#define d_EMVCL_SID_VISA_WAVE_2								0x16
#define d_EMVCL_SID_VISA_WAVE_QVSDC							0x17
#define d_EMVCL_SID_VISA_WAVE_MSD							0x18
#define d_EMVCL_SID_PAYPASS_MAG_STRIPE						0x20
#define d_EMVCL_SID_PAYPASS_MCHIP							0x21
#define d_EMVCL_SID_JCB_WAVE_2								0x61
#define d_EMVCL_SID_JCB_WAVE_QVSDC							0x62
#define d_EMVCL_SID_AE_EMV									0x50
#define d_EMVCL_SID_AE_MAG_STRIPE							0x52
#define d_EMVCL_SID_DISCOVER									0x41

//Transction Result : Used for EMVCL_RC_DATA_ANALYZE--> usTransResult
#define d_EMVCL_OUTCOME_APPROVAL							0x0002
#define d_EMVCL_OUTCOME_DECLINED							0x0003
#define d_EMVCL_OUTCOME_ONL								0x0004

//CVM Analysis : Used for EMVCL_RC_DATA_ANALYZE--> bCVMAnalysis
#define d_EMVCL_CVM_REQUIRED_NONE							0x00
#define d_EMVCL_CVM_REQUIRED_SIGNATURE						0x01
#define d_EMVCL_CVM_REQUIRED_ONLPIN						0x02
#define d_EMVCL_CVM_FAIL										0x03
#define d_EMVCL_CVM_REQUIRED_NOCVM						0x04
#define d_EMVCL_CVM_REQUIRED_CONFIRMATION_CODE_VERIFIED	0x05

//Used for EMVCL_SetUIType/EMVCL_GetUIType --> bType
#define d_EMVCL_UITYPE_NORMAL								0x00
#define d_EMVCL_UITYPE_EUR									0x01

//Txn return code is d_EMVCL_RC_DEK_SIGNAL, check the baChipData[0]
#define d_DEK_VISA_MOBILE_DEVICE_SEE_PHONE					0x06
#define d_DEK_VISA_EUR_CL_TIG_FATAL_COMMUNICATION			0x07
	
//Used for EMVCL_USER_INTERFACE_REQ_DATA -> bMessageIdentifier
#define d_EMVCL_USR_REQ_MSG_CARD_READ_OK					0x17 
#define d_EMVCL_USR_REQ_MSG_TRY_AGAIN						0x21 
#define d_EMVCL_USR_REQ_MSG_APPROVED						0x03 
#define d_EMVCL_USR_REQ_MSG_APPROVED_SIGN					0x1A 
#define d_EMVCL_USR_REQ_MSG_DECLINED						0x07 
#define d_EMVCL_USR_REQ_MSG_ERROR_OTHER_CARD				0x1C 
#define d_EMVCL_USR_REQ_MSG_INSERT_CARD					0x1D 
#define d_EMVCL_USR_REQ_MSG_SEE_PHONE						0x20 
#define d_EMVCL_USR_REQ_MSG_AUTHORISING_PLEASE_WAIT		0x1B     
#define d_EMVCL_USR_REQ_MSG_CLEAR_DISPLAY					0x1E 
#define d_EMVCL_USR_REQ_MSG_ENTER_PIN						0x09 
#define d_EMVCL_USR_REQ_MSG_PROCESSING_ERR					0x0F 
#define d_EMVCL_USR_REQ_MSG_REMOVE_CARD					0x10     
#define d_EMVCL_USR_REQ_MSG_WELCOME						0x14     
#define d_EMVCL_USR_REQ_MSG_PRESENT_CARD					0x15 
#define d_EMVCL_USR_REQ_MSG_PROCESSING						0x16 
#define d_EMVCL_USR_REQ_MSG_INSERT_OR_SWIPE_CARD			0x18 
#define d_EMVCL_USR_REQ_MSG_PRESENT_1_CARD_ONLY			0x19     
#define d_EMVCL_USR_REQ_MSG_PRESENT_CARD_AGAIN			0x21 
#define d_EMVCL_USR_REQ_MSG_NO_CARD						0xA0     
#define d_EMVCL_USR_REQ_MSG_NA								0xFF 

//Used for EMVCL_USER_INTERFACE_REQ_DATA -> bStatus
#define d_EMVCL_USR_REQ_STATUS_NOT_READY					0x00
#define d_EMVCL_USR_REQ_STATUS_IDLE							0x01
#define d_EMVCL_USR_REQ_STATUS_READY_TO_READ				0x02
#define d_EMVCL_USR_REQ_STATUS_PROCESSING					0x03
#define d_EMVCL_USR_REQ_STATUS_CARD_READ_SUCCESSFULLY		0x04
#define d_EMVCL_USR_REQ_STATUS_PROCESSING_ERROR			0x05
#define d_EMVCL_USR_REQ_STATUS_NA							0xFF

// Kernel ID
#define d_EMVCL_KERNEL_ID_MASTERCARD						0x02
#define d_EMVCL_KERNEL_ID_VISA								0x03

// Transaction Type
#define d_EMVCL_TXN_TYPE_PURCHASE							0x00
#define d_EMVCL_TXN_TYPE_CASH								0x01
#define d_EMVCL_TXN_TYPE_CASHBACK							0x09
#define d_EMVCL_TXN_TYPE_REFUND								0x20

// Parameter ID
#define d_EMVCL_PARA_INDEX_SALE_TIMEOUT						0x0002
#define d_EMVCL_PARA_INDEX_UI_TYPE							0x100A
#define d_EMVCL_PARA_INDEX_VISA_EUR_CL_TIG_FOLLOW			0x100B

// Action Value for EMVCL_CA_PUBLIC_KEY
#define d_EMVCL_CAPK_ACTION_ADD								0x00
#define d_EMVCL_CAPK_ACTION_DELETE							0x01
#define d_EMVCL_CAPK_ACTION_DELETE_ALL						0x02
	
//
#define d_EMVCL_EVENTID_LED_PIC_SHOW						0x01
typedef ULONG (*EVENT_EMVCL_LED_PIC_SHOW)(IN BYTE bIndex, IN BYTE bOnOff);


//------------------------------------------------------------------------------
//Data Structure
//------------------------------------------------------------------------------
	
//------------------------------------------------------------------------------
typedef struct 
{
	BYTE	bMessageIdentifier;
	BYTE	bStatus;
	BYTE	baHoldTime[3];
	BYTE	baLanguagePreference[8];
	BYTE	bValueQualifier;
	BYTE	baValue[6];
	BYTE	baCurrencyCode[2];
	
}EMVCL_USER_INTERFACE_REQ_DATA;

typedef struct 
{
	BOOL (*OnCancelTransaction)(void);
	void (*OnShowMessage)(BYTE bKernel, EMVCL_USER_INTERFACE_REQ_DATA *baUserInterfaceRequestData);
	
}EMVCL_EVENT;

typedef struct 
{
	BYTE	bConfigFilenameLen;
	BYTE	*pConfigFilename;
	EMVCL_EVENT stOnEvent;
	
}EMVCL_INIT_DATA;
	
//------------------------------------------------------------------------------
typedef struct 
{
	BYTE	bStart;
	BYTE	bTagNum;
	USHORT	usTransactionDataLen;
	BYTE	*pbaTransactionData;

}EMVCL_ACT_DATA;
	
//------------------------------------------------------------------------------
typedef struct 
{
	BYTE	bSID;
	BYTE	baDateTime[15];
	BYTE	bTrack1Len;
	BYTE	baTrack1Data[100];
	BYTE	bTrack2Len;
	BYTE	baTrack2Data[100];
	USHORT	usChipDataLen;
	BYTE	baChipData[1024];
	USHORT	usAdditionalDataLen;
	BYTE	baAdditionalData[1024];
	
}EMVCL_RC_DATA_EX;

//------------------------------------------------------------------------------
typedef struct
{
	USHORT	usTransResult;		// Transction Result
	BYTE	bCVMAnalysis;		//
	BYTE	baCVMResults[3];	//CVM Result
	BYTE	bVisaAOSAPresent;	//Visa Available Offline Spending Amount(AOSA) Present
	BYTE	baVisaAOSA[6];
	BOOL	bODAFail;			//Offline Data Authentication Fail , ODA FAIL -> TRUE, ODA OK --> FALSE
	
}EMVCL_RC_DATA_ANALYZE;

//------------------------------------------------------------------------------
typedef struct 
{
	IN BYTE			bAIDLen;
	IN BYTE			baAID[16];
	IN BYTE			bKernelID;
	IN BYTE			bTransactionType;
	IN USHORT		usTAGDataLen;
	IN BYTE			*pbaTAGData;

}EMVCL_AID_SET_TAG_DATA;

//------------------------------------------------------------------------------
typedef struct 
{
	IN BYTE			bAIDLen;
	IN BYTE			baAID[16];
	IN BYTE			bKernelID;
	IN BYTE			bTransactionType;
	INOUT USHORT	usTAGDataLen;
	OUT BYTE		*pbaTAGData;
	
}EMVCL_AID_GET_TAG_DATA;

//------------------------------------------------------------------------------
typedef struct
{
	BYTE	bAction;
	BYTE	bIndex;
	UINT	uiModulusLen;
	BYTE	baModulus[248];
	UINT	uiExponentLen;		// Length of Extension
	BYTE	baExponent[3];		// Extension
	BYTE	baHash[20];			// Key Hash (SHA-1) Result

}EMVCL_CA_PUBLIC_KEY;

//------------------------------------------------------------------------------
typedef struct
{
	UINT	uiNoP;				// Number of Parameters
	UINT	uiIndex[100];		// Parameter Index
	UINT	uiLen[100];			// Length of Parameter Data
	BYTE	baData[100][20];	// Parameter Data
	
}EMVCL_PARAMETER_DATA;

//------------------------------------------------------------------------------
typedef struct
{
	BYTE	bNoS;				// Number of Schemes
	BYTE	baID[255];			// Scheme ID
	BYTE	baAction[255];		// Active or deactive
	
}EMVCL_SCHEME_DATA;



/* ==========================================================================
 * FUNCTION NAME: EMVCL_Initialize
 * DESCRIPTION:   Initiate EMVCL environment.
 * 
 * [IN] pEvent : point to struct EMVCL_INIT_DATA
 * ========================================================================== */
ULONG EMVCL_Initialize(EMVCL_INIT_DATA *pInitData);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_ShowContactlessSymbol
 * DESCRIPTION:   Show contactless symbol on the screen.
 * 
 * [IN] pPara : RFU. Please set to NULL
 * ========================================================================== */
ULONG EMVCL_ShowContactlessSymbol(void *pPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_ShowVirtualLED
 * DESCRIPTION:   Show Virtual LED on screen.
 *
 * [IN] pPara : RFU. Please set to NULL
 * ========================================================================== */
ULONG EMVCL_ShowVirtualLED(void *pPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_SetLED
 * DESCRIPTION:   Set LED
 * 
 * [in]bIndex : LED Index (Bit0:LED1 RED, Bit1:LED2 GREEN, Bit2:LED3 YELLOW, Bit3:LED4 BLUE, Bit4-Bit7:RFU)
 *		Bitx = 1: LED(x+1) on/off indicated in bOnOff Bitx
 *		Bitx = 0: LED(x+1) with the current state 
 * [in]bOnOff : Turn on or off the LEDs
 *		Bitx = 1: control LED(x+1) on if LED index Bitx is set.
 *		Bitx = 0: control LED(x+1) off if LED index Bitx is set.
 * ========================================================================== */
ULONG EMVCL_SetLED(BYTE bIndex, BYTE bOnOff);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_StartIdleLEDBehavior
 * DESCRIPTION:   Start the idle behavior on Virtual LED.
 *		Normal UI : First indicator(blue led) is always on
 *		EUR UI : First indicator blink on for approximately 200ms every five seconds.
 *
 * [IN] pPara : RFU. Please set to NULL
 * ========================================================================== */
ULONG EMVCL_StartIdleLEDBehavior(void *pPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_StopIdleLEDBehavior
 * DESCRIPTION:   Stop the idle behavior on Virtual LED.
 *
 * [IN] pPara : RFU. Please set to NULL
 * ========================================================================== */
ULONG EMVCL_StopIdleLEDBehavior(void *pPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_AIDSetTagData
 * DESCRIPTION:   Set AID with TagsSetting. 
 *				EMVCL kernel can handle and storage more tags settings 
 *				for different combination list {TransType-AID-KERNEL ID}
 * 
 *				This API is used to set TagsSettingx 
 *				for one combination list {TransType-AID-KERNEL ID}
 * 
 * [IN] bAction : 
 *				= 0x00 for one TagSetting Addition
 *				= 0x01 for one TagSetting Deletion
 *				= 0x02 for All TagSetting Deletion
 * [IN] stTagData : Point to a EMVCL_AID_TAG_DATA structure containing the tag setting to be set/deleted
 * ========================================================================== */
ULONG EMVCL_AIDSetTagData(BYTE bAction, EMVCL_AID_SET_TAG_DATA *stTagData);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_AIDGetTagData
 * DESCRIPTION:   Get TagSetting of specific AID from EMVCL Contactless kernel.
 * 
 * [INOUT] stTagData : input is AID-kernelID-Transaction, output is TagsSetting
 * ========================================================================== */
ULONG EMVCL_AIDGetTagData(EMVCL_AID_GET_TAG_DATA *stTagData);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_SetCAPK
 * DESCRIPTION:   Set CA Public Key with specified RID to EMVCL Contactless kernel. 
 *				  The key to be set will belong to the specified RID.
 * 
 * [in]baRID : Point to a buffer containing RID. RID must be 5 bytes
 * [in]stCAPubKey : Point to a EMVCL_CA_PUBLIC_KEY structure containing the public key to be set.
 * ========================================================================== */
ULONG EMVCL_SetCAPK(BYTE *baRID, EMVCL_CA_PUBLIC_KEY *stCAPubKey);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_GetCAPK
 * DESCRIPTION:   Get CA Public Key with specified RID from EMVCL Contactless kernel.
 * 
 * [in]baRID : Point to a buffer containing RID. RID must be 5 bytes.
 * [in]bKID : CAPK index
 * [out]stCAPubKey : Point to a EMVCL_CA_PUBLIC_KEY structure to retrieve the corresponding CA public key.
 * ========================================================================== */
ULONG EMVCL_GetCAPK(BYTE *baRID, BYTE bKID, EMVCL_CA_PUBLIC_KEY *stCAPubKey);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_ListAllCAPKID
 * DESCRIPTION:   List all CAPK indexs saved in EMVCL Contactless kernel..
 * 
 * ListCAPK_x = RIDx + RIDx CAPKI number + RIDx CAPKIx + RIDx CAPKI2 + RIDx CAPKI3 + ...
 * [out]baRBuf : format is RID number +  ListCAPK_1 +  ListCAPK_2 +  ListCAPK_3 +...
 * [out]uiRLen : length of baRBuf
 * ========================================================================== */
ULONG EMVCL_ListAllCAPKID(BYTE *baRBuf, UINT *uiRLen);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_SetParameter
 * DESCRIPTION:   Set parameter.
 * 
 * [in]stPara : Point to a EMVCL_PARAMETER_DATA structure. 
 * ========================================================================== */
ULONG EMVCL_SetParameter(EMVCL_PARAMETER_DATA *stPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_GetParameter
 * DESCRIPTION:   Get one parameter.
 * 
 * [in]uiPID : parameter index
 * [out] stPara : parameter data
 * ========================================================================== */
ULONG EMVCL_GetParameter(UINT uiPID, EMVCL_PARAMETER_DATA *stPara);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_SetUIType
 * DESCRIPTION:   Set UI Type.
 * 
 * [in]bType : UI Type
 *		= 0x00 for Normal UI Type
 *		= 0x01 for EUR UI Type
 * ========================================================================== */
ULONG EMVCL_SetUIType(BYTE bType);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_GetUIType
 * DESCRIPTION:   Get UI Type.
 * 
 * [out]bType : UI Type
 *		= 0x00 for Normal UI Type
 *		= 0x01 for EUR UI Type
 * ========================================================================== */
void EMVCL_GetUIType(BYTE *bType);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_VisaSetCapability
 * DESCRIPTION:   Set Visa Capability.
 * 
 * [in]stScheme : scheme
 * [out]stRsp : response scheme
 * ========================================================================== */
ULONG EMVCL_VisaSetCapability(EMVCL_SCHEME_DATA *stScheme, EMVCL_SCHEME_DATA *stRsp);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_VisaGetCapability
 * DESCRIPTION:   Get Visa Capability.
 * 
 * [in]stScheme.bNoS : number of scheme id to be checked
 * [in]stScheme.baID : scheme id to be checked
 * [out]stScheme.bNoS : response number of scheme id
 * [out]stScheme.baID : response scheme id
 * [out]stScheme.baActive : support or not
 * ========================================================================== */
ULONG EMVCL_VisaGetCapability(EMVCL_SCHEME_DATA *stScheme);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_StartTransactionEx
 * DESCRIPTION:   
 * 
 * Start an EMV contactless transaction with transaction related data. Transaction related data should be TLV format.(TLV1 + TLV2 + .. + TLVn). ex : 9F02060000000015009F0306000000000000.... .
 * 
 * Transaction Related Data includes : (M:Madatory, O:Option)
 * Tag 9F02   (Amount Authorized(Numeric)) : visa - M   , MC - M
 * Tag 9F03   (Amount Other(Numeric))     : visa - O   , MC - O	 
 * Tag 9C     (Transaction Type)           : visa - M   , MC - O
 * Tag 9F53   (Transaction Category Code)  : visa - M   , MC - O
 * Tag 5F2A   (Transaction Currency Code)  : visa - M   , MC - O
 * 
 * Special Transaction Related Data for PayPass 3.0 Balance Reading function : 
 * Tag DF8104 (Balance Read before Gen AC) : 
 * MC with no Balance Reading - Absent , MC with Balance Reading - O
 * Tag DF8105 (Balance Read after Gen AC)  : 
 * MC with no Balance Reading - Absent , MC with Balance Reading - O
 * 
 * [IN] stACTData : Point to a EMVCL_ACT_DATA structure to send transaction related data.
 * [OUT] stRCDataEx : Point to a EMVCL_RC_DATA_EX structure to get the transaction data.
 *
 * ========================================================================== */
ULONG EMVCL_StartTransactionEx(EMVCL_ACT_DATA *stACTData, EMVCL_RC_DATA_EX *stRCDataEx);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_InitTransactionEx
 * DESCRIPTION:   Start a EMV contactless L2 transaction with transaction related data.
 *				  Transaction related data should be TLV format.(TLV1 + TLV2 + .. + TLVn) 
 *				  ex : 9F02060000000015009F0306000000000000....
 *				  The transaction result should be retrieved by EMVCL_PollTransactionEx function.
 *
 * Transaction Related Data include : (M:Madatory, O:Option)
 *	Tag 9F02   (Amount Authorized(Numeric)) 	: visa - M   , MC - M
 *	Tag 9F03   (Amount Other(Numeric))      	: visa - O   , MC - O	 
 *	Tag 9C     (Transaction Type)           		: visa - M   , MC - O
 *	Tag 9F53   (Transaction Category Code)  	: visa - M   , MC - O
 *	Tag 5F2A   (Transaction Currency Code)  	: visa - M   , MC - O
 *
 * Special Transaction Related Data for PayPass 3.0 : (Only for Balance Reading function) 
 *	Tag DF8104 (Balance Read before Gen AC) : MC with no Balance Reading - lack , MC with Balance Reading - O
 *	Tag DF8105 (Balance Read after Gen AC)  : MC with no Balance Reading - lack , MC with Balance Reading - O
 *
 * 
 * [in]bTagNum : Number of transaction related data 
 * [in]baTransData : Transaction related data
 * [in]usTransDataLen : Transaction related data length
 * ========================================================================== */
ULONG EMVCL_InitTransactionEx(BYTE bTagNum, BYTE *baTransData, USHORT usTransDataLen);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_PerformTransactionEx
 * DESCRIPTION:   Perform transaction and Receive the result of transaction strated by EMVCL_InitTransactionEx. 
 * 
 * [out]stRCDataEx : transaction response data
 * ========================================================================== */
ULONG EMVCL_PerformTransactionEx(EMVCL_RC_DATA_EX *stRCDataEx);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_PollTransactionEx
 * DESCRIPTION:   Receive the result of transaction strated by EMVCL_InitTransactionEx. 
 * 
 * [out]stRCData : transaction response data
 * [in]ulMS : RFU
 * ========================================================================== */
ULONG EMVCL_PollTransactionEx(EMVCL_RC_DATA_EX *stRCDataEx,ULONG ulMS);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_CompleteEx
 * DESCRIPTION:   Perform Complete/Issuer Update Processing process.
 * 
 * [in]bAction : 
 * [in]baARC : authorization Response Code (2 Bytes)
 * [in]uiIADLen : length of IAD 
 * [in]baIAD : issuer authentication data
 * [in]uiScriptLen : length og script
 * [in]baScript : pointer for the emitter scripts
 * [out]stRCData : transaction response data
 * ========================================================================== */
ULONG EMVCL_CompleteEx(BYTE bAction, BYTE *baARC, UINT uiIADLen, BYTE *baIAD, UINT uiScriptLen, BYTE *baScript, EMVCL_RC_DATA_EX *stRCDataEx);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_CancelTransaction
 * DESCRIPTION:   Abort the current transaction. 
    This API is used with EMVCL_InitTransactionEx and EMVCL_PerformTransactionEx.
    After send EMVCL_CancelTransaction API, please check return code 
    of EMVCL_PerformTransactionEx. If the return code is d_EMVCL_TX_CANCEL, 
    this transaction was canceled.
 * ========================================================================== */
ULONG EMVCL_CancelTransaction(void);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_AnalyzeTransactionEx
 * DESCRIPTION:   Analyze transaction Response Data EMV_RC_DATA_EX
 * 
 * [in]stRCDataEx : transaction response data
 * [out]stRCDataAnalyze : Point to struct EMVCL_RC_DATA_ANALYZ to show analyzed result.
 * ========================================================================== */
void EMVCL_AnalyzeTransactionEx(EMVCL_RC_DATA_EX *stRCDataEx, EMVCL_RC_DATA_ANALYZE *stRCDataAnalyze);

/* ==========================================================================
 * FUNCTION NAME: EMVCL_SetDebug
 * DESCRIPTION: Enable/Disable castles debug log. If enable, the debug log will be output by bDebugPort
 *			     For comport, the baudrate is 115200, N, 8, 1	 
 * 
 * [in]fDebufEnable : 
 			TRUE - Enable
 			FALSE - Disable
 * [in]bDebugPort : 
 			d_DEBUG_PORT_USB, d_DEBUG_PORT_COM1, d_DEBUG_PORT_COM2, d_DEBUG_PORT_COM3
 * ========================================================================== */ 
void EMVCL_SetDebug(BYTE fDebufEnable, BYTE bDebugPort);


ULONG EMVCL_SpecialEventRegister(IN BYTE bEventID, IN void *EventFunc);




#ifdef	__cplusplus
}
#endif

#endif	/* EMV_CL_H */

