#include "EMV_appmain.h"
#include <vwdleapi.h>
#include "emv_cl.h"
#include "wub_lib.h"
#include "Transaction.h"
#include "Setting.h"
#include "VirtualLED.h"
#include "ScreenDispaly.h"
#include "debug.h"

//------------------------------------------------------------------------------
EMVCL_INIT_DATA emvcl_initdat;
#define d_EMVCL_EVENTID_LED_PIC_SHOW						0x01
BYTE g_DeviceModel;

BYTE Dollar_Sign;

#define	d_EMVCL_UITYPE_1	d_EMVCL_UITYPE_NORMAL
#define d_EMVCL_UITYPE_2	d_EMVCL_UITYPE_EUR

void Transaction(void);
void Contact_MSR(void);

//------------------------------------------------------------------------------

BOOL CancelTransactionEvent(void) {
    BYTE k;

    CTOS_KBDHit(&k);

    if (k == '1') {
        return TRUE;
    }

    return FALSE;
}
//------------------------------------------------------------------------------

void ShowMessageEvent(BYTE bKernel, EMVCL_USER_INTERFACE_REQ_DATA *stUserInterfaceRequestData) {
    __DebugAddSTR("Enter Show Message Event");

    __DebugAddINT("Current Kernel", bKernel);
    __DebugAddHEX("Usr Req Data", (BYTE*) stUserInterfaceRequestData, sizeof (EMVCL_USER_INTERFACE_REQ_DATA));
	if(stUserInterfaceRequestData->bStatus == d_EMVCL_USR_REQ_STATUS_CARD_READ_SUCCESSFULLY ||
	stUserInterfaceRequestData->bMessageIdentifier == d_EMVCL_USR_REQ_MSG_CARD_READ_OK)
	{
		CTOS_Delay(750);
		//delay --> 750 ms
	}
}
//------------------------------------------------------------------------------

ULONG OnEVENT_EMVCL_LED_SHOW(BYTE bLedIndex, BYTE bOnOff) {

/*
    if (g_DeviceModel == d_Device_V3) {
        VirtualLedShow(bLedIndex, bOnOff, FALSE);
    } else if (g_DeviceModel == d_Device_V5S) {
        VW_SetLED(bLedIndex, bOnOff);
    } else {

    }
	*/

	//VirtualLedShow(bLedIndex, bOnOff, FALSE);
	if(Dollar_Sign == 1){
		VirtualLedShow(bLedIndex, bOnOff, FALSE);
	}else if(Dollar_Sign == 2){
		VirtualLedShow2(bLedIndex, bOnOff, FALSE);
	}
}
//------------------------------------------------------------------------------

void ShowDBGOnScreen(int line, BYTE *str)
{
    BYTE        buf[30];
    BYTE        key;
    
    CTOS_LCDTClearDisplay();
    memset(buf,0,sizeof(buf));
    sprintf(buf,"%s",str);
    CTOS_LCDTPrintXY(1,1,buf);
    memset(buf,0,sizeof(buf));
    sprintf(buf,"Program Line is %d",line);
    CTOS_LCDTPrintXY(1,2,buf);    
    CTOS_KBDGet(&key);
}

int EMV_Main(void){
	BYTE bKey;
    ULONG ulRtn;
	
	CTOS_LCDSelectMode(0x01);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "Welcome_V3.bmp");
	
	g_usScreenTopOffset = 0;
    g_ScreenSize_X = 20;
    g_ScreenSize_Y = 6;
	
    while (1) {
		ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset); //clear screen from relative first line to screen last line
        //CTOS_LCDGShowBMPPic(0, 0, "Welcome_V3.bmp");
		//TopRelative_LCDTPrintXY(1, 3, "Input Amount:       ");
        //TopRelative_LCDTPrintXY(1, 4, "( 0...999999 )      ");
		
		__DebugInit();
		emvcl_initdat.stOnEvent.OnCancelTransaction = CancelTransactionEvent;
		emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;          
		emvcl_initdat.bConfigFilenameLen = strlen("emvcl_config.xml");
		emvcl_initdat.pConfigFilename = "emvcl_config.xml";     
		ulRtn = EMVCL_Initialize(&emvcl_initdat);          
		if (ulRtn != 0) {
			ShowRtn(4, "EMVCL Init Fail ", ulRtn);
			CTOS_KBDGet(&bKey);
			return 0;
		}
		
		//Select UI
		CTOS_LCDFontSelectMode(d_FONT_TTF_MODE);
		CTOS_LCDTTFSelect("kaiu.ttf", 0);//
	
