#include "../sharedef.h"
#include "../debug3.h"
#include "../wub_lib.h"
#include "utility.h"
#include <time.h>
#include <sys/time.h>
#include <emvaplib.h>



BYTE g_term_data[4096];
static BYTE pin_block[16];
static BYTE baAuthorizationCode[4]; 
static BYTE baIssuerAuthenticationData[128];
static BYTE baIssuerScript[256]; 

#define d_EMV_CONFIG_FILE       "emv_config.xml"

#define d_ONLINE_KEYSET     0x2000
#define d_ONLINE_KEYINDEX   0x0000
#define d_OFFLINE_KEYINDEX  0x0001

#define d_ONLINE_KEY        "\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11\x11"

void OnDisplayShow(IN char *pStrMsg)  //add '\n' break line
{
    CTOS_LCDTPrintXY(1, 6, pStrMsg);
}
    
void OnErrorMsg(IN char *pStrMsg)
{
    CTOS_LCDTPrintXY(1, 6, pStrMsg);
}
    
// This function will be called during EMV_Initialize;
void OnEMVConfigActive(INOUT BYTE* pActiveIndex)
{
}
        
USHORT OnTxnDataGet(OUT EMV_TXNDATA *pTxnData)
{
  pTxnData->Version = 1;
    pTxnData->ulAmount = 1;
    
    return d_OK;
}
    
// Range of pAppSelectedIndex value is 0 to (AppNum-1)    
USHORT OnAppList(IN BYTE AppNum, IN char AppLabel[][d_LABEL_STR_SIZE+1], OUT BYTE *pAppSelectedIndex)
{
  BYTE sHeaderString[17];
    
    memset(sHeaderString, 0x00, sizeof(sHeaderString));
    sprintf(sHeaderString, "APP List");
    
    if (ShowAPList(2, 6, sHeaderString, strlen(sHeaderString), AppNum, AppLabel, pAppSelectedIndex) != 0)
        return d_EMVAPLIB_ERR_ABORT_TX;
    
    return d_EMVAPLIB_OK;
    
}

// Return d_OK to indicate CONFIRMED        
USHORT OnAppSelectedConfirm(IN BOOL IsRequiredbyCard, IN BYTE *pLabel, IN BYTE bLabelLen)
{
  return d_OK;
}
    
BOOL OnTerminalDataGet(IN USHORT usTag, INOUT USHORT *pLen, OUT BYTE *pValue)
{
    
    return FALSE;
}
    
BOOL OnCAPKGet(IN BYTE *pRID, IN BYTE bKeyIndex, OUT BYTE *pModulus, OUT USHORT *pModulusLen, OUT BYTE *pExponent, OUT USHORT *pExponentLen)
{
    
    return FALSE;
}
    
// Return d_OK to indicate Online PIN block is ready for application
USHORT OnOnlinePINBlockGet(OUT ONLINE_PIN_DATA *pOnlinePINData)
{
    
    pOnlinePINData->bPINLen = 8;
    memcpy(pin_block, "\xB5\x1E\xC3\xBE\xB7\x24\x37\x13", 8);
    pOnlinePINData->pPIN = pin_block;
    
    return d_OK;
    //return d_EMVAPLIB_ERR_PIN_BY_PASS;
}
   
static int iTestCancel(void)
{
	return 0;
}

// Return d_OK to indicate Offline PIN block is ready for Kernel
// If this function uses KMS_GetEncOfflinePIN function to get offline pin, return d_EMV_ENTER_KMS_OFFLINEPIN to indicate enciphed offline PIN is ready for Kernel    
USHORT OnOfflinePINBlockGet(void)
{
    
    USHORT ret;
    BYTE key;
    CTOS_stDefEncOffPINStruc para;
    CTOS_KMS2DATAENCRYPT_PARA stDataEncPara;
    BYTE PINBlock[32], PINBlockLen;
    BYTE msg1[20], msg2[20], procmsg[20];

    
    stDataEncPara.Version = 0x00;
    
    stDataEncPara.Protection.CipherKeyIndex = d_OFFLINE_KEYINDEX;
    stDataEncPara.Protection.CipherKeySet = d_ONLINE_KEYSET;
    stDataEncPara.Protection.CipherMethod = KMS2_DATAENCRYPTCIPHERMETHOD_EXTPIN_ECB;
    memcpy(PINBlock, "\xB5\x1E\xC3\xBE\xB7\x24\x37\x13", 8);
    PINBlockLen = 8;
    stDataEncPara.Input.pData = PINBlock;
    stDataEncPara.Input.Length = PINBlockLen;
    
    ret = CTOS_KMS2DataEncrypt(&stDataEncPara);
    if (ret != d_OK)
      return d_EMVAPLIB_ERR_CRITICAL_ERROR;
    
    return d_EMVAPLIB_ERR_ENTER_KMS_OFFLINEPIN;
    
}

