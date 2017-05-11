#include "appmain.h"
#include "emv_cl.h"
#include "wub_lib.h"
#include "Transaction.h"
#include "ScreenDispaly.h"
#include "debug.h"

BYTE g_baTempbuffer[2048];

//------------------------------------------------------------------------
EMVCL_AID_SET_TAG_DATA stTagData;
EMVCL_AID_GET_TAG_DATA stGetTagData;

//Data Format : TLV1 + TLV2 + TLV3 + ....
#define d_SET_PAYPASS_TAG		"\x5F\x57\x00\x9F\x01\x00\x9F\x40\x05\x00\x00\x00\x00\x00\x9F\x09\x02\x00\x02\xDF\x81\x17\x01\x00\xDF\x81\x18\x01\x60\xDF\x81\x19\x01\x08\xDF\x81\x1A\x03\x9F\x6A\x04\x9F\x1E\x08\x31\x32\x33\x34\x35\x36\x37\x38\xDF\x81\x0C\x01\x02\x9F\x6D\x02\x00\x01\xDF\x81\x1E\x01\x10\xDF\x81\x2C\x01\x00\xDF\x81\x1C\x02\x00\x00\xDF\x81\x1D\x01\x00\x9F\x15\x02\x01\x01\x9F\x16\x00\x9F\x4E\x00\x9F\x7E\x00\xDF\x81\x23\x06\x00\x00\x00\x01\x00\x00\xDF\x81\x24\x06\x00\x00\x00\x03\x00\x00\xDF\x81\x25\x06\x00\x00\x00\x05\x00\x00\xDF\x81\x1F\x01\x08\xDF\x81\x21\x05\x00\x00\x00\x00\x00\xDF\x81\x22\x05\x00\x00\x00\x00\x00\xDF\x81\x20\x05\x00\x00\x00\x00\x00\x9F\x33\x00\x9F\x1A\x02\x00\x56\x9F\x1C\x00\xDF\x81\x1B\x01\x20\x9F\x35\x01\x22\xDF\x81\x26\x06\x00\x00\x00\x00\x10\x00"
#define d_SET_PAYWAVE_TAG		"\x9F\x35\x01\x00\x9F\x33\x03\x00\x08\xC8\x9F\x40\x05\x6F\x00\x00\x20\x01\x9F\x09\x02\x01\x05\x9F\x1A\x02\x08\x40\x5F\x2A\x02\x08\x40\x9F\x1B\x04\x00\x00\x07\xD4\x9F\x7A\x01\x01\xDF\x21\x01\x01\xDF\x22\x01\x01\xDF\x25\x01\xFF\xDF\x00\x06\x00\x00\x00\x00\x30\x00\xDF\x01\x06\x00\x00\x00\x00\x22\x00\xDF\x02\x06\x00\x00\x00\x00\x27\x00\x9F\x66\x04\xB6\x00\x40\x00\xDF\x06\x01\x01\xDF\x8F\x4B\x01\x00\xDF\x24\x01\x01\xDF\x23\x81\x9B\x05\x31\x02\x68\x26\x20\x1F\xDF\x25\x01\xFF\xDF\x8F\x4B\x01\x00\xDF\x00\x01\xFF\xDF\x01\x06\x00\x00\x00\x00\x30\x01\xDF\x02\x06\x00\x00\x00\x00\x30\x01\x08\x31\x02\x68\x26\x12\x00\x00\x03\x1F\xDF\x25\x01\xFF\xDF\x8F\x4B\x01\x00\xDF\x00\x01\xFF\xDF\x01\x06\x00\x00\x00\x00\x15\x01\xDF\x02\x06\x00\x00\x00\x00\x10\x01\x05\x31\x02\x68\x26\x12\x1F\xDF\x25\x01\xFF\xDF\x8F\x4B\x01\x00\xDF\x00\x01\xFF\xDF\x01\x06\x00\x00\x00\x00\x15\x01\xDF\x02\x06\x00\x00\x00\x00\x25\x01\x05\x31\x02\x68\x26\x00\x1F\xDF\x25\x01\xFF\xDF\x8F\x4B\x01\x00\xDF\x00\x01\xFF\xDF\x01\x06\x00\x00\x00\x00\x20\x01\xDF\x02\x06\x00\x00\x00\x00\x15\x01\xDF\x05\x01\x01"
#define d_SET_EXPRESSPAY_TAG	"\x9F\x33\x03\x00\xE8\x88\x9F\x40\x05\x6F\x00\x00\x20\x01\x9F\x09\x02\x01\x05\x9F\x1A\x02\x06\x20\x5F\x2A\x02\x09\x78\x9F\x1B\x04\x00\x00\x07\xD4\x9F\x6D\x02\x01\x05\xDF\x81\x21\x05\x00\x00\x00\x00\x00\xDF\x81\x22\x05\xC4\x00\x00\x00\x00\xDF\x81\x20\x05\xDC\x50\x84\x00\x00\xDF\x8F\x49\x12\xFF\xC3\x0C\x5A\x0A\x9F\x27\x01\x95\x05\x9B\x02\x9F\x26\x08\x9F\x34\x00\xDF\x51\x06\x00\x00\x00\x00\x00\x3C\x9F\x35\x01\x22\xDF\x57\x01\xC0\xDF\x58\x01\x01\xDF\x59\x02\x00\x0A\xDF\x5A\x15\xFF\xC3\x00\x5A\x0A\x95\x05\x9B\x02\x9F\x34\x00\x9F\x02\x00\x9F\x35\x00\xDF\x28\x00\xDF\x5B\x06\x00\x01\x00\x02\x00\x03\xDF\x50\x06\x00\x00\x00\x00\x40\x00\xDF\x52\x06\x00\x00\x00\x00\x20\x00\xDF\x53\x06\x00\x00\x00\x00\x30\x00\x9F\x1E\x08\x01\x02\x03\x04\x05\x06\x07\x08\x9F\x16\x0F\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F\xDF\x9F\x50\x01\x00\xDF\x9F\x51\x01\x00"

