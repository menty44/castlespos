/********************************************************************
Copyright (c) Castles Technology Co., Ltd. 2003-2005

Module Name:
	ctosapi.h

Abstract:

Created:
	2005/11/25

Author:
	Peril Chen

Revision History:

*********************************************************************/
#ifndef __CTOS_API_H__
#define __CTOS_API_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "typedef.h"
#include "ctoserr.h"

#define IN
#define OUT
#define INOUT

#define d_TRUE						1
#define d_FALSE						0

#define d_ON						1
#define d_OFF						0

//=============================================================================================================================
//
// System Functions
//
//=============================================================================================================================
#define ID_BOOTSULD					0
#define ID_CRYPTO_HAL				1
#define ID_LINUX_KERNEL				3
#define ID_SECURITY_KO				4
#define ID_SYSUPD_KO				5
#define ID_KMS                      6       //NEW ID ID_KMS
#define ID_CADRV_KO					7
#define ID_CAUSB_KO					8
#define ID_LIBCAUART_SO				9
#define ID_LIBCAUSBH_SO				10
#define ID_LIBCAMODEM_SO			11
#define ID_LIBCAETHERNET_SO			12
#define ID_LIBCAFONT_SO				13
#define ID_LIBCALCD_SO				14
#define ID_LIBCAPRT_SO				15
#define ID_LIBCARTC_SO				16
#define ID_LIBCAULDPM_SO   			17
#define ID_LIBCAPMODEM_SO   		18
#define ID_LIBCAGSM_SO   			19
#define ID_LIBCAEMVL2_SO   			20
#define ID_LIBCAKMS_SO    			21
#define ID_LIBCAFS_SO    			22
#define ID_LIBCABARCODE_SO    		23
#define ID_CRADLE_MP	    		24 //for Cradle-Base Main-program
#define ID_LIBTLS_SO				25
#define ID_LIBCLVW_SO				26
#define ID_LIBCTOSAPI_SO			27
#define ID_SAM_KO          		    28      //NEW ID ID_SAM_KO
#define ID_CLVWM_MP					29
#define ID_ROOTFS					30
#define ID_BIOS						31
#define ID_CIF_KO                   32
#define ID_CLDRV_KO                 33
#define ID_TMS                      34
#define ID_ULDPM                    35
#define ID_SC_KO                    36
#define ID_MAXIMUM					36 // Maximum ID number of object files

//Certification
#define ID_CERT_PEDST				80
//Contactless librarys
#define ID_EXTLIBCACLMDL_SO                        100     //contactless middleware kernel
#define ID_EXTLIBCACLENTRY_SO                      101     //contactless entrypoint kernel
#define ID_EXTLIBCAMPP_SO                          102     //contactless mastercard paypass kernel
#define ID_EXTLIBCAVPW_SO                          103     //contactless visa paywave kernel
#define ID_EXTLIBCAAEP_SO                          104     //contactless amex expresspay
#define ID_EXTLIBCAJCT_SO                          105     //contactless jcb contactless terminal
#define ID_EXTLIBCAVAP_SO                          106     //contactless visa asia pacific
#define ID_EXTLIBCAIFH_SO                          108     //contactless interac flash


//Contact EMV-Level-2 librarys
#define ID_EXTLIBCAEMVL2_SO                        110     //contact EMV-L2 kernel
#define ID_EXTLIBCAEMVL2AP_SO                      111     //contact EMV AP library based on EMV-L2 kernel

//PCIPAD
#define ID_EXTLIBCAPCIPAD_SO                       112     //command set to control pcipad

//REDIRECT
#define ID_EXTLIBCAREDIECT_SO                      113     //redirect fun/api to externel device

//BT interface
#define ID_EXTLIBCABLUETOOTH_SO                    120     //Bluetooth interface


// Hw Settings
#define d_MK_HW_MODEM       0x0001
#define d_MK_HW_ETHERNET    0x0002
#define d_MK_HW_GPRS        0x0004
#define d_MK_HW_CONTACTLESS 0x0008
#define d_MK_HW_ZIGBEE      0x0010
#define d_MK_HW_WIFI		0x0020
#define d_MK_HW_BT		0x0040

//Device Mode
#define d_MODEL_VEGA9000	1
#define d_MODEL_VEGA7000	2
#define d_MODEL_VEGA5000	3
#define d_MODEL_VEGA5000S	4
#define d_MODEL_VEGA3000	5
#define d_MODEL_VEGA3000P	6
#define d_MODEL_QPAD		7
#define d_MODEL_MP200		8
#define d_MODEL_TR220		100
#define d_MODEL_PPC930		101
#define d_MODEL_CRT1000		102
#define d_MODEL_MPIN10		103
#define d_MODEL_TR300		104
#define d_MODEL_MP20		105

USHORT CTOS_GetSerialNumber(BYTE baBuf[16]);
USHORT CTOS_GetSystemInfo(BYTE bID, BYTE baBuf[17]);
USHORT CTOS_GetKeyHash(BYTE bKeyIndex, BYTE* baHash);
USHORT CTOS_HWSettingGet(BOOL* fPortable,BOOL* fPCI,USHORT* mkHWSupport);
USHORT CTOS_DeviceModelGet(BYTE *bModel);
USHORT CTOS_NVMWriteData(USHORT usOffset, BYTE *baBuffer, USHORT usBufferLength);
USHORT CTOS_NVMReadData(USHORT usOffset, BYTE *baBuffer, USHORT usBufferLength);

//System Wait Event
#define d_EVENT_KBD						0x00000001
#define d_EVENT_SC						0x00000002
#define d_EVENT_MSR						0x00000004
#define d_EVENT_MODEM					0x00000008
#define d_EVENT_ETHERNET				0x00000010
#define d_EVENT_COM1					0x00000020
#define d_EVENT_COM2					0x00000040
#define d_TIME_INFINITE					0xFFFFFFFF

USHORT CTOS_APGetLastStatus (DWORD *dwStatus);

// PED Life Cycle
#define d_PED_LIFE_CYCLE_NOT_INITIALIZE 												1
#define d_PED_LIFE_CYCLE_INITIALIZED 														2
#define d_PED_LIFE_CYCLE_PERSONALIZED 													3

USHORT CTOS_SystemGetLifeCycle (OUT BYTE * pbLifeCycle);

//=============================================================================================================================
//
// LED & Back Light Functions
//
//=============================================================================================================================

//LED  parameter
#define d_LED1						0	// => RED
#define d_LED2						1	// => GREEN
#define d_LED3						2	// => ORANGE
#define d_LED4						3	// => BLUE

#define d_LED_RED					0
#define d_LED_GREEN					1
#define d_LED_ORANG					2
#define d_LED_BLUE					3

// Back Light parameter
#define d_BKLIT_LCD					0
#define d_BKLIT_KBD					1
#define d_BKLIT_LCD_DEVICE_0		d_BKLIT_LCD
#define d_BKLIT_LCD_DEVICE_1		2

USHORT CTOS_LEDSet(BYTE bLED, BYTE bOnOff);
USHORT CTOS_BackLightSet (BYTE bDevice, BYTE bOnOff);
USHORT CTOS_BackLightSetEx(BYTE bDevice, BYTE bOnOff, DWORD dwDuration);
USHORT CTOS_BackLightAutoOff( BOOL fEnable, USHORT usTimeout);
USHORT CTOS_BackLightSetBrightness(BYTE bDevice,BYTE bValue);

//=============================================================================================================================
//
// Clock and Time Functions
//
//=============================================================================================================================

// Real Time Clock define for RTC functions
typedef struct
{
	BYTE    bSecond;
	BYTE    bMinute;
	BYTE    bHour;
	BYTE    bDay;
	BYTE    bMonth;
	BYTE    bYear;
	BYTE    bDoW;
} CTOS_RTC;

#define d_RTC_TZ_GMT    0   ///Greenwich Mean Time
#define d_RTC_TZ_ECT    1   ///European Central Time
#define d_RTC_TZ_EET    2   ///Eastern European Time
#define d_RTC_TZ_ART    3   ///(Arabic)Egypt Standard Time
#define d_RTC_TZ_EAT    4   ///Eastern African Time

#define d_RTC_TZ_MET    5   ///Middle East Time
#define d_RTC_TZ_NET    6   ///Near East Time
#define d_RTC_TZ_PLT    7   ///Pakistan Lahore Time
#define d_RTC_TZ_IST    8   ///India Standard Time
#define d_RTC_TZ_BST    9   ///Bangladesh Standard Time

#define d_RTC_TZ_VST    10  ///Vietnam Standard Time
#define d_RTC_TZ_CTT    11  ///China Taiwan Time
#define d_RTC_TZ_JST    12  ///Japan Standard Time
#define d_RTC_TZ_ACT    13  ///Australia Central Time
#define d_RTC_TZ_AET    14  ///Australia Eastern Time

#define d_RTC_TZ_SST    15  ///Solomon Standard Time
#define d_RTC_TZ_NST    16  ///New Zealand Standard Time
#define d_RTC_TZ_MIT    17  ///Midway Islands Time
#define d_RTC_TZ_HST    18  ///Hawaii Standard Time
#define d_RTC_TZ_AST    19  ///Alaska Standard Time

#define d_RTC_TZ_PST    20  ///Pacific Standard Time
#define d_RTC_TZ_PNT    21  ///Phoenix Standard Time
#define d_RTC_TZ_MST    22  ///Mountain Standard Time
#define d_RTC_TZ_CST    23  ///Central Standard Time
#define d_RTC_TZ_EST    24  ///Eastern Standard Time

#define d_RTC_TZ_IET    25  ///Indiana Eastern Standard Time
#define d_RTC_TZ_PRT    26  ///Puerto Rico and US Virgin Islands Time
#define d_RTC_TZ_CNT    27  ///Canada Newfoundland Time
#define d_RTC_TZ_AGT    28  ///Argentina Standard Time
#define d_RTC_TZ_BET    29  ///Brazil Eastern Time

#define d_RTC_TZ_CAT    30  ///Central African Time
#define d_RTC_TZ_TOTAL_COUNT    31   ///Total Time Zone count
//Time parameter
#define TIMER_ID_1		0
#define TIMER_ID_2		1
#define TIMER_ID_3		2
#define TIMER_ID_4		3

USHORT CTOS_RTCGet (CTOS_RTC *pstRTC);
USHORT CTOS_RTCSet (CTOS_RTC *pstRTC);
void CTOS_Delay(ULONG ulMSec); // in 1 ms
ULONG CTOS_TickGet(void); // in 10 ms
USHORT CTOS_TimeOutSet(BYTE bTID, ULONG ulMSec); // in 10 ms
USHORT CTOS_TimeOutCheck(BYTE bTID);
USHORT CTOS_RTCSetTimeZone(BYTE bTimeZone);

//=============================================================================================================================
//
// Buzzer Functions
//
//=============================================================================================================================

// Key Frequence
#define C_KEY 						264
#define D_KEY 						297
#define E_KEY 						330
#define F_KEY 						352
#define G_KEY 						396
#define A_KEY 						440
#define B_KEY						495
#define C2_KEY 						528


USHORT CTOS_Beep(void);
USHORT CTOS_Sound(USHORT usFreq, USHORT usDuration); // in 10 ms

//=============================================================================================================================
//
// Encryption/Decryption Functions
//
//=============================================================================================================================

#define d_ENCRYPTION				0
#define	d_DECRYPTION				1

typedef struct
{
	unsigned long Message_Digest[5];	/* Message Digest (output)          */

	unsigned long Length_Low;					/* Message length in bits           */
	unsigned long Length_High;				/* Message length in bits           */

	unsigned char Message_Block[64];	/* 512-bit message blocks      			*/
	int Message_Block_Index;    			/* Index into message block array   */

	int Computed; 										/* Is the digest computed?          */
	int Corrupted;										/* Is the message digest corruped?  */
}SHA_CTX;

typedef struct
{
	unsigned int tot_len;
	unsigned int len;
	unsigned char block[2 * 64];
	ULONG h[8];
}CTOS_SHA256_CTX;

typedef struct
{
	IN BYTE Version;

	IN USHORT bits;

	OUT USHORT m_len;
	OUT BYTE *m;
	OUT USHORT d_len;
	OUT BYTE *d;
	IN 	USHORT e_len;
	IN 	BYTE *e;

}CTOS_RSA_KEY_GEN;


USHORT CTOS_RSA(BYTE *baModulus, USHORT usModulousLen, BYTE *baExponent, USHORT usExponentLen, BYTE *baData, BYTE *baResult);
USHORT CTOS_RSAKeyGenerate(CTOS_RSA_KEY_GEN *para);
USHORT CTOS_RNG(BYTE *baResult);
USHORT CTOS_DES (BYTE bEncDec, BYTE *baKey, BYTE bKeyLen, BYTE *baData, USHORT usDataLen, BYTE *baResult);
void CTOS_SHA1Init (SHA_CTX *pstInfo);
void CTOS_SHA1Update (SHA_CTX *pstInfo, BYTE *baBuffer, USHORT usCount);
void CTOS_SHA1Final (BYTE *baOutput, SHA_CTX *pstInfo);
USHORT CTOS_AES (BYTE bEncDec, BYTE *baKey, BYTE *baData, USHORT usDataLen, BYTE *baResult);
USHORT CTOS_MAC (BYTE *baKey, BYTE bKeyLen, BYTE *baICV, BYTE *baData, USHORT usDataLen, BYTE *baMAC);
USHORT CTOS_DES_CBC(BYTE bEncDec, BYTE *baKey, BYTE bKeyLen, BYTE *baICV, BYTE *baData, USHORT usDataLen, BYTE *baResult);
void CTOS_SHA256Init(CTOS_SHA256_CTX *ctx);
void CTOS_SHA256Update(CTOS_SHA256_CTX *ctx, const BYTE *message, UINT len);
void CTOS_SHA256Final(CTOS_SHA256_CTX *ctx, BYTE *digest);
//=============================================================================================================================
//
// KMS Functions
//
//=============================================================================================================================

// Key Flag/Attribute
#define d_KEY_FLAG_PIN    			0x01
#define d_KEY_FLAG_ENC    			0x02
#define d_KEY_FLAG_MAC    			0x04
#define d_KEY_FLAG_DECRYPT   		0x10
#define d_KEY_FLAG_SK_ENCRYPT   	0x40
#define d_KEY_FLAG_INTERMEDIATE   0x80

// MAC Mode
#define MAC_MODE_CBC				0x00	// 3DES CBC
#define MAC_MODE_X9_19				0x01	// Retail MAC, done in one call
#define MAC_MODE_X9_19_START		0x02	// Start for Retail MAC. Retail MAC is done in three or more calls
#define MAC_MODE_X9_19_UPDATE		0x03	// Continue for Retail MAC. Retail MAC is done in three or more calls
#define MAC_MODE_X9_19_FINAL		0x04	// End for Retail MAC. Retail MAC is done in three or more calls

// PIN Encryption Mode
#define d_PIN_ENC_MODE_DES     											1
#define d_PIN_ENC_MODE_TDES    											2
#define d_PIN_ENC_MODE_DUKPT   											3
#define d_PIN_ENC_MODE_TDUKPT											4
#define d_PIN_ENC_MODE_ISBAN_REVERSIBLE_PIN_4B_MODE						5
#define d_PIN_ENC_MODE_ISBAN_IRREVERSIBLE_PIN_4B_MODE					6

// UpdateKey Mode
#define MODE_UPDATE_KEY_OEN_ECB		0x00
#define MODE_UPDATE_KEY_OEN_CBC		0x01

// Index for Intermediate Key
#define d_INTERMEDIATE_KEY_0_INDEX				0xF0
#define d_INTERMEDIATE_KEY_1_INDEX				0xF1
#define d_INTERMEDIATE_KEY_2_INDEX				0xF2
#define d_INTERMEDIATE_KEY_3_INDEX				0xF3
#define d_INTERMEDIATE_KEY_4_INDEX				0xF4
#define d_INTERMEDIATE_KEY_5_INDEX				0xF5
#define d_INTERMEDIATE_KEY_6_INDEX				0xF6
#define d_INTERMEDIATE_KEY_7_INDEX				0xF7

// Operation for Intermediate Key
#define d_INTERMEDIATE_KEYGEN_OP_XOR				0
#define d_INTERMEDIATE_KEYGEN_OP_DES_ENCRYPT		1
#define d_INTERMEDIATE_KEYGEN_OP_DES_DECRYPT		2
#define d_INTERMEDIATE_KEYGEN_OP_TAKE_LEFT		3
#define d_INTERMEDIATE_KEYGEN_OP_TAKE_RIGHT		4
#define d_INTERMEDIATE_KEYGEN_OP_COMBINE		5

typedef struct{
	BYTE EncMode;
	WORD TimeOut;
	BYTE MaxLEN;
	BYTE MinLEN;
	BYTE MK_Index;
	BYTE LenPAN;
	BYTE *sPAN;
	BYTE LenSK;
	BYTE *sSK;
	BYTE *sLine1Msg;
	BYTE *sLine2Msg;
	BYTE *sProcMsg;
	BYTE NULLPIN;
	BYTE LenPIN;
	BYTE *sEPB;
	BYTE *sKSN;
	BYTE PBType;
	int (*piTestCancel)(void);
} CTOS_stDefEncPINStruc;

typedef struct{
	WORD StructureSize; // this field included as well
	BYTE EncMode;
	WORD TimeOut;
	BYTE MaxLEN;
	BYTE MinLEN;
	BYTE MK_Index;
	BYTE LenPAN;
	BYTE *sPAN;
	BYTE LenSK;
	BYTE *sSK;
	STR *sLine1Msg;
	STR *sLine2Msg;
	STR *sProcMsg;
	BYTE NULLPIN;
	BYTE LenPIN;
	BYTE *sEPB;
	BYTE *sKSN;
	int (*piTestCancel)(void);
	BYTE AsteriskPositionX;
	BYTE AsteriskPositionY;
	BYTE isRightJustified;
} CTOS_stDefEncPINStrucEx2;

#define d_KMS_KBD_EVENT_NUM_DIGITAL								0x01
#define d_KMS_KBD_EVENT_CLEAR									0x02
#define d_KMS_KBD_EVENT_ENTER									0x03
#define d_KMS_KBD_EVENT_CANCEL									0x04
#define d_KMS_KBD_EVENT_NUM_DIGITAL_LEN_OVERFLOW 				0x05
#define d_KMS_KBD_EVENT_CLEAR_WITH_NO_DIGITAL					0x06
#define d_KMS_KBD_EVENT_NULL_PIN 								0x07
#define d_KMS_KBD_EVENT_ENTER_WITH_NUM_DIGITAL_LEN_UNDERFLOW	0x08

typedef struct{
	IN WORD Version; // Structure version, should be 0x0000 or 0x0001

	struct
	{
		IN BYTE EncMode;
		IN BYTE MaxLEN;
		IN BYTE MinLEN;
	}PIN_Info;

	struct
	{
		IN BYTE MK_Index;

		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE LenSK;
		IN BYTE *sSK;
	}Protection;

	struct
	{
		// This is used for PAN.
		// This is used for terminal pseudo random if EncMode is d_PIN_ENC_MODE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if EncMode is d_PIN_ENC_MODE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;
	}AdditionalData;

	struct
	{
		OUT BYTE LenPIN;	// Output actual PIN digital len.
		OUT	BYTE* sEPB;
		OUT BYTE* sKSN;
	}Output;

	struct
	{
		IN WORD TimeOut;
		IN BYTE NULLPIN;
		IN int (*piTestCancel)(void);
		IN void (*pKBDEvent)(BYTE Event);
	}Control;

} CTOS_stDefEncPINStrucExtension;

typedef struct{
	WORD TimeOut;
	BYTE MaxLEN;
	BYTE MinLEN;
	STR *sLine1Msg;
	STR *sLine2Msg;
	STR *sProcMsg;
	BYTE NULLPIN;
	BYTE LenPIN;
	int (*piTestCancel)(void);
	BYTE AsteriskPositionX;
	BYTE AsteriskPositionY;
	BYTE isRightJustified;
} CTOS_stDefEncOffPINStruc;

typedef struct{
	BYTE *baData;
	BYTE bMK_Index;
	BYTE bLenSK;
	BYTE *baSK;
	BYTE *baEDB;
} CTOS_stDefEncDataStruc;