void OnPINVerifyResult(IN USHORT usResult)
{
   BYTE data[32];
    
    memset(data, 0, sizeof(data));
    
    if (usResult == d_PIN_RESULT_OK) {
		//"PIN Verify OK"
        sprintf(data, "PIN Verify OK");

	} else if (usResult == d_PIN_RESULT_FAIL) {
		//"!PIN Wrong!"
        sprintf(data, "PIN Wrong");
	} else if (usResult == d_PIN_RESULT_BLOCKED || usResult == d_PIN_RESULT_FAILBLOCKED) {
		//"!PIN Blocked!"
        //sprintf(data, "PIN Blocked");
	}
    
    CTOS_LCDTPrintXY(1, 6, data);
    
}

void OnTxnOnline(IN ONLINE_PIN_DATA *pOnlinePINData, OUT EMV_ONLINE_RESPONSE_DATA* pOnlineResponseData)
{
  CTOS_LCDTPrintXY(1, 2, "Online Host      ");
  CTOS_Delay(1500);
  
    pOnlineResponseData->bAction = d_ONLINE_ACTION_APPROVAL;
    memcpy(baAuthorizationCode, "00", 2);
    
    pOnlineResponseData->pAuthorizationCode = baAuthorizationCode;
    pOnlineResponseData->pIssuerAuthenticationData = baIssuerAuthenticationData;
    pOnlineResponseData->pIssuerScript = baIssuerScript;
}

void OnTxnIssuerScriptResult(IN BYTE* pScriptResult, IN USHORT pScriptResultLen)
{
}

void OnTxnResult(IN BYTE bResult, IN BOOL IsSignatureRequired)
{
    CTOS_LCDTPrintXY(1, 3, "Txn Result      ");
  CTOS_Delay(1500);
  
  switch(bResult)
  {
    case d_PIN_RESULT_OK:
      CTOS_LCDTPrintXY(1, 6, "APPROVAL         ");
      break;
    case d_PIN_RESULT_FAIL:
      CTOS_LCDTPrintXY(1, 6, "DECLINE          ");
      break;
    case d_PIN_RESULT_BLOCKED:
      CTOS_LCDTPrintXY(1, 6, "BLOCKED          ");
      break;
    case d_PIN_RESULT_FAILBLOCKED:
      CTOS_LCDTPrintXY(1, 6, "FAIL BLOCKED     ");
      break;
  }
}

void OnTotalAmountGet(IN BYTE *pPAN, IN BYTE bPANLen, OUT ULONG *pAmount)
{
    *pAmount = 0;
}

void OnExceptionFileCheck(IN BYTE *pPAN, IN BYTE bPANLen, OUT BOOL *isException)
{
}

BOOL OnCAPKRevocationCheck(IN BYTE *pbRID, IN BYTE bCAPKIdx, BYTE *pbSerialNumuber)
{
    return FALSE;
}

void OnGetPINNotify(IN BYTE bPINType, IN USHORT bRemainingCounter, OUT BOOL* pIsUseDefaultGetPINFunc, OUT DEFAULT_GETPIN_FUNC_PARA *pPara)
{
  BYTE pan[32];
  
  *pIsUseDefaultGetPINFunc = TRUE;
  
  memset(pPara, 0x00, sizeof(DEFAULT_GETPIN_FUNC_PARA));
  pPara->usLineLeft_X = 5;
  pPara->usLineRight_X = 20;
  pPara->bPINDigitMaxLength = 8;
  pPara->bPINDigitMinLength = 4;
  pPara->usLinePosition_Y = 8;
  pPara->ulTimeout = 10;
  
  if (bPINType == d_NOTIFY_OFFLINE_PIN)
  {
    pPara->IsReverseLine = TRUE;
    pPara->IsRightToLeft = TRUE;
  
    CTOS_LCDTPrintXY(1, 7, "Enter Offline PIN:");
  }else
  {
    pPara->ONLINEPIN_PARA.CipherKeyIndex = d_ONLINE_KEYINDEX;
    pPara->ONLINEPIN_PARA.CipherKeySet = d_ONLINE_KEYSET;
    pPara->ONLINEPIN_PARA.bPANLen = 16;
    memset(pan, 0x30, sizeof(pan));
    memset(pPara->ONLINEPIN_PARA.baPAN, 0x30, 16);
            
    CTOS_LCDTPrintXY(1, 7, "Enter Online PIN:");
  }
}

