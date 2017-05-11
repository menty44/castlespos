#include <ctosapi.h>
#include "debug4.h"
#include "../wub_lib.h"
#include <stdlib.h>
#include <stdarg.h>

#define d_Cradle_error 0xDD
//#define _DEBUG_LOG_
#define _DEBUG_RS232_
//#define d_USB_V5
BOOL isOpen = FALSE;

#ifdef _DEBUG_LOG_
BYTE DebugLog[4096];
USHORT DebugLen;

	

#endif

//#define d_RS232_V9
#define d_RS232_V7

#ifdef _DEBUG_LOG_

void DebugInit()
{
	USHORT usVendorID=0x0CA6, usProductID=0xA050, usRtn;
	

    DebugLen = 0;

#ifdef _DEBUG_RS232_
	#ifdef d_RS232_V9
	    CIT_ExInitialRS232_B(115200);
	#endif
	#ifdef d_RS232_V7
		usRtn = CTOS_RS232Open(d_DEBUG_COM, 115200, 'N', 8, 1);
                if(usRtn != d_OK)
                {
                    isOpen = FALSE;
                }else
                {
                    isOpen = TRUE;
                }
                
	#endif
		
	#ifdef d_USB_V5
		//CTOS_USBSetCDCMode() ;
		//CTOS_USBSetVidPid 	( 0x0CA6A050);
		 CTOS_USBHostOpen(usVendorID, usProductID); 
	 

	#endif	
		
	//DebugAddINT((BYTE*)"Hello(K)", 0);
#endif


}

USHORT DebugExport232(void)
{
	USHORT ret;
#ifdef _DEBUG_LOG_

#ifdef _DEBUG_RS232_
	#ifdef d_RS232_V9
		CIT_SendString_B(DebugLog, DebugLen, 1000);
	#endif
	#ifdef d_RS232_V7
                if(isOpen)
                {
                    while (CTOS_RS232TxReady(d_DEBUG_COM) != d_OK);
                    CTOS_RS232TxData(d_DEBUG_COM, DebugLog, DebugLen);
                    while (CTOS_RS232TxReady(d_DEBUG_COM) != d_OK);
                }
	#endif
	#ifdef d_USB_V5
				
		ret = CTOS_USBTxReady();
		if (ret == d_OK)
		{
		//CTOS_RS232TxData(d_COM2, DebugLog, DebugLen);
		CTOS_USBTxData(	DebugLog, DebugLen );		
		while (CTOS_USBTxReady() != d_OK) ;			
		}		
	#endif			
				
	DebugLen = 0;
        return d_OK;
#endif
	
#endif
}

void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len)
{
#ifdef _DEBUG_LOG_
    USHORT usRtn;
    if (len > (sizeof(DebugLog)/2) - 8)
        len = (sizeof(DebugLog)/2)-8;
    
    DebugLog[DebugLen] = 0x00;
	
    DebugLog[DebugLen ++] = '[';
    DebugLog[DebugLen] = 0x00;
    wub_strcat(&DebugLog[DebugLen], title);
    DebugLen += wub_strlen(title);
    DebugLog[DebugLen ++] = ']';
    DebugLen += wub_hex_2_str(hex, &DebugLog[DebugLen], len);
        //wub_strcat(&DebugLog[DebugLen], hex);   
        //DebugLen +=len;
    DebugLog[DebugLen ++] = 0x0D;
    DebugLog[DebugLen ++] = 0x0A;

    DebugExport232();
      

#endif
}

void DebugAddINT(BYTE *title, ULONG value)
{
#ifdef _DEBUG_LOG_
    USHORT usRtn;
    wub_strcpy(DebugLog, "[");
    wub_strcat(DebugLog, title);
    wub_strcat(DebugLog, "] ");
    wub_str_append_long_dec(DebugLog, value);

    DebugLen = wub_strlen(DebugLog);

    DebugExport232();
    DebugLog[DebugLen ++] = 0x0D;
    DebugLog[DebugLen ++] = 0x0A;

    DebugExport232();

#endif
}

void DebugAddSTR(BYTE *str)
{
#ifdef _DEBUG_LOG_
    wub_strcpy(DebugLog, "[");
    wub_strcat(DebugLog, str);
    wub_strcat(DebugLog, "]");    
    DebugLen = wub_strlen(DebugLog);
    DebugExport232();
    
    DebugLog[DebugLen ++] = 0x0D;
    DebugLog[DebugLen ++] = 0x0A;
    DebugExport232();
    
#endif
}


#endif