UI_Select:	
		CTOS_LCDGShowBMPPic(0, 0, "UI_Select.bmp");
		CTOS_KBDGet(&bKey);
		
		if(bKey == d_KBD_1){
			EMVCL_SetUIType(d_EMVCL_UITYPE_1);
			Dollar_Sign = 1;
		}else if(bKey == d_KBD_2){
			EMVCL_SetUIType(d_EMVCL_UITYPE_2);
			Dollar_Sign = 2;
		}else if(bKey == d_KBD_CANCEL){
			return 0;
		}else{
			goto UI_Select;
		}
		
		VirtualLEDInit();
		EMVCL_SpecialEventRegister(1, OnEVENT_EMVCL_LED_SHOW);
		
		ulRtn = EMVCL_SetLED(0x0F, 0x08);           
		__DebugAddINT("EMVCL_SetLED Rtn", ulRtn);  

		g_isForcedOnl = FALSE;
		Wave2TransactionEnable();
		
		Transaction();  
		
		return 0;
    }

END:
    return 0;
}

int EMV_Contactless_main(void) {
    BYTE bKey;
    ULONG ulRtn;

    CTOS_LCDSelectMode(0x01);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");

    g_usScreenTopOffset = 0;
    g_ScreenSize_X = 20;
    g_ScreenSize_Y = 6;


    while (1) {
        ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset); //clear screen from relative first line to screen last line
        CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
        TopRelative_LCDTPrintXY(1, 3, "1. Contact      ");
        TopRelative_LCDTPrintXY(1, 4, "2. Contactless  ");
        CTOS_LCDTPrintXY(1, 10, "\frX\fn:Exit");

        

        CTOS_KBDGet(&bKey);
        if (bKey == '1') {
            Contact_MSR();

        } else if (bKey == '2') {
//ShowDBGOnScreen(__LINE__, __func__);            
//            EMVCL_SetDebug(TRUE, d_COM1);
            __DebugInit();
//ShowDBGOnScreen(__LINE__, __func__);
            emvcl_initdat.stOnEvent.OnCancelTransaction = CancelTransactionEvent;
//ShowDBGOnScreen(__LINE__, __func__);            
            //emvcl_initdat.stOnEvent.OnShowMessage = NULL;
            emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;
//ShowDBGOnScreen(__LINE__, __func__);            
            emvcl_initdat.bConfigFilenameLen = strlen("emvcl_config.xml");
//ShowDBGOnScreen(__LINE__, __func__);            
            //emvcl_initdat.bConfigFilenameLen = 0;
            emvcl_initdat.pConfigFilename = "emvcl_config.xml";
//ShowDBGOnScreen(__LINE__, __func__);            
            ulRtn = EMVCL_Initialize(&emvcl_initdat);
//ShowDBGOnScreen(__LINE__, __func__);            
            if (ulRtn != 0) {
                ShowRtn(4, "EMVCL Init Fail ", ulRtn);
                CTOS_KBDGet(&bKey);
                goto END;
            }
//ShowDBGOnScreen(__LINE__, __func__);
            ulRtn = EMVCL_SetLED(0x0F, 0x08);
//ShowDBGOnScreen(__LINE__, __func__);            
            __DebugAddINT("EMVCL_SetLED Rtn", ulRtn);
//ShowDBGOnScreen(__LINE__, __func__);            

            g_isForcedOnl = FALSE;
            Wave2TransactionEnable();
//ShowDBGOnScreen(__LINE__, __func__);            
//            TopRelative_LCDTPrintXY(1, 4, " CK TB ");
//            CTOS_KBDGet(&bKey);
            
            Transaction();
//ShowDBGOnScreen(__LINE__, __func__);            
        } else if (bKey == d_KBD_CANCEL) {
            CTOS_LCDTClearDisplay();
            CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
            TopRelative_LCDTPrintXY(1, 4, " Saving Settings... ");
            
//            Wave2TransactionDisable();
            goto END;
//            break;

        }
    }

END:

    return 0;
}


