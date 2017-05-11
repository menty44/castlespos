#include "../sharedef.h"
#include "debug.h"
#include "../wub_lib.h"


#if _DEBUG_RS232_ == 1
	#define d_DEBUG_COMPORT	d_COM1
#endif

#if _DEBUG_LOG_ == 1
BYTE DebugLog[4096];
int DebugLen;
#endif

#if _DEBUG_LOG_ == 1

void DebugInit()
{
#if _DEBUG_LOG_ == 1
	USHORT rtn;
	
	DebugLen = 0;

#if _DEBUG_RS232_ == 1	
	rtn = CTOS_RS232Open(d_DEBUG_COMPORT, 115200, 'N', 8, 1);
#elif _DEBUG_USB_ == 1
	rtn = CTOS_USBOpen();
#endif
	
	if(rtn == 0)
	{
		DebugAddINT((BYTE*)"Hello(K)", 0);
	}
	
#endif
}

void DebugExport232(void)
{
#if _DEBUG_LOG_ == 1

#if _DEBUG_RS232_ == 1
		
	while(CTOS_RS232TxReady(d_DEBUG_COMPORT) != d_OK) ;
	CTOS_RS232TxData(d_DEBUG_COMPORT, DebugLog, DebugLen);
	while(CTOS_RS232TxReady(d_DEBUG_COMPORT) != d_OK) ;

	DebugLen = 0;
#elif _DEBUG_USB_ == 1
	
	while(CTOS_USBTxReady() != d_OK) ;
	CTOS_USBTxData(DebugLog, DebugLen);
	while(CTOS_USBTxReady() != d_OK) ;
	
	DebugLen = 0;
	
#endif
#endif
}

void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len)
{
#if _DEBUG_LOG_ == 1

	if(len > (sizeof(DebugLog)/2) - 8)
	{
		len = (sizeof(DebugLog)/2)-8;
	}

	DebugLog[DebugLen] = 0x00;

	DebugLog[DebugLen ++] = '[';
	DebugLog[DebugLen] = 0x00;
	wub_strcat(&DebugLog[DebugLen], title);
	DebugLen += wub_strlen(title);
	DebugLog[DebugLen ++] = ']';

	DebugLen += wub_hex_2_str(hex, &DebugLog[DebugLen], len);

	DebugLog[DebugLen ++] = 0x0D;
	DebugLog[DebugLen ++] = 0x0A;

	DebugExport232();
#endif
}

void DebugAddINT(BYTE *title, ULONG value)
{
#if _DEBUG_LOG_ == 1

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

void DebugAddSTR(BYTE *title)
{
#if _DEBUG_LOG_ == 1
	
	wub_memset(DebugLog, 0x00, sizeof(DebugLog));
	wub_strcat(DebugLog, "****");
	wub_strcat(DebugLog, title);
	wub_strcat(DebugLog, "****");
	DebugLen = wub_strlen(DebugLog);
	DebugExport232();

#endif
}

#endif