void Tag(void)
{
	BYTE bKey, i;
	ULONG rtn;
	BYTE baRBuf1[1024];
	UINT uiRLen1;
	
	while(1)
	{
		PageShow(d_PAGE_SETTING_TAG);
		
next:		
		CTOS_KBDGet(&bKey);
		
		if(bKey == '1')
		{
		//Set PayPass AID with TagsSetting to EMVCL kernel
			
			//tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x00(sale))
			stTagData.bAIDLen = 0x07;
			memcpy(stTagData.baAID, "\xA0\x00\x00\x00\x04\x10\x10", 7);
			stTagData.bKernelID = 0x02;
			stTagData.bTransactionType = 0x00;
			stTagData.usTAGDataLen = sizeof(d_SET_PAYPASS_TAG)-1;
			stTagData.pbaTAGData = (BYTE*)d_SET_PAYPASS_TAG;
	
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(paypass purchase) Rtn", rtn);
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);		
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x01(cash))
			stTagData.bTransactionType = 0x01;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(paypass Cash) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x09(cashback))
			stTagData.bTransactionType = 0x09;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(paypass Cashback) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x20(refund))
			stTagData.bTransactionType = 0x20;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(paypass Refund) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
		
		//Set payWave AID with TagsSetting to EMVCL kernel
			//tag setting of (AID A0000000031010 + Kernel ID 0x03 +  Txn Type = 0x00(sale))
			stTagData.bAIDLen = 0x07;
			memcpy(stTagData.baAID, "\xA0\x00\x00\x00\x03\x10\x10", 7);
			stTagData.bKernelID = 0x03;
			stTagData.bTransactionType = 0x00;
			stTagData.usTAGDataLen = sizeof(d_SET_PAYWAVE_TAG)-1;
			stTagData.pbaTAGData = (BYTE*)d_SET_PAYWAVE_TAG;
	
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(payWave purchase) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);		
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000031010 + Kernel ID 0x03 +  Txn Type = 0x01(cash))
			stTagData.bTransactionType = 0x01;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(payWave Cash) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000031010 + Kernel ID 0x03 +  Txn Type = 0x09(cashback))
			stTagData.bTransactionType = 0x09;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(payWave Cashback) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			
			//tag setting of (AID A0000000031010 + Kernel ID 0x03 +  Txn Type = 0x20(refund))
			stTagData.bTransactionType = 0x20;
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(payWave Refund) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			
		//Set Expresspay AID with TagsSetting to EMVCL kernel
			//tag setting of (AID A00000002501 + Kernel ID 0x04 +  Txn Type = 0x00(sale))
			stTagData.bAIDLen = 0x06;
			memcpy(stTagData.baAID, "\xA0\x00\x00\x00\x25\x01", 6);
			stTagData.bKernelID = 0x04;
			stTagData.bTransactionType = 0x00;
			stTagData.usTAGDataLen = sizeof(d_SET_EXPRESSPAY_TAG)-1;
			stTagData.pbaTAGData = (BYTE*)d_SET_EXPRESSPAY_TAG;
	
			rtn = EMVCL_AIDSetTagData(0x00, &stTagData);
			__DebugAddINT("Set TagSetting(Expresspay purchase) Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_SET_FAIL);		
				CTOS_KBDGet(&bKey);
			}	
			
			PageSetParameter(1,&rtn);
			PageShow(d_PAGE_SETTING_TAG_SET_OK);
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == '2')
		{
			//Get tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x00(sale))
			stGetTagData.bAIDLen = 0x07;
			memcpy(stGetTagData.baAID, "\xA0\x00\x00\x00\x04\x10\x10", 7);
			stGetTagData.bKernelID = 0x02;
			stGetTagData.bTransactionType = 0x00;
			stGetTagData.pbaTAGData = g_baTempbuffer;
					
			rtn = EMVCL_AIDGetTagData(&stGetTagData);
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_GET_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_GET_OK);
				__DebugAddHEX("Get Tag", stGetTagData.pbaTAGData, stGetTagData.usTAGDataLen);
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == '3')
		{
			//Delete tag setting of (AID A0000000041010 + Kernel ID 0x02 +  Txn Type = 0x00(sale))
			stTagData.bAIDLen = 0x07;
			memcpy(stTagData.baAID, "\xA0\x00\x00\x00\x04\x10\x10", 7);
			stTagData.bKernelID = 0x02;
			stTagData.bTransactionType = 0x00;
	
			rtn = EMVCL_AIDSetTagData(0x01, &stTagData);
			__DebugAddINT("Del TagSetting(purchase) Rtn", rtn);
			
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_DEL_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_DEL_OK);
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == '4')
		{
			//Delete All tagsetting.
			rtn = EMVCL_AIDSetTagData(0x02, &stTagData);
			__DebugAddINT("Del All TagSetting Rtn", rtn);
			
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_DELALL_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_TAG_DELALL_FAIL);
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto next;
		}
		
	}	
}