typedef struct{

	// Structure Version, Should be 0x0000 or 0x0001
	DWORD ulVersion;

	// Encryption Mode: d_DATA_ENC_MODE_ECB, d_DATA_ENC_MODE_CBC_PADDING_ZERO
	BYTE bEncMode;

	// MK Index
	BYTE bMKIndex;

	// Length of Session Key
	BYTE bLenSK;

	// Session Key which encrypted by MK
	BYTE *baSK;

	// Length of baICV
	BYTE bLenICV;

	// ICV for CBC Mode
	BYTE *baICV;

	// Input Length
	USHORT usInLen;

	// Input Data
	BYTE *baInData;

	// Output Length
	USHORT usOutLen;

	// Output Data
	BYTE *baOutData;

	// Output KSN for DUKPT/3DUKPT
	BYTE *baKSN;

} CTOS_stDefEncDataExStruc;

typedef struct{
	WORD iMLen;
	BYTE bELen;
	BYTE *baM;
	BYTE *baD;
	BYTE *baE;
} CTOS_stDefRSACertKey;

typedef struct{
	BYTE bMode;
	BYTE bMK_Index;
	BYTE bLenSK;
	BYTE *baSK;
	BYTE *baICV;
	USHORT usDataLen;
	BYTE *baData;
	BYTE *baMAC;
} CTOS_stDefMACStruc;

typedef struct{
    BYTE bKBPK_Index;
    USHORT usDataLen;
    BYTE *baData;
} CTOS_stDefTR31Struc;

typedef struct
{
    BYTE bMK_Index;
    BYTE bKey_Flag;
    BYTE *sComp1;
    BYTE *sComp2;
    BYTE *sComp3;
    BYTE *sCV;
} CTOS_stSaveDESMK16;

typedef struct
{
    BYTE bMK_Index;
    BYTE bKey_Flag;
    BYTE *sComp1;
    BYTE *sComp2;
    BYTE *sCV;
} CTOS_stSaveDESMK32;

typedef struct
{
    BYTE bMK_Index;
    BYTE bKey_Flag;
    BYTE *sComp1;
    BYTE *sComp2;
    BYTE *sCV;
} CTOS_stSaveDESMK48;

typedef struct
{
	BYTE bMK_Index;
	BYTE bKey_Flag;
    BYTE *sIK;
    BYTE *sKSN;
} CTOS_stSaveDUKPTIK;

typedef struct {
   BYTE bKeyType;
   BYTE bMKIndex;
   BYTE bC1Len;
   BYTE *baC1;
   BYTE bC2Len;
   BYTE *baC2;
   BYTE bC3Len;
   BYTE *baC3;
   BYTE bC4Len;
   BYTE *baC4;
}CTOS_stGenKeyCertifyed;

typedef struct
{
	BYTE Index;
	BYTE RFU;
	BYTE KeyLen;
	BYTE CVLen;
    BYTE *sComp1;
    BYTE *sComp2;
    BYTE *sComp3;
    BYTE *sCV;
}SAVE_KPK;

typedef struct
{
	BYTE MK_Index;
	BYTE KeyFlag;
    BYTE MK_KeyLen;
    BYTE KPK_Index;
    BYTE *EMK;
    BYTE *sCV;
    BYTE CVLen;
    BYTE RFU[3];
}SAVE_MK_BY_KPK;

// Protection Mode
#define KMS_KEYPROTECTIONMODE_KPK_ECB			0x00
#define KMS_KEYPROTECTIONMODE_KPK_CBC			0x01

// Verification Method
#define KMS_KEYVERIFICATIONMETHOD_DEFAULT		0x00

typedef struct
{
	IN BYTE Version;

	struct
	{
		IN BYTE MK_Index;
		IN BYTE KeyFlag;

	}Info;

	struct
	{
		IN BYTE Mode;
		IN BYTE KPK_Index;
		struct
		{
			// This is used as ICV for CBC mode
			IN USHORT Length;
			IN BYTE* pData;
		}AdditionalData;

	}Protection;

	struct
	{
		IN BYTE MK_KeyLen;
		IN BYTE* EMK;

	}Value;

	struct
	{
		IN BYTE Method;
		IN USHORT CVLen;
		IN BYTE* sCV;

	}Verification;

}SAVE_MK_BY_KPK_EX;

typedef struct
{
	BYTE EncMode;
	BYTE MK_Index;
	BYTE KeyLen;
	BYTE CCodeLen;

	BYTE *pEncryptedNewKey;
	BYTE *pCCode;
	BYTE *pICV;

	void *pRFU;

}KMS_UPDATE_KEY; // 20

typedef struct
{
	BYTE MK_Index; // IN
	BYTE CV_Len; // IN, 3 or 4
	BYTE RFU[2];
	BYTE *baCV;
}GET_KCV;

typedef struct
{
	// Structure Version, Should be 0x0000 or 0x0001
	USHORT Version;

	// Operation ID, from 0 to 4
	USHORT OperationID;

	// Source Key Index 1. It can be the key stored in KMS or the intermediate key.
	USHORT SrcKeyIndex1;

	// Source Key Index 2. It can be the key stored in KMS or the intermediate key.
	// If this value is 0xFFFF, it indicates to use the following OperationData instead of KMS key or intermediate key
	USHORT SrcKeyIndex2;

	// Operation Length,
	//     for XOR operation, it indicates how many bytes in Src Key and OperationData will be calculated in this opersation.
	//     for DES_ENCRYPT/DES_DECRYPT, it indicates how many bytes in Src Key and OperationData will be calculated in this opersation.
	//     for TAKE_LEFT/TAKE_RIGHT operation, it indicates how many bytes of Src Key will be taked.
	//     for COMBINE operation, it indicates how many bytes of the OperationData will be taked when SrcKeyIndex2 is 0xFFFF.
	USHORT OP_Length;

	// Range from 0xF0 to 0xF7
	USHORT DestIntermediateKeyIndex;

	// Specify the key flag to the destination intermediate key.
	// The key flag is bit mask as use in normal KMS key.
	// Besides, the destination intermediate key will be set with d_KEY_FLAG_INTERMEDIATE automatically.
	DWORD DestIntermediateKeyFlag;

	BYTE OperationData[32];

}INTERMEDIATE_KEYGEN_DATA;

void CTOS_KMSInitializeCryptoLib(void);
USHORT CTOS_KMSbEncryptData(CTOS_stDefEncDataStruc *para);
USHORT CTOS_KMSbEncryptDataEx(CTOS_stDefEncDataExStruc *para);
USHORT CTOS_KMSbCheckMK(BYTE bMKIndex);
USHORT CTOS_KMSbGetDUKPTKSN(BYTE bMKIndex, BYTE *pbKSN);
USHORT CTOS_KMSbSaveKeyCertifyed(BYTE *baCert);
USHORT CTOS_KMSbSaveRSACertKey(CTOS_stDefRSACertKey *para);
void CTOS_KMSSelfTest(BYTE *baPVR);
void CTOS_KMSCheckFirstTime(BYTE *baPVR);
USHORT CTOS_SelfTestSetFlag(BYTE bFlag);
USHORT CTOS_KMSbGetEncPIN(CTOS_stDefEncPINStruc *para);
USHORT CTOS_KMSbGetEncPINEx2(CTOS_stDefEncPINStrucEx2 *para);
USHORT CTOS_KMSbGetEncPINExtension(CTOS_stDefEncPINStrucExtension *para);
USHORT CTOS_KMSbGetEncOfflinePIN(CTOS_stDefEncOffPINStruc *para, BYTE* pPINBlock, BYTE* pPINBlockLen);
USHORT CTOS_KMSbDeleteKey(BYTE bMKIndex);
USHORT CTOS_KMSbMAC(CTOS_stDefMACStruc *para);
USHORT CTOS_KMSbSaveDESMK16(CTOS_stSaveDESMK16 *para);
USHORT CTOS_KMSbSaveDESMK32(CTOS_stSaveDESMK32 *para);
USHORT CTOS_KMSbSaveDESMK48(CTOS_stSaveDESMK48 *para);
USHORT CTOS_KMSbSaveDUKPTIK(CTOS_stSaveDUKPTIK *para);
USHORT CTOS_KMSbSaveDUKPTIK_T(CTOS_stSaveDUKPTIK *para);
USHORT CTOS_KMSGenKeyCertificate(CTOS_stGenKeyCertifyed *para, BYTE *baCertifyedKey);
USHORT CTOS_KMSSaveKPK(SAVE_KPK *pKPK);
USHORT CTOS_KMSSaveMKbyKPK(SAVE_MK_BY_KPK *pMKbyKPK);
USHORT CTOS_KMSSaveMKbyKPKEx(SAVE_MK_BY_KPK_EX *pMKbyKPKEX);
USHORT CTOS_KMSUserDataWrite(ULONG Offset, BYTE *pData, USHORT Len);
USHORT CTOS_KMSUserDataRead(ULONG Offset, BYTE *pData, USHORT Len);
void CTOS_KMSReset(void);
USHORT CTOS_KMSbSaveKeyTR31(CTOS_stDefTR31Struc *para);
USHORT CTOS_KMSGetKCV(GET_KCV *pKCV);
USHORT CTOS_KMSUpdateKey(KMS_UPDATE_KEY *para);

USHORT CTOS_KMSIntermediateKeyGenerate(INTERMEDIATE_KEYGEN_DATA* pIntermediateKeyGenData);
USHORT CTOS_KMSIntermediateKeyFlush(USHORT KeyIndex);
USHORT CTOS_KMSIntermediateKeyWrite(USHORT SrcIntermediateKeyIndex, USHORT DestKeyIndex, DWORD KeyFlag);

//=============================================================================================================================
//
// KMS2 Function
//
//=============================================================================================================================

//---------------------------------------------------------------------------------------------
// KeySets

// Reserved Keys for System
#define KMS2_RESERVED_KEY_SETS_0000				0x0000
#define KMS2_RESERVED_KEY_SETS_START			0xFF00
#define KMS2_RESERVED_KEY_SETS_END				0xFFFF

//---------------------------------------------------------------------------------------------

// Key Type
#define KMS2_KEYTYPE_3DES						0x01
#define KMS2_KEYTYPE_3DES_DUKPT					0x02 	// ANS X9.24 - 2004

// User Data Area
#define KMS2_PRIVATE_USER_DATA_MAX_SIZE			(16 * 1024)
#define KMS2_COMMON_USER_DATA_MAX_SIZE			(64 * 1024)

//---------------------------------------------------------------------------------------------

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN USHORT KeySet;
		IN USHORT KeyIndex;

	}Info;

	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;

	}Protection;

	struct
	{
		IN USHORT KeyLength;
		IN BYTE* pKeyData;

	}Value;

}CTOS_KMS2KEYWRITEBYTR31_PARA;

//---------------------------------------------------------------------------------------------
// PIN Block Type
#define KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0						0x00
#define KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE			0x01
#define KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE		0x02

// PIN Protection Cipher Method
#define KMS2_PINCIPHERMETHOD_ECB									0x00
#define KMS2_PINCIPHERMETHOD_EMV_OFFLINE_PIN			0x02

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN BYTE BlockType;
		IN BYTE PINDigitMaxLength;
		IN BYTE PINDigitMinLength;
	}PIN_Info;

	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;

		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;

	struct
	{
		// This is used for PAN if BlockType is KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0.
		// Ths is used for terminal pseudo random if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;

	}AdditionalData;

	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;

	struct
	{
		INOUT USHORT EncryptedBlockLength;
		OUT	BYTE* pEncryptedBlock;
		OUT BYTE PINDigitActualLength;
	}PINOutput;

	struct
	{
		IN DWORD Timeout;
		IN BYTE AsteriskPositionX;
		IN BYTE AsteriskPositionY;
		IN BYTE NULLPIN;
		IN int (*piTestCancel)(void);
	}Control;

}CTOS_KMS2PINGET_PARA;

typedef struct
{
	// Should be 0x02
	IN BYTE Version;

	struct
	{
		IN BYTE BlockType;
		IN BYTE PINDigitMaxLength;
		IN BYTE PINDigitMinLength;
	}PIN_Info;

	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;

		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;

	struct
	{
		// This is used for PAN if BlockType is KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0.
		// Ths is used for terminal pseudo random if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;

	}AdditionalData;

	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;

	struct
	{
		INOUT USHORT EncryptedBlockLength;
		OUT	BYTE* pEncryptedBlock;
		OUT BYTE PINDigitActualLength;
	}PINOutput;

	struct
	{
		IN DWORD Timeout;
		IN BYTE NULLPIN;
	}Control;

	struct
	{
		void (*OnGetPINDigit)(BYTE NoDigits);
		void (*OnGetPINCancel)(void);
		void (*OnGetPINBackspace)(BYTE NoDigits);
	}EventFunction;

}CTOS_KMS2PINGET_PARA_VERSION_2;
//---------------------------------------------------------------------------------------------
#define KMS2_DATAENCRYPTCIPHERMETHOD_ECB							0x00
#define KMS2_DATAENCRYPTCIPHERMETHOD_CBC							0x01

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;

		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;

	}Protection;

	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;

	struct
	{
		IN USHORT Length;
		IN BYTE* pData;

		IN USHORT ICVLength;
		IN BYTE* pICV;
	}Input;

	// This is not used if CipherMethod is KMS2_DATAENCRYPTCIPHERMETHOD_EXTPIN_ECB
	struct
	{
		OUT USHORT Length;
		OUT BYTE* pData;
	}Output;

}CTOS_KMS2DATAENCRYPT_PARA;

//---------------------------------------------------------------------------------------------
#define KMS2_MACMETHOD_CBC							0x00
#define KMS2_MACMETHOD_X9_19						0x01	// Retail MAC, done in one call

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;

		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;

	struct
	{
		BYTE Length;
		BYTE* pData;
	}ICV;

	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;

	struct
	{
		IN USHORT Length;
		IN BYTE* pData;
	}Input;

	struct
	{
		OUT USHORT Length;
		OUT BYTE* pData;
	}Output;

}CTOS_KMS2MAC_PARA;

//---------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN USHORT KeySet;

		IN USHORT KeyIndex;

		// Only used for KeyType 3DES/3DES-DUKPT/AES
		IN BYTE CVLen;

		// Only used for KeyType RSA
		IN BYTE HashAlgorithm;

	}Input;

	struct
	{
		OUT BYTE KeyType;
		OUT BYTE KeyVersion;
		OUT DWORD KeyAttribute;
		OUT USHORT KeyLength;

		// Only used for KeyType 3DES/3DES-DUKPT/AES
		OUT BYTE* pCV;

		// Only used for KeyType RSA
		OUT USHORT KeyExponentLength;

		// Only used for KeyType RSA
		// Calculated with the following input data in order:
		//		Modulus Length - 2 bytes, MSB to LSB
		//		Modulus
		//		Exponent Length - 2 bytes, MSB to LSB
		//		Exponent
		OUT BYTE* pHash;
	}Output;

}CTOS_KMS2KEYGETINFO_PARA;

//---------------------------------------------------------------------------------------------
typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		IN USHORT KeySet;

		IN USHORT KeyIndex;

	}Source1;

	struct
	{
		IN USHORT KeySet;

		IN USHORT KeyIndex;

	}Source2;

}CTOS_KMS2KEYSWAP_PARA;

//---------------------------------------------------------------------------------------------



typedef struct
{
         USHORT KeySet;
         USHORT KeyIndex;
         USHORT KeyResult;  //0x00 : key OK, 0x01 : integrity error
}CTOS_KMS2KEYCHECKGETRESULT_PARA;

// Management
USHORT CTOS_KMS2Init(void);
// Check all the keys belong to the application
USHORT CTOS_KMS2KeyCheckAll(void);
// Get all key status after calling CTOS_KMS2KeyCheckAll function
USHORT CTOS_KMS2KeyCheckGetResult(OUT USHORT *ResultCount, OUT CTOS_KMS2KEYCHECKGETRESULT_PARA *pResultData, INOUT USHORT *DataLen);
// Check the specific key
USHORT CTOS_KMS2KeyCheck(IN USHORT KeySet, IN USHORT KeyIndex);
// Delete all the keys belong to the application
USHORT CTOS_KMS2KeyDeleteAll(void);
// Delete the specific key
USHORT CTOS_KMS2KeyDelete(IN USHORT KeySet, IN USHORT KeyIndex);
// Specify two keys and swap each other.
USHORT CTOS_KMS2KeySwap(CTOS_KMS2KEYSWAP_PARA *para);

// Key Injection
USHORT CTOS_KMS2KeyWriteByTR31(INOUT CTOS_KMS2KEYWRITEBYTR31_PARA* pKeyWritebyTR31Para);

// Key Crypto Functions
// Can used to get online or offline
USHORT CTOS_KMS2PINGet(CTOS_KMS2PINGET_PARA *pPinGetPara);
USHORT CTOS_KMS2DataEncrypt(CTOS_KMS2DATAENCRYPT_PARA *pDataEncPara);
USHORT CTOS_KMS2MAC(CTOS_KMS2MAC_PARA *pMacPara);
USHORT CTOS_KMS2KeyGetInfo(IN CTOS_KMS2KEYGETINFO_PARA *pKeyGetInfoPara);
USHORT CTOS_KMS2DUKPTGetKSN(IN USHORT KeySet, IN USHORT KeyIndex, OUT BYTE* pKSN, INOUT BYTE* KSNLen);

// Additional Storage Functions
USHORT CTOS_KMS2UserDataWrite(IN BOOL IsCommon, IN ULONG Offset, IN BYTE *pData, IN USHORT usLen);
USHORT CTOS_KMS2UserDataRead(IN BOOL IsCommon, IN ULONG Offset, OUT BYTE *pData, IN USHORT usLen);

// include Extern function and define.
#include "kmsext.h"

//=============================================================================================================================
//
// Remote Key Injection Functions
//
//=============================================================================================================================

#define d_CAPKI_DEFAULT                 0x00
#define d_TKI_DEFAULT                   0x00

#define d_CAPKI_MAX_NUMBER     			0x40
#define d_TKI_MAX_NUMBER				0x40

USHORT CTOS_RKIGetRootPKCertificate(IN USHORT CAPKI, IN char *pDestPath, IN char *pDestFileName);
USHORT CTOS_RKIWriteRootRSAKey(IN USHORT CAPKI, IN USHORT KeyLength, IN BYTE* pModulus, IN BYTE* pPrivateExponent, IN BYTE* pPublicExponent, IN USHORT PublicExponentLength);
USHORT CTOS_RKIDeleteRootRSAKey(IN USHORT CAPKI);

USHORT CTOS_RKIGetTerminalPKRequest(IN BYTE isReGen, IN USHORT TKI, IN char *pDestPath, IN char *pDestFileName);

USHORT CTOS_RKIWriteTerminalRSAKey(IN USHORT TKI, IN USHORT KeyLength, IN BYTE* pModulus, IN BYTE* pPrivateExponent, IN BYTE* pPublicExponent, IN USHORT PublicExponentLength);
USHORT CTOS_RKIDeleteTerminalRSAKey(IN USHORT TKI);

USHORT CTOS_RKIWriteTerminalPKCertificate(IN USHORT TKI, IN char *pSrcPath, IN char *pSrcFileName);
USHORT CTOS_RKIReadTerminalPKCertificate(IN USHORT TKI, IN char *pDestPath, IN char *pDestFileName);

USHORT CTOS_RKIGenerateTerminalPKCertificate(IN BYTE CAPKI, IN USHORT TKI, IN char *pDestPath, IN char *pDestFileName);

//=============================================================================================================================
//
// File System Functions
//
//=============================================================================================================================

// Storage Type
#define	d_STORAGE_FLASH					0
#define	d_STORAGE_SRAM					1

// Attribute
#define d_FA_PRIVATE					0
#define d_FA_READ						1		//	Read by other APs
#define d_FA_WRITE						2		//	Written by other APs
#define d_FA_PUBLIC						0xFF

#define d_SEEK_FROM_BEGINNING			0
#define	d_SEEK_FROM_CURRENT				1
#define	d_SEEK_FROM_EOF					2

//For the whole useless blocks in the file system.
#define	d_FORMAT_TYPE_0					0

//For the last ## blocks, the flash FAT size assigned by this AP, in the file system.
#define	d_FORMAT_TYPE_1					1

typedef struct
{
	BYTE Filename[15];
	ULONG Filesize;
	BYTE FileAttrib;
	ULONG UID;
} CTOS_FILE_ATTRIB;

typedef struct
{
	BYTE  Filename[15];
	ULONG Filesize;
	BYTE  FileStorageType;
	BYTE  RFU[4];
} CTOS_FILE_INFO;

