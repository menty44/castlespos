/********************************************************************
 Copyright (c) Castles Technology Co., Ltd. 2006~
 Module Name: vwdleapi.h
 --------------------------------------------------------------------
 v1.0		2007.06.26	Release 
 v1.1		2007.07.09      Modify coding in DLE_ReadWriteRS232() & DLE_TXRS232()
		2007.07.10      Add VW_NAKPollStart(),VW_NAKPollStop() and VW_NAKPollSet() functions
					Modify coding in VW_MifareAuth()
 v1.2		2007.07.13      Remove Select AID parameter (bSelAIDFlag) from all related functions
 v1.3		2007.07.16	Optimize coding in VisaWave and DLE protocol
 v1.4		2007.07.17      Remove d_VW_COMM_COM3 definition for COM3 in V7 
 v1.5		2007.07.19      Optimize coding in checking status 
 v1.6		2007.07.24	Remrove ICC SAM & Mifare related functions from vwdleapi.c
					Remrove contactless card related functions from vwdleapi.c
		2007.07.25	Add new baudrate index 0x05(BR:9600) in VW_SetBaudRate()
 v1.7		2007.10.29      Modify VW_GetCAPublicKey() and VW_GetJCBPublicKey() 
 v2.0		2008.02.21	Add some functions for DLE protocol with payPass transaction use 
					Modify coding in VisaWave related functions	
		2008.03.18	Remove d_SAM_xxxxx definition
					Remove baudrate index 0x05(BR:9600) from VW_SetBaudRate()
		2008.04.14      Modify return code value of d_HOST_ID_INCORRECT 
 v2.1		2009.10.01	Modify VW_DES function for single DES
 v2.2		2010.01.20	Add new function VW_TypeB_ActiveIdleEx() 
		2010.01.29      Add new function VW_TypeA_RATSEx()
 v2.3		2010.09.21      Change parameter bPos data type define from BYTE to UINT. 					
 v2.4		2010.10.26	Add new functions VW_SetASCIIVerticalOffset() and VW_SetASCIIHorizontalOffset()
 v2.5		2011.03.22	Add a new function VW_MifareAuthEx() in iccmifare.c
 v2.6		2011.03.31	Add VW_InitTransactionV5CL(),CPP_InitSaleV5CL()
 v2.7		2011.04.28      Add para d_VW_COMM_V5CL and function K_UARTTxData for V5CL
 v3.0       2011.12.27  Add VW_SwitchToAdministrativeModeEx function	
 v3.1       2012.01.11  Modify VW_GetEMVTags parser data len > 128 issue
 			2012.01.19	Modify buffer size of baSDataBuf, baTmpBuf and baRDataBuf to GLOBAL_IN_OUT_BUF_SIZE
 			2012.01.19	Modufy ulRecLen from 1024 to GLOBAL_IN_OUT_BUF_SIZE in VW_GetEMVTags and VW_SetEMVTags function
		    2011.03.09	For VW_InitComm function, if set datetime fail, retry 3 times
 v3.2       2012.08.08  Modify buffer size when that use for GP_UnpackData()
*********************************************************************/
#ifndef VWDLE_API_H
#define VWDLE_API_H