void OnOutputCardAPDU(IN BYTE *pTxAPDU, IN USHORT TxAPUDLen, IN BYTE *pRxAPDU, IN USHORT RxAPDULen)
{

  BYTE buff[1024];
  USHORT len = 0;
  
  memset(buff, 0, sizeof(buff));
  CTOS_PrinterPutString("\nTxAPDU");
  wub_hex_2_str(pTxAPDU, buff, TxAPUDLen);
  
#if 1
  do
  {
    CTOS_PrinterPutString(&buff[len]);
    len += 32;
  }while(len < (TxAPUDLen*2));
  
  memset(buff, 0, sizeof(buff));
  len = 0;
  CTOS_PrinterPutString("\nRxAPDU");
  wub_hex_2_str(pRxAPDU, buff, RxAPDULen);
  do
  {
    CTOS_PrinterPutString(&buff[len]);
    len += 32;
  }while(len < (RxAPDULen*2));
#endif
  
}
        
EMV_EVENT g_emv_event = 
{
    1,
    OnDisplayShow,
    OnErrorMsg, 
    OnEMVConfigActive, 
    NULL,
    OnTxnDataGet, 
    OnAppList,
    OnAppSelectedConfirm,
    OnTerminalDataGet,
    OnCAPKGet,
    OnGetPINNotify,
    OnOnlinePINBlockGet,
    OnOfflinePINBlockGet,
    OnPINVerifyResult,
    OnTxnOnline,
    OnTxnIssuerScriptResult,
    OnTxnResult,
    OnTotalAmountGet,
    OnExceptionFileCheck,
    OnCAPKRevocationCheck,
};
/** 
** The main entry of the terminal application 
**/

BYTE insertCard(void)
{
	BYTE baStatus;

	CTOS_SCStatus(d_SC_USER, &baStatus);
	if (baStatus & d_MK_SC_PRESENT) {
		return TRUE;
	}

	return FALSE;
}

void write_online_key(void)
{
  USHORT usRet;
  CTOS_KMS2KEYWRITE_PARA stKeyWritePara;
  
  memset(&stKeyWritePara, 0x00, sizeof(CTOS_KMS2KEYWRITE_PARA));
  
  stKeyWritePara.Info.KeySet = d_ONLINE_KEYSET;
  //stKeyWritePara.Info.KeySet = 0x1001;
  stKeyWritePara.Info.KeyIndex = d_ONLINE_KEYINDEX;
  stKeyWritePara.Info.KeyVersion = 0x01;
  stKeyWritePara.Info.KeyType = KMS2_KEYTYPE_3DES;
  stKeyWritePara.Info.KeyAttribute = KMS2_KEYATTRIBUTE_PIN;
  
  stKeyWritePara.Protection.Mode = KMS2_KEYPROTECTIONMODE_PLAINTEXT;
  //stKeyWritePara.Protection.Mode = KMS2_KEYPROTECTIONMODE_KPK_ECB;
  //stKeyWritePara.Verification.KeyCheckValueLength = 4;
  //stKeyWritePara.Verification.pKeyCheckValue = check_value;
  
  stKeyWritePara.Value.KeyLength = 16;
  stKeyWritePara.Value.pKeyData = d_ONLINE_KEY;
      
  usRet = CTOS_KMS2KeyWrite(&stKeyWritePara);
  
  stKeyWritePara.Info.KeyIndex = d_OFFLINE_KEYINDEX;
  stKeyWritePara.Info.KeyAttribute = KMS2_KEYATTRIBUTE_ENCRYPT+KMS2_KEYATTRIBUTE_DECRYPT;
  
  usRet = CTOS_KMS2KeyWrite(&stKeyWritePara);
}