USHORT CTOS_FileOpen(BYTE* caFileName, BYTE bStorageType, ULONG* pulFileHandle);
USHORT CTOS_FileOpenAttrib(BYTE* caFileName, BYTE bStorageType, ULONG* pulFileHandle ,BYTE bAttrib); //<VK>2011.5.3
USHORT CTOS_FileClose(ULONG ulFileHandle);
USHORT CTOS_FileDelete(BYTE* caFileName);
USHORT CTOS_FileGetSize(BYTE* caFileName, ULONG* pulFileSize);
USHORT CTOS_FileSeek(ULONG ulFileHandle, ULONG ulOffset, BYTE bOrigin);
USHORT CTOS_FileRead(ULONG ulFileHandle, BYTE* baBuffer, ULONG* pulActualLength);
USHORT CTOS_FileWrite(ULONG ulFileHandle, BYTE* baBuffer, ULONG ulBufferLength);
USHORT CTOS_FileDir(BYTE *baFileBuf, ULONG *pulFileSize, USHORT *pusLen);
USHORT CTOS_FileCut (BYTE* caFileName, ULONG ulFileLen);
USHORT CTOS_FileRename (BYTE* caFileName, BYTE* caFileNewName);
USHORT CTOS_FileGetPosition(ULONG ulFileHandle, ULONG *pulPosition);
USHORT CTOS_FileReopen(BYTE* caFileName, BYTE bStorageType, ULONG* pulFileHandle);
USHORT CTOS_FileSetAttrib(BYTE* caFileName, BYTE bAttrib);
USHORT CTOS_FileDirAttrib(CTOS_FILE_ATTRIB *pstFA, USHORT *pusFileNumber);
USHORT CTOS_FileDirA(CTOS_FILE_INFO *pstInfo , USHORT *pusLen);
USHORT CTOS_FileGetAttrib(BYTE* caFileName, CTOS_FILE_ATTRIB *pstFA);
USHORT CTOS_FileFormat(BYTE bType);
USHORT CTOS_FileGetFreeSpace(BYTE bStorgeType, ULONG* pulFreeSize);
USHORT CTOS_SystemMemoryStatus(ULONG* ulUsedDiskSize ,ULONG* ulTotalDiskSize ,ULONG* ulUsedRamSize ,ULONG* ulTotalRamSize);

//=============================================================================================================================
//
// RS232 Functions
//
//=============================================================================================================================

#define d_COM1						0
#define d_COM2						1
#define d_COM3                      2
#define d_COM4                      3

USHORT CTOS_RS232Open(BYTE bPort, ULONG ulBaudRate, BYTE bParity, BYTE bDataBits, BYTE bStopBits);
USHORT CTOS_RS232TxReady(BYTE bPort);
USHORT CTOS_RS232TxData(BYTE bPort, BYTE* baBuf, USHORT usLen);
USHORT CTOS_RS232RxReady(BYTE bPort, USHORT* pusLen);
USHORT CTOS_RS232RxData(BYTE bPort, BYTE* baBuf, USHORT* pusLen);
USHORT CTOS_RS232SetRTS(BYTE bPort, BYTE bOnOff);
USHORT CTOS_RS232GetCTS(BYTE bPort);
USHORT CTOS_RS232FlushRxBuffer(BYTE bPort);
USHORT CTOS_RS232FlushTxBuffer(BYTE bPort);
USHORT CTOS_RS232Close(BYTE bPort);


//=============================================================================================================================
//
// SPI Functions
//
//=============================================================================================================================
#define d_SPI_PORT_0			0

// SPI operation mode
#define	d_MK_SPI_CPHA			0x01	// clock phase
#define	d_MK_SPI_CPOL			0x02	// clock polarity
#define d_MK_SPI_MODE			(d_MK_SPI_CPOL | d_MK_SPI_CPHA)
#define d_SPI_MODE_CPOL0_CPHA0		0	//	__T--|__ (default)
#define d_SPI_MODE_CPOL0_CPHA1		1	//	__|--T__
#define d_SPI_MODE_CPOL1_CPHA0		2	//	--T__|--
#define d_SPI_MODE_CPOL1_CPHA1		3	//	--|__T--

// SPI bits per word
#define d_SPI_BITS_7			7
#define d_SPI_BITS_8			8	// default
#define d_SPI_BITS_9			9

// Clock rate
#define d_SPI_SPEED_400K		400000	// 400 KHz
#define d_SPI_SPEED_2M			2000000	//   2 MHz

// SPI functions
USHORT CTOS_SPIOpen(BYTE bPort);
USHORT CTOS_SPIClose(BYTE bPort);
USHORT CTOS_SPISetMode(BYTE bPort, BYTE bMode);
USHORT CTOS_SPIGetMode(BYTE bPort, BYTE *bMode);
USHORT CTOS_SPISetWordSize(BYTE bPort, BYTE bSize);
USHORT CTOS_SPIGetWordSize(BYTE bPort, BYTE *bSize);
USHORT CTOS_SPISetSpeed(BYTE bPort, UINT uiSpeed);
USHORT CTOS_SPIGetSpeed(BYTE bPort, UINT *uiSpeed);
USHORT CTOS_SPIWrite(BYTE bPort, BYTE *bBuf, UINT uiLen);
USHORT CTOS_SPIRead(BYTE bPort, BYTE *bBuf, UINT uiLen);


//=============================================================================================================================
//
// Fiscal board GPIO Functions
//
//=============================================================================================================================
// GPIO level
#define d_GP_LOW			0
#define d_GP_HIGH			1

// GPO port
enum GP_OUTPUT {
	d_GPO_CS_EJ			= 0,
	d_GPO_CS_FRAM			= 1,
	d_GPO_CS_FM			= 2,
	d_GPO_DRAWER			= 3,
	d_GPO_MASTER			= 4
};

enum GP_INPUT {
	d_GPI_FM			= 0,
	d_GPI_EJ			= 1
};

USHORT CTOS_GPIOSet(enum GP_OUTPUT bPort, BOOL fCtrl);
USHORT CTOS_GPIOGet(enum GP_INPUT bPort, BOOL *fLevel);


//=============================================================================================================================
//
// Modem Functions
//
//=============================================================================================================================

// Para Mode
#define d_M_MODE_AYNC_NORMAL					1
#define d_M_MODE_AYNC_FAST						2
#define d_M_MODE_SDLC_NORMAL					3
#define d_M_MODE_SDLC_FAST						4
#define d_M_MODE_SDLC_FAST_EX					5

// HANDSHAKE
#define d_M_HANDSHAKE_V90_AUTO_FB				0
#define d_M_HANDSHAKE_V90_ONLY					1
#define d_M_HANDSHAKE_V34_AUTO_FB				2
#define d_M_HANDSHAKE_V34_ONLY					3
#define d_M_HANDSHAKE_V32BIS_AUTO_FB			4
#define d_M_HANDSHAKE_V32BIS_ONLY				5
#define d_M_HANDSHAKE_V22BIS_ONLY				6
#define	d_M_HANDSHAKE_V22_ONLY					7
#define d_M_HANDSHAKE_BELL_212					8
#define d_M_HANDSHAKE_BELL_103					9
#define d_M_HANDSHAKE_V21_ONLY					10
#define d_M_HANDSHAKE_V23						11

// Country Code
#define d_M_COUNTRY_TAIWAN						0
#define d_M_COUNTRY_CHINA						1
#define d_M_COUNTRY_USA							2
#define d_M_COUNTRY_GERMANY						3
#define d_M_COUNTRY_SPAIN						3
#define d_M_COUNTRY_FRANCE						4
#define d_M_COUNTRY_MALAYSIA					5
#define d_M_COUNTRY_ENGLISH						6
#define d_M_COUNTRY_THAILAND					7
#define d_M_COUNTRY_SINGAPORE					8
#define d_M_COUNTRY_JAPEN						9
#define d_M_COUNTRY_TURKEY						10
#define d_M_COUNTRY_RUSSIA						11
#define d_M_COUNTRY_HONGKONG					12
#define d_M_COUNTRY_INDONESIA					13
#define d_M_COUNTRY_AUSTRALIA					14
#define d_M_COUNTRY_BRAZIL						15
#define d_M_COUNTRY_CANADA						16
#define d_M_COUNTRY_SOUTH_AFRICA				17
#define d_M_COUNTRY_SOUTH_KOREA					18
#define d_M_COUNTRY_QATAR						19

// PreDialCheck
#define d_M_PRECHECK_NO_DETECT					0
#define	d_M_PRECHECK_DIAL_TONE_DETECT_ONLY		1
#define	d_M_PRECHECK_BUSY_DETECT_ONLY			2
#define	d_M_PRECHECK_DETECT_BOTH				3
#define	d_M_PRECHECK_DETECT_ALL					4

// CONFIG
#define d_M_CONFIG_DIALING_DURATION				1
#define d_M_CONFIG_MIN_ONHOOK_DURATION			2
#define d_M_CONFIG_PREDIAL_DELAY_TIME			3
#define d_M_CONFIG_DIAL_TONE_DETECT_DURATION	4
#define d_M_CONFIG_DIAL_TONE_MIN_ON_TIME		5
#define d_M_CONFIG_DTMF_ON_TIME					6
#define d_M_CONFIG_DTMF_OFF_TIME				7
#define d_M_CONFIG_BUSY_TONE_MIN_TOTAL_TIME		8
#define d_M_CONFIG_BUSY_TONE_DELTA_TIME			9
#define d_M_CONFIG_BUSY_TONE_MIN_ON_TIME		10
#define d_M_CONFIG_RINGBACK_TONE_MIN_TOTAL_TIME	11
#define d_M_CONFIG_RINGBACK_TONE_DELTA_TIME		12
#define d_M_CONFIG_RINGBACK_TONE_MIN_ON_TIME	13
#define d_M_CONFIG_ANSWER_TONE_WAIT_DURATION	14
#define d_M_CONFIG_BLIND_DIAL_DELAY_TIME		15
#define d_M_CONFIG_CARRIER_PRESENT_TIME			16
#define d_M_CONFIG_TX_POWER_LEVEL				17
#define d_M_CONFIG_RX_POWER_LEVEL				18

#define d_M_POWER_LEVEL_0						0
#define d_M_POWER_LEVEL_1						1
#define d_M_POWER_LEVEL_2						2
#define d_M_POWER_LEVEL_3						3	//default
#define d_M_POWER_LEVEL_4						4
#define d_M_POWER_LEVEL_5						5

// Status
#define d_M_STATUS_MODEM_OPEN					0x00000001
#define d_M_STATUS_MODEM_ONLINE					0x00000002
#define d_M_STATUS_SDLC_MODE					0x00000004
#define d_M_STATUS_SDLC_ONLINE					0x00000008
#define d_M_STATUS_DIALING						0x00000010
#define d_M_STATUS_NO_DIAL_TONE					0x00000020	// Dail up error
#define d_M_STATUS_LINE_BUSY					0x00000040	// Dail up error
#define d_M_STATUS_RING_BACK					0x00000080	// Dail up error
#define d_M_STATUS_TX_BUSY						0x00000100
#define d_M_STATUS_REMOTE_NOT_ANSWER			0x00000200	// Dail up error
#define d_M_STATUS_NO_CARRIER					0x00000400	// Dail up error
#define d_M_STATUS_ALL_DATA_SENT				0x00000800
#define d_M_STATUS_RX_DATA_VALID				0x00001000
#define d_M_STATUS_LISTENING					0x00002000
#define d_M_STATUS_RX_FRAME_ERROR				0x00004000	// Got enough frame error Rx buffer
#define d_M_STATUS_OTHER_ERROR					0x00008000	//Dail up error
#define d_M_STATUS_DATA_SENT_ERROR				0x00010000	//Over USHORT range
#define d_M_STATUS_DATA_RECEIVE_ERROR			0x00020000	//Over USHORT range
#define d_M_STATUS_TIMEOUT						0x00040000	//Over USHORT range

//Socket Device
#define d_TCP_DEVICE_ETHERNET			0
#define d_TCP_DEVICE_GPRS 				1
#define d_TCP_DEVICE_MODEM 				2
#define d_TCP_DEVICE_WIFI 				3

//Device Support
#define d_TCP_DEVICE_CA0				0x00000001
#define d_TCP_DEVICE_PPP0 				0x00000002
#define d_TCP_DEVICE_ETH0 				0x00000004
#define d_TCP_DEVICE_WLAN0 				0x00000008

//=============================================================================================================================
//
// Modem API Functions
//
//=============================================================================================================================
USHORT CTOS_ModemOpen(BYTE bMode, BYTE bHandShake, BYTE bCountryCode);
USHORT CTOS_ModemClose(void);
USHORT CTOS_ModemDialup(BYTE *baNumber, USHORT usLen);
USHORT CTOS_ModemTxReady(void);
USHORT CTOS_ModemTxData(BYTE *baData, USHORT usLen);
USHORT CTOS_ModemRxReady(USHORT* pusLen);
USHORT CTOS_ModemRxData(BYTE* baData, USHORT* pusLen);
USHORT CTOS_ModemATCommand(BYTE* baCmd, USHORT usCmdLen, BYTE* pbResponse, USHORT* pusRespLen);
USHORT CTOS_ModemStatus(DWORD* pdwStatus);
USHORT CTOS_ModemHookOff(void);
USHORT CTOS_ModemHookOn(void);
USHORT CTOS_ModemSetDialPrecheck(BYTE bMode);
USHORT CTOS_ModemSetConfig(BYTE bTag, USHORT usValue);
USHORT CTOS_ModemReadConfig(BYTE bTag, USHORT* pusValue);
USHORT CTOS_ModemFlushRxData(void);
USHORT CTOS_ModemListen (BYTE bNumOfRing);
USHORT CTOS_ModemSetCommParam(ULONG ulBaudRate, BYTE bParity, BYTE bDataBits, BYTE bStopBits);
USHORT CTOS_ModemOpenEx(BYTE bMode, BYTE bHandShake, BYTE bCountryCode);
USHORT CTOS_ModemCloseEx(void);


//=============================================================================================================================
//
// Modem TCP API Functions
//
//=============================================================================================================================
void CTOS_TCP_ModemInit(void);
USHORT CTOS_TCP_ModemOpen(BYTE bMode , BYTE bHandShake , BYTE bCountryCode);
USHORT CTOS_TCP_ModemClose(void);
USHORT CTOS_TCP_ModemDialup(BYTE *baPhone, BYTE *baID, BYTE *baPW, ULONG ulTimeout);
USHORT CTOS_TCP_ModemOnHook(void);
USHORT CTOS_TCP_ModemGetIP(BYTE *baIP);
USHORT CTOS_TCP_ModemSetIP(BYTE *baIP);
USHORT CTOS_TCP_ModemConnectEx(BYTE *bSocket, BYTE *baIP, USHORT usPort );
USHORT CTOS_TCP_ModemDisconnect(BYTE bSocket);
USHORT CTOS_TCP_ModemTx(BYTE bSocket , BYTE *baBuffer, USHORT usLen);
USHORT CTOS_TCP_ModemRx(BYTE bSocket , BYTE *baBuffer, USHORT *usLen);
USHORT CTOS_UDP_ModemTx(BYTE *baIP , USHORT usPort , BYTE *baBuffer, USHORT usLen);
USHORT CTOS_UDP_ModemRx(BYTE *bSrcDestIP, USHORT *usPort , BYTE *baBuffer, USHORT *usLen);
USHORT CTOS_TCP_ModemStatus(DWORD *pdwState);
USHORT CTOS_TCP_ModemSetDNSServer(BYTE *baIP);
USHORT CTOS_TCP_ModemGetDNSServer(BYTE *baIP);
USHORT CTOS_TCP_ModemConnectURL(BYTE *pbSocket, BYTE *baIPURL, USHORT usPort);
USHORT CTOS_TCP_ModemOpenEx(BYTE bMode , BYTE bHandShake , BYTE bCountryCode);
USHORT CTOS_TCP_ModemURL2IP(STR* strURL, BYTE* baIP);
USHORT CTOS_TCP_ModemPing(STR *strIPURL, BYTE bTimeout);
USHORT CTOS_TCP_ModemSetConfig(BYTE bTag, USHORT usValue);
USHORT CTOS_TCP_ModemGetConfig(BYTE bTag, USHORT* pusValue);

#define TCP_MODEM_STATE_ONLINE 			0x00000002
#define TCP_MODEM_STATE_DIALING 		0x00000010
#define TCP_MODEM_STATE_CONNECTING		0x00000020
#define TCP_MODEM_STATE_SENDING			0x00000040
#define TCP_MODEM_STATE_RECEIVING		0x00000080
#define TCP_MODEM_STATE_DISCONNECTING	0x00000100
#define TCP_MODEM_STATE_ONHOOKING		0x00000200


//=============================================================================================================================
//
// GPRS API Functions
//
//=============================================================================================================================
void CTOS_TCP_GPRSInit(void);
USHORT CTOS_TCP_GPRSOpen(BYTE *baIP, STR *strAPN, STR *baID, STR *baPW);
USHORT CTOS_TCP_GPRSOpenEx(BYTE *baIP, STR *strAPN, STR *baID, STR *baPW);
USHORT CTOS_TCP_GPRSClose(void);
USHORT CTOS_TCP_GPRSClose_A(void);
USHORT CTOS_TCP_GPRSGetIP(BYTE *baIP);
USHORT CTOS_TCP_GPRSConnectEx(BYTE *bSocket, BYTE *baIP, USHORT usPort);
USHORT CTOS_TCP_GPRSDisconnect(BYTE bSocket);
USHORT CTOS_TCP_GPRSTx(BYTE bSocket, BYTE *baBuffer, USHORT usLen);
USHORT CTOS_TCP_GPRSRx(BYTE bSocket, BYTE *baBuffer, USHORT *usLen);
USHORT CTOS_TCP_GPRSStatus (DWORD* pdwState);
USHORT CTOS_TCP_GPRSSocketStatus(BYTE bSocket, DWORD *pdwState);
USHORT CTOS_TCP_GPRSSwitchAPN(BYTE *baIP, STR *strAPN, STR *baID, STR *baPW);   //SYNC
USHORT CTOS_TCP_GPRSSwitchAPN_A(BYTE *baIP, STR *strAPN, STR *baID, STR *baPW);  //ASYNC
USHORT CTOS_TCP_GPRSCancelTask(void *RFU);
USHORT CTOS_TCP_GPRSSetDNSServer(BYTE *baIP);
USHORT CTOS_TCP_GPRSGetDNSServer(BYTE *baIP);
USHORT CTOS_TCP_GPRSConnectURL(BYTE *pbSocket, BYTE *baIPURL, USHORT usPort);
USHORT CTOS_TCP_GPRSPing(STR *strIPURL, BYTE bTimeout);
USHORT CTOS_TCP_GPRSURL2IP(STR* strURL, BYTE* baIP);

#define TCP_GPRS_STATE_ESTABLISHED 		0x00000002
#define TCP_GPRS_STATE_ESTABLISHING		0x00000010
#define TCP_GPRS_STATE_CONNECTING		0x00000020
#define TCP_GPRS_STATE_SENDING			0x00000040
#define TCP_GPRS_STATE_RECEIVING		0x00000080
#define TCP_GPRS_STATE_DISCONNECTING	0x00000100
#define TCP_GPRS_STATE_ONHOOKING		0x00000200


//=============================================================================================================================
//
// Modem/GPRS Setting Functions
//
//=============================================================================================================================
USHORT CTOS_TCP_BindToDevice(INT iSocket,BYTE bDevice);
USHORT CTOS_TCP_SelectDefaultDevice(BYTE bDevice);
USHORT CTOS_TCP_SetConnectTO(ULONG ulTime);
USHORT CTOS_TCP_GetConnectTO(ULONG *ulTime);
USHORT CTOS_TCP_SetRxAckTO(ULONG ulTime);	//NA
USHORT CTOS_TCP_GetRxAckTO(ULONG *ulTime); //NA
USHORT CTOS_TCP_SetRxTO(ULONG ulTime);
USHORT CTOS_TCP_GetRxTO(ULONG *ulTime);
USHORT CTOS_TCP_SetRetryCounter(USHORT usTime);
USHORT CTOS_TCP_GetRetryCounter(USHORT *usTime);
USHORT CTOS_PPP_SetTO(ULONG ulTime);
USHORT CTOS_PPP_GetTO(ULONG *ulTime);
USHORT CTOS_PPP_SetRetryCounter(USHORT usTime);
USHORT CTOS_PPP_GetRetryCounter(USHORT *usTime);
USHORT CTOS_PPP_SetRetryCounterEx(USHORT usTime);
USHORT CTOS_PPP_GetRetryCounterEx(USHORT *usTime);
USHORT CTOS_TCP_SetMaxSegSize(ULONG ulMss);
USHORT CTOS_TCP_GetMaxSegSize(ULONG *ulMss);

//=============================================================================================================================
//
// Wifi Functions
//
//=============================================================================================================================

