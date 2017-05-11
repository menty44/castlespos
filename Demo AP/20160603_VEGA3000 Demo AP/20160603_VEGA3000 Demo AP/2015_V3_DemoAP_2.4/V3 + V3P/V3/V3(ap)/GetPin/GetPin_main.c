#include "../sharedef.h"
#include "../wub_lib.h"
#include "debug4.h"
#include "pcipad.h"



BYTE gkey;


void ClearLCDLine(BYTE pos_y)
{
    CTOS_LCDTPrintXY(1, pos_y, "                    ");
}

USHORT RXData(BYTE *data, USHORT *len)
{
    USHORT usRtn;
    
    CTOS_TimeOutSet(TIMER_ID_1, 100);
    while(CTOS_RS232RxReady( g_bCOM, len ) != d_OK)
    {
        if(CTOS_TimeOutCheck(TIMER_ID_1) == d_YES)
        {
            return d_PCIPAD_TIME_OUT;
        }
    }
    usRtn = CTOS_RS232RxData( g_bCOM, data, len );
    if(*len > 0)
    {
        DebugAddHEX("RXData", data, *len);
    }
    else
    {
        return d_PCIPAD_NO_DATA;
    }
    return d_PCIPAD_OK;
}

USHORT TXData(BYTE *data, USHORT len)
{
    USHORT usRtn;
    
    CTOS_TimeOutSet(TIMER_ID_1, 100);
    while(CTOS_RS232TxReady(g_bCOM) != d_OK)
    {
        if(CTOS_TimeOutCheck(TIMER_ID_1) == d_YES)
        {
            return d_PCIPAD_TIME_OUT;
        }
    }
    usRtn = CTOS_RS232TxData( g_bCOM, data, len );
    DebugAddHEX("TXData", data, len);
    
    return d_PCIPAD_OK;
}

USHORT DECData(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen)
{
    if(d_PCIPAD_COMMAND_MODE_ADMIN)
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
    else if(d_PCIPAD_COMMAND_MODE_USER)
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
    else
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
}

USHORT ENCData(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen)
{
    if(d_PCIPAD_COMMAND_MODE_ADMIN)
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
    else if(d_PCIPAD_COMMAND_MODE_USER)
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
    else
    {
        *pResultLen = Len;
        memcpy(pResult, pData, Len);
    }
}

void ShowMenu(void);
void ShowMenu()
{
    CTOS_LCDTPrintXY(1, 1, "\fr   PCI PAD Sample   \fn");
    CTOS_LCDTPrintXY(1, 2, "1. Inject WK        ");  
    CTOS_LCDTPrintXY(1, 3, "2. Get PIN Block    ");
    
}

void InjectWK(void)
{
    BYTE c, baTmp[20];
    USHORT ret;
    PCIPAD_WK_DATA pWKData;
	BYTE EncKey[32];
	
	memset(&pWKData, 0x00, sizeof(PCIPAD_WK_DATA));
    pWKData.Version = 0x00;
    pWKData.MKIndex = 0x0000;
    pWKData.WKIndex = 0x0000;
    pWKData.KeyAttribute = KMS2_KEYATTRIBUTE_PIN;
    pWKData.EncKeyLen = 16;
	pWKData.pEncKeyData = EncKey;
	
 
    memcpy(pWKData.pEncKeyData, "\xEB\xA4\xC4\x36\x44\xA4\xC6\x63\x47\x4A\x33\x88\x0F\xB5\x2B\xB6", 16);
    
    ret = PCIPAD_WriteEncryptedWorkingKey(&pWKData);
    
    ClearLCDLine(5);
    ClearLCDLine(6);
    ClearLCDLine(7);
    ClearLCDLine(8);
    if(ret != d_PCIPAD_OK)
    {
        CTOS_LCDTPrintXY(1, 7, "Inject WK Fail      ");
        sprintf(baTmp, "ret = %04X", ret);
        CTOS_LCDTPrintXY(1, 8, baTmp); 
        ForceMainDevice_KBDGet(&c);
    }
    else
    {
        CTOS_LCDTPrintXY(1, 7, "Inject WK Success      ");
    }
}

BOOL CancelPIN(void)
{
    BYTE bKey;
    
    ForceMainDevice_KBDHit(&bKey);
    
    if(bKey == d_KBD_CANCEL)
    {
        return TRUE;
    }
    
    return FALSE;
}

void ClearLCDLines(BYTE start, BYTE end)
{
    BYTE i;
    for(i = start ; i <= end ; i++)
    {
        ClearLCDLine(i);
    }
}

