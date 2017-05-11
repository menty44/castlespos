#ifndef PCIPAD_H
#define	PCIPAD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define d_PCIPAD_INEFFECTIVE_DATA                             0x0102
#define d_PCIPAD_AUTH_NOT_PERFORMED                           0x0103
#define d_PCIPAD_AUTH_FAIL                                    0x0104
#define d_PCIPAD_INEFFECTIVE_PARAMETER                        0x0105
#define d_PCIPAD_INEFFECTIVE_MODE                             0x0106
#define d_PCIPAD_INEFFECTIVE_CMD                              0x0107

#define d_PCIPAD_RUN_FIRST_BOOT                               0x0120
#define d_PCIPAD_INIT_AUTH_NOT_PERFORMEDED                    0x0121
#define d_PCIPAD_DEVICE_BLOCKED                               0x0123
#define d_PCIPAD_NOT_GETPIN_MODE                              0x0130
#define d_PCIPAD_KEY_INDEX_EXCEED                             0x0131
#define d_PCIPAD_NO_KEY										0x0132
#define d_PCIPAD_NOT_ALLOW									0x0133
#define d_PCIPAD_KEY_EXIST									0x0134
#define d_PCIPAD_FRONT_KEY_NOT_EXISTED                        0x0135
#define d_PCIPAD_SELFTEST_FAILED                              0x0136
#define d_PCIPAD_KEY_ATTRIBUTE_INVALID                        0x0137
#define d_PCIPAD_KEY_TYPE_INVALID                             0x0138
#define d_PCIPAD_UNCOMPRESS_ERROR								0x0140				
	
//return code
#define d_PCIPAD_OK                                        0x0000
#define d_PCIPAD_NO_DATA                                   0x0001
//#define d_PCIPAD_KEY_INDEX_EXCEED                          0x0002
#define d_PCIPAD_USER_CANCEL                               0x0020
#define d_PCIPAD_PARAMETER_INVALID                         0x0040    
#define d_PCIPAD_TIME_OUT                                  0x00FF

//Normal Config ID
#define d_PCIPAD_CONFIG_SELECT_MODE					0x00
#define d_PCIPAD_CONFIG_TTF_FONT_SETTING				0x01
#define d_PCIPAD_CONFIG_RTC							0x02

//Select Mode - Font Mode
#define d_PCIPAD_SELECT_MODE_FONT_FNT_MODE							0x00
#define d_PCIPAD_SELECT_MODE_FONT_LCD_MODE							0x01

//Select Mode - LCD Mode
#define d_PCIPAD_SELECT_MODE_LCD_GRAPHIC_MODE						0x00
#define d_PCIPAD_SELECT_MODE_LCD_TEXT_MODE							0x01
#define d_PCIPAD_SELECT_MODE_LCD_GRAPHIC_320x240_MODE				0x03
#define d_PCIPAD_SELECT_MODE_LCD_TEXT_320x240_MODE					0x04

//Language ID
#define d_PCIPAD_FONT_EMPTY   											  0		  //No font
#define d_PCIPAD_FONT_CHINESE_TAIWAN   								  1028	  //Chinese(Taiwan)
#define d_PCIPAD_FONT_CZECH											  1029	  //Czech
#define d_PCIPAD_FONT_JAPANESE											  1041    //Japanese
#define d_PCIPAD_FONT_KOREAN											  1042    //Korean
#define d_PCIPAD_FONT_PORTUGUESE_BRAZIL        						  1046    //Portuguese(Brazil)
#define d_PCIPAD_FONT_RUSSIAN											  1049    //Russian
#define d_PCIPAD_FONT_THAI  											  1054    //Thai
#define d_PCIPAD_FONT_TURKISH 											  1055    //Turkish
#define d_PCIPAD_FONT_FARSI											  1065    //Farsi
#define d_PCIPAD_FONT_VIETNAMESE										  1066    //Vietnamese
#define d_PCIPAD_FONT_CHINESE_PRC										  2052    //Chinese(PRC)
#define d_PCIPAD_FONT_CHINESE_PRC1										  2054    //Simple(Song)
#define d_PCIPAD_FONT_PORTUGUESE_PORTUGAL								  2070	  //Portuguese(Portugal)
#define d_PCIPAD_FONT_SPANISH 											  3082    //Spanish(Spain)
#define d_PCIPAD_FONT_ARABIC_QATAR										  16385   //Arabic(Qatar)
#define d_PCIPAD_FONT_CHINESE_TAIWAN_PLUS 								  64507	  //Chinese(Taiwan) with Symbol
#define d_PCIPAD_FONT_DEFAULTASCII             						  36864