typedef struct
{
 BYTE Address[32];            //MAC addr
 BYTE ESSID[36];              //SSID : Service Set Identifier
 BYTE Mode[64];               //Operation mode : Managed/Ad-hoc/...
 BYTE Freq[64];               //Channel : 2.442 GHz (Channel 7)
 BYTE Quality[16];            //Quality : 3/5 (the strength)
 BYTE SignalLv[16];
 BYTE NoiseLv[16];
 BYTE EncryptionKey[8];       //Encryption : on/off
 //-------------------------------
 BYTE Type_1[8];              //Type : WPA/WPA2/WEP
 BYTE GroupCipher_1[8];       //Cipher : TKIP/CCMP
 BYTE PairwiseCiphers_1[8];   //Cipher : TKIP/CCMP
 BYTE Authentication_1[8];    //Authentication : PSK/...
 //---------------------------
 BYTE Type_2[8];
 BYTE GroupCipher_2[8];
 BYTE PairwiseCiphers_2[8];
 BYTE Authentication_2[8];
}CTOS_stWifiInfo;


USHORT CTOS_WifiOpen(void);
USHORT CTOS_WifiClose(void);

USHORT CTOS_WifiScan(void);
USHORT CTOS_WifiInfoGet(BYTE* bNumInfo, CTOS_stWifiInfo** stInfo);
USHORT CTOS_WifiConnectAP(CTOS_stWifiInfo* stInfo, BYTE *baPassword, USHORT usPasswordLen);
USHORT CTOS_WifiDisconnectAP(void);
USHORT CTOS_WifiStatus(DWORD* pdwState);

USHORT CTOS_WifiConfigSet(BYTE bTag, BYTE* baValue, BYTE bLen);
USHORT CTOS_WifiConfigGet(BYTE bTag, BYTE* baValue, BYTE *pbLen);
USHORT CTOS_WifiConnectAPEx(BYTE *baSSid,USHORT usSSIDLen, BYTE bProtocal, BYTE bPairwise, BYTE bGroup, BYTE *baPassword,USHORT usPasswordLen);
USHORT CTOS_WifiPing(STR *strIPURL, BYTE bTimeout);

// pdwState of CTOS_WifiStatus
#define d_WIFI_STATE_AP_CONNECTED		0x00000002
#define d_WIFI_STATE_SCANNING			0x00000008
#define d_WIFI_STATE_AP_CONNECTING		0x00000010
#define d_WIFI_STATE_CONNECTING			0x00000020
#define d_WIFI_STATE_SENDING			0x00000040
#define d_WIFI_STATE_RECEIVING			0x00000080
#define d_WIFI_STATE_DISCONNECTING		0x00000100
#define d_WIFI_STATE_AP_DISCONNECTING	0x00000200

//the configuration tag
#define d_WIFI_CONFIG_DHCP				1
#define d_WIFI_CONFIG_AUTOCON_AP		2
#define d_WIFI_CONFIG_IP				3
#define d_WIFI_CONFIG_MASK				4
#define d_WIFI_CONFIG_GATEWAY			5
#define d_WIFI_CONFIG_DNSIP				6
#define d_WIFI_CONFIG_MAC				7

//Protocol
#define d_WIFI_PROTOCOL_WEP    			0x01
#define d_WIFI_PROTOCOL_WPA    			0x02
#define d_WIFI_PROTOCOL_WPA2    		0x03

//Pairwise
#define d_WIFI_PAIRWISE_TKIP    		0x01
#define d_WIFI_PAIRWISE_CCMP    		0x02
#define d_WIFI_PAIRWISE_TKIPCCMP    	0x03

//Group
#define d_WIFI_GROUP_TKIP    			0x01
#define d_WIFI_GROUP_CCMP    			0x02
#define d_WIFI_GROUP_TKIPCCMP    		0x03

//=============================================================================================================================
//
// Bluetooth Functions
//
//=============================================================================================================================

typedef struct DeviceInfo{
    BYTE *pbDeviceName;
    BYTE *pbDeviceMac;
}stDeviceInfo;

typedef struct ServiceInfo{
    BYTE *pbSeviceName;
    BYTE *pbSeviceUid;
    BYTE bSeviceChannel;
}stServiceInfo;

USHORT CTOS_BluetoothConfigSet(BYTE bTag, BYTE* baValue, USHORT usLen);
USHORT CTOS_BluetoothConfigGet(BYTE bTag, BYTE* baValue, USHORT *pusLen);
USHORT CTOS_BluetoothDeviceScan(void);
USHORT CTOS_BluetoothDeviceInfoGet(BYTE *bpitem, stDeviceInfo **sppDeviceInfo);
USHORT CTOS_BluetoothServiceScan(stDeviceInfo *psDeviceInfo);
USHORT CTOS_BluetoothServiceInfoGet(BYTE *pbNum, stServiceInfo **sppServiceInfo);
USHORT CTOS_BluetoothConnect(stDeviceInfo *psDeviceInfo,stServiceInfo *psServiceInfo);
USHORT CTOS_BluetoothTxReady(void);
USHORT CTOS_BluetoothTxData(BYTE* baData, USHORT usLen);
USHORT CTOS_BluetoothRxReady(USHORT* pusLen);
USHORT CTOS_BluetoothRxData(BYTE* baData, USHORT* pusLen);
USHORT CTOS_BluetoothDisconnect(void);
USHORT CTOS_BluetoothStatus(DWORD* pdwState);
USHORT CTOS_BluetoothListen(BYTE* baServiceName, BYTE* baUUID);
USHORT CTOS_BluetoothUnlisten(void);
USHORT CTOS_BluetoothOpen(void);
USHORT CTOS_BluetoothClose(void);
USHORT CTOS_BluetoothHCITxData(BYTE* baData, USHORT usLen);
USHORT CTOS_BluetoothHCITxReady(void);
USHORT CTOS_BluetoothHCIRxData(BYTE* baData, USHORT *usLen);
USHORT CTOS_BluetoothHCIRxReady(USHORT* usLen);
USHORT CTOS_BluetoothServiceScanEx(stDeviceInfo *psDeviceInfo, USHORT usServiceType);
USHORT CTOS_CradleBluetoothConfigSet(BYTE bTag, BYTE* baValue, USHORT usLen);
USHORT CTOS_CradleBluetoothConfigGet(BYTE bTag, BYTE* baValue, USHORT *pusLen);
USHORT CTOS_CradleSelectAccessMode(BYTE bMode);
USHORT CTOS_BluetoothPairedListGet(BYTE *pbNum, stDeviceInfo **sppDeviceInfo);
USHORT CTOS_BluetoothUnpair(BYTE bIndex);

// for Bluetooth SecureMode/IncureMode
#define	d_BLUETOOTH_INSECURE_MODE			"0"
#define	d_BLUETOOTH_SECURE_MODE				"1"

// for tag of d_BLUETOOTH_CONFIG_MODE
#define d_BLUETOOTH_MODE_CRADLE			"C"
#define d_BLUETOOTH_MODE_OPEN			"O"

#define d_BLUETOOTH_CONFIG_AUTOCON    		1
#define d_BLUETOOTH_CONFIG_DEVICE_NAME 		2
#define d_BLUETOOTH_CONFIG_PASSKEY		 	3
#define d_BLUETOOTH_CONFIG_SECURE		 	4
#define d_BLUETOOTH_CONFIG_MAC				5
#define d_BLUETOOTH_CONFIG_AUTOCON_INTERVAL	6
#define d_BLUETOOTH_CONFIG_DISCOVERABLE		7
#define d_BLUETOOTH_CONFIG_ACCESSORY_NAME	8
#define d_BLUETOOTH_CONFIG_FACTORY_ID 		9
#define d_BLUETOOTH_CONFIG_PROTOCOL_NAME	10
#define d_BLUETOOTH_CONFIG_BUNDLE_ID		11
#define d_BLUETOOTH_CONFIG_MANUFACTURERNAME	12
#define d_BLUETOOTH_CONFIG_MODE		 		13

/*
 * Service class identifiers of standard services and service groups
 */
#define d_BLUETOOTH_SVCLASS_ID_SDP_SERVER                   0x1000
#define d_BLUETOOTH_SVCLASS_ID_BROWSE_GRP_DESC        		0x1001
#define d_BLUETOOTH_SVCLASS_ID_PUBLIC_BROWSE_GROUP  		0x1002
#define d_BLUETOOTH_SVCLASS_ID_SERIAL_PORT                  0x1101

#define d_CRADLE_ACCESS_MODE_UART     						0x00
#define d_CRADLE_ACCESS_MODE_BLUETOOTH      				0x01

#define d_CRADLE_BLUETOOTH_CONFIG_DEVICE_NAME     	1
#define d_CRADLE_BLUETOOTH_CONFIG_PASSKEY    		2

// pdwState of CTOS_BluetoothStatus
#define d_BLUETOOTH_STATE_CONNECTED         0x00000002
#define d_BLUETOOTH_STATE_LISTENING         0x00000004
#define d_BLUETOOTH_STATE_SCANNING			0x00000008
#define d_BLUETOOTH_STATE_CONNECTING		0x00000010

#define d_BLUETOOTH_STATE_SENDING			0x00000040
#define d_BLUETOOTH_STATE_RECEIVING			0x00000080
#define d_BLUETOOTH_STATE_DISCONNECTING		0x00000100

#define d_BLUETOOTH_STATE_BUSY				(d_BLUETOOTH_STATE_LISTENING | d_BLUETOOTH_STATE_SCANNING | d_BLUETOOTH_STATE_CONNECTING | \
											d_BLUETOOTH_STATE_SENDING | d_BLUETOOTH_STATE_RECEIVING | d_BLUETOOTH_STATE_DISCONNECTING)

//=============================================================================================================================
//
// Ethernet Functions
//
//=============================================================================================================================

// ConfigSet/Get
#define d_ETHERNET_CONFIG_IP					1
#define d_ETHERNET_CONFIG_MASK					2
#define d_ETHERNET_CONFIG_GATEWAY				3
#define d_ETHERNET_CONFIG_HOSTIP				4
#define d_ETHERNET_CONFIG_HOSTPORT				8
#define d_ETHERNET_CONFIG_VERSION				10
#define d_ETHERNET_CONFIG_MAC					11
#define d_ETHERNET_CONFIG_DHCP					12
#define d_ETHERNET_CONFIG_AUTOCON				14
#define d_ETHERNET_CONFIG_UPDATE_EXIT			15
#define d_ETHERNET_CONFIG_DNSIP					16
#define d_ETHERNET_CONFIG_HOSTURL				17
#define d_ETHERNET_CONFIG_CONNTIMEOUT			18

// Status
#define d_STATUS_ETHERNET_CONNECTED				0x00000001
#define d_STATUS_ETHERNET_PHYSICAL_ONLINE		0x00000010
#define d_STATUS_ETHERNET_RX_READY				0x00000020
#define d_STATUS_ETHERNET_TX_BUSY				0x00000040
#define d_STATUS_ETHERNET_COMMAND_MODE			0x00000080

#define ETHERNET_MS_CONNECTED_SOCKET0			0x00000100
#define ETHERNET_MS_CONNECTED_SOCKET1			0x00000200
#define ETHERNET_MS_CONNECTED_SOCKET2			0x00000400

// Multi-socket
#define d_ETHERNET_NUM_SOCKET			3
#define d_ETHERNET_MAX_SOCKET			2
#define d_ETHERNET_SOCKET_0				0
#define d_ETHERNET_SOCKET_1				1
#define d_ETHERNET_SOCKET_2				2

USHORT CTOS_EthernetOpen(void);
USHORT CTOS_EthernetOpenEx(void);
USHORT CTOS_EthernetClose(void);
USHORT CTOS_EthernetTxReady(void);
USHORT CTOS_EthernetTxData(BYTE* baData, USHORT usLen);
USHORT CTOS_EthernetRxReady(USHORT* pusLen);
USHORT CTOS_EthernetRxData(BYTE* baData, USHORT* pusLen);
USHORT CTOS_EthernetConfigSet(BYTE bTag, BYTE* baValue, BYTE bLen);
USHORT CTOS_EthernetConfigGet(BYTE bTag, BYTE* baValue, BYTE* pbLen);
USHORT CTOS_EthernetStatus(DWORD* pdwStatus);
USHORT CTOS_EthernetConnect(void);
USHORT CTOS_EthernetConnectEx(BYTE* baDestIP, BYTE bIPLen, BYTE* baPort, BYTE bPortLen);
USHORT CTOS_EthernetDisconnect(void);
USHORT CTOS_EthernetPing(BYTE* baDestIP, BYTE bLen);
USHORT CTOS_EthernetFlushRxData(void);
USHORT CTOS_EthernetPingEx(STR *strIPURL, BYTE bTimeout);

USHORT CTOS_EthernetMSConnect(BYTE bMSSocket);
USHORT CTOS_EthernetMSConnectEx(BYTE bMSsocket, BYTE* baDestIP, BYTE bIPLen, BYTE* baPort, BYTE bPortLen);
USHORT CTOS_EthernetMSDisconnect(BYTE bMSSocket);
USHORT CTOS_EthernetMSTxReady(BYTE bMSSocket);
USHORT CTOS_EthernetMSTxData(BYTE bMSSocket, BYTE *baData, USHORT usLen);
USHORT CTOS_EthernetMSRxReady(BYTE bMSSocket, DWORD* pdwLen);
USHORT CTOS_EthernetMSRxData(BYTE bMSSocket, BYTE *baData, DWORD* pdwLen);
USHORT CTOS_EthernetURL2IP(BYTE* baDestURL, BYTE bURLLen, BYTE* baRspIP, BYTE* pbRspIPLen);
USHORT CTOS_EthernetIP2MAC(BYTE* baDestIP, BYTE bIPLen, BYTE* baRspMAC, BYTE* pbRspMACLen);
USHORT CTOS_EthernetConnectURL(void);
USHORT CTOS_EthernetConnectURLEx(BYTE* baDestURL, BYTE bURLLen);
USHORT CTOS_EthernetMSListen(BYTE bMSSocket, BYTE* baListenPort, BYTE bListenPortLen);
USHORT CTOS_EthernetMSUnlisten(BYTE bMSSocket);
USHORT CTOS_EthernetEnable(void);
USHORT CTOS_EthernetDisable(void);
USHORT CTOS_EthernetMSStatus(DWORD* pdwMSStatus);
USHORT CTOS_EthernetMSRxbufSet(BYTE bMSSocket, BYTE *baBuf, DWORD dwBufsize);
USHORT CTOS_EthernetGetConnectionInfo(BYTE* baIP, BYTE* pbIPLen, BYTE* baPort, BYTE* pbPorLen);
USHORT CTOS_EthernetMSGetConnectionInfo(BYTE bMSSocket, BYTE* baIP, BYTE* pbIPLen, BYTE* baPort, BYTE* pbPorLen);

// FTP
USHORT CTOS_EthernetFTPGetState(BYTE* pbFTPState);
USHORT CTOS_EthernetFTPConnect(BYTE* baHost, BYTE bHostLen, BYTE* baPort, BYTE bPortLen, BYTE* baUserName, BYTE bUserNameLen, BYTE* baPassword, BYTE bPasswordLen, BOOL fActiveMode);
USHORT CTOS_EthernetFTPDisconnect(void);
USHORT CTOS_EthernetFTPList(BYTE* baDataDir, DWORD* pdwDataDirLen, BYTE* baDataFile, DWORD* pdwDataFileLen);
USHORT CTOS_EthernetFTPChangeDir(BYTE* baChangeDirName, USHORT usChangeDirLen, BYTE* baDataDir, DWORD* pdwDataDirLen, BYTE* baDataFile, DWORD* pdwDataFileLen);
USHORT CTOS_EthernetFTPDownload(BYTE* baFileName, USHORT usFileNameLen, BYTE* baFileData, DWORD* pdwFileDataLen);
USHORT CTOS_EthernetFTPUpload(BYTE* baFileName, USHORT usFileNameLen, BYTE* baFileData, DWORD dwFileDataLen);
USHORT CTOS_EthernetFTPTranStatus(DWORD* pdwFileDataLen);
USHORT CTOS_EthernetFTPCancel(void);
USHORT CTOS_EthernetFTPDownloadFile(BYTE* baFileName);
USHORT CTOS_EthernetFTPUploadFile(BYTE* baFileName);

USHORT CTOS_EthernetConnectURLPort(BYTE* baDestURL, BYTE bURLLen, BYTE* baPort, BYTE bPortLen);
//=============================================================================================================================
//
// USB Functions
//
//=============================================================================================================================
#define d_MK_USB_STATUS_CDCMODE		0x00000001
#define d_MK_USB_STATUS_HOSTMODE	0x00000002

#define d_USB_DEVICE_MODE				0
#define d_USB_HOST_MODE					1

USHORT CTOS_USBSelectMode(BYTE bMode);
USHORT CTOS_USBSetCDCMode(void);
USHORT CTOS_USBSetSTDMode(void);
USHORT CTOS_USBSetVidPid(DWORD dwVidPid);
USHORT CTOS_USBGetVidPid(DWORD* dwVidPid);
USHORT CTOS_USBGetStatus(DWORD* pdwUSBStatus);

USHORT CTOS_USBOpen(void);
USHORT CTOS_USBClose(void);
USHORT CTOS_USBTxReady(void);
USHORT CTOS_USBTxData(BYTE* baSBuf, USHORT usSLen);
USHORT CTOS_USBRxReady(USHORT* pusRLen);
USHORT CTOS_USBRxData(BYTE* baRBuf, USHORT* pusRLen);
USHORT CTOS_USBTxFlush(void);
USHORT CTOS_USBRxFlush(void);

USHORT CTOS_USBHostOpen(IN USHORT usVendorID, IN USHORT usProductID);
USHORT CTOS_USBHostClose(void);
USHORT CTOS_USBHostTxData(IN BYTE* baSBuf, IN ULONG ulTxLen, IN ULONG ulMSec);
USHORT CTOS_USBHostRxData(OUT BYTE* baRBuf, IN OUT ULONG* ulRxLen, IN ULONG ulMSec);

USHORT CTOS_BaseUSBOpen(void);
USHORT CTOS_BaseUSBClose(void);
USHORT CTOS_BaseUSBTxReady(void);
USHORT CTOS_BaseUSBTxData(BYTE* baSBuf, USHORT usSLen);
USHORT CTOS_BaseUSBRxReady(USHORT* pusRLen);
USHORT CTOS_BaseUSBRxData(BYTE* baRBuf, USHORT* pusRLen);
USHORT CTOS_BaseUSBTxFlush(void);
USHORT CTOS_BaseUSBRxFlush(void);
USHORT CTOS_BaseUSBSetCDCMode(void);
USHORT CTOS_BaseUSBSetSTDMode(void);
USHORT CTOS_BaseUSBGetVidPid(DWORD *pdwVidPid);
USHORT CTOS_BaseUSBSetVidPid(DWORD dwVidPid);
USHORT CTOS_BaseUSBGetStatus(DWORD* pdwUSBStatus);

//=============================================================================================================================
//
// GSM Functions
//
//=============================================================================================================================

#define d_GSM_GPRS_STATE_NOT_REG 		0
#define d_GSM_GPRS_STATE_REG     		1
#define d_GSM_GPRS_STATE_TRYING  		2
#define d_GSM_GPRS_STATE_DENY    		3
#define d_GSM_GPRS_STATE_UNKNOW  		4
#define d_GSM_GPRS_STATE_ROAM    		5

#define d_GSM_PWR_WORK					0
#define d_GSM_PWR_STANDBY				1
#define d_GSM_PWR_SLEEP					2

#define d_GPRS_SIM1						0
#define d_GPRS_SIM2						1

#define d_GSM_900_1800					0
#define d_GSM_900_1900					1
#define d_GSM_850_1800					2
#define d_GSM_850_1900					3

#define d_GSM_PIN_PUK_1          		0
#define d_GSM_PIN_PUK_2          		1

#define d_GSM_AUTH_SC            		0
#define d_GSM_AUTH_PS            		1
#define d_GSM_AUTH_FD            		2

//Phonebook
#define d_GSM_PB_FD              		0
#define d_GSM_PB_SM              		1
#define d_GSM_PB_ON              		2
#define d_GSM_PB_ME              		3
#define d_GSM_PB_LD              		4
#define d_GSM_PB_MC              		5
#define d_GSM_PB_RC              		6
#define d_GSM_PB_UNKNOW          		0xFF

//Addr Type
#define d_GSM_ADDR_NUMBER        		145
#define d_GSM_ADDR_CHAR          		209
#define d_GSM_ADDR_OTHER         		129