void DisplayHex(BYTE pos_y, USHORT ret, BYTE *hex, USHORT len)
{
    BYTE baTmp[20];
    BYTE str[128];
    memset(str, 0, 128);
    wub_hex_2_str(hex, str, len);
    
    ClearLCDLine(pos_y);
//    CTOS_LCDTPrintXY(1, pos_y, str);
    if(ret == d_OK)
    {
        CTOS_LCDTPrintXY(1, pos_y, str);            
    }
    else
    {
        sprintf(baTmp, "ret = %04X", ret);
        CTOS_LCDTPrintXY(1, pos_y, baTmp);              
    }    
}

void GetPINBlock( void )
{
    BYTE baESK[24];
    BYTE baICV[8];
    BYTE baKSN[10];
    BYTE baMsg[2048];
    BYTE baOut[20];
    BYTE baTmp[64];
    USHORT usRtn, i;
    PCIPAD_GETPIN_PARA stGetpin;
    PCIPAD_UI_MSG_PARA stMsg;
    
    memset(&stGetpin, 0, sizeof(PCIPAD_GETPIN_PARA));
//    DebugAddINT("PINBlockLen", stGetpin.PINBlockLen);
    memset(&stMsg, 0, sizeof(PCIPAD_UI_MSG_PARA));
    memset(baTmp, 0, sizeof(baTmp));
    memset(baICV, 0, sizeof(baICV));
    memset(baESK, 0, sizeof(baESK));
    memset(baKSN, 0, sizeof(baKSN));
    memset(baOut, 0, sizeof(baOut));
    memset(baMsg, 0, sizeof(baMsg));    
    
    stGetpin.Version = 0x00;
    stGetpin.MKIndex = 0x0000;
    stGetpin.WKIndex = 0x0000;
    stGetpin.TimeOut = 0x00;
    stGetpin.PINBlockType = 0x00;
    stGetpin.PoisitionX = 0x01;
    stGetpin.PoisitionY = 0x05;
    stGetpin.ESK_Len = 0;
    stGetpin.pESK = baESK;
    stGetpin.pKSN = baKSN;
    stGetpin.MinPINLen = 4;
    stGetpin.MaxPINLen = 12;
    stGetpin.isNullPIN = TRUE;
    stGetpin.PAN_Len = 8;
    stGetpin.pPAN = baICV;
    stGetpin.pPINBlock = baOut;
    
    stMsg.Version = 0x00;
//    stMsg.isClearLCD = TRUE;
    stMsg.TotalLine = 0x01;
    memcpy(baMsg, "\x01\x18\x0C\x72\x20\x20\x20\x20\x20\x20\x47\x65\x74\x20\x50\x49\x4E\x20\x20\x20\x20\x20\x20\x20\x0C\x6E", 26);
    stMsg.pMsgData = baMsg;
    stMsg.MsgLen = 26;
    
    usRtn = PCIPAD_GETPIN(&stGetpin, &stMsg, CancelPIN);
//    CTOS_LCDTPrintXY( 1, 7, "                    ");
//    DebugAddINT("PINBlockLen", stGetpin.PINBlockLen);
//    DebugAddHEX("BIN Block", stGetpin.PINBlock, stGetpin.PINBlockLen);
//    CTOS_KBDGet(baESK);
    if( usRtn == d_PCIPAD_USER_CANCEL )
    {
        return;
    }
    else
    {
        CTOS_LCDTPrintXY(1, 5, "PIN Block           ");
        DisplayHex(6, usRtn, stGetpin.pPINBlock, stGetpin.PINBlockLen );        
        CTOS_DES(d_DECRYPTION, "\x31\x32\x33\x34\x35\x36\x37\x38\x41\x42\x43\x44\x45\x46\x47\x48", 16, stGetpin.pPINBlock, stGetpin.PINBlockLen, baTmp);
        CTOS_LCDTPrintXY(1, 7, "DEC PIN Block       ");
        DisplayHex(8, usRtn, baTmp, stGetpin.PINBlockLen );
    }
}

int GetPin_main(int argc,char *argv[])
{
    BYTE bKey;
    BYTE baLCD[20];
    USHORT ret, pos;
    
    //DebugInit();
    
    CTOS_LCDTClearDisplay();

    
    
    PCIPAD_EVENT stComm;
    
    stComm.OnRxData = RXData;
    stComm.OnTxData = TXData;
    stComm.OnDecryptWithSK = DECData;
    stComm.OnEncryptWithSK = ENCData;
    
    PCIPAD_CommunicationInitialize(&stComm);
    
    
    bKey = 0;
    pos = 2;
    while(bKey != d_KBD_CANCEL)
    {        

        ShowMenu();
        ForceMainDevice_KBDGet(&bKey);
		
        switch(bKey)
        {
            case d_KBD_1:
                InjectWK();
                break;
                
            case d_KBD_2:
               GetPINBlock();
                break;
            
			default:                   
                break;
        }            
    }
    

	
	return 0;
}