#ifdef __cplusplus
extern "C" 
{
#endif

// Definition 
#define d_VW_SUCCESS					0x00
#define d_VW_CAKEY_ADD					0x00
#define d_VW_CAKEY_DELETE				0x01
#define d_VW_CAKEY_GET_ALL				0xFF
#define d_VW_MODE_DEBUG					0x00
#define d_VW_MODE_NORMAL				0x01
#define d_VW_MODE_ADMIN					0x02
#define d_VW_SCHEME_ACTIVE				0x01
#define d_VW_SCHEME_DEACTIVE			0x00
#define d_VW_SCHEME_GET_ALL				0xFF
#define d_VW_SCHEME_SUPPORT				0x01
#define d_VW_SCHEME_NOT_SUPPORT			0x00
#define d_VW_TAGS_GET_ALL				0xFF
#define d_VW_MESSAGES_GET_ALL			0xFF
#define d_VW_CVM_ACTIVE					0x01
#define d_VW_CVM_DEACTIVE				0x00
#define d_VW_CMV_GET_ALL				0xFF
#define d_VW_IMEK_MDK					0x00
#define d_VW_IMEK						0x01
#define d_VW_MEK						0x02
#define d_VW_Msession					0x03
#define d_VW_IAEK_MDK					0x04
#define d_VW_IAEK						0x05
#define d_VW_AEK						0x06
#define d_VW_Asession					0x07
#define d_VW_BAUDRATE_115200			0x00
#define d_VW_BAUDRATE_57600				0x01
#define d_VW_BAUDRATE_38400				0x02
#define d_VW_BAUDRATE_28800				0x03
#define d_VW_BAUDRATE_19200				0x04
#define d_VW_BAUDRATE_9600				0x05
#define d_VW_CVM_NOT_SUPPORT			0x00
#define d_VW_CVM_SIGNATURE				0x10
#define d_VW_CVM_ONLINE_PIN				0x11
#define d_VW_CVM_OFFLINE_PIN			0x12
#define d_VW_ON							0x01
#define d_VW_OFF						0x00
#define d_VW_SAM1						0x01
#define d_VW_SAM2						0x02
#define d_VW_SAM3						0x03
#define d_VW_SAM4						0x04
#define d_VW_5V							0x01
#define d_VW_3V							0x02
#define d_VW_18V						0x03
#define d_VW_EMV						0x01
#define d_VW_NONEMV						0x00
#define d_VW_PTS						0x01
#define d_VW_NOPTS						0x00
#define d_VW_IFSD						0x01
#define d_VW_NOIFSD						0x00
#define d_VW_TYPEKEYA					0X60
#define d_VW_TYPEKEYB					0X61
#define d_ACT_ONL_APPR					0x01
#define d_ACT_ONL_DENY					0x02
#define d_ACT_UNAB_ONL					0x03
#define d_ACT_ONL_ISSUER_REFERRAL_APPR	0x04
#define d_ACT_ONL_ISSUER_REFERRAL_DENY	0x05
#define d_CPP_GETALL					0x00

#define d_DLE_MODE						0xC0
#define d_VW_MODE						0xC1

#define d_VW_COMM_COM1	1
#define d_VW_COMM_COM2	2
#define d_VW_COMM_COM3  3
#define d_VW_COMM_V5CL  0xc2
#define d_VW_COMM_USB   0x81


#define d_NO_ERROR				0x00000000
#define d_TX_TIMEOUT			0x00000002
#define d_RX_TIMEOUT			0x00000003
#define d_CRC_INCORRECT			0x00000004
#define d_LRC_INCORRECT			0x00000004
#define d_BUF_NOT_ENOUGH		0x00000005
#define d_DLE_INCORRECT			0x00000006
#define	d_INIT_COM_ERROR		0x80000001
#define d_INVALID_HANDLE		0x80000002
#define	d_INVALID_PARA			0x80000003
#define	d_COMM_FAIL				0x80000004
#define	d_RSP_LEN_ERROR			0x80000005
#define	d_RSP_CMD_ERROR			0x80000006
#define d_OUT_OF_DATA_LEN		0x80000007
#define d_SN_INCORRECT			0x80000008
#define d_RSP_DATA_LEN_ERROR	0x80000009
#define	d_RSP_ID_ERROR			0x8000000A
#define d_BASE_INDEX_ERROR		0x8000000B
#define d_COM_ALREADY_OPEN      0x8000000C

#define d_MSession_NOT_READY	0x8000000C
#define d_ASession_NOT_READY	0x8000000D

#define d_CMD_ID_INCORRECT		0x80000015
#define d_HOST_ID_INCORRECT		0x80000016
#define d_READER_ID_INCORRECT	0x80000017
#define d_CBN_ERROR				0x80000018
#define d_UNKNOWN_PROTOCOL_MODE 0x80000019
#define d_SET_DATETIME_ERROR	0x8000001A
#define d_PENDING				0x80000020
#define d_TX_CANCEL				0x80000021

#define d_VW_RC_DATA							0xA0000001
#define d_VW_RC_SCHEME_SUPPORTED				0xA0000004
#define d_VW_RC_SIGNATURE						0xA0000005
#define d_VW_RC_SECOND_APPLICATION				0xA0000008
#define d_VW_RC_FAILURE							0xA00000FF
#define d_VW_RC_DDA_AUTH_FAILURE				0xA00000FA
#define d_VW_RC_INVALID_DATA					0xA00000F8
#define d_VW_RC_INVALID_PARAM					0xA00000F7
#define d_VW_RC_INVALID_SCHEME					0xA00000F5
#define d_VW_RC_INVALID_CA_KEY					0xA00000F4
#define d_VW_RC_MORE_CARDS						0xA00000F3
#define d_VW_RC_NO_CARD							0xA00000F2
#define d_VW_RC_NO_EMV_TAGS						0xA00000F1
#define d_VW_RC_CARD_DIFF_FROM_OTHER_AP_COUNTRY	0xA00000EE
#define d_VW_RC_US_CARDS						0xA00000ED
#define d_VW_RC_FALLBACK						0xA00000E9
#define d_VW_RC_EXCEED_CL_TX_LIMIT				0xA00000E8
#define d_VW_RC_NO_AP_FOUND						0xA00000E7
#define d_VW_RC_USE_CONTACT_ONLY				0xA00000E3

// AnalyzeTransaction : CVM Analysis
#define d_CVM_REQUIRED_NONE			0x00
#define d_CVM_REQUIRED_SIGNATURE	0x01
#define d_CVM_REQUIRED_ONLPIN		0x02
#define d_CVM_FAIL					0x03
#define d_CVM_REQUIRED_NOCVM		0x04

//For VW_Setdebug
#define d_DEBUG_PORT_USB    		0xFF
#define d_DEBUG_PORT_COM1   		d_COM1
#define d_DEBUG_PORT_COM2   		d_COM2
#define d_DEBUG_PORT_COM3   		d_COM3

//Scheme ID : Used for EMVCL_RC_DATA and EMVCL_RC_DATA_EX --> bSID
#define d_VW_SID_VISA_OLD_US					0x13
#define d_VW_SID_VISA_WAVE_2					0x16
#define d_VW_SID_VISA_WAVE_QVSDC				0x17
#define d_VW_SID_VISA_WAVE_MSD					0x18
#define d_VW_SID_PAYPASS_MAG_STRIPE				0x20
#define d_VW_SID_PAYPASS_MCHIP					0x21
#define d_VW_SID_JCB_WAVE_2						0x61
#define d_VW_SID_JCB_WAVE_QVSDC					0x62
#define d_VW_SID_AE_EMV							0x50
#define d_VW_SID_AE_MAG_STRIPE					0x52
#define d_VW_SID_DISCOVER						0x41


typedef struct {
	BYTE		bSID;				//Scheme Identifier
	BYTE		baDateTime[15];		//YYYYMMDDHHMMSS format
	BYTE		bTrack1Len;
	BYTE        baTrack1Data[100];	//ANS 
	BYTE		bTrack2Len;
	BYTE        baTrack2Data[100];	//ASCII
	BYTE        bChipDataLen;		//Chip Data
	BYTE        baChipData[256];
	BYTE        bAdditionalDataLen;	//Additional Data
	BYTE        baAdditionalData[256];
}RC_DATA;

typedef struct {
	BYTE		bSID;				//Scheme Identifier
	BYTE		baDateTime[15];		//YYYYMMDDHHMMSS format
	BYTE		bTrack1Len;
	BYTE        baTrack1Data[100];	//ANS 
	BYTE		bTrack2Len;
	BYTE        baTrack2Data[100];	//ASCII
	USHORT      usChipDataLen;		//Chip Data
	BYTE        baChipData[1024];
	USHORT      usAdditionalDataLen;	//Additional Data
	BYTE        baAdditionalData[1024];
}RC_DATA_EX;

typedef struct {
	USHORT		usTransResult;		// Transction Result
	BYTE		bCVMAnalysis;		//
	BYTE		baCVMResults[3];	//CVM Result
}RC_DATA_ANALYZE;

typedef struct {
	BYTE		bStatus;		//0x00: Success, 0x01: Error
	BYTE		bNoM;			//Number of Message
	BYTE        baMessage[20][80];
}STATUS_INFO;

typedef struct {
	BYTE		bAction;		//0x00: Key Addition, 0x01: Key Deletion
	BYTE		bIndex;			// Key Index
	UINT		uiModulusLen;	// Length of Modulus
	BYTE		baModulus[248];	// Modulus
	UINT		uiExponentLen;	// Length of Extension
	BYTE		baExponent[3];	// Extension
	BYTE		baHash[20]; 	// Key Hash (SHA-1) Result
}CA_PUBLIC_KEY;

typedef struct {
	UINT		uiNoP;			// Number of Parameters
	UINT		uiIndex[100];	// Parameter Index
	UINT		uiLen[100];		// Length of Parameter Data
	BYTE		baData[100][20];// Parameter Data
}PARAMETER_DATA;

typedef struct {
	BYTE		bNoS;			// Number of Schemes
	BYTE		baID[255];		// Scheme ID
	BYTE		baAction[255];	// Active or deactive
}SCHEME_DATA;

typedef struct {
	BYTE		bKeyType;		// Key Type
	BYTE		bKeyIndex;		// Key Index
	BYTE		baRND_R[8];		// Random Number R
	BYTE		baEnRND[16];	// Encrypted Random Number B & R
}AUTHKEY_DATA;					// baEnRND[0..7]: RND_B// baEnRND[8..15]: RND_R

typedef struct {
	BYTE		bNoMsg;				// Number of Message
	BYTE		baMsgID[30];		// Message ID
	BYTE		baMsgLen[30];		// Message ID length
	BYTE		baMsgData[30][80];	// Message Data
}MESSAGE_DATA;

typedef struct {
	BYTE		bNoCVM;			// Number of CVM
	BYTE		baCVMID[10];	// CVM ID
	BYTE		baAction[10];	// Active or deactive
}CVM_DATA;

typedef struct {
	BYTE		bCardType;			//Card Type
	USHORT		usTxResult;			//Transaction Result
	BYTE		bT1Len;				//Track 1 Length
	BYTE        baT1Data[256];		//Track 1 Data
	BYTE		bT2Len;				//Track 2 Length
	BYTE        baT2Data[256];		//Track 2 Data
	USHORT      usChipDataLen;		//Chip Data Length
	BYTE        baChipData[65536];	//Chip Data
}SALE_DATAOUT;

typedef struct {
	BYTE		baRID[5];			//RID
	BYTE		bCAPKI;				//CP Public Key Index
	BYTE		bModulusLen;		//Modulus Length
	BYTE		baModulus[248];		//Modulus
	BYTE		bExponentLen;		//Extension Length
	BYTE		baExponent[3];		//Extension
	BYTE		baHash[20]; 		//Key Hash (SHA-1) Result
}CAPK_DATA;
/*************** for API declaration *********************************/
void 	VW_DES(int iE_D,BYTE bKeyLen,BYTE *baKey,BYTE *baData,BYTE	*baOut);
ULONG	VW_InitComm(int iCom, ULONG uiBaudRate);
void	VW_CloseComm(int iCom);
ULONG	VW_Time_Out_Set(ULONG ulMS);
ULONG	VW_SetSenderIndex(UINT uiSIndex);
ULONG	VW_SetReceiverIndex(UINT uiRIndex);
ULONG 	VW_SetSessionKey(BYTE bKeyID,BYTE *baKeyData);
ULONG	VW_Set_Protocol(BYTE bMode);
void	VW_GetAPIVersion(char *cVer);
void	VW_SetDebug(BYTE fDebufEnable, BYTE bDebugPort);
//--POLL, Echo, Optimization Messages -----
ULONG 	VW_Poll(void);
ULONG 	VW_Echo(BYTE *baSBuf,UINT uiSLen,BYTE *baRBuf,UINT *uiRLen);
ULONG 	VW_SetMode(BYTE bMode);
ULONG 	VW_SetParameter(PARAMETER_DATA *stPara);
//--Authentication Messages--------------------
ULONG 	VW_InitializeCommunication(BYTE bKeyType,BYTE bKeyIndex,BYTE *baRNDB,AUTHKEY_DATA *stKeyData);
ULONG 	VW_MutualAuthenticate(AUTHKEY_DATA *stKeyData);
ULONG 	VW_GenerateKeys(AUTHKEY_DATA *stKeyData);
ULONG 	VW_InvalidReader(void);
//--Transaction Messages--------------------
ULONG	VW_StartTransaction(ULONG ulAmount,RC_DATA *stRCData);
ULONG 	VW_Reset(void);
ULONG	VW_CancelTransaction(void);
ULONG	VW_ShowStatus(BYTE *baBuf,UINT uiLen);
ULONG	VW_InitTransaction(ULONG ulAmount);
ULONG	VW_PollTransaction(RC_DATA *stRCData,ULONG ulMS);
ULONG	VW_InitTransactionEx(BYTE bTagNum, BYTE *baTransData, USHORT usTransDataLen);
ULONG	VW_PollTransactionEx(RC_DATA_EX *stRCDataEx,ULONG ulMS);
ULONG	VW_Complete(BYTE bAction,BYTE *baARC,UINT uiIADLen,BYTE *baIAD,UINT uiScriptLen,BYTE *baScript,RC_DATA *stRCData);
void	VW_AnalyzeTransaction(RC_DATA *stRCData, RC_DATA_ANALYZE *stRCDataAnalyze);
void	VW_AnalyzeTransactionEx(RC_DATA_EX *stRCData, RC_DATA_ANALYZE *stRCDataAnalyze);
ULONG	VW_UploadTransactionData(BYTE *baDOLData, BYTE bDOLLen, BYTE *baOut, USHORT *usOutLen);
//--Administative Messages--------------------
ULONG 	VW_SwitchToAdministrativeMode(BYTE bMode,BYTE *baBuf);
ULONG 	VW_SwitchToAdministrativeModeEx(BYTE bMode,BYTE *baBuf);
ULONG 	VW_GetCapability(SCHEME_DATA *stScheme);
ULONG 	VW_SetCapability(SCHEME_DATA *stScheme,SCHEME_DATA *stRsp);
ULONG 	VW_GetDateTime(BYTE *baDateTime);
ULONG 	VW_SetDateTime(BYTE *baDateTime);
ULONG 	VW_GetParameter(UINT uiPID,PARAMETER_DATA *stPara);
ULONG 	VW_GetCAPublicKey(BYTE bKID,CA_PUBLIC_KEY *stCAPubKey,BYTE *bNoK);
ULONG 	VW_SetCAPublicKey(CA_PUBLIC_KEY *stCAPubKey);
ULONG 	VW_GetBaudRate(BYTE *bBaudRateIndex);
ULONG 	VW_SetBaudRate(BYTE bBaudRateIndex);
ULONG 	VW_ResetAcquirerKey(BYTE bKeyType,BYTE bKeyIndex);
ULONG 	VW_ReaderRecovery(void);
ULONG 	VW_GetEMVTags(BYTE bTagNo,BYTE *baTagsData,UINT uiTagLen,BYTE *baRBuf,UINT *uiRLen);
ULONG 	VW_SetEMVTags(BYTE *baTagsData,UINT uiTagLen,BYTE *baRBuf,UINT *uiRLen);
ULONG 	VW_GetDisplayMessage(BYTE bMsgID,MESSAGE_DATA *stMessage);
ULONG 	VW_SetDisplayMessage(MESSAGE_DATA *stMessage,MESSAGE_DATA *stRsp);
ULONG 	VW_GetCVMCapability(BYTE bCVMID,CVM_DATA *stCVMData);
ULONG 	VW_SetCVMCapability(CVM_DATA *stCVMData,CVM_DATA *stRsp);
ULONG	VW_GetJCBPublicKey(BYTE bKID,CA_PUBLIC_KEY *stCAPubKey,BYTE *bNoK);
ULONG	VW_SetJCBPublicKey(CA_PUBLIC_KEY *stCAPubKey);
//--Security Functions----------------------
ULONG	CPP_GetReaderStatus(BYTE *bAuthState,BYTE *baRSN);
ULONG	CPP_InitAuthen(BYTE *baTRN,BYTE *bKeyVer,BYTE *baRRN,BYTE *baRCrypto);
ULONG	CPP_MutualAuthen(BYTE *baAuthenKey,BYTE *baTCrypto);
ULONG	CPP_InjectKey(BYTE bKeyVer,BYTE *baKeyValue,BYTE *baCheckCode);
//--Transaction Functions--------------------
ULONG	CPP_Sale(ULONG ulAmount,SALE_DATAOUT *stRspData);
ULONG	CPP_InitSale(ULONG ulAmount);
ULONG	CPP_PollSale(SALE_DATAOUT *stRspData,ULONG ulMS);
ULONG	CPP_Cancel(void);
ULONG	CPP_DisplayMessage(BYTE *baMsgID,BYTE bMsgIDLen);
//--Setting Functions------------------------
ULONG	CPP_SetReaderSN(BYTE *baRSN);
ULONG	CPP_SetTags(BYTE bTagNum,BYTE *baTagData,UINT uiDLen);
ULONG	CPP_GetTags(BYTE *bTagNum,BYTE *baTagData,UINT *uiDLen);
ULONG	CPP_SetCAPK(CAPK_DATA *stCAPKData);
ULONG	CPP_ListCAPKID(BYTE *bCAPKNum,BYTE *baCAPKList,UINT *uiRLen);
ULONG	CPP_SetMessage(BYTE bMsgNum,BYTE *baMsgData,UINT uiDLen);
ULONG	CPP_GetMessage(BYTE *bMsgNum,BYTE *baMsgData,UINT *uiDLen);
ULONG	CPP_SetParameters(BYTE bParamNum,BYTE *baParamData,UINT uiDLen);
ULONG	CPP_GetParameters(BYTE *bParamNum,BYTE *baParamData,UINT *uiDLen);
ULONG	CPP_SetRTC(BYTE *baDateTime);
ULONG	CPP_GetRTC(BYTE *baDateTime);
ULONG	CPP_SetBaudrate(ULONG ulBaudrate);
//--Proprietary Messages--------------------
ULONG 	VW_Display(BYTE bFlag,BYTE bX,BYTE bY,BYTE *baMsgBuf,UINT uiSLen);
ULONG 	VW_Sound(USHORT usFreq,USHORT usDuration);
ULONG 	VW_SetLCDBackLight(BYTE bOnOff);
ULONG 	VW_SetLED(BYTE bIndex,BYTE bOnOff);
ULONG	VW_SetLEDTwinkle(BYTE bIndex,BYTE bOnOff,BYTE bBackLight,BYTE bBuzzer,USHORT usFreq,USHORT usDuration,BYTE *baMsgBuf,UINT uiSLen);
ULONG	VW_SetPowerModeParm(BOOL fAuto, ULONG ulAutoOffTime, BOOL fLEDOn);
ULONG   VW_GetPowerModeParm(BOOL * fAuto, ULONG * ulAutoOffTime, BOOL * fLEDOn);
ULONG   VW_PowerMode(BYTE bMode);
ULONG 	VW_SetCAPK(BYTE *baRID,CA_PUBLIC_KEY *stCAPubKey);
ULONG 	VW_GetCAPK(BYTE *baRID,BYTE bKID,CA_PUBLIC_KEY *stCAPubKey);
ULONG 	VW_ListAllCAPKID(BYTE *baRBuf,UINT *uiRLen);
ULONG	VW_GetDongleAPVersion(BYTE *baRdrType,BYTE *bRLen);
ULONG	VW_SetASCIIVerticalOffset(BYTE bDirection,BYTE bOffset);
ULONG	VW_SetASCIIHorizontalOffset(BYTE bDirection,BYTE bOffset);
ULONG	VW_RemoveTags(BYTE *baRemoveTags, USHORT usRemoveTagsLen);
//--V5 CL Command--------------------
ULONG	VW_InitTransactionV5CL(ULONG ulAmount, BYTE *baDateTime, BYTE *baRN);
ULONG   VW_PollTransactionV5CL(RC_DATA *stRCData,ULONG ulMS);
ULONG	CPP_InitSaleV5CL(ULONG ulAmount, BYTE *baDateTime, BYTE *baRN);
ULONG 	VW_SelectSpecificAID(ULONG ulAmount,BYTE *baAID, BYTE *baRceiveBuf, ULONG *ulRecBufLen);
ULONG   VW_DetectTransaction(ULONG ulAmount, BYTE *baAID, BYTE *bAIDLen, BYTE *baFCIData, ULONG *ulFCIDataLen, BYTE *baPSE_FCI, ULONG *ulPSE_FCILen);


#ifdef __cplusplus
}
#endif

#endif