//------------------------------------------------------------------------
#define d_CAPK_RID	"\xA0\x00\x00\x00\x04"
#define d_CAPK_INDEX	0x52
#define d_CAPK_M	"\xAF\xF7\x40\xF8\xDB\xE7\x63\xF3\x33\xA1\x01\x3A\x43\x72\x20\x55\xC8\xE2\x2F\x41\x77\x9E\x21\x9B\x0E\x1C\x40\x9D\x60\xAF\xD4\x5C\x87\x89\xC5\x7E\xEC\xD7\x1E\xA4\xA2\x69\xA6\x75\x91\x6C\xC1\xC5\xE1\xA0\x5A\x35\xBD\x74\x5A\x79\xF9\x45\x55\xCE\x29\x61\x2A\xC9\x33\x87\x69\x66\x5B\x87\xC3\xCA\x8E\x1A\xC4\x95\x7F\x9F\x61\xFA\x7B\xFF\xE4\xE1\x76\x31\xE9\x37\x83\x7C\xAB\xF4\x3D\xD6\x18\x3D\x63\x60\xA2\x28\xA3\xEB\xC7\x3A\x1D\x1C\xDC\x72\xBF\x09\x95\x3C\x81\x20\x3A\xB7\xE4\x92\x14\x8E\x4C\xB7\x74\xCD\xDF\xAA\xC3\x54\x4D\x0D\xD4\xF8\xC8\xA0\xE9\xC7\x0B\x87\x7E\xA7\x9F\x2C\x22\xE4\xCE\x52\xC6\x9F\x3E\xF3\x76\xF6\x1B\x0F\x43\xA5\x40\xFE\x96\xC6\x3F\x58\x63\x10\xC3\xB6\xE3\x9C\x78\xC4\xD6\x47\xCA\xDB\x59\x33"
#define d_CAPK_E	"\x03"