#define d_GSM_SMS_REC_UNREAD     		0
#define d_GSM_SMS_REC_READ       		1
#define d_GSM_SMS_STO_UNSEND     		2
#define d_GSM_SMS_STO_SEND       		3
#define d_GSM_SMS_ALL            		4

//Unicode Type
#define d_GSM_SMS_UTF8					0
#define d_GSM_SMS_UCS2					1

// Packet Service Network Type
#define	d_GSM_NETWORK_GPRS				0
#define	d_GSM_NETWORK_EGPRS				1
#define	d_GSM_NETWORK_WCDMA				2
#define	d_GSM_NETWORK_HSDPA				3
#define	d_GSM_NETWORK_UNKNOWN			4

// Manufacturer Information
#define	d_GSM_MANUFACTURER_TELIT		0x01	// Telit
#define	d_GSM_MANUFACTURER_SIMCOM		0x02	// SIMCOM

// Model Information
// Telit
#define	d_GSM_MODEL_GC864_QUAD			0x01	// 2G GSM/GPRS
#define	d_GSM_MODEL_GC864_QUAD_V2		0x02	// 2G GSM/GPRS
#define	d_GSM_MODEL_CC864_SR			0x03	// 3G CDMA
#define	d_GSM_MODEL_CC864_DUAL			0x04	// 3G CDMA
#define	d_GSM_MODEL_UC864_E				0x05	// 3G UMTS
#define	d_GSM_MODEL_UC864_E_DUAL		0x06	// 3G UMTS
#define	d_GSM_MODEL_UC864_G				0x07	// 3G UMTS

// SIMCOM
#define	d_GSM_MODEL_SIM900				0x21	// 2G GSM/GPRS

// Country Code
#define d_GSM_COUNTRY_TAIWAN			0
#define d_GSM_COUNTRY_SPAN				20

// GPIO control
#define d_GSM_IO_POWER		0
#define d_GSM_IO_RESET		1
#define d_GSM_IO_SIM		2
#define d_GSM_IO_VGSM		3
#define d_GSM_IO_DTR		4
#define d_GSM_IO_USBEN		5

// Module operate mode
#define d_GSM_MODULE_CMD_MODE         0x00
#define d_GSM_MODULE_DATA_MODE        0x01

typedef struct
{
    BYTE bIndex;
    BYTE baName[20];
    BYTE bNameLen;
    BYTE baNumber[30];
    BYTE bNumberLen;
    BYTE bAddrType;
} stPhoneBook;

typedef struct
{
    BYTE bIndex;
    BYTE bType;
    BYTE baPhoneNumber[20];
    BYTE bPhoneNumberLen;
    BYTE baTimeStamp[20];
    BYTE bTimeStampLen;
    BYTE baMessage[300];
    USHORT usMessageLen;
} stSMS;

typedef struct
{
    BYTE bVp;
    BYTE bDcs;
    BYTE baDa[20];
    BYTE bDaLen;
    BYTE baMessage[300];
    USHORT usMessageLen;
} stSMS_Submit;

typedef struct
{
    BYTE bVp;
    BYTE bDcs;
    BYTE baDa[128];
    BYTE bDaLen;
    BYTE baMessage[1340];
    USHORT usMessageLen;
} stSMS_Unicode_Submit;

// General
USHORT CTOS_GSMOpen(ULONG ulBaud, BYTE bInit);
USHORT CTOS_GSMClose(void);
void CTOS_GSMReset(void);
USHORT CTOS_GSMPowerOn(void);
USHORT CTOS_GSMPowerOff(void);
USHORT CTOS_GSMSendATCmd(BYTE *baCmd, ULONG ulLen, ULONG ulTimeout);
USHORT CTOS_GSMSendData(BYTE *baData, USHORT usLen);
USHORT CTOS_GSMRecvData(BYTE *baData, USHORT *pusLen);
USHORT CTOS_GSMGetModuleOpMode(BYTE *pbOpMode);
USHORT CTOS_GSMSwitchToCmdMode(void);
USHORT CTOS_GSMSwitchToCmdMode_A(void);
USHORT CTOS_GSMSwitchToDataMode(void);
USHORT CTOS_GSMInfo(BYTE *pbManufacturer, BYTE *pbModel, BYTE *baRevision);
USHORT CTOS_GSMGetIMEI(BYTE *pbInfo);
USHORT CTOS_GSMGetNetworkType(BYTE *pbType);
USHORT CTOS_GSMQueryOperatorName(BYTE *baName, BYTE *bpLen);
USHORT CTOS_GSMSignalQuality(BYTE *bpStrength);
USHORT CTOS_GSMSetBAND(BYTE bID);
USHORT CTOS_GSMGetBAND(BYTE *bID);
USHORT CTOS_GSMPowerMode(BYTE bMode);
USHORT CTOS_GSMRS232Open(void);
USHORT CTOS_GSMRS232OpenEx(ULONG ulBaudRate, BYTE bParity, BYTE bDataBits, BYTE bStopBits);
USHORT CTOS_GSMRS232Close(void);
USHORT CTOS_GSMIOControl(BYTE bGPIO, BOOL boHigh);

// SIM Control
USHORT CTOS_GSMSelectSIM(BYTE bID);
USHORT CTOS_GSMGetCurrentSIM(BYTE* bID);
USHORT CTOS_SIMCheckReady(void);
USHORT CTOS_SIMGetIMSI(BYTE *pbInfo);

// Call Control
USHORT CTOS_GSMDial(BYTE *baNumber, BYTE bLen);
USHORT CTOS_GSMHangup(void);

// Network
USHORT CTOS_GPRSGetRegState(BYTE *baState);
USHORT CTOS_GPRSAttach(BYTE *baAPN, BYTE bAPNLen);
USHORT CTOS_GPRSDetach(void);
USHORT CTOS_GPRSPPPConnect(void);

// Mobile Equipment Control
USHORT CTOS_PINGetAuthStatus(void);
USHORT CTOS_PINVerify(BYTE bPinType, BYTE *baPin, BYTE bPinLen);
USHORT CTOS_PINCheckLock(BYTE locktype);
USHORT CTOS_PINLock(BYTE locktype, BYTE *pin, BYTE pinlen);
USHORT CTOS_PINUnLock(BYTE locktype, BYTE *pin, BYTE pinlen);
USHORT CTOS_PINUpdate(BYTE pintype, BYTE *oldpin, BYTE oldpinlen, BYTE *newpin, BYTE newpinlen);
USHORT CTOS_GSMPUKVerify (BYTE bPinType,BYTE *baPuk, BYTE bPukLen,BYTE *baNewPin, BYTE bNewPinLen);


// Phone Book
USHORT CTOS_PBSelect(BYTE bPhoneBookType, BYTE *pbUsed, BYTE *pbCapacity);
USHORT CTOS_PBRead(BYTE bIndex, stPhoneBook *pstPhoneBook);
USHORT CTOS_PBWrite(stPhoneBook *pstPhoneBook);
USHORT CTOS_PBDelete(BYTE bIndex);

//SMS
USHORT CTOS_SMSSetSCNumber(BYTE *baNumber, BYTE bLen);
USHORT CTOS_SMSGetSCNumber(BYTE *baNumber, BYTE *pbLen);
USHORT CTOS_SMSGetList(BYTE bStorage, stSMS *pstSMS, BYTE *pbNum);
USHORT CTOS_SMSRead(BYTE bIndex, stSMS *pstSMS);
USHORT CTOS_SMSDelete(BYTE bIndex);
USHORT CTOS_SMSSend(stSMS_Submit *pstSMS, BYTE *pbIndex);
USHORT CTOS_SMSSendPDU(BYTE *baPDU, ULONG ulLen, BYTE *pbIndex);
USHORT CTOS_SMSUnicodeSend(BYTE bMode, stSMS_Unicode_Submit *pstSMS, BYTE *pbIndex);

//=============================================================================================================================
//
// Mobile Functions
//
//=============================================================================================================================
#define d_MOBILE_NETWORK_GPRS			0x0001
#define d_MOBILE_NETWORK_UMTS			0x0002
#define d_MOBILE_NETWORK_CDMA			0x0004
#define d_MOBILE_NETWORK_AUTO			0x8000

USHORT CTOS_MobileSetNetworkType(USHORT usType);
USHORT CTOS_MobileGetNetworkTypeCurrent(USHORT* pusType);
USHORT CTOS_MobileGetNetworkTypeSupport(USHORT* pusType);

//=============================================================================================================================
//
// TMS Functions
//
//=============================================================================================================================
#define	d_TMS_CONFIG_SET					0x00
#define	d_TMS_CONFIG_GET					0x01

// The option of configuration
#define	d_TMS_CONFIG_CONNECTION				0x00
#define	d_TMS_CONFIG_IP						0x01
#define	d_TMS_CONFIG_PORT					0x02
#define	d_TMS_CONFIG_LOCALIP				0x08
#define	d_TMS_CONFIG_TIME					0x0B
#define	d_TMS_CONFIG_SHOWMSG				0x0C
#define	d_TMS_CONFIG_AUTOCONNECT			0x0D
#define	d_TMS_CONFIG_TIMEOUT				0x0F
#define	d_TMS_CONFIG_APN					0x11
#define	d_TMS_CONFIG_ISP_ID					0x12
#define	d_TMS_CONFIG_ISP_PW					0x13
#define	d_TMS_CONFIG_M_TCP_MODE				0x14
#define	d_TMS_CONFIG_M_TCP_HANDSHAKE		0x15
#define	d_TMS_CONFIG_M_TCP_COUNTRYCODE		0x16
#define	d_TMS_CONFIG_M_TCP_PHONE			0x17
#define	d_TMS_CONFIG_M_TCP_TIMEOUT			0x18

// The type of connection
#define	d_CONNECTION_ETHERNET				0x02
#define	d_CONNECTION_GPRS					0x04
#define	d_CONNECTION_MODEMTCP				0x08

void	CTOS_TMSUtil(void);
void	CTOS_TMSUtil_Modem(BYTE bMode, BYTE bHandShake, BYTE bCountryCode, STR *strPhone, STR *strID, STR *strPW, ULONG ulTimeout);
void	CTOS_TMSUtil_GPRS(STR *strAPN, STR *strID, STR *strPW);
USHORT	CTOS_TMSConfig(IN BYTE bSetGet, IN BYTE bItem, INOUT BYTE *baValue);
USHORT	CTOS_TMSSetUploadFile(IN BYTE bRIndex, IN BYTE *baFileName, IN BYTE bDelete);
USHORT	CTOS_TMSGetUploadFile(IN BYTE bRIndex, IN BYTE *baFileName);
USHORT	CTOS_TMSGetStatus(OUT USHORT *usStatus);
void    CTOS_TMSUpdateByMMCI(BYTE *baMMCI, BYTE bShowUI);
USHORT  CTOS_TMSGetUpdateResult(void);

//=============================================================================================================================
//
// Font Functions
//
//=============================================================================================================================
// Font language
// ASCII < 0x80 is world-wide same
// ASCII >=0x80 is language dependent
#define d_TTF_C0_CONTROLS										  0x0000
#define d_TTF_BASIC_LATIN	 									  0x0020
#define d_TTF_C1_CONTROLS										  0x0080
#define d_TTF_LATIN_1_SUPPLEMENT                                  0x00A0
#define d_TTF_LATIN_EXTENDED_A                                    0x0100
#define d_TTF_LATIN_EXTENDED_B                                    0x0180
#define d_TTF_IPA_EXTENSIONS                                      0x0250
#define d_TTF_SPACING_MODIFIERS                                   0x02B0
#define d_TTF_COMBINING_DIACRITICS_MARKS                          0x0300
#define d_TTF_GREEK_AND_COPTIC                                    0x0370
#define d_TTF_CYRILLIC                                            0x0400
#define d_TTF_CYRILLIC_SUPPLEMENT                                 0x0500
#define d_TTF_ARMENIAN                                            0x0530
#define d_TTF_HEBREW                                              0x0590
#define d_TTF_ARABIC                                              0x0600
#define d_TTF_SYRIAC                                              0x0700
#define d_TTF_ARABIC_SUPPLEMENT                                   0x0750
#define d_TTF_THAANA                                              0x0780
#define d_TTF_N_KO                                                0x07C0
#define d_TTF_SAMARITAN                                           0x0800
#define d_TTF_MANDAIC                                             0x0840
#define d_TTF_DEVANAGARI                                          0x0900
#define d_TTF_BENGALI                                             0x0980
#define d_TTF_GURMUKHI                                            0x0A00
#define d_TTF_GUJARATI                                            0x0A80
#define d_TTF_ORIYA                                               0x0B00
#define d_TTF_TAMIL                                               0x0B80
#define d_TTF_TELUGU                                              0x0C00
#define d_TTF_KANNADA                                             0x0C80
#define d_TTF_MALAYALAM                                           0x0D00
#define d_TTF_SINHALA                                             0x0D80
#define d_TTF_THAI                                                0x0E00
#define d_TTF_LAO                                                 0x0E80
#define d_TTF_TIBETAN                                             0x0F00
#define d_TTF_MYANMAR                                             0x1000
#define d_TTF_GEORGIAN                                            0x10A0
#define d_TTF_HANGUL_JAMO                                         0x1100
#define d_TTF_ETHIOPIC                                            0x1200
#define d_TTF_ETHIOPIC_SUPPLEMENT                                 0x1380
#define d_TTF_CHEROKEE                                            0x13A0
#define d_TTF_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS               0x1400
#define d_TTF_OGHAM                                               0x1680
#define d_TTF_RUNIC                                               0x16A0
#define d_TTF_TAGALOG                                             0x1700
#define d_TTF_HANUNOO                                             0x1720
#define d_TTF_BUHID                                               0x1740
#define d_TTF_TAGBANWA                                            0x1760
#define d_TTF_KHMER                                               0x1780
#define d_TTF_MONGOLIAN                                           0x1800
#define d_TTF_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED      0x18B0
#define d_TTF_LIMBU                                               0x1900
#define d_TTF_TAI_LE                                              0x1950
#define d_TTF_NEW_TAI_LUE                                         0x1980
#define d_TTF_KHMER_SYMBOLS                                       0x19E0
#define d_TTF_BUGINESE                                            0x1A00
#define d_TTF_TAI_THAM                                            0x1A20
#define d_TTF_BALINESE                                            0x1B00
#define d_TTF_SUNDANESE                                           0x1B80
#define d_TTF_BATAK                                               0x1BC0
#define d_TTF_LEPCHA                                              0x1C00
#define d_TTF_OL_CHIKI                                            0x1C50
#define d_TTF_SUDANESE_SUPPLEMENT                                 0x1CC0
#define d_TTF_VEDIC_EXTENSIONS                                    0x1CD0
#define d_TTF_PHONETIC_EXTENSIONS                                 0x1D00
#define d_TTF_PHONETIC_EXTENSIONS_SUPPLEMENT                      0x1D80
#define d_TTF_COMBINING_DIACRITICS_MARKS_SUPPLEMENT               0x1DC0
#define d_TTF_LATIN_EXTENDED_ADDITIONAL                           0x1E00
#define d_TTF_GREEK_EXTENDED                                      0x1F00
#define d_TTF_GENERAL_PUNCTUATION                                 0x2000
#define d_TTF_SUPERSCRIPTS_AND_SUBSCRIPTS                         0x2070
#define d_TTF_CURRENCY_SYMBOLS                                    0x20A0
#define d_TTF_COMBINING_DIACRITICS_MARKS_FOR_SYMBOLS              0x20D0
#define d_TTF_LETTERLIKE_SYMBOLS                                  0x2100
#define d_TTF_NUMBER_FORM                                         0x2150
#define d_TTF_ARROWS                                              0x2190
#define d_TTF_MATHEMATICAL_OPERATOR                               0x2200
#define d_TTF_MISCELLANEOUS_TECHNICAL                             0x2300
#define d_TTF_CONTROL_PICTURES                                    0x2400
#define d_TTF_OPTICAL_CHARACTER_RECOGNITION                       0x2440
#define d_TTF_ENCLOSED_ALPHANUMERICS                              0x2460
#define d_TTF_BOX_DRAWING                                         0x2500
#define d_TTF_BLOCK_ELEMENT                                       0x2580
#define d_TTF_GEOMETRIC_SHAPES                                    0x25A0
#define d_TTF_MISCELLANEOUS_SYMBOLS                               0x2600
#define d_TTF_DINGBATS                                            0x2700
#define d_TTF_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A                0x27C0
#define d_TTF_SUPPLEMENTAL_ARROWS_A                               0x27F0
#define d_TTF_BRAILLE_PATTERNS                                    0x2800
#define d_TTF_SUPPLEMENTAL_ARROWS_B                               0x2900
#define d_TTF_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B                0x2980
#define d_TTF_SUPPLEMENTAL_MATHEMATICAL_OPERATOR                  0x2A00
#define d_TTF_MISCELLANEOUS_SYMBOLS_AND_ARROWS                    0x2B00
#define d_TTF_GLAGOLITIC                                          0x2C00
#define d_TTF_LATIN_EXTENDED_C                                    0x2C60
#define d_TTF_COPTIC                                              0x2C80
#define d_TTF_GEORGIAN_SUPPLEMENT                                 0x2D00
#define d_TTF_TIFINAGH                                            0x2D30
#define d_TTF_ETHIOPIC_EXTENDED                                   0x2D80
#define d_TTF_SUPPLEMENTAL_PUNCTUATION                            0x2E00
#define d_TTF_CJK_RADICALS_SUPPLEMENT                             0x2E80
#define d_TTF_KANGXI_RADICALS                                     0x2F00
#define d_TTF_IDEOGRAPHIC_DESCRIPTION_CHARACTERS                  0x2FF0
#define d_TTF_CJK_SYMBOLS_AND_PUNCTUATION                         0x3000
#define d_TTF_HIRAGANA                                            0x3040
#define d_TTF_KATAKANA                                            0x30A0
#define d_TTF_BOPOMOFO                                            0x3100
#define d_TTF_HANGUL_COMPATIBILITY_JAMO                           0x3130
#define d_TTF_KANBUN                                              0x3190
#define d_TTF_BOPOMOFO_EXTENDED                                   0x31A0
#define d_TTF_CJK_STROKES                                         0x31C0
#define d_TTF_KATAKANA_PHONETIC_EXTENSIONS                        0x31F0
#define d_TTF_ENCLOSED_CJK_LETTERS_AND_MONTHS                     0x3200
#define d_TTF_CJK_COMPATIBILITY                                   0x3300
#define d_TTF_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A                  0x3400
#define d_TTF_YIJING_HEXAGRAMS_SYMBOLS                            0x4DC0
#define d_TTF_CJK_UNIFIED_IDEOGRAPHS                              0x4E00
#define d_TTF_YI_SYLLABLES                                        0xA000
#define d_TTF_YI_RADICALS                                         0xA490
#define d_TTF_LISU                                                0xA4D0
#define d_TTF_VAI                                                 0xA500
#define d_TTF_CYRILLIC_EXTENDED_B                                 0xA640
#define d_TTF_BAMUM                                               0xA6A0
#define d_TTF_MODIFIER_TONE_LETTERS                               0xA700
#define d_TTF_LATIN_EXTENDED_D                                    0xA720
#define d_TTF_SYLOTI_NAGRI                                        0xA800
#define d_TTF_IND_NO                                              0xA830
#define d_TTF_PHAGS_PA                                            0xA840
#define d_TTF_SAURASHTRA                                          0xA880
#define d_TTF_DEVA_EXT                                            0xA8E0
#define d_TTF_KAYAH_LI                                            0xA900
#define d_TTF_REJANG                                              0xA930
#define d_TTF_JAVANESE                                            0xA980
#define d_TTF_CHAM                                                0xAA00
#define d_TTF_MYANMAR_EXTA                                        0xAA60
#define d_TTF_TAI_VIET                                            0xAA80
#define d_TTF_MEETEI_EXT                                          0xAAE0
#define d_TTF_ETHIOPIC_EXT_A                                      0xAB00
#define d_TTF_MEETEI_MAYEK                                        0xABC0
#define d_TTF_HANGUL_SYLLABLES                                    0xAC00
#define d_TTF_HANGUL_JAMO_EXTENDED_B                              0xD7B0
#define d_TTF_HIGH_HALF_ZONE_OF_UTF_16                            0xD800
#define d_TTF_LOW_HALF_ZONE_OF_UTF_16                             0xDC00
#define d_TTF_PRIVATE_USE_ZONE                                    0xE000
#define d_TTF_CJK_COMPATIBILITY_IDEOGRAPHS                        0xF900
#define d_TTF_ALPHABETIC_PRESENTATION_FORMS      				  0xFB00
#define d_TTF_ARABIC_PRESENTATION_FORMS_A                         0xFB50
#define d_TTF_VARIATION_SELECTOR                                  0xFE00
#define d_TTF_VERTICAL_FORMS                                      0xFE10
#define d_TTF_COMBINING_HALF_MARKS                                0xFE20
#define d_TTF_CJK_COMPATIBILITY_FORMS                             0xFE30
#define d_TTF_SMALL_FORM_VARIANTS                                 0xFE50
#define d_TTF_ARABIC_PRESENTATION_FORMS_B                         0xFE70
#define d_TTF_HALFWIDTH_AND_FULLWIDTH_FORMS                       0xFF00
#define d_TTF_SPECIALS                                            0xFFF0

