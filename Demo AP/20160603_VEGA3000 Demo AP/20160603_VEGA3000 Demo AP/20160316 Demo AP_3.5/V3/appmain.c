#include "appmain.h"
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
}
//------------------------------------------------------------------------------

ULONG OnEVENT_EMVCL_LED_SHOW(BYTE bLedIndex, BYTE bOnOff) {

    if (g_DeviceModel == d_Device_V3) {
        VirtualLedShow(bLedIndex, bOnOff, FALSE);
    } else if (g_DeviceModel == d_Device_V5S) {
        VW_SetLED(bLedIndex, bOnOff);
    } else {

    }

}
//------------------------------------------------------------------------------

int main(void) {
    BYTE bKey;
    ULONG ulRtn;

    CTOS_LCDSelectMode(0x01);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);
    CTOS_LCDTClearDisplay();
    
    g_usScreenTopOffset = 0;
    g_ScreenSize_X = 20;
    g_ScreenSize_Y = 10;
	
	//EMVCL
    __DebugInit();

	CTOS_LCDFontSelectMode(d_FONT_TTF_MODE);
	CTOS_LCDTTFSelect("kaiu.ttf", 0);//
	//CTOS_PrinterFontSelectMode(d_FONT_TTF_MODE);
	//CTOS_PrinterTTFSelect("kaiu.ttf", 0);
	
	//{
	//	CTOS_LCDTTFSelect("arial.ttf", 0);
	//	CTOS_LanguageLCDFontSize(d_FONT_24x24, d_FONT_TTF_MODE);
	//}
	

    emvcl_initdat.stOnEvent.OnCancelTransaction = CancelTransactionEvent;
    emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;
    emvcl_initdat.bConfigFilenameLen = strlen("emvcl_config.xml");
    emvcl_initdat.pConfigFilename = "emvcl_config.xml";
    ulRtn = EMVCL_Initialize(&emvcl_initdat);
    if (ulRtn != 0) {
        ShowRtn(4, "EMVCL Init Fail ", ulRtn);
        CTOS_KBDGet(&bKey);
        goto END;
    }
	
	UI_Slect:	
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
		goto UI_Slect;
	}

    __DebugAddINT("EMVCL_SetLED Rtn", ulRtn);

    g_isForcedOnl = FALSE;
    Wave2TransactionEnable();                    
    Transaction();   

END:
    return 0;
}