ULONG SetCAPK(void)
{
	EMVCL_CA_PUBLIC_KEY stCAPubKey;
	ULONG rtn;
	BYTE inbuf[1024];
	SHA_CTX sha;
	
//Set CAPK via EMVCL_SetCAPK function
	
	//bAction = 0x00 -> Add, bAction = 0x01 -> Del
	stCAPubKey.bAction = 0x00;
	//CAPK Index
	stCAPubKey.bIndex = d_CAPK_INDEX;
	//Modulus
	stCAPubKey.uiModulusLen = sizeof(d_CAPK_M) -1;
	memcpy(stCAPubKey.baModulus, d_CAPK_M, stCAPubKey.uiModulusLen);
	//Exponent
	stCAPubKey.uiExponentLen = sizeof(d_CAPK_E) -1;
	memcpy(stCAPubKey.baExponent, d_CAPK_E, stCAPubKey.uiExponentLen);
	//HAsh
	CTOS_SHA1Init (&sha);
	CTOS_SHA1Update (&sha, d_CAPK_RID, sizeof(d_CAPK_RID)-1);
	CTOS_SHA1Update (&sha, &stCAPubKey.bIndex, 1);
	CTOS_SHA1Update (&sha, stCAPubKey.baModulus, stCAPubKey.uiModulusLen);
	CTOS_SHA1Update (&sha, stCAPubKey.baExponent, stCAPubKey.uiExponentLen);
	CTOS_SHA1Final (stCAPubKey.baHash, &sha);
	
	__DebugAddHEX("Set CAPK Hash", stCAPubKey.baHash, 20);

	rtn = EMVCL_SetCAPK(d_CAPK_RID, &stCAPubKey);
	
	return rtn;
}

ULONG DelCAPK(void)
{
	EMVCL_CA_PUBLIC_KEY stCAPubKey;
	ULONG rtn;
 
	//bAction = 0x00 -> Add, bAction = 0x01 -> Del
	stCAPubKey.bAction = 0x01;
	//CAPK Index
	stCAPubKey.bIndex = d_CAPK_INDEX;

	rtn = EMVCL_SetCAPK(d_CAPK_RID, &stCAPubKey);
	
	return rtn;
}

ULONG ReaseAllCAPK(void)
{
	EMVCL_CA_PUBLIC_KEY stCAPubKey;
	ULONG rtn;
 
	//bAction = 0x00 -> Add, bAction = 0x01 -> Del
	stCAPubKey.bAction = 0x02;
	
	rtn = EMVCL_SetCAPK(NULL, &stCAPubKey);
	
	return rtn;
}