#define d_FONT_EMPTY   											  0		  //No font
#define d_FONT_CHINESE_TAIWAN   								  1028	  //Chinese(Taiwan)
#define d_FONT_CZECH											  1029	  //Czech
#define d_FONT_JAPANESE											  1041    //Japanese
#define d_FONT_KOREAN											  1042    //Korean
#define d_FONT_PORTUGUESE_BRAZIL        						  1046    //Portuguese(Brazil)
#define d_FONT_RUSSIAN											  1049    //Russian
#define d_FONT_THAI  											  1054    //Thai
#define d_FONT_TURKISH 											  1055    //Turkish
#define d_FONT_FARSI											  1065    //Farsi
#define d_FONT_VIETNAMESE										  1066    //Vietnamese
#define d_FONT_CHINESE_PRC										  2052    //Chinese(PRC)
#define d_FONT_CHINESE_PRC1										  2054    //Simple(Song)
#define d_FONT_PORTUGUESE_PORTUGAL								  2070	  //Portuguese(Portugal)
#define d_FONT_SPANISH 											  3082    //Spanish(Spain)
#define d_FONT_ARABIC_QATAR										  16385   //Arabic(Qatar)
#define d_FONT_CHINESE_TAIWAN_PLUS 								  64507	  //Chinese(Taiwan) with Symbol
#define d_FONT_DEFAULTASCII             						  36864
// Font size
#define d_FONT_8x8												  0x0808
#define d_FONT_8x16												  0x0810
#define d_FONT_16x16											  0x1010
#define d_FONT_12x24											  0x0C18
#define d_FONT_24x24											  0x1818
#define d_FONT_9x9												  0x0909
#define d_FONT_9x18												  0x0912
#define d_FONT_16x30											  0x101E
#define d_FONT_20x40											  0x1428

// for printer font type set
#define d_FONT_NO_SET_TYPE										  0
#define d_FONT_TYPE1											  1
#define d_FONT_TYPE2											  2
#define d_FONT_TYPE3											  3

// for font usage
#define d_FONT_LCD_USE											  0x00
#define d_FONT_PRINTER_USE										  0x01
#define d_FONT_FNT_MODE   										  0
#define d_FONT_TTF_MODE   										  1
#define	d_FONT_DEFAULT_TTF										  "ca_default.ttf"

USHORT CTOS_LanguageConfig(USHORT usLanguage,USHORT usFontSize,USHORT usFontStyle, BOOL boSetDefault);
USHORT CTOS_LanguageLCDFontSize(USHORT usFontSize,USHORT usFontStyle);
USHORT CTOS_LanguagePrinterFontSize(USHORT usFontSize,USHORT usFontStyle, USHORT usSetType);
USHORT CTOS_LanguageInfo(USHORT usIndex,USHORT* pusLanguage,USHORT* pusFontSize,USHORT* pusFontStyle);
USHORT CTOS_LanguageNum(USHORT* pusIndex);
USHORT CTOS_LanguagePrinterSelectASCII(USHORT usASCIIFontID);
USHORT CTOS_LanguageLCDSelectASCII(USHORT usASCIIFontID);
USHORT CTOS_LanguagePrinterGetFontInfo(USHORT* usASCIIFontID,USHORT* usFontSize,USHORT* usFontStyle);
USHORT CTOS_LanguageLCDGetFontInfo(USHORT* usASCIIFontID,USHORT* usFontSize,USHORT* usFontStyle);

//----------------------------------------------------------------------
// FONT Definition
//----------------------------------------------------------------------
// font device definition
#define d_FONT_DEVICE_LCD_0													0x00
#define d_FONT_DEVICE_LCD_1													0x01
#define d_FONT_DEVICE_PRINTER												0x80

// font style definition
#define d_FONT_STYLE_NORMAL													0x0000
#define d_FONT_STYLE_REVERSE												0x0001
#define d_FONT_STYLE_UNDERLINE												0x0002
#define d_FONT_STYLE_BOLD													0x0004
#define d_FONT_STYLE_ITALIC													0x0010

// FNT Lauguage definition
#define d_FNT_LANGUAGE_ALPHABET												0x0000
#define d_FNT_LANGUAGE_CHINESE_TRADITIONAL   								0x0001	//Chinese(Traiditional)
#define d_FNT_LANGUAGE_CHINESE_SIMPLIFIED									0x0002    //Chinese(Simplified)
#define d_FNT_LANGUAGE_JAPANESE												0x0003    //Japanese
#define d_FNT_LANGUAGE_THAI  												0x0004    //Thai
#define d_FNT_LANGUAGE_VIETNAMESE										 	0x0005    //Vietnamese
#define d_FNT_LANGUAGE_KOREAN												0x0006    //Korean
#define d_FNT_LANGUAGE_RUSSIAN											 	0x0007	//Russian
#define d_FNT_LANGUAGE_PORTUGUESE_PORTUGAL								  	d_FNT_LANGUAGE_ALPHABET
#define d_FNT_LANGUAGE_SPANISH												d_FNT_LANGUAGE_ALPHABET
#define d_FNT_LANGUAGE_TURKISH 											  	d_FNT_LANGUAGE_ALPHABET
#define d_FNT_LANGUAGE_FARSI											 	d_FNT_LANGUAGE_ALPHABET

#define d_FNT_LANGUAGE_PORTUGUESE_BRAZIL        							d_FNT_LANGUAGE_ALPHABET
#define d_FNT_LANGUAGE_CZECH												d_FNT_LANGUAGE_ALPHABET
#define d_FNT_LANGUAGE_ARABIC_QATAR											d_FNT_LANGUAGE_ALPHABET

// FNT FontID definition
#define d_FNT_FONTID_EMPTY   												0		//No font
#define d_FNT_FONTID_CHINESE_TAIWAN   										1028	//Chinese(Taiwan)
#define d_FNT_FONTID_CZECH													1029	//Czech
#define d_FNT_FONTID_JAPANESE												1041    //Japanese
#define d_FNT_FONTID_KOREAN													1042    //Korean
#define d_FNT_FONTID_PORTUGUESE_BRAZIL        								1046    //Portuguese(Brazil)
#define d_FNT_FONTID_RUSSIAN												1049    //Russian
#define d_FNT_FONTID_THAI  													1054    //Thai
#define d_FNT_FONTID_TURKISH 												1055    //Turkish
#define d_FNT_FONTID_FARSI													1065    //Farsi
#define d_FNT_FONTID_VIETNAMESE												1066    //Vietnamese
#define d_FNT_FONTID_CHINESE_PRC											2052    //Chinese(PRC)
#define d_FNT_FONTID_CHINESE_PRC1											2054    //Simple(Song)
#define d_FNT_FONTID_PORTUGUESE_PORTUGAL									2070	//Portuguese(Portugal)
#define d_FNT_FONTID_SPANISH 												3082    //Spanish(Spain)
#define d_FNT_FONTID_ARABIC_QATAR											16385   //Arabic(Qatar)
#define d_FNT_FONTID_CHINESE_TAIWAN_PLUS 									64507	//Chinese(Taiwan) with Symbol
#define d_FNT_FONTID_DEFAULTASCII             								36864
//----------------------------------------------------------------------
// Font functions
//----------------------------------------------------------------------
// FONT mode (TTF/FNT) selection
USHORT CTOS_FontSelectMode(BYTE bDevice,BYTE bMode);
// FNT mode
USHORT CTOS_FontFNTNum(USHORT* pusIndex);
USHORT CTOS_FontFNTInfo(USHORT usIndex,USHORT* pusFontID,USHORT* pusFontSize/*,USHORT* pusFontStyle*/);
USHORT CTOS_FontFNTSelectLanguage(BYTE bDevice,USHORT usLanguage);
USHORT CTOS_FontFNTSelectFont(BYTE bDevice,USHORT usFontID);
USHORT CTOS_FontFNTSelectASCIIFont(BYTE bDevice,USHORT usFontID);
USHORT CTOS_FontFNTSelectStyle(BYTE bDevice,USHORT usStyle);
USHORT CTOS_FontFNTSelectSize(BYTE bDevice,USHORT usFontSize);

// TTF mode
USHORT CTOS_FontTTFCheckSupport(ULONG ulEncoding, BOOL *fSupported );
USHORT CTOS_FontTTFSelectFontFile(BYTE bDevice,BYTE *baFontFileName, BYTE bIndex);
USHORT CTOS_FontTTFSelectStyle(BYTE bDevice,USHORT usStyle);
USHORT CTOS_FontTTFSelectSize(BYTE bDevice,USHORT usFontSize);
USHORT CTOS_FontTTFSwichDisplayMode(BYTE bDevice, USHORT usMode);

//----------------------------------------------------------------------
// LCD Definition
//----------------------------------------------------------------------
#define d_LCD_DEVICE_0													d_FONT_DEVICE_LCD_0
#define d_LCD_DEVICE_1													d_FONT_DEVICE_LCD_1

//----------------------------------------------------------------------
// LCD control functions
//----------------------------------------------------------------------
// General
USHORT CTOS_MultiLCDSelectMode(BYTE bDeviceNo, BYTE bMode, BOOL fClear);
USHORT CTOS_MultiLCDSetContrast(BYTE bDeviceNo, BYTE bValue);
USHORT CTOS_MultiLCDReflesh(BYTE bDeviceNo);
USHORT CTOS_MultiLCDSetForeGndColor(BYTE bDeviceNo,ULONG ulColor);
USHORT CTOS_MultiLCDSetBackGndColor(BYTE bDeviceNo,ULONG ulColor);
USHORT CTOS_MultiLCDGetResolution(BYTE bDeviceNo, USHORT *pusXsize, USHORT *pusYsize);
// Graphic Mode
USHORT CTOS_MultiLCDGClearCanvas(BYTE bDeviceNo);
USHORT CTOS_MultiLCDGPixel(BYTE bDeviceNo, USHORT usX,USHORT usY, BOOL boPat);
USHORT CTOS_MultiLCDGTextOut(BYTE bDeviceNo, USHORT usX, USHORT usY, UCHAR* pusBuf, USHORT usFontSize, BOOL boReverse);
USHORT CTOS_MultiLCDGSetBox(BYTE bDeviceNo, USHORT usX, USHORT usY, USHORT usXSize, USHORT usYSize, BYTE bFill);
USHORT CTOS_MultiLCDGShowPic(BYTE bDeviceNo, USHORT usX, USHORT usY, BYTE* baPat, ULONG ulPatLen, USHORT usXSize);
USHORT CTOS_MultiLCDGClearWindow(BYTE bDeviceNo);
USHORT CTOS_MultiLCDGMoveWindow(BYTE bDeviceNo, USHORT usOffset);
USHORT CTOS_MultiLCDGGetWindowOffset(BYTE bDeviceNo);
USHORT CTOS_MultiLCDGShowPicEx(BYTE bDeviceNo, UCHAR bMode,USHORT usX, USHORT usY, BYTE* baPat, ULONG ulPatLen, USHORT usXSize);
// Text Mode
USHORT CTOS_MultiLCDTClearDisplay(BYTE bDeviceNo);
USHORT CTOS_MultiLCDTGotoXY(BYTE bDeviceNo, USHORT usX,USHORT usY);
USHORT CTOS_MultiLCDTWhereX(BYTE bDeviceNo);
USHORT CTOS_MultiLCDTWhereY(BYTE bDeviceNo);
USHORT CTOS_MultiLCDTPrint(BYTE bDeviceNo, UCHAR* sBuf);
USHORT CTOS_MultiLCDTPrintXY(BYTE bDeviceNo, USHORT usX, USHORT usY, UCHAR* pbBuf);
USHORT CTOS_MultiLCDTPutch(BYTE bDeviceNo, UCHAR bChar);
USHORT CTOS_MultiLCDTPutchXY (BYTE bDeviceNo, USHORT usX, USHORT usY, UCHAR bChar);
USHORT CTOS_MultiLCDTClear2EOL(BYTE bDeviceNo);
USHORT CTOS_MultiLCDTSetASCIIVerticalOffset(BYTE bDeviceNo, BOOL fVDirection, BYTE bVOffect);
USHORT CTOS_MultiLCDTSetASCIIHorizontalOffset(BYTE bDeviceNo, BOOL fHDirection, BYTE bHOffect);

// future function
//USHORT CTOS_LCDTMenu();
//USHORT CTOS_UIKeypad();
//USHORT CTOS_LCDGMenu();
//USHORT CTOS_FontFNTGetInfo(BYTE bDevice, USHORT* usFontID, USHORT* usASCIIFontID,USHORT* usFontSize,USHORT* usFontStyle);
//USHORT CTOS_FontTTFGetInfo(BYTE bDevice, USHORT* baFontFileName,USHORT* usFontSize,USHORT* usFontStyle);
//-----------------------------------------------------

//=============================================================================================================================
//
// LCD Functions
//
//=============================================================================================================================

// Graphic mode canvas x/y size
#define d_LCD_CANVAS_X_SIZE 									  128
#define d_LCD_CANVAS_Y_SIZE 									  (64*4)
// Graphic/text mode window x/y size
#define d_LCD_WINDOW_X_SIZE 									  128
#define d_LCD_WINDOW_Y_SIZE 									  64
// value for bMode
#define d_LCD_GRAPHIC_MODE										  0
#define d_LCD_TEXT_MODE											  1
#define d_LCD_GRAPHIC_HIGH_RES_MODE						  		  3
#define d_LCD_TEXT_HIGH_RES_MODE						  		  4

// value for English Size
#define d_LCD_FONT_8x8											  d_FONT_8x8
#define d_LCD_FONT_8x16											  d_FONT_8x16
#define d_LCD_FONT_12x24										  d_FONT_12x24

// value for bFill
#define d_LCD_FILL_0											  0
#define d_LCD_FILL_1											  1
#define d_LCD_FILL_XOR											  2

// for font shift
#define d_LCD_SHIFTLEFT											  0
#define d_LCD_SHIFTRIGHT										  1
#define d_LCD_SHIFTUP											  0
#define d_LCD_SHIFTDOWN											  1
#define d_LCD_WHITE 											  0xFFFFFF
#define d_LCD_BLACK 											  0x000000
#define d_LCD_BLUE 												  0xFF0000
#define d_LCD_GREEN 											  0x00FF00
#define d_LCD_RED 												  0x0000FF

// for show pic mode
#define d_LCD_SHOWPIC_MONO  									  0
#define d_LCD_SHOWPIC_RGB  										  1

#define d_LCD_ALIGNLEFT											  0
#define d_LCD_ALIGNCENTER										  1
#define d_LCD_ALIGNRIGHT										  2

// for usMode CTOS_LCDTTFSwichDisplayMode()
#define d_TTF_MODE_DEFAULT                						  0x0000
#define d_TTF_MODE_VIETNAM                						  0xA001
#define d_TTF_MODE_BURMA									  	  0xA002
#define d_TTF_MODE_KHMER										  0xA003

//for LCD attribute
#define d_RESOLUTION_480x320		  ((480 << 16) | 320)
#define d_RESOLUTION_320x480          ((320 << 16) | 480)
#define d_RESOLUTION_320x240          ((320 << 16) | 240)
#define d_RESOLUTION_128x64			  ((128 << 16) | 64)
#define d_RESOLUTION_128x32			  ((128 << 16) | 32)
#define d_COLOR_MONO  			                                  1
#define d_COLOR_262K       		                                  2
#define d_COLOR_16M        		                                  3
#define d_TOUCH_NONE	   		                                  0
#define d_TOUCH_RESISTOR   		                                  1
#define d_TOUCH_CAPACITOR_1P	                                  2



// For CTOS_LCDGMenu().
enum TAttribute {
    _taNormal  = 0x00,
    _taReverse = 0x01,
    //_taClrOne  = 0x02,
    _taRight   = 0x04,
    _taCenter  = 0x08,
    _taErrCode = 0x10,
    _taDelay   = 0x20
};
// For CTOS_LCDTMenu().
enum TAttribute_T {
    _taTNormal  = 0x00,
    _taTReverse = 0x01,
    //_taTClrOne  = 0x02,
    _taTRight   = 0x04,
    _taTCenter  = 0x08,
    _taTErrCode = 0x10,
    _taTDelay   = 0x20
};

// For CTOS_UIKeypad().
#define d_UI_KEYPAD_ENGLISH {" 0", "qzQZ1", "abcABC2", "defDEF3", "ghiGHI4", "jklJKL5", "mnoMNO6", "prsPRS7", "tuvTUV8", "wxyWXY9", ":;/\\|?,.<>", ".!@#$%^&*()"}
#define d_UI_KEYPAD_NUM_RAD {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", "."}
#define d_UI_KEYPAD_NUM {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "", ""}

// General
USHORT CTOS_LCDSelectMode(BYTE bMode);
USHORT CTOS_LCDSelectModeEx(BYTE bMode,BOOL fClear);
USHORT CTOS_LCDSetContrast(BYTE bValue);
USHORT CTOS_LCDReflesh(void);
USHORT CTOS_LCDForeGndColor(ULONG ulColor);
USHORT CTOS_LCDBackGndColor(ULONG ulColor);
USHORT CTOS_LCDFontSelectMode(BYTE bMode);
USHORT CTOS_LCDTTFSelect(BYTE *baFilename, BYTE bIndex);
USHORT CTOS_LCDTTFCheckLanguageSupport(ULONG ulLanguage, BOOL *fSupported );
USHORT CTOS_LCDTTFSwichDisplayMode(USHORT usMode);
USHORT CTOS_LCDGetResolution(USHORT *pusXsize, USHORT *pusYsize);
USHORT CTOS_LCDAttributeGet(ULONG *pulResolution, BYTE *pbColor, BYTE *pbTouch);



// Graphic Mode
USHORT CTOS_LCDGClearCanvas(void);
USHORT CTOS_LCDGPixel(USHORT usX,USHORT usY, BOOL boPat);
USHORT CTOS_LCDGTextOut(USHORT usX, USHORT usY, UCHAR* pusBuf, USHORT usFontSize, BOOL boReverse);
USHORT CTOS_LCDGSetBox(USHORT usX, USHORT usY, USHORT usXSize, USHORT usYSize, BYTE bFill);
USHORT CTOS_LCDGShowPic(USHORT usX, USHORT usY, BYTE* baPat, ULONG ulPatLen, USHORT usXSize);
USHORT CTOS_LCDGClearWindow(void);
USHORT CTOS_LCDGMoveWindow(USHORT usOffset);
USHORT CTOS_LCDGGetWindowOffset(void);
USHORT CTOS_LCDGMenu(BYTE bAttribute, STR *pbaHeaderString, STR *pcaItemString);
USHORT CTOS_LCDGMenuEx(BYTE bAttribute, STR *pbaHeaderString, STR *pcaItemString,USHORT usShowItem);
USHORT CTOS_LCDGShowPicEx(UCHAR bMode,USHORT usX, USHORT usY, BYTE* baPat, ULONG ulPatLen, USHORT usXSize);
USHORT CTOS_LCDGShowBMPPic(USHORT usX, USHORT usY, BYTE *baFilename);

// Text Mode
USHORT CTOS_LCDTClearDisplay(void);
USHORT CTOS_LCDTGotoXY(USHORT usX,USHORT usY);
USHORT CTOS_LCDTWhereX(void);
USHORT CTOS_LCDTWhereY(void);
USHORT CTOS_LCDTPrint(UCHAR* sBuf);
USHORT CTOS_LCDTPrintXY(USHORT usX, USHORT usY, UCHAR* pbBuf);
USHORT CTOS_LCDTPutch(UCHAR ch);
USHORT CTOS_LCDTPutchXY (USHORT usX, USHORT usY, UCHAR bChar);
USHORT CTOS_LCDTClear2EOL(void);
USHORT CTOS_LCDTSetReverse(BOOL boReverse);
USHORT CTOS_LCDTSelectFontSize(USHORT usFontSize);
USHORT CTOS_LCDTSetASCIIVerticalOffset(BOOL fVDirection, BYTE bVOffect);
USHORT CTOS_LCDTSetASCIIHorizontalOffset(BOOL fHDirection, BYTE bHOffect);
USHORT CTOS_LCDTMenu(BYTE bAttribute, STR *pbaHeaderString, STR *pcaItemString);
USHORT CTOS_LCDTPrintAligned(USHORT usY, UCHAR* pbBuf, BYTE bMode);