BYTE g_logbuf[64*1024];
USHORT g_loglen;

int EMV_Contact_main(int argc,char *argv[])
{	
	
	BYTE bKey, insert = FALSE;
    USHORT ret;
    BYTE label_len, label[32];
    BYTE SelectedAID[16], SelectedAIDLen;
    USHORT len;
    BYTE value[128], buff[128]={0};
	        
	// TODO: Add your program here //
	CTOS_LCDTClearDisplay();
	
	CTOS_LCDTPrintXY(1, 1, "Initialing...");
      
    ret = EMV_Initialize(&g_emv_event, d_EMV_CONFIG_FILE);
	
    sprintf(buff, "initial ret %04X ", ret);
    CTOS_LCDTPrintXY(1, 7, buff);
   
	//CTOS_LCDTPrintXY(1, 8, "press any key");
	//CTOS_KBDGet(&key);
	CTOS_LCDTPrintXY(1, 8, "                         ");
	
    if (ret != d_EMVAPLIB_OK)
      exit(0);
    
    //EMV_SpecialEventRegister(d_EVENTID_OUTPUT_CARDAPDU, (EVENT_OUTPUTCARDAPDU) OnOutputCardAPDU);
    
    write_online_key();
    
    CTOS_LCDTPrintXY(1, 1, "Plz Insert Card    ");
   do
   {
       ForceMainDevice_KBDHit(&bKey);
       if (bKey == d_KBD_CANCEL)
           break;
       
       insert = insertCard();
       if (insert)
       {
            CTOS_LCDTPrintXY(1, 6, "Processing...");
			
			
            ret = EMV_TxnAppSelect(SelectedAID, &SelectedAIDLen, label, &label_len);
		
			
            sprintf(buff, "select ret %04X ", ret);
            CTOS_LCDTPrintXY(1, 7, buff);
            if (ret == d_OK)
            {
                len = sizeof(value);
                EMV_DataGet(d_TAG_PAN, &len, value);
                memset(buff, 0, sizeof(buff));
                len = wub_hex_2_str(value, buff, len);
                CTOS_LCDTPrintXY(1, 3, buff);
     
				ret = EMV_TxnPerform();
		
			  sprintf(buff, "perform ret %04X ", ret);
              // CTOS_LCDTPrintXY(1, 7, buff);
                if (ret == d_OK)
                {
                  len = sizeof(value);
                  EMV_DataGet(d_TAG_TRACK2_EQUIVALENT_DATA, &len, value);
                  sprintf(buff, "Track2 equivalent data len: %d", len);
                  CTOS_PrinterPutString(buff);
                  memset(buff, 0, sizeof(buff));
                  CTOS_PrinterPutString("Track2 equivalent data :");
                  len = wub_hex_2_str(value, &buff[strlen(buff)], len);
                  CTOS_PrinterPutString(buff);
                  
                  len = sizeof(value);
                  EMV_DataGet(d_TAG_PAN, &len, value);
                  memset(buff, 0, sizeof(buff));
                  sprintf(buff, "PAN :");
                  len = wub_hex_2_str(value, &buff[strlen(buff)], len);
                  CTOS_PrinterPutString(buff);
                  
                  len = sizeof(value);
                  EMV_DataGet(0x5F24, &len, value);
                  memset(buff, 0, sizeof(buff));
                  sprintf(buff, "Expire Date :");
                  len = wub_hex_2_str(value, &buff[strlen(buff)], len);
                  CTOS_PrinterPutString(buff);
                  
                  CTOS_PrinterFline(30);
                  
                }
            }
            
            CTOS_SCPowerOff(d_SC_USER);
            
            CTOS_LCDTPrintXY(1, 10, "X key : cancel");
			CTOS_LCDTPrintXY(1, 11, "other key : again");
            
			ForceMainDevice_KBDGet(&bKey);
			if(bKey == d_KBD_CANCEL)
			{
				break;
			}
			
            CTOS_LCDTClearDisplay();
            CTOS_LCDTPrintXY(1, 1, "Plz Insert Card");
            insert = FALSE;
       }
       
   }while(!insert);
   
    
   //CTOS_LCDTPrintXY(1, 8, "Get Key to Exit");
   //CTOS_KBDGet(&key);
        
   return 0;
}