//FontSize
#define d_PCIPAD_FONT_8x8												  0x0808
#define d_PCIPAD_FONT_8x16												  0x0810
#define d_PCIPAD_FONT_16x16											  0x1010
#define d_PCIPAD_FONT_12x24											  0x0C18
#define d_PCIPAD_FONT_24x24											  0x1818
#define d_PCIPAD_FONT_9x9												  0x0909
#define d_PCIPAD_FONT_9x18												  0x0912
#define d_PCIPAD_FONT_16x30											  0x101E

//Update From ZIP status
#define d_PCIPAD_ZIP_FILE_FIRST_BLOCK						0
#define d_PCIPAD_ZIP_FILE_NEXT_BLOCK						1
#define d_PCIPAD_ZIP_FILE_LAST_BLOCK						2

#define d_PCIPAD_SET_SESSION_ADMIN			0x00
#define d_PCIPAD_SET_SESSION_NORMAL			0x01
    
    
#define d_PCIPAD_COMMAND_MODE_ADMIN	0x00
#define d_PCIPAD_COMMAND_MODE_USER     0x01	
#define d_PCIPAD_COMMAND_MODE_GENERAL	0x02    

typedef struct
{
	USHORT (*OnTxData)(IN BYTE *pData, IN USHORT Len);
	USHORT (*OnRxData)(OUT BYTE *pData, INOUT USHORT *pLen);
	USHORT (*OnEncryptWithSK)(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen);
	USHORT (*OnDecryptWithSK)(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen);
}PCIPAD_EVENT;

//USHORT PCIPAD_Initialize(IN BYTE bCOM);
        
void PCIPAD_CommunicationInitialize(PCIPAD_EVENT *pstCommEvent);

//Genernal Command

USHORT PCIPAD_GetDeviceInfo(OUT BYTE baSN[16], OUT BYTE baVersion[16]);

USHORT PCIPAD_FactoryReset(void);

USHORT PCIPAD_SelfTest(OUT USHORT *pResultLen, OUT BYTE *pVerifyResult);

USHORT PCIPAD_GetSystmInfo(IN BYTE ID, OUT BYTE baInfo[17]);

USHORT PCIPAD_UpdateFromZIP(IN BYTE *pZip_Filename, BOOL (*OnStatus)(BYTE Status));

USHORT PCIPAD_GetUpdatedResult(void);

//Authentication

USHORT PCIPAD_InitialAuthenticationNormal(IN BYTE *pTermRN, OUT BYTE *pPinpadRN, OUT BYTE *pPinpadCrypto);

USHORT PCIPAD_MutualAuthenticationNormal(IN BYTE *pTermCrypto);

USHORT PCIPAD_ResetSessionNormal(void);

//Normal Operation Command - Setting

USHORT PCIPAD_SetNormalConfiguration(IN BYTE ConfigID, IN USHORT Len, IN void *pData);

typedef struct
{
        IN BYTE Version;
        IN BYTE TotalLine;       
        IN USHORT MsgLen;
        IN BYTE *pMsgData; //LineNo 1(1)+MsgLen 1(1)+Msg 1(var)+LineNo 2(1)+MsgLen 2(1)+Msg 2(var)+....+LineNo n(1)+MsgLen n(1) + Msg n(var)
}PCIPAD_UI_MSG_PARA;

USHORT PCIPAD_TIdleScreenSet(PCIPAD_UI_MSG_PARA *pstMsgPara);