void CAPK(void)
{
	BYTE bKey, i;
	ULONG rtn;
	BYTE baRBuf1[1024];
	UINT uiRLen1;
	EMVCL_CA_PUBLIC_KEY stCAPubKey;
	
	while(1)
	{
		PageShow(d_PAGE_SETTING_CAPK);
		
next:		
		CTOS_KBDGet(&bKey);
		
		if(bKey == '1')
		{
			rtn = SetCAPK();
			__DebugAddINT("Set CAPK Rtn", rtn);
			
		
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_SET_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_SET_OK);
			}
			
			CTOS_KBDGet(&bKey);
			
		}
		else if(bKey == '2')
		{
			rtn = EMVCL_GetCAPK(d_CAPK_RID, d_CAPK_INDEX, &stCAPubKey);
			__DebugAddINT("EMVCL_GetCAPK Rtn", rtn);
			
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_GET_FAIL);
			}
			else
			{	
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_GET_OK);
				__DebugAddHEX("stCAPubKey.baExponent", stCAPubKey.baExponent, stCAPubKey.uiExponentLen);		
				__DebugAddHEX("stCAPubKey.baModulus", stCAPubKey.baModulus, stCAPubKey.uiModulusLen);	
				__DebugAddHEX("stCAPubKey.baHash", stCAPubKey.baHash, 20);
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == '3')
		{
			rtn = DelCAPK();
			__DebugAddINT("DelCAPK Rtn", rtn);
			
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_DEL_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_DEL_OK);
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == '4')
		{
			rtn = ReaseAllCAPK();
			__DebugAddINT("ReaseAllCAPK Rtn", rtn);
			
			
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_DELALL_FAIL);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPK_DELALL_OK);	
			}
			
			CTOS_KBDGet(&bKey);
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto next;
		}
		
	}	
}

void UIType(void)
{
	BYTE bKey;
	ULONG rtn;
	BYTE bType;
	
	while(1)
	{
		PageShow(d_PAGE_SETTING_UI_TYPE);
		
next:		
		CTOS_KBDGet(&bKey);
		
		if(bKey == '1')
		{
			rtn = EMVCL_SetUIType(d_EMVCL_UITYPE_NORMAL);
			__DebugAddINT("Set Normal UI Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_UI_TYPE_NORMAL_FAIL);
				CTOS_KBDGet(&bKey);
			}
		}
		else if(bKey == '2')
		{
			rtn = EMVCL_SetUIType(d_EMVCL_UITYPE_EUR);
			__DebugAddINT("Set EUR UI Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_UI_TYPE_EUR_FAIL);
				CTOS_KBDGet(&bKey);
			}
		}
		else if(bKey == '3')
		{
			EMVCL_GetUIType(&bType);
			__DebugAddINT("Current UI Type", bType);	
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto next;
		}
		
	}
	
}

void SetDate(void)
{

	BYTE TempIN[32] = {0};
	BYTE bKey = d_KBD_INVALID;
	BYTE bX = 1;
	BYTE bY = 4;
	BYTE i = 0;
	ULONG rtn = 0;
	
	PageShow(d_PAGE_SETTING_DATE);
	
	while(1)
	{
		CTOS_KBDGet(&bKey);
		if((bKey >= '0' && bKey <= '9') && i < 6)
		{
			TopRelative_LCDTPutchXY(bX, bY, bKey);
			bX++;
			TempIN[i++] = bKey;
		}
		else if(bKey == d_KBD_ENTER && i == 6)
		{
			g_RTCTempSetting.bYear = ((TempIN[0] - 0x30)*10)+(TempIN[1] - 0x30);
			g_RTCTempSetting.bMonth = ((TempIN[2] - 0x30)*10)+(TempIN[3] - 0x30);
			g_RTCTempSetting.bDay = ((TempIN[4] - 0x30)*10)+(TempIN[5] - 0x30);

			rtn = CTOS_RTCSet(&g_RTCTempSetting);
			if(rtn != d_OK)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_DATE_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			else
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_DATE_SET_OK);
				CTOS_KBDGet(&bKey);
			}
			break;
		}
		else if(bKey == d_KBD_CANCEL)
		{
			memset(TempIN, 0, sizeof(TempIN));
			i = 0;
			break;
		}
		else if(bKey == d_KBD_CLEAR)
		{
			memset(TempIN, 0, sizeof(TempIN));
			i = 0;
			bX = 1;
			ClearScreen(4, 4);
		}
	}

}

