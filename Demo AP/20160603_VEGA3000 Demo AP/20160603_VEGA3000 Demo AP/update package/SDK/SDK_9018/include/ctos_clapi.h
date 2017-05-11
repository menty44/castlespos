#ifndef __CTOS_CLAPI_H__

#ifdef __cplusplus
extern "C"
{
#endif

// Comm Channel baudrate definition
#define d_COMM_DEFAULT_BAUDRATE					38400

// Type definition
#define d_CL_TYPE_A						0
#define d_CL_TYPE_B						1
#define d_CL_TYPE_C						2
 
// AntennaParam baudrate definition
#define d_CL_BR_106						0
#define d_CL_BR_212						1
#define d_CL_BR_424						2
#define d_CL_BR_848						3

// FSDI definition
#define d_CL_FSDI_16						0
#define d_CL_FSDI_24						1
#define d_CL_FSDI_32						2
#define d_CL_FSDI_40						3
#define d_CL_FSDI_48						4
#define d_CL_FSDI_64						5
#define d_CL_FSDI_96						6
#define d_CL_FSDI_128						7
#define d_CL_FSDI_256						8
#define d_CL_DFT_FSDI						8
#define d_CL_MAX_FSDI						8

// NumSlot definition
#define d_CL_NUMSLOT_x1						0x00
#define d_CL_NUMSLOT_x2						0x01
#define d_CL_NUMSLOT_x4						0x02
#define d_CL_NUMSLOT_x8						0x03
#define d_CL_NUMSLOT_x16					0x04

// MaxRate definition
#define d_CL_MAXRATE_106					106
#define d_CL_MAXRATE_212					212
#define d_CL_MAXRATE_424					424
#define d_CL_MAXRATE_848					848

// Power status definition 
#define d_CL_POWER_STATUS_OFF					0
#define d_CL_POWER_STATUS_ON					1

// value for LED Index
#define d_CL_LED_RED					0x01
#define d_CL_LED_GREEN					0x02
#define d_CL_LED_YELLOW					0x04
#define d_CL_LED_BLUE					0x08
#define d_CL_LED_EXT_RED				0x10
#define d_CL_LED_EXT_GREEN				0x20			
#define d_CL_LED_EXT_BLUE				0x40

//------------------------------------------------------------------------------------------------
// CL Open/Close Comm Channel
USHORT CTOS_CLInitComm(ULONG uiBaudRate);
void   CTOS_CLCloseComm(void);

// CL General
USHORT CTOS_CLInit(void);
USHORT CTOS_CLPowerOn(void); 
USHORT CTOS_CLPowerOff(void); 
USHORT CTOS_CLVerGet(ULONG* ulVer);
USHORT CTOS_CLSetBaudrate(UCHAR bIsTypeA,UCHAR bTxBR,UCHAR bRxBR);
USHORT CTOS_ReadRC(UCHAR bAddr,UCHAR* bValue);
USHORT CTOS_WriteRC(UCHAR bAddr,UCHAR bValue);  
USHORT CTOS_CLPowerStatus(BYTE *bStatus);
USHORT CTOS_CLSetPowerModeParm(BOOL fAuto, ULONG ulAutoOffTime,BOOL fLEDOn);
USHORT CTOS_CLGetPowerModeParm(BOOL *fAuto, ULONG *ulAutoOffTime,BOOL *fLEDOn);

// ISO14443-3 Type A
USHORT CTOS_REQA(UCHAR* baATQA);
USHORT CTOS_WUPA(UCHAR* baATQA);
USHORT CTOS_ANTIA(UCHAR bSelCode,UCHAR* baSNR,UCHAR bCnt);
USHORT CTOS_SELECTA(UCHAR bSelCode,UCHAR* baSNR,UCHAR* bSAK);
USHORT CTOS_CLTypeAHalt(void);
USHORT CTOS_CLTypeAActiveFromIdle(BYTE bBaudRate,BYTE* baATQA,BYTE *bSAK,BYTE* baCSN,BYTE* bCSNLen);
USHORT CTOS_CLTypeAActiveFromHalt(BYTE bBaudRate,BYTE* baATQA,BYTE *bSAK,BYTE* baCSN,BYTE bCSNLen);

// RC531 specific function
USHORT CTOS_MifareREADE2(UCHAR bAddrMSB,UCHAR bAddrLSB,UCHAR bNumByte,UCHAR* baBuf); 
USHORT CTOS_MifareWRITEE2(UCHAR bAddrMSB,UCHAR bAddrLSB,UCHAR bNumByte,UCHAR* baBuf);
USHORT CTOS_MifareLOADKEYE2(UCHAR bAddrMSB,UCHAR bAddrLSB);

// Mifare function
USHORT CTOS_MifareLOADKEY(UCHAR* baKey);
USHORT CTOS_MifareAUTHEx(UCHAR baKeyType,UCHAR bBlockNr,UCHAR* baCardSN,UCHAR bCardSNLen); 
USHORT CTOS_MifareAUTH2Ex(UCHAR baKeyType,UCHAR bBlockNr,UCHAR* baKey,UCHAR* baCardSN,UCHAR bCardSNLen);
USHORT CTOS_MifareREADBLOCK(UCHAR bBlockNr,UCHAR* baBuf);
USHORT CTOS_MifareWRITEBLOCK(UCHAR bBlockNr,UCHAR* baBuf);
USHORT CTOS_MifareINCREASE(UCHAR bBlockNr,UCHAR* bValue); 
USHORT CTOS_MifareDECREASE(UCHAR bBlockNr,UCHAR* bValue);
USHORT CTOS_MifareRESTORE(UCHAR bBlockNr); 
USHORT CTOS_MifareTRANSFER(UCHAR bBlockNr);

// ISO14443-3 Type B
USHORT CTOS_REQB(UCHAR bAFI,UCHAR* baATQB,UCHAR* bATQBLen); 
USHORT CTOS_WUPB(UCHAR bAFI,UCHAR* baATQB,UCHAR* bATQBLen);
USHORT CTOS_ATTRIB(UCHAR* baPUPI,UCHAR* bRep);  
USHORT CTOS_HALTB(BYTE *baPUPI);
USHORT CTOS_CLTypeBActive(BYTE* baPUPI); 
USHORT CTOS_CLTypeBActiveEx(BYTE* baPUPI,UCHAR bAFI,BOOL fWUPB,UCHAR bFSDI,UCHAR bNumAntiColSlot,USHORT usMaxRate);

// ISO14443-4 T=CL
USHORT CTOS_CLRATS(BYTE bAutoBR,BYTE* baATS,USHORT* bATSLen); 
USHORT CTOS_CLRATSEx(BYTE bAutoBR, BYTE* baATS, USHORT* bATSLen, USHORT usMaxRate, BYTE bFSDI);
USHORT CTOS_CLAPDU(BYTE* baSBuf,USHORT usSLen,BYTE* baRBuf,USHORT* usRLen);
USHORT CTOS_CLDESELECT(void);
USHORT CTOS_CLNAKPOLL(void);

// Transparent CL Access
USHORT CTOS_TclTransparent(BYTE* baSBuf,USHORT usSLen,BYTE* baRBuf,USHORT* usRLen);  
USHORT CTOS_TclTransparentEx(BYTE* baSBuf,USHORT usSLen,BYTE* baRBuf,USHORT* usRLen,BOOL fTxCrcEnable,BOOL fRxCrcEnable);  
USHORT CTOS_TclSetTimeout(ULONG ulTimeout);

// ISO18092 Felica
USHORT CTOS_FelicaPolling(UCHAR* IDm, UCHAR* PMm);
// ulTimeout is in T=256x16/fc basis (0.302ms)
// TxBuf : Length + Payload
// RxBuf : Length + Payload
USHORT CTOS_FelicaReadWrite(UCHAR* TxBuf,USHORT TxLen,UCHAR* RxBuf,USHORT* RxLen,USHORT ulTimeout);

// Peripheral
USHORT CTOS_CLLEDSet(BYTE bmIndex,BYTE bOnOff);
USHORT CTOS_CLSound(USHORT usFreq,USHORT usDuration);

#ifdef __cplusplus
}
#endif


#endif