USHORT PCIPAD_GetNormalConfiguration(IN BYTE ConfigID, OUT USHORT *Len, OUT void *Data);

//Normal Operation Command - Key Management

typedef struct
{
        IN BYTE Version;
        IN USHORT WKIndex;
        IN USHORT KeyAttribute;
        IN USHORT EncKeyLen;
        IN BYTE *pEncKeyData;
        IN BYTE *pKSN;  //this is used for DUPKT, fixed 10 bytes
        IN BYTE KCV_Len;
        IN BYTE *pKCV;		//key check value
        IN USHORT MKIndex;
}PCIPAD_WK_DATA;

USHORT PCIPAD_WriteEncryptedWorkingKey(PCIPAD_WK_DATA *pstWKData);

typedef struct
{
    IN BYTE Version;
    IN BYTE KeyGroup;
    IN USHORT MKIndex;
    IN USHORT WKIndex;
    IN OUT BYTE KCV_Len;
    OUT BYTE *pKCV;
    OUT BYTE *pHash;
    OUT BYTE *pKSN;
}PCIPAD_KEYINFO_DATA;

USHORT PCIPAD_GetKeyInfo(PCIPAD_KEYINFO_DATA *pstKeyInfoData);

USHORT PCIPAD_CheckKey(IN BYTE KeyGroup, IN USHORT KeyIndex);

//Normal Operation Command - Cryptographic

USHORT PCIPAD_GenerateRandomNumber(IN BYTE RNDLen, OUT BYTE *pRND);

typedef struct
{
        IN BYTE Version;
        IN USHORT MKIndex;
        IN USHORT WKIndex;
        IN BYTE EncryptMethod;
        IN BYTE ESK_Len;
        IN BYTE *pESK;
        IN BYTE ICVLength;
        IN BYTE	*pICV;
        IN USHORT DataLen;
        IN BYTE *pInData;
        OUT BYTE *pOutData;
}PCIPAD_DATAENCRYPT_PARA;

USHORT PCIPAD_DataEncrypt(PCIPAD_DATAENCRYPT_PARA *pstDataEncPara);

typedef struct
{
        IN BYTE Version;
        IN USHORT MKIndex;
        IN USHORT WKIndex;
        IN BYTE MACMethod;
        IN BYTE ESK_Len;
        IN BYTE *pESK;
        IN BYTE ICV_Len;
        IN BYTE *pICV;
        IN USHORT DataLen;
        IN BYTE *pInData;
        OUT BYTE MAC_Len;
        OUT BYTE *pMAC;
}PCIPAD_MAC_PARA;

USHORT PCIPAD_MAC(PCIPAD_MAC_PARA *pstMACPara);

typedef struct
{
    IN BYTE Version;
    IN USHORT MKIndex;
    IN USHORT WKIndex; //old: Key Set
    IN BYTE PINBlockType;
    IN BYTE MaxPINLen;
    IN BYTE MinPINLen;
    IN BOOL isNullPIN;
    IN BYTE TimeOut;	//second
    IN BYTE PoisitionX;
    IN BYTE PoisitionY;

    IN BYTE ESK_Len;
    IN BYTE *pESK;

    IN BYTE PAN_Len;
    IN BYTE *pPAN;

    OUT BYTE PINBlockLen;
    OUT BYTE *pPINBlock;
    OUT BYTE *pKSN;
}PCIPAD_GETPIN_PARA;

USHORT PCIPAD_GETPIN(PCIPAD_GETPIN_PARA *pstGetPINPara, PCIPAD_UI_MSG_PARA *pstMsgPara, BOOL (*OnCancel)(void));

USHORT PCIPAD_CancelPIN(void);

//Normal Operation Command - Display

USHORT PCIPAD_DisplayMessage(IN BYTE Duration, IN BOOL isClearLCD, PCIPAD_UI_MSG_PARA *pstMsgPara);

#ifdef	__cplusplus
}
#endif

#endif	/* PCIPAD_H */

