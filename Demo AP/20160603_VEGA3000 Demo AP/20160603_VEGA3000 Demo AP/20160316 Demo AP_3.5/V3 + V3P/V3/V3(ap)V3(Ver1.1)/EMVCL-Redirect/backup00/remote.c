#include "../sharedef.h"
#include "../wub_lib.h"
#include <emv_cl.h>
#include "remote.h"
#include "unistd.h"
#include "typedef.h"
#include "debug.h"
//---------------------------
//emvcontactl2
//#include <emvaplib.h>


//--------------------------------------------------

void CLMW_CommandProcess(BYTE* pFrameBuffer, USHORT* pdwFrameLength,BYTE *isTran);

#define d_PC_DELAY             (BYTE)  10  //      msec
#define d_PC_TIMEOUT           (DWORD) 3   // * 10 msec
#define d_DISP_MAX_X	20
#define d_VERSION	0x0001

BYTE baTotalBuf[5210];
USHORT usTotalLen;
BYTE isTranFlag = FALSE;

int Remote(void)
{
    BYTE key;
    BYTE str[100];
    ULONG ret;
    USHORT usOnceLen;
    ULONG ulTickMsg;
    ULONG ulTickStart;
	BYTE bPercentage, bLastPercentage;
	BYTE bPercentPic, bLastPercentPic;
	USHORT usRtn;
	BYTE ContrastValue;
	
	
	CTOS_USBTxFlush();
	CTOS_USBRxFlush();
	
	ret = CTOS_USBOpen();
	if(ret != d_OK)
	{
		return 1;
	}
    
	ulTickMsg = CTOS_TickGet();

    do
    {
        usTotalLen = 0;
        memset(baTotalBuf, 0x00, sizeof(baTotalBuf));
        ulTickStart = CTOS_TickGet();
        do
        {

            usOnceLen = 0;
            CTOS_Delay(d_PC_DELAY);

            CTOS_USBRxReady(&usOnceLen);
            if(usOnceLen > 0)
            {
                CTOS_USBRxData(&baTotalBuf[usTotalLen], &usOnceLen);

                usTotalLen += usOnceLen;
                ulTickStart = CTOS_TickGet();
            }
            else
            {
                //bRetryCount++;
            }

            //}while( usOnceLen != 0 && bRetryCount <= d_PC_RETRY );
        } while(usOnceLen != 0 && (CTOS_TickGet() - ulTickStart) < d_PC_TIMEOUT);
		
		if(usTotalLen > 0)
		{
			CLMW_CommandProcess(baTotalBuf, &usTotalLen, &isTranFlag);
			
			while(CTOS_USBTxReady() != d_OK);
			CTOS_USBTxData(baTotalBuf, usTotalLen);
			while(CTOS_USBTxReady() != d_OK);
		
		}
		
		ForceMainDevice_KBDHit(&key);
		//CTOS_KBDHit(&key);

    } while(key != d_KBD_CANCEL);

    return 0;

}
