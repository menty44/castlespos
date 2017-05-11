#include "../sharedef.h"
#include "../wub_lib.h"
#include <emv_cl.h>
#include "debug2.h"
#include "Transaction.h"
#include "Setting.h"


BOOL CancelTransactionEvent(void)
{
	BYTE k;
/*	
	CTOS_KBDHit(&k);
	
	if(k == '1')
	{
		return TRUE;
	}
*/	
	return FALSE;
}

void ShowMessageEvent(BYTE bKernel, EMVCL_USER_INTERFACE_REQ_DATA *stUserInterfaceRequestData)
{
	DebugAddSTR("Enter Show Message Event");
	
	DebugAddINT("Current Kernel", bKernel);
	DebugAddHEX("Usr Req Data", (BYTE*)stUserInterfaceRequestData, sizeof(EMVCL_USER_INTERFACE_REQ_DATA));
}

EMVCL_INIT_DATA emvcl_initdat;

int EMV_Contactless_main(void) 
{
	BYTE bKey;
	ULONG ulRtn;
	
	CTOS_LCDTClearDisplay();
	CTOS_LCDSelectMode(0x04);
	CTOS_LCDTSelectFontSize(d_FONT_16x30);

	DebugInit();
	
	emvcl_initdat.stOnEvent.OnCancelTransaction = NULL;
	//emvcl_event.OnCancelTransaction = CancelTransactionEvent;
	//emvcl_initdat.stOnEvent.OnShowMessage = NULL;
	emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;
	emvcl_initdat.bConfigFilenameLen = strlen("V3CLVpTP_config.xml");
	emvcl_initdat.pConfigFilename = "V3CLVpTP_config.xml";
	ulRtn = EMVCL_Initialize(&emvcl_initdat);
	if(ulRtn != 0) 
	{
		ShowRtn(3, "EMVCL Init Fail ", ulRtn);
		ForceMainDevice_KBDGet(&bKey);
		goto END;
	}
	
	EMVCL_ShowVirtualLED(NULL);
	EMVCL_SetLED(0x0F, 0x08);
	
	while(1)
	{
		ClearScreen(4, 14);
		ShowTitle("   EMVCL Demo V001  ");
		CTOS_LCDTPrintXY(1, 15, "              X-Exit");
		
		CTOS_LCDTPrintXY(1, 4, "1. Setting      ");
		CTOS_LCDTPrintXY(1, 5, "2. Transaction  ");
		EMVCL_ShowContactlessSymbol(NULL);

getnext:		
		ForceMainDevice_KBDGet(&bKey);
		if(bKey == '1')
		{
			Do_Setting();
		}
		else if(bKey == '2')
		{
			Do_Transaction();
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto getnext;
		}
	}
	

END:
	
	return 0;   
}