// User Mode
void CTOS_LCDUClearDisplay(void);
void CTOS_LCDUInit(BYTE bCXSize, BYTE bCYSize, BYTE bTWXSize, BYTE bTWYSize, BYTE *baPattern);
USHORT CTOS_LCDUPrintXY(USHORT usX, USHORT usY, BYTE *pbBuf);
USHORT CTOS_LCDUPrint(BYTE *pbBuf);
USHORT CTOS_UIKeypad(USHORT usX, USHORT usY, STR *pcaKeyboardLayout[], UCHAR ucCursorBlinkInterval, UCHAR ucDelayToNextChar, BOOL boEnableCursorMove, BOOL boOneRadixPointOnly, UCHAR ucDigitAfterRadixPoint, BYTE bPasswordMask, STR caData[], UCHAR ucDataLen);
//=============================================================================================================================
//
// Keyboard Functions
//
//=============================================================================================================================

#define d_KBD_INVALID						0xFF

#define d_KBD_1                                                         '1'
#define d_KBD_2                                                         '2'
#define d_KBD_3                                                         '3'
#define d_KBD_4                                                         '4'
#define d_KBD_5                                                         '5'
#define d_KBD_6                                                         '6'
#define d_KBD_7                                                         '7'
#define d_KBD_8                                                         '8'
#define d_KBD_9                                                         '9'
#define d_KBD_0                                                         '0'

#define d_KBD_K1                                                        'X'
#define d_KBD_K2                                                        'Y'
#define d_KBD_K3                                                        'I'
#define d_KBD_K4                                                        'J'
#define d_KBD_UP							'U'
#define d_KBD_DOWN							'D'

#define d_KBD_CANCEL                                                    'C'
#define d_KBD_CLEAR                                                     'R'
#define d_KBD_ENTER							'A'
#define d_KBD_DOT							'Q'
#define d_KBD_00							'P'

#define d_KBD_X                                                         'Q'
#define d_KBD_COMMA                                                     'P'

#define d_KBD_CREDITCARD                                                'D'
#define d_KBD_SUBTOTAL                                                  'S'
#define d_KBD_POWER                                                     'W'
#define d_KBD_PERCENTAGE                                                'E'
#define d_KBD_PLU                                                       'U'

#define d_KBD_F1                                                        'X'
#define d_KBD_F2                                                        'Y'
#define d_KBD_F3                                                        'I'
#define d_KBD_F4                                                        'J'
#define d_KBD_F5                                                        'K'
#define d_KBD_F6                                                        'L'
#define d_KBD_F7                                                        'M'
#define d_KBD_F8                                                        'N'

USHORT CTOS_KBDGet(BYTE* pbKey);
USHORT CTOS_KBDHit(BYTE* pbKey);
USHORT CTOS_KBDSetSound(BYTE bOnOff);
USHORT CTOS_KBDSetFrequence(USHORT usFreq, USHORT usDuration);
USHORT CTOS_KBDInKey(BOOL* fKeyIn);
USHORT CTOS_KBDInKeyCheck(BYTE *pbKey);
USHORT CTOS_KBDSetResetEnable(BOOL boIsEnable);
USHORT CTOS_KBDScan(BYTE *pbKey);

USHORT CTOS_KBDBufCheck(BOOL *fKeyPressed);
USHORT CTOS_KBDBufGet(UCHAR *bKey);
USHORT CTOS_KBDBufPut(UCHAR bKey);
USHORT CTOS_KBDBufFlush(void);

//=============================================================================================================================
//
// Printer Functions
//
//=============================================================================================================================
#define PAPER_X_SIZE			384

typedef struct
{
	USHORT FontSize;
	USHORT X_Zoom;
	USHORT Y_Zoom;
	USHORT X_Space;
	USHORT Y_Space;
} CTOS_FONT_ATTRIB;

USHORT CTOS_PrinterPutString(UCHAR* baBuf);
USHORT CTOS_PrinterLogo(BYTE* baLogo, USHORT usXstart, USHORT usXsize, USHORT usY8Size);
USHORT CTOS_PrinterFline(USHORT usLines);
USHORT CTOS_PrinterStatus(void);
USHORT CTOS_PrinterBMPPic(USHORT usX, BYTE *baFilename);

// TTF
USHORT CTOS_PrinterFontSelectMode(BYTE bMode);
USHORT CTOS_PrinterTTFSelect(BYTE *baFilename, BYTE bIndex);
USHORT CTOS_PrinterTTFCheckLanguageSupport(ULONG ulLanguage, BOOL *fSupported );
USHORT CTOS_PrinterTTFSwichDisplayMode(USHORT usMode);

USHORT CTOS_PrinterBufferPutString(BYTE* pbPtr, USHORT usXPos, USHORT usYPos, BYTE *baStr, CTOS_FONT_ATTRIB* ATTRIB);
USHORT CTOS_PrinterBufferOutput(BYTE* pbPtr, USHORT usY8Len);
USHORT CTOS_PrinterSetWorkTime(USHORT usWorkTime, USHORT usCoolTime);
USHORT CTOS_PrinterSetHeatLevel(UCHAR bHeatLevel);

USHORT CTOS_PrinterCodaBarBarcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterCode39Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterEAN13Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterCode128Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterInterleaved2of5Barcode(USHORT x, USHORT y, BYTE *baCodeContent, BYTE bContentLen, BYTE bXExtend, BYTE bY8Extend, BOOL bShowChar);

//=============================================================================================================================
//
// Printer Buffer Functions
//
//=============================================================================================================================
#define PB_CANVAS_X_SIZE			384
#define PB_CANVAS_Y_SIZE 			80
#define MAX_PB_CANVAS_NUM			2

#define d_ORIGINAL					0x01
#define d_DOUBLE					0x02
#define d_ONE_AND_HALF				0x13		//Enlarge 1.5

void CTOS_PrinterBufferEnable(void);
USHORT CTOS_PrinterBufferInit(BYTE* pPtr, USHORT usHeight);
USHORT CTOS_PrinterBufferSelectActiveAddress (BYTE *pPtr);
USHORT CTOS_PrinterBufferFill(USHORT usXStart, USHORT usYStart, USHORT usXEnd, USHORT usYEnd, BOOL fPat);
USHORT CTOS_PrinterBufferHLine(USHORT usXStart, USHORT usYStart, USHORT usXEnd, BOOL fPat);
USHORT CTOS_PrinterBufferVLine(USHORT usXStart, USHORT usYStart, USHORT usYEnd, BOOL fPat);
USHORT CTOS_PrinterBufferLogo(USHORT usXPos, USHORT usYPos, USHORT usWidth, USHORT usHeight, BYTE *baPat);
USHORT CTOS_PrinterBufferPixel(USHORT usXPos, USHORT usYPos,BOOL fPat);
USHORT CTOS_PrinterBufferEAN13Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterBufferCodaBarBarcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterBufferCode39Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterBufferCode128Barcode(IN USHORT x, IN USHORT y, IN BYTE *baCodeContent, IN BYTE bContentLen, IN BYTE bXExtend, IN BYTE bY8Extend, IN BOOL bShowChar);
USHORT CTOS_PrinterBufferInterleaved2of5Barcode(USHORT x, USHORT y, BYTE *baCodeContent, BYTE bContentLen, BYTE bXExtend, BYTE bY8Extend, BOOL bShowChar);
USHORT CTOS_PrinterBufferBMPPic(BYTE* pbPtr, USHORT usXPos, USHORT usYPos, BYTE *baFilename);
//=============================================================================================================================
//
// Smart Card  & Memory Card Functions
//
//=============================================================================================================================

// value for bID
#define d_SC_USER							0
#define d_SC_SAM1							1
#define d_SC_SAM2							2
#define d_SC_SAM3							3
#define d_SC_SAM4							4
#define d_SC_MAX_SOCKET						4

// value for bVolt
#define d_SC_5V								1
#define d_SC_3V								2
#define d_SC_1_8V							3

// mask for bStatus
#define d_MK_SC_PRESENT						1
#define d_MK_SC_ACTIVE						2

// value for CardType of CTOS_ATR
#define d_SC_TYPE_T0						0
#define	d_SC_TYPE_T1						1
#define	d_SC_TYPE_MEM						2
#define d_SC_TYPE_I2C						3
#define d_SC_TYPE_RFU						4

USHORT CTOS_SCStatus(BYTE bID, BYTE* baStatus);
USHORT CTOS_SCPowerOff(BYTE bID);
USHORT CTOS_SCEnterTIBC(BYTE bID);
USHORT CTOS_SCResetEMV(BYTE bID, BYTE bVolt, BYTE* baATR, BYTE* baATRLen, BYTE* baCardType);
USHORT CTOS_SCResetISO(BYTE bID, BYTE bVolt, BYTE* baATR, BYTE* baATRLen, BYTE* baCardType);
USHORT CTOS_SCWarmResetEMV(BYTE bID, BYTE bVolt, BYTE* baATR, BYTE* baATRLen, BYTE* baCardType);
USHORT CTOS_SCWarmResetISO(BYTE bID, BYTE bVolt, BYTE* baATR, BYTE* baATRLen, BYTE* baCardType);
USHORT CTOS_SCCommonReset(BYTE bID, BYTE bTA1, BOOL fColdReset, BOOL fEMV, BOOL fPTS, BOOL fIFSD, BYTE bVolt, BYTE* baATR, BYTE* bATRLen, BYTE* bCardType);
USHORT CTOS_SCSendAPDU(BYTE bID, BYTE* baSBuf, USHORT usSLen, BYTE* baRBuf, USHORT* pusRLen);

USHORT CTOS_SCSetPBOC(BOOL fEnable);
//Memory Card Functions
USHORT CTOS_SyncICCReset(UCHAR* baBuf,BYTE* bLen);

USHORT CTOS_44x2ReadMainMemory(BYTE bAddr,UCHAR* baBuf,USHORT* usLen);
USHORT CTOS_44x2WriteMainMemory(BYTE bAddr,UCHAR* baBuf,USHORT usLen);
USHORT CTOS_44x2ReadProtectionMemory(UCHAR* baBuf);
USHORT CTOS_44x2SetProtectionBit(UCHAR bAddr);
USHORT CTOS_44x2ReadSecurityMemory(UCHAR* baBuf);
USHORT CTOS_44x2ChangePSC(UCHAR* baBuf);
USHORT CTOS_44x2VerifyPSC(UCHAR* baBuf);

USHORT CTOS_44x8WriteMemoryWithoutPBit(USHORT usAddr,UCHAR* baBuf,USHORT usLen);
USHORT CTOS_44x8WriteMemoryWithPBit(USHORT usAddr,UCHAR* baBuf,USHORT usLen);
USHORT CTOS_44x8WritePBitWithDataCompare(USHORT usAddr,UCHAR* baBuf,USHORT usLen);
USHORT CTOS_44x8ReadMemoryWithoutPBit(USHORT usAddr,UCHAR* baBuf,USHORT* usLen);
USHORT CTOS_44x8ReadMemoryWithPBit(USHORT usAddr,UCHAR* baBuf,UCHAR* baPBit,USHORT* usLen);
USHORT CTOS_44x8VerifyPSC(UCHAR* baBuf);

USHORT CTOS_44x6ReadData(UCHAR bAddr,UCHAR* baBuf,USHORT* usLen);
USHORT CTOS_44x6WriteData(UCHAR bAddr,UCHAR* baBuf,USHORT usLen);
USHORT CTOS_44x6Reload(BOOL fCounterBak,BYTE bBitNum);
USHORT CTOS_44x6VerifyTSC(UCHAR* baBuf);
USHORT CTOS_44x6Auth(BOOL fExtAuth,BYTE bKey,BYTE bNumClk,BYTE* baChallenge,BYTE* baRepBits);

USHORT CTOS_I2CCReset(UCHAR* baBuf,BYTE* bLen);
USHORT CTOS_I2CReadMemory(BYTE bCmd,BYTE bNumAddr,USHORT usAddr,BOOL fDummyRead,UCHAR* baBuf,USHORT* usLen);
USHORT CTOS_I2CWriteMemory(BYTE bCmd,BYTE bNumAddr,USHORT usAddr,UCHAR* baBuf,USHORT usLen);

USHORT CTOS_SLE44x4ReadMemory(BYTE bAddr,UCHAR* baBuf,BYTE* bLen);
USHORT CTOS_SLE44x4VerifyUserCode(UCHAR* baBuf);
USHORT CTOS_SLE44x4VerifyMemoryCode(UCHAR* baBuf);
USHORT CTOS_SLE44x4WriteMemory(BYTE bAddr,UCHAR* baBuf,BYTE bLen);
USHORT CTOS_SLE44x4EraseMemory(BYTE bAddr,BYTE bLen);
USHORT CTOS_SLE44x4BlowFuse(void);
USHORT CTOS_SLE44x4EnterTestMode(void);
USHORT CTOS_SLE44x4ExitTestMode(void);

USHORT CTOS_GPM896ReadMemory(BYTE bAddr,UCHAR* baBuf,BYTE* bLen);
USHORT CTOS_GPM896VerifySecurityCode(UCHAR* baKey);
USHORT CTOS_GPM896WriteMemory(BYTE bAddr,UCHAR* baBuf,BYTE bLen);
USHORT CTOS_GPM896EraseMemory(BYTE bAddr, BYTE bLen);
USHORT CTOS_GPM896EraseArea1(UCHAR* baKey);
USHORT CTOS_GPM896EraseArea2(UCHAR* baKey);

USHORT CTOS_SLE44x4ReadMemory(BYTE bAddr,UCHAR* baBuf,BYTE* bLen);
USHORT CTOS_SLE44x4VerifyUserCode(UCHAR* baBuf);
USHORT CTOS_SLE44x4VerifyMemoryCode(UCHAR* baBuf);
USHORT CTOS_SLE44x4WriteMemory(BYTE bAddr,UCHAR* baBuf,BYTE bLen);
USHORT CTOS_SLE44x4EraseMemory(BYTE bAddr,BYTE bLen);
USHORT CTOS_SLE44x4BlowFuse(void);
USHORT CTOS_SLE44x4EnterTestMode(void);
USHORT CTOS_SLE44x4ExitTestMode(void);

USHORT CTOS_GPM896ReadMemory(BYTE bAddr,UCHAR* baBuf,BYTE* bLen);
USHORT CTOS_GPM896VerifySecurityCode(UCHAR* baKey);
USHORT CTOS_GPM896WriteMemory(BYTE bAddr,UCHAR* baBuf,BYTE bLen);
USHORT CTOS_GPM896EraseMemory(BYTE bAddr, BYTE bLen);
USHORT CTOS_GPM896EraseArea1(UCHAR* baKey);
USHORT CTOS_GPM896EraseArea2(UCHAR* baKey);

//=============================================================================================================================
//
// MSR Functions
//
//=============================================================================================================================

// output value for bTkxErr
#define d_MSR_SUCCESS						0x00
#define d_MSR_STX_NOT_FOUND					0x81
#define d_MSR_NO_DATA						0x82
#define d_MSR_BUF_OVERFLOW					0x83
#define d_MSR_ETX_NOT_FOUND					0x84
#define d_MSR_LRC_NOT_FOUND					0x85
#define d_MSR_LRC_ERR						0x86
#define d_MSR_UNKNOWN_CHAR					0x87

// mask for return value of CTOS_MSRRead()
#define d_MK_MSR_TK1						0x0001
#define d_MK_MSR_TK2						0x0002
#define d_MK_MSR_TK3						0x0004
#define d_MK_MSR_TK1_ERR					0x0010
#define d_MK_MSR_TK2_ERR					0x0020
#define d_MK_MSR_TK3_ERR					0x0040

USHORT CTOS_MSRRead(BYTE* baTk1Buf, USHORT* pusTk1Len, BYTE* baTk2Buf, USHORT* pusTk2Len, BYTE* baTk3Buf, USHORT* pusTk3Len);
USHORT CTOS_MSRGetLastErr (BYTE* baTk1Err, BYTE* baTk2Err, BYTE* baTk3Err);

//=============================================================================================================================
//
// Power Saving Functions
//
//=============================================================================================================================
// value for bMode
#define	d_PWR_STANDBY_MODE				0x00
#define	d_PWR_SLEEP_MODE				0x01
#define	d_PWR_REBOOT					0x02
#define	d_PWR_POWER_OFF					0x03

// value for usWakeSrc
#define d_MK_WAKE_KBD					0x01
#define d_MK_WAKE_SC					0x02
#define d_MK_WAKE_MSR					0x04
#define d_MK_WAKE_RTC					0x08

// for bPwrType
#define d_PWRMNG_ENTER_STANDBY			1
#define d_PWRMNG_ENTER_SLEEP			2

// for bPwrEnable
#define d_PWRMNG_DISABLE				0
#define d_PWRMNG_ENABLE					1

#define d_PWR_ACTION_QUERY				0x0
#define d_PWR_ACTION_SET				0x1

#define d_PWR_STATUS_STANDBY			0x0
#define d_PWR_STATUS_SLEEP				0x1
#define d_PWR_STATUS_WORKING			0x2
#define d_PWR_STATUS_CANCEL				0x3

// definition for power state
#define d_PWRMNG_STATE_UNKNOWN			0
#define d_PWRMNG_STATE_ENTERING_STANDBY	1
#define d_PWRMNG_STATE_STANDBY			2
#define d_PWRMNG_STATE_ENTERING_SLEEP	3
#define d_PWRMNG_STATE_SLEEP			4
#define d_PWRMNG_STATE_WORKING			5


#define PWR_QUERY_STANDBY_SIGNAL		100
#define PWR_QUERY_SLEEP_SIGNAL			101
#define PWR_SET_STANDBY_SIGNAL			102
#define PWR_SET_SLEEP_SIGNAL			103
#define PWR_SET_WORKING_SIGNAL			104
#define PWR_QUERY_CANCEL_SIGNAL			105
#define PWR_SET_CANCEL_SIGNAL			106

// Power Source
#define d_PWRSRC_DCJACK      			0
#define d_PWRSRC_CRADLE      			1
#define d_PWRSRC_BATTERY     			2
#define d_PWRSRC_USB              3

// definition for battery status
#define d_MK_BATTERY_EXIST				0x00000001
#define d_MK_BATTERY_CHARGE				0x00000002
#define d_MK_BATTERY_FULL				0x00000004

USHORT CTOS_PwrMngDisable(void);
USHORT CTOS_PwrMngEnable(UCHAR bPwrType,ULONG ulPwrTime);
USHORT CTOS_PwrMngGetParameter(UCHAR* bPwrEnable, UCHAR* bPwrType, ULONG* ulPwrTime);
USHORT CTOS_PwrMngSetParameter(UCHAR bPwrEnable, UCHAR bPwrType, ULONG ulPwrTime);

USHORT CTOS_PwrMngRegisterCallBack(void *PwrCallBack);
USHORT CTOS_PwrMngUnRegisterCallBack(void);
USHORT CTOS_PwrMngSetBusy(void);
USHORT CTOS_PwrMngClearBusy(void);
USHORT CTOS_PwrMngGetBusy(BOOL *fBusy);
USHORT CTOS_PwrMngGetState(UCHAR *bState);

USHORT CTOS_PowerMode(BYTE bMode);
USHORT CTOS_PowerModeEX(BYTE bMode, USHORT *usWakeSrc);
void CTOS_PowerOff(void);
void CTOS_SystemReset(void);
USHORT CTOS_PowerSource(UCHAR* bSrc);
USHORT CTOS_PowerAwakening(SHORT sSecond, SHORT sMinute, SHORT sHour, SHORT sDay, SHORT sMonth, SHORT sYear);

USHORT CTOS_BatteryGetCapacity(BYTE* bPercentage);
USHORT CTOS_BatterySetChargeThreshold(UCHAR bPercentage);
USHORT CTOS_BatteryGetChargeThreshold(UCHAR* bPercentage);
USHORT CTOS_BatteryForceCharge(void);
USHORT CTOS_BatteryStatus(DWORD* pdwStatus);

// Auto PoWer Management
// for stCallback of CTOS_PowerAutoModeRegisterCallback()
typedef BOOL (*eventEnterPowerMode)(void* pData, BYTE bMode);
typedef BOOL (*eventExitPowerMode)(void* pData,BYTE bMode,USHORT *usWakeSrc);