void Capability(void)
{
	BYTE bKey, i;
	ULONG rtn;
	EMVCL_SCHEME_DATA stScheme, stRsp;
	
	while(1)
	{
		PageShow(d_PAGE_SETTING_CAPABILITY);
next:		
		CTOS_KBDGet(&bKey);
		
		if(bKey == '1')
		{
			stScheme.bNoS = 3;
			
			memcpy(stScheme.baID, "\x17\x18\x16", 3);
			memcpy(stScheme.baAction, "\x01\x00\x01",3);
			
			rtn = EMVCL_VisaSetCapability(&stScheme, &stRsp);
			
			__DebugAddINT("EMVCL_VisaSetCapability Rtn", rtn);
			if(rtn != 0)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPABILITY_SET_FAIL);
				CTOS_KBDGet(&bKey);
			}
		}
		else if(bKey == '2')
		{
			stScheme.bNoS = 0xFF;
			rtn = EMVCL_VisaGetCapability(&stScheme);
			__DebugAddINT("EMVCL_VisaGetCapability Rtn", rtn);
			//If the response code is 0xA0000004, the reader provides the scheme information below
			if(rtn != 0xA0000004)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPABILITY_GET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			else
			{
				__DebugAddINT("stScheme.bNoS", stScheme.bNoS);
				for(i=0;i<stScheme.bNoS;i++)
				{
					__DebugAddINT("ID", stScheme.baID[i]);
					__DebugAddINT("Active", stScheme.baAction[i]);
				}
			}
			
		}
		else if(bKey == '3')
		{
			stScheme.bNoS = 0x03;
			memcpy(stScheme.baID, "\x17\x18\x16", 3);
			
			rtn = EMVCL_VisaGetCapability(&stScheme);
			
			__DebugAddINT("EMVCL_VisaGetCapability Rtn", rtn);
			//If the response code is 0xA0000004, the reader provides the scheme information below
			if(rtn != 0xA0000004)
			{
				PageSetParameter(1,&rtn);
				PageShow(d_PAGE_SETTING_CAPABILITY_GET_FAIL);
				CTOS_KBDGet(&bKey);
			}
			else
			{
				__DebugAddINT("stScheme.bNoS", stScheme.bNoS);
				for(i=0;i<stScheme.bNoS;i++)
				{
					__DebugAddINT("ID", stScheme.baID[i]);
					__DebugAddINT("Active", stScheme.baAction[i]);
				}
			}
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto next;
		}
		
	}
}

//------------------------------------------------------------------------
void Do_Setting(void)
{
	BYTE bKey;
    
	while(1)
	{
		
		PageShow(d_PAGE_SETTING);
		
next:
		CTOS_KBDGet(&bKey);
		
		if(bKey == '1')
		{
			Tag();
		}
		else if(bKey == '2')
		{
			CAPK();
		}
		else if(bKey == '3')
		{
			UIType();
		}
		else if(bKey == '4')
		{
			SetDate();
		}
		else if(bKey == '5')
		{
			Capability();
		}
		else if(bKey == d_KBD_CANCEL)
		{
			break;
		}
		else
		{
			goto next;
		}
	}

}

void Wave2TransactionEnable(void)
{
	EMVCL_SCHEME_DATA stScheme, stRsp;
	ULONG rtn;
	
	stScheme.bNoS = 1;
			
	memcpy(stScheme.baID, "\x16", 1);
	memcpy(stScheme.baAction, "\x01",1);
			
	rtn = EMVCL_VisaSetCapability(&stScheme, &stRsp);
}

void Wave2TransactionDisable(void)
{
	EMVCL_SCHEME_DATA stScheme, stRsp;
	ULONG rtn;
	
	stScheme.bNoS = 1;
			
	memcpy(stScheme.baID, "\x16", 1);
	memcpy(stScheme.baAction, "\x00",1);
			
	rtn = EMVCL_VisaSetCapability(&stScheme, &stRsp);
}