typedef struct
{
 eventEnterPowerMode OnEnterPowerMode;
 void *pEnterPowerModeData;

 eventExitPowerMode OnExitPowerMode;
 void *pExitPowerModeData;

} CTOS_stPowerModeCallback;


USHORT CTOS_PowerAutoModeEnable(void);
USHORT CTOS_PowerAutoModeDisable(void);
USHORT CTOS_PowerAutoModeTimeToStandby(ULONG ulSec);
USHORT CTOS_PowerAutoModeTimeToSleep(ULONG ulSec);
USHORT CTOS_PowerAutoModeRegisterCallback(CTOS_stPowerModeCallback *stCallback);
USHORT CTOS_PowerAutoModeUNRegisterCallback(void);

//=============================================
// Power key event.
//=============================================

#define d_PKE_KEY_RELEASE 	0
#define d_PKE_KEY_PRESS		1
#define d_PKE_KEY_PRESSING	2

typedef BOOL (*eventPowerKey)(void *pData, BYTE Keystatus);

typedef struct
{
	eventPowerKey PowerKeyEventHandle;
	void *pPowerKeyEventData;
}CTOS_stPowerKeyCallback;

USHORT CTOS_PowerKeyEventRegisterCallback(CTOS_stPowerKeyCallback *stCallback);
USHORT CTOS_PowerKeyEventUNRegisterCallback(void);


//=============================================================================================================================
//---- Power Wakeup souce setting.
//=============================================================================================================================

#define d_PWR_WAKEUP_SRC_ALL			0x00
#define d_PWR_WAKEUP_SRC_KBD_ALL		0x01
#define d_PWR_WAKEUP_SRC_SC				0x02
#define d_PWR_WAKEUP_SRC_MSR			0x03
#define d_PWR_WAKEUP_SRC_BLUETOOTH		0x04

// All keys can be set to wakupe the device individually
// below are the definition for the common key among all devices
#define d_PWR_WAKUEP_SRC_KBD_1			d_KBD_1
#define d_PWR_WAKUEP_SRC_KBD_2			d_KBD_2
#define d_PWR_WAKUEP_SRC_KBD_3			d_KBD_3
#define d_PWR_WAKUEP_SRC_KBD_4			d_KBD_4
#define d_PWR_WAKUEP_SRC_KBD_5			d_KBD_5
#define d_PWR_WAKUEP_SRC_KBD_6			d_KBD_6
#define d_PWR_WAKUEP_SRC_KBD_7			d_KBD_7
#define d_PWR_WAKUEP_SRC_KBD_8			d_KBD_8
#define d_PWR_WAKUEP_SRC_KBD_9			d_KBD_9
#define d_PWR_WAKUEP_SRC_KBD_0			d_KBD_0


USHORT CTOS_PowerWakeupSrcGet(UCHAR bMode,UCHAR* baWakeupSrc,UCHAR* bWakeupSrcNum);
USHORT CTOS_PowerWakeupSrcSet(UCHAR bMode,UCHAR* baWakeupSrc,UCHAR  bWakeupSrcNum);
//=============================================================================================================================
//
// ULDPM Functions
//
//=============================================================================================================================

#define d_MAX_AP_TABLE				25

#define d_AP_FLAG_DEF_SEL			0x40

#define PROGRAM_UPDATE_WHOLE		0x00
//#define PROGRAM_UPDATE_START		0x01
//#define PROGRAM_UPDATE_CONTINUE		0x02
//#define PROGRAM_UPDATE_FINAL		0x03
//#define PROGRAM_FORCE_REBOOT		0x04

//Should be padding to 128 bytes
typedef struct
{
	BYTE bFlag;
	BYTE bCAPType;
	BYTE baGeneratedDateTime[13];
	BYTE baName[21];
	BYTE baVersion[2];
	BYTE baCompany[21];
	BYTE baExeName[25];
	BYTE RFU[44];
} CTOS_stCAPInfo;

// definition for the return code of CTOS_UpdateGetResult()
#define d_PM_MMCI_NOT_FOUND 			0x0001
#define d_PM_MCI_NOT_FOUND				0x0002
#define d_PM_COPY_FILE_ERROR			0x0003
#define d_CAP_OPEN_FILE_FAILED			0x0004
#define d_CAP_FILE_FORMAT_ERROR			0x0005
#define d_CAP_EKEY_INCORRECT			0x0006
#define d_CAP_ESIGN_INCORRECT			0x0007
#define d_CAP_HEADER2_INCORRECT			0x0008
#define d_CAP_NOT_SIGNED				0x0009
#define d_CAP_CA_KEY_REQUIRED			0x000A
#define d_CAP_SIGN_KEY_INCORRECT		0x000B
#define d_CAP_CAP_HASH_INCORRECT		0x000C
#define d_CAP_DECOMPRESS_ERROR			0x000D
#define d_CAP_WRONG_KEY					0x000E
#define d_CAP_BINARY_FILENAME_TOOLONG 	0x000F
#define d_CAP_UPDATE_FINISHED			0x0064
#define d_CAP_RESET_REQUIRED			0x0065
#define d_CAP_REBOOT_REQUIRED			0x0066
#define d_CAP_CONTINUE_DOWNLOAD			0x0067

/////////// System ///////////
//typedef void (*eventUpdateFromMMCI)(INT totalProgress, INT capProgress, CHAR *curMCI, CHAR *curCAP);
typedef void (*eventProgressChange)(UINT uiTotalProgress, UINT uiCAPProgress, BYTE *baCurMCI, BYTE *baCurCAP);

//USHORT CTOS_UpdateFromMMCIEx( CHAR *szFilePath, eventUpdateFromMMCI callackFun, CHAR * szInvalidCapName);
USHORT CTOS_UpdateFromMMCIEx(BYTE *baFilename, eventProgressChange onProgressChange);

void CTOS_SystemReset(void);
void CTOS_PowerOff(void);
USHORT CTOS_GetSerialNumber(BYTE baBuf[16]);
USHORT CTOS_GetSystemInfo(BYTE bID, BYTE baBuf[17]);
USHORT CTOS_GetSystemInfo_TMS(BYTE baBuf[17]);
USHORT CTOS_GetKeyHash(BYTE bKeyIndex, BYTE* baHash);
USHORT CTOS_GetLayer3KeyHash(BYTE bKeyIndex, BYTE* baHash);
USHORT CTOS_GetFactorySN(BYTE *baFactorySN);
USHORT CTOS_SetUSBMode(BYTE baUSBMode);
void CTOS_UpdateFromMMCI(BYTE *baMMCI, BYTE bShowUI);
USHORT CTOS_UpdateFromCAPs(BYTE *pCAPData, DWORD dwDataLen, BYTE Indicator);
USHORT CTOS_UpdateGetResult(void);
USHORT CTOS_SystemWait(DWORD dwTimeout, DWORD dwWaitEvent, DWORD* pdwWakeupEvent);
USHORT CTOS_FactoryReset( BOOL IsNeedConfirm );
USHORT CTOS_CradleAttached(void);

/////////// PM ///////////

#define d_POWERKEY_FUN_REBOOT       0
#define d_POWERKEY_FUN_POWEROFF     1

USHORT CTOS_APFind(BYTE *baAPName, USHORT *usAPIndex);
USHORT CTOS_APGet(USHORT usAPIndex, CTOS_stCAPInfo *stInfo);
USHORT CTOS_APSet(USHORT usAPIndex, BYTE bFlag);
USHORT CTOS_APDel(USHORT usAPIndex);
USHORT CTOS_APFork(BYTE* baAPName);
USHORT CTOS_APRelease(void);
void CTOS_PM_Reset(void);
USHORT CTOS_SetFunKeyPassword(BYTE *baPasswordString, BOOL IsEnable);
USHORT CTOS_SetPMEnterPassword(BYTE *baPasswordString, BOOL IsEnable);
USHORT CTOS_SetPPCMode(BOOL bEnable);
USHORT CTOS_PowerKeyFunSet(BYTE bFun);
USHORT CTOS_PowerKeyFunGet(BYTE *pbFun);

// AP Stack
USHORT CTOS_APJump(BYTE* baAPName);
USHORT CTOS_APCall(BYTE* baAPName);

/////////// ULD ///////////
USHORT CTOS_EnterDownloadMode(void);
USHORT CTOS_SetULDPassword(BYTE *baPasswordString);
USHORT CTOS_SealULD(BYTE *baPasswordString, BOOL IsEnable);

//=============================================================================================================================
//
// CTMS Functions
//
//=============================================================================================================================

/** CTMS STATUS***/

#define d_CTMS_UPDATE_UNFINISHED	0x0000
#define d_CTMS_UPDATE_FINISHED 		0x0001
#define d_CTMS_UPDATE_ERR 			0x0002

#define d_CTMS_GPRS_CONFIG			0x01
#define d_CTMS_ETHERNET_CONFIG		0x02
#define d_CTMS_MODEM_CONFIG			0x03
#define d_CTMS_RECOUNT				0x04
#define d_CTMS_LOCALIP				0x05
#define d_CTMS_SERIALNUM			0x06
#define d_CTMS_WIFI_CONFIG			0x07

#define d_CTMS_UPLOAD_ADD			0x01
#define d_CTMS_UPLOAD_DELETE		0x02
#define d_CTMS_UPLOAD_DELETEALL		0x03

/** CTMS Tirgger MODE **/
#define d_CTMS_NORMAL_MODE			0x01
#define d_CTMS_DEFAULT_GPRS			0x02
#define d_CTMS_DEFAULT_MODEM		0x03
#define d_CTMS_DEFAULT_ETHERNET		0x04
#define d_CTMS_DEFAULT_WIFI			0x05

#define d_CTMS_INFO_LAST_UPDATE_TIME	0x01
/** CTMS UPDATE TYPE **/

typedef struct{
	BYTE bType;	//Bit1:FW, Bit2:AP, Bit3:Share Lib, Bit4:APP Lib, Bit5:Share File, Bit6:APP File, Bit7:PRM File, Bit8:NULL
	BYTE bNums;	//Number of update
	CTOS_RTC stRTC; //Last got update information time
	BYTE RFU[10];
}__attribute__((packed)) CTMS_UpdateInfo;


typedef struct {
    BYTE bSIMSlot; // The SIM slot ID
	BYTE RFU[3];
    STR strAPN[32]; // APN name

    STR strID[32]; // The ID string used for the CHAP authentication
    STR strPW[32]; // The password string used for the CHAP authentication

    STR strRemoteIP[40]; // Remote IP address
    USHORT usRemotePort; // Remote port number
	BYTE RFU1[2];
    STR strLocalIP[40]; // Local IP address

    ULONG ulSIMReadyTimeout; // The timeout value, in millisecond, for checking if SIM is ready
    ULONG ulGPRSRegTimeout; // The timeout value, in millisecond, for checking if GPRS is registered

    USHORT usPPPRetryCounter; // The times of retry in PPP layer
    BYTE RFU2[2];
    ULONG ulPPPTimeout; // The timeout value in millisecond in PPP layer

    USHORT usTCPRetryCounter; // The times of retry in TCP layer
    BYTE RFU3[2];
    ULONG ulTCPConnectTimeout; // The timeout value, in millisecond, for connection in TCP layer
    ULONG ulTCPTxTimeout; // The timeout value, in millisecond, for transmitting in TCP layer
    ULONG ulTCPRxTimeout; // The timeout value, in millisecond, for receiving in TCP layer

    //BYTE*	pbRxStack;					// The pointer to Received stack
} __attribute__((packed)) CTMS_GPRSInfo;

typedef struct {
    BYTE bMode; // The mode of Modem connection
    BYTE bHandShake; // The handshakes of modem connection
    BYTE bCountryCode; // Country Code
	BYTE RFU[1];
    BYTE strRemotePhoneNum[32]; // The dial number
    BYTE strID[32]; // The ID string used for the CHAP authentication
    BYTE strPW[32]; // The password string used for the CHAP authentication

    BYTE strRemoteIP[40]; // Remote IP address
    USHORT usRemotePort; // Remote port number
	BYTE RFU1[2];

    STR strLocalIP[40]; // Local IP address

    ULONG ulDialTimeout; // The timeout value in millisecond for dialing up

    USHORT usPPPRetryCounter; // The times of retry in PPP layer
	BYTE RFU2[2];

	ULONG ulPPPTimeout; // The timeout value in millisecond in PPP layer

    USHORT usTCPRetryCounter; // The times of retry in TCP layer
	BYTE RFU3[2];
	ULONG ulTCPConnectTimeout; // The timeout value, in millisecond, for connection in TCP layer
    ULONG ulTCPTxTimeout; // The timeout value, in millisecond, for transmitting in TCP layer
    ULONG ulTCPRxTimeout; // The timeout value, in millisecond, for receiving in TCP layer

    //BYTE*	pbRxStack;					// The pointer to Received stack
}__attribute__((packed)) CTMS_ModemInfo;

typedef struct {
    //BOOL	boSave;						// Save all setting to module or end of information retrieve on Ethernet module

    STR strRemoteIP[40]; // Remote IP address
    USHORT usRemotePort; // Remote port number
	//BYTE RFU[2];
	BYTE bDHCP;
	BYTE RFU;
	STR strLocalIP[40]; // Local IP address

    STR strMask[40]; // Network mask
    STR strGateway[40]; // Gateway address

}__attribute__((packed)) CTMS_EthernetInfo;

typedef struct
{
    BYTE IsAutoConnect;	//if this parameter set to 1 then wifi opne will auto connect to AP
    BYTE IsHidden;
    BYTE baPassword[64];
    BYTE baSSid[36];
    BYTE bProtocal; //Refer Wifi Setting
    BYTE bGroup;	//Refer Wifi Setting
    BYTE bPairwise;	//Refer Wifi Setting
    STR strRemoteIP[40]; // Remote IP address
    USHORT usRemotePort; // Remote port number
    BYTE bDHCP;
    STR strLocalIP[40]; // Local IP address
    STR strMask[40]; // Network mask
    STR strGateway[40]; // Gateway address
    BYTE RFU[2];

} __attribute__((packed)) CTMS_WIFIInfo;




void   CTOS_CTMSUtility(IN BYTE bMode);
USHORT CTOS_CTMSSetConfig(IN BYTE Config_ID, IN void *stConfig);
USHORT CTOS_CTMSGetConfig(IN BYTE Config_ID, OUT void *stConfig);
USHORT CTOS_CTMSSetUploadFile(IN BYTE *baFileName, IN BYTE bMode);
USHORT CTOS_CTMSGetTriggerTime(OUT CTOS_RTC *pstRTC);
USHORT CTOS_CTMSSaveLog(IN USHORT usApid, IN BYTE bMainStep, IN BYTE bSubStep,IN USHORT usRet,  IN BYTE *baMeg);
USHORT CTOS_CTMSGetStatus(OUT USHORT *usStatus, OUT USHORT *usRetErr);
USHORT CTOS_CTMSInitDaemonProcess(IN BYTE bMode);
USHORT CTOS_CTMSGetUpdateType(OUT CTMS_UpdateInfo *st);
USHORT CTOS_CTMSReset(void);
USHORT CTOS_CTMSGetInfo(IN BYTE Info_ID, IN void *stInfo);


// definition for backward compatible
#define d_M_CONFIG_DAILING_DURATION				1
#define d_STATUS_ETHERNET_PHYICAL_ONLINE		0x00000010
#define d_LCD_CAVANS_X_SIZE              		128
#define d_LCD_CAVANS_Y_SIZE              		(64*4)
#define d_BATTERY_EXIST				d_MK_BATTERY_EXIST
#define d_BATTERY_CHARGE			d_MK_BATTERY_CHARGE
#define d_LCD_WINDOW_320x240_X_SIZE				320
#define d_LCD_WINDOW_320x240_Y_SIZE				240
#define d_LCD_GRAPHIC_320x240_MODE				3
#define d_LCD_TEXT_320x240_MODE					4
#define d_LCD_CANVAS_320x240_X_SIZE				320
#define d_LCD_CANVAS_320x240_Y_SIZE				(240*4)
#define ID_KMODEM_KO				6       //OLD
#define ID_CASC_KO				28      //OLD
//----------------------------------------------------------------------
// WiFi Definition
//----------------------------------------------------------------------
//wifi Protocol
#define d_WIFI_PROTOCAL_WEP    					0x01
#define d_WIFI_PROTOCAL_WPA    					0x02
#define d_WIFI_PROTOCAL_WPA2    				0x03

#define MK_HW_MODEM								d_MK_HW_MODEM
#define MK_HW_ETHERNET							d_MK_HW_ETHERNET
#define MK_HW_GPRS								d_MK_HW_GPRS
#define MK_HW_CONTACTLESS						d_MK_HW_CONTACTLESS
#define MK_HW_ZIGBEE							d_MK_HW_ZIGBEE
#define MK_HW_WIFI								d_MK_HW_WIFI
#define MK_HW_BT								d_MK_HW_BT

#define d_STATUS_BASEUSB_MODECDC				0x00000001
USHORT CTOS_BaseUSBStatus(DWORD* pdwUSBStatus);
USHORT CTOS_Get_Battery_Capacity_ByIC(BYTE* bPercentage);
USHORT CTOS_BatteryGetCapacityByIC(BYTE* bPercentage);

//Device Mode
#define d_Model_VEGA9000						d_MODEL_VEGA9000
#define d_Model_VEGA7000						d_MODEL_VEGA7000
#define d_Model_VEGA5000						d_MODEL_VEGA5000
#define d_Model_VEGA5000S						d_MODEL_VEGA5000S
#define d_Model_VEGA3000						d_MODEL_VEGA3000
#define d_Model_VEGA3000P						d_MODEL_VEGA3000P
//=============================================================================================================================
//
// NTP Functions
//
//=============================================================================================================================
//Time Zone
USHORT CTOS_NTPSetParameter(BOOL fEnable, STR *strIPURL, USHORT usFreq);
USHORT CTOS_NTPForceUpdate(void);
USHORT CTOS_NTPForceUpdateEx (int timtOut);


//=============================================================================================================================
//
// Hash Functions
//
//=============================================================================================================================
//Hash
USHORT CTOS_GetDirHash (BYTE *baDirectory, BYTE* baHash);
USHORT CTOS_GetFunKeyPasswordHash(BYTE *baPasswordHash);
USHORT CTOS_GetPMEnterPasswordHash(BYTE *baPasswordHash);
USHORT CTOS_GetULDPasswordHash(BYTE *baPasswordHash);

//=============================================================================================================================
//
// Virtual Functions
// for V3 touch panel
//
//=============================================================================================================================
typedef struct
{
    USHORT LeftTopX;
    USHORT LeftTopY;
    USHORT RightBottomX;
    USHORT RightBottomY;
}CTOS_VIRTUAL_FUNCTION_KEY_SET_PARA;

USHORT CTOS_VirtualFunctionKeySet(IN CTOS_VIRTUAL_FUNCTION_KEY_SET_PARA* pPara, IN BYTE FuncKeyCount);

//=============================================================================================================================
//
// Signature Functions
// for V3 touch panel
//
//=============================================================================================================================


USHORT CTOS_TouchSignatureStart(UINT ulXStart , UINT ulYStart ,
								UINT ulWidth , UINT ulHeight ,STR *strBMPFile,ULONG ulTimeout );

//-------------------------------------------------

#define d_TOUCH_SIGNATURE_CONFIG_COLOR_RED		1
#define d_TOUCH_SIGNATURE_CONFIG_COLOR_GREEN	2
#define d_TOUCH_SIGNATURE_CONFIG_COLOR_BLUE		3
#define d_TOUCH_SIGNATURE_CONFIG_FONT_WIDTH		4

USHORT CTOS_TouchSignatureConfigSet(BYTE bTag, STR *strValue, BYTE bLen);

//-------------------------------------------------

#define d_SCP_STATUS_NO_DATA	        0x00000001
#define d_SCP_STATUS_IDLE	            0x00000002
#define d_SCP_STATUS_SIGNING           0x00000003

USHORT CTOS_GetSignatureStatus(ULONG* pulStatus , ULONG *pulDuration);

//-------------------------------------------------

USHORT CTOS_TouchSignatureTerminate(void);

//-------------------------------------------------
#define d_BMP_CONVERT_ONE_BIT_COLOR		1
#define d_BMP_CONVERT_RIGHT_ROTATE		2
#define d_BMP_CONVERT_LEFT_ROTATE		3

USHORT CTOS_BMPConverter(STR *strInputBMPFile, STR *strOutputBMPFile, BYTE bTag);



#ifdef __cplusplus
}
#endif

#endif
