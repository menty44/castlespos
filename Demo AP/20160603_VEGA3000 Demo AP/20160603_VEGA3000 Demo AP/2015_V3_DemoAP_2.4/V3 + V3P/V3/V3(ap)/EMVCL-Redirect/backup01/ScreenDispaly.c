#include "EMV_appmain.h"
#include "Transaction.h"
#include "ScreenDispaly.h"



CTOS_RTC g_RTCTempSetting;
USHORT g_usScreenTopOffset;
USHORT g_ScreenSize_X;
USHORT g_ScreenSize_Y;
ULONG g_ulDisplayPara[10];
BYTE g_str[50];
BYTE g_str2[50];

void TopRelative_LCDTPrintXY(BYTE bX, BYTE bY, BYTE *str)
{
	CTOS_LCDTPrintXY(bX, g_usScreenTopOffset + bY, str)	;		
}

void TopRelative_LCDTPrintY_RightAlign(BYTE bY, BYTE *str)
{
	USHORT str_len;
	USHORT usX;
	
	str_len = strlen(str);
	usX = g_ScreenSize_X - str_len;
	
	CTOS_LCDTPrintXY(usX, g_usScreenTopOffset + bY, str);		
}

void TopRelative_LCDTPutchXY(BYTE bX, BYTE bY, BYTE bKey)
{
	CTOS_LCDTPutchXY(bX, g_usScreenTopOffset + bY, bKey);
}
//------------------------------------------------------------------------------
void ShowTitle(BYTE *str)
{
	USHORT str_len;
	USHORT usX;
	USHORT i;
	
	str_len = strlen(str);
	usX = (g_ScreenSize_X - str_len) / 2;
	usX += 1;
	
	CTOS_LCDTSetReverse(d_TRUE);
	for(i= 1 ; i < usX;i++)
		TopRelative_LCDTPrintXY(i, 1, " ");
	
	TopRelative_LCDTPrintXY(usX, 1, str);
	
	for(i= usX + str_len ; i <= g_ScreenSize_X ; i++)
		TopRelative_LCDTPrintXY(i, 1, " ");
	
	CTOS_LCDTSetReverse(d_FALSE);
}
//------------------------------------------------------------------------------
void ShowRtn(BYTE usY, BYTE *baMessage, ULONG ulRtn)
{
	STR str[80];

	TopRelative_LCDTPrintXY(1, usY, baMessage);
	usY = CTOS_LCDTWhereY();
	sprintf(str, "Rtn:0x%08lX  ", ulRtn);
	TopRelative_LCDTPrintXY(1, usY + 1, str); 
}
//------------------------------------------------------------------------------
void ClearScreen(USHORT usStartY, USHORT usEndY)
{
	int i;
	
	for(i=0 ; usStartY + i <= usEndY; i++)
		TopRelative_LCDTPrintXY(1, usStartY + i, "                     ");
}
//------------------------------------------------------------------------------
void PageClean(void)
{
	// clear sceen from relative first line to relative last line - 1
	ClearScreen(2, g_ScreenSize_Y - g_usScreenTopOffset - 1 );
}
//------------------------------------------------------------------------------
USHORT PageSetParameter(BYTE bNum, ULONG *ulPara)
{
	BYTE i;
	
	for(i = 0 ; i < bNum ; i++)
	{
		g_ulDisplayPara[i] = ulPara[i];
	}
	
	return 0;
}

//------------------------------------------------------------------------------
USHORT PageSetString(BYTE bID, BYTE *str)
{
	
	if(bID == 0x01)
	{
		memset(g_str, 0 ,50);
		strcpy(g_str, str);
	}
	else if (bID == 0x02)
	{
		memset(g_str2, 0 ,50);
		strcpy(g_str2, str);
	}
	else
	{
	
	}
	
}
//------------------------------------------------------------------------------
#if 0
void PageShowTest(USHORT PageNo)
{
	BYTE bKey;
	USHORT x;
	
	PageShow(0);
	CTOS_KBDGet(&bKey);
	
	PageShow(100);
	CTOS_KBDGet(&bKey);
	
	
	x = 110;
	for(; x <= 118 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}	
	
	x = 120;
	for(; x <= 128 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	x = 130;
	for(; x <= 132 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	x = 140;
	for(; x <= 142 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	x = 150;
	for(; x <= 152 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	x = 210;
	for(; x <= 222 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	x = 230;
	for(; x <= 231 ;x++)
	{
		PageShow(x);
		CTOS_KBDGet(&bKey);
	}
	
	PageShow(240);
	CTOS_KBDGet(&bKey);
	PageShow(300);
	CTOS_KBDGet(&bKey);
	
}
#endif
//------------------------------------------------------------------------------
void PageShow(USHORT PageNo)
{
	BYTE temp[32] = {0};
	
	switch(PageNo)
	{
		case d_PAGE_MAIN:	//main page
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("EMVCL TestAP 003");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1. Setting      ");
			TopRelative_LCDTPrintXY(1, 3, "2. Transaction  ");
			break;
		}
		case d_PAGE_SETTING :	
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("Setting");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1. Tag          ");
			TopRelative_LCDTPrintXY(1, 3, "2. CAPK         ");
			TopRelative_LCDTPrintXY(1, 4, "3. UI Type      ");
			TopRelative_LCDTPrintXY(1, 5, "4. Set Date     ");
			TopRelative_LCDTPrintXY(1, 6, "5. Set Capability");
			break;
		}	
		
		//========================= TAG ============================
		case d_PAGE_SETTING_TAG :	
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("Tag");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1.Set TagSetting");
			TopRelative_LCDTPrintXY(1, 3, "2.Get TagSetting");
			TopRelative_LCDTPrintXY(1, 4, "3.Del TagSetting");
			TopRelative_LCDTPrintXY(1, 5, "4.Del All Tag   ");
			break;
		}
		case d_PAGE_SETTING_TAG_SET_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Set Tag Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_SET_OK :
		{
			PageClean();		
			ShowRtn(2, "Set Tag OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_GET_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Get Tag Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_GET_OK :
		{
			PageClean();		
			ShowRtn(2, "Get Tag OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_DEL_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Del Tag Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_DEL_OK :
		{
			PageClean();		
			ShowRtn(2, "Del Tag OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_DELALL_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Del All Tag Fail", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_TAG_DELALL_OK :
		{
			PageClean();		
			ShowRtn(2, "Del All Tag OK", g_ulDisplayPara[0]);
			break;
		}
		
		
		//======================== CAPK ============================
		case d_PAGE_SETTING_CAPK :	
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("CAPK");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1.Set CAPK   ");
			TopRelative_LCDTPrintXY(1, 3, "2.Get CAPK   ");
			TopRelative_LCDTPrintXY(1, 4, "3.Del CAPK");
			TopRelative_LCDTPrintXY(1, 5, "4.Erase CAPK");
			break;
		}	
		case d_PAGE_SETTING_CAPK_SET_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Set CAPK Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_SET_OK :
		{
			PageClean();		
			ShowRtn(2, "Set CAPK OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_GET_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Get CAPK Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_GET_OK :
		{
			PageClean();		
			ShowRtn(2, "Get CAPK OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_DEL_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Del CAPK Fail    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_DEL_OK :
		{
			PageClean();		
			ShowRtn(2, "Del CAPK OK    ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_DELALL_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Del All CAPK Fail", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPK_DELALL_OK :
		{
			PageClean();		
			ShowRtn(2, "Del All CAPK OK", g_ulDisplayPara[0]);
			break;
		}
		
		
		//======================== UI TYPE ============================
		case d_PAGE_SETTING_UI_TYPE :
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("UI Type");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1.Set Normal UI ");
			TopRelative_LCDTPrintXY(1, 3, "2.Set EUR UI    ");
			TopRelative_LCDTPrintXY(1, 4, "3.Get UI        ");
			break;
		}
		case d_PAGE_SETTING_UI_TYPE_NORMAL_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Set Normal UI   \nFail            ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_UI_TYPE_EUR_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Set EUR UI   \nFail            ", g_ulDisplayPara[0]);
			break;
		}
		
		//======================== Date ============================		
		case d_PAGE_SETTING_DATE :
		{
			CTOS_RTCGet(&g_RTCTempSetting);	
			sprintf(temp,"Cur Date %02d/%02d/%02d",g_RTCTempSetting.bYear,g_RTCTempSetting.bMonth,g_RTCTempSetting.bDay);
			
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("Date");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, temp);
			TopRelative_LCDTPrintXY(1, 3, "Date YY/MM/DD :         ");
			break;
		}
		case d_PAGE_SETTING_DATE_SET_FAIL :
		{
			PageClean();		
			ShowRtn(2, "Set Date Fail", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_DATE_SET_OK :
		{
			PageClean();		
			ShowRtn(2, "Set Date OK", g_ulDisplayPara[0]);
			break;
		}
		
		//======================== Capability ============================	
		case d_PAGE_SETTING_CAPABILITY :
		{
			ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset);	//clear screen from relative first line to screen last line
			ShowTitle("Capability");
			TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
			TopRelative_LCDTPrintXY(1, 2, "1.Set Capability");
			TopRelative_LCDTPrintXY(1, 3, "2.Get Capability");
			break;
		}
		case d_PAGE_SETTING_CAPABILITY_SET_FAIL :
		{
			PageClean();		
			ShowRtn( 2, "Set Capability  \nFail            ", g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_SETTING_CAPABILITY_GET_FAIL :
		{
			PageClean();		
			ShowRtn( 2, "Get Capability  \nFail            ", g_ulDisplayPara[0]);
			break;
		}
		
		//======================== Transaction ============================
		case d_PAGE_TRANSACTION :
		{
			PageClean();
			ShowTitle("Transaction");
			TopRelative_LCDTPrintXY(1, 2, "1. CL Trans     ");
			TopRelative_LCDTPrintXY(1, 3, "2. Txn Type     ");
			TopRelative_LCDTPrintXY(1, 4, "3. Forced OnL     ");
			break;
		}
		case d_PAGE_TRANSACTION_PRESENT_CARD :
		{
			PageClean();
			TopRelative_LCDTPrintXY(1, 2, " Present Card   ");
			TopRelative_LCDTPrintXY(1, 3, g_str);
			break;
		}
		case d_PAGE_TRANSACTION_NO_CARD_AND_USE_OTHER_CARD :
		{
			if(g_ulDisplayPara[0] == d_EMVCL_RC_NO_CARD)
			{
				strcpy(g_str, "No Card  ");
			}
			else
			{
				strcpy(g_str,"Terminated, Pls \nUse Other Card  ");
			}
			
			ShowRtn(2, g_str, g_ulDisplayPara[0]);
			break;
		}
		case d_PAGE_TRANSACTION_ENTER_ONLINE_PIN :
		{
			TopRelative_LCDTPrintXY(1, 1, "Enter ONL PIN :");
			break;
		}
		case d_PAGE_TRANSACTION_PIN_BY_PASS :
		{
			TopRelative_LCDTPrintXY(1, 2, "PIN By Pass");
			break;
		}
		case d_PAGE_TRANSACTION_SHOW_SCHEME_ID :
		{
			
			switch(g_ulDisplayPara[0])
			{
				case d_VW_SID_PAYPASS_MAG_STRIPE:
					strcpy(g_str,"PayPass M-Stripe");
					break;
				case d_VW_SID_PAYPASS_MCHIP:
					strcpy(g_str," PayPass MChip  ");
					break;
				case d_VW_SID_VISA_OLD_US:
					strcpy(g_str," VISA Old US MSD");
					break;
				case d_VW_SID_VISA_WAVE_MSD:
					strcpy(g_str, "VisaWave MSD   ");
					break;
				case d_VW_SID_VISA_WAVE_2:
					strcpy(g_str," VisaWave 2     ");
					break;
				case d_VW_SID_VISA_WAVE_QVSDC:
					strcpy(g_str," VisaWave qVSDC ");
					break;
				case d_VW_SID_AE_EMV:
					strcpy(g_str," ExpressPay EMV ");
					break;
				case d_VW_SID_AE_MAG_STRIPE:
					strcpy(g_str," AE M-Stripe    ");
					break;
				case d_VW_SID_JCB_WAVE_2:
					strcpy(g_str, " J/Speedy Wave 2");
					break;
				case d_VW_SID_JCB_WAVE_QVSDC:
					strcpy(g_str," J/Speedy qVSDC ");
					break;
				case d_VW_DISCOVER:
					strcpy(g_str," Zip            ");
					break;
				default:
					strcpy(g_str,"CardType No Def.");
					break;
			}

			TopRelative_LCDTPrintXY(1, 6, g_str);
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_UNKNOWN :
		{
			TopRelative_LCDTPrintXY(1,  3, "Unknow Result");
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_OFFLINE_APPROVAL :
		{
			TopRelative_LCDTPrintXY(1, 2, g_str);
			TopRelative_LCDTPrintXY(1, 3, " [Off Approval] ");
			TopRelative_LCDTPrintXY(1, 4, g_str2);
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_OFFLINE_DECLINED:
		{
			TopRelative_LCDTPrintXY(1, 2, " [Off Declined] ");
			TopRelative_LCDTPrintXY(1, 3, g_str);
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_GO_ONL :
		{
			TopRelative_LCDTPrintXY(1, 3, " Go Online...  ");
                        TopRelative_LCDTPrintXY(1, 7, "                     ");
                        TopRelative_LCDTPrintXY(1, 8, "                     ");
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_ONLINE_APPROVAL :
		{
			TopRelative_LCDTPrintXY(1, 2, g_str);
			TopRelative_LCDTPrintXY(1, 3, " [ONL Approval] ");
			TopRelative_LCDTPrintXY(1, 4, g_str2);			
			break;
		}
		case d_PAGE_TRANSACTION_OUTCOME_ONLINE_DECLINED:
		{
			TopRelative_LCDTPrintXY(1,  4, " [ONL Declined] ");
			TopRelative_LCDTPrintXY(1,  4, g_str);
			break;
		}
		case d_PAGE_TRANSACTION_SELECT_TYPE :
		{
			PageClean();
			ShowTitle("Select Txn Type");
			TopRelative_LCDTPrintXY(1, 2, "1.	Purchase");
			TopRelative_LCDTPrintXY(1, 3, "2.	Cash");
			TopRelative_LCDTPrintXY(1, 4, "3.	Cash Back");
			TopRelative_LCDTPrintXY(1, 5, "4.	Refund");
			break;
		}
		case d_PAGE_TRANSACTION_SELECT_TYPE_SET_OK :
		{
			TopRelative_LCDTPrintXY(1, 6, "Set OK!!");
			break;
		}
		case d_PAGE_TRANSACTION_FORCE_ONLINE :
		{
			ShowTitle("Forced Txn Onl");
			PageClean();
			break;
		}
		case d_PAGE_TRANSACTION_CL_TRNSACTION :
		{
			switch(g_ulDisplayPara[0])
			{
				case 0x00:
//					strcpy(g_str, "Sale Txn");
                                        strcpy(g_str, "Transaction");
					break;
				case 0x01:
					strcpy(g_str, "Cash Txn");
					break;
				case 0x09:
					strcpy(g_str, "CashBack Txn");
					break;
				case 0x20:
					strcpy(g_str, "Refund Txn");
					break;
			}
	
			ShowTitle(g_str);
			break;
		}
		case d_PAGE_TRANSACTION_INPUT_AMOUNT :
		{
			PageClean();
			TopRelative_LCDTPrintXY(1, 2, "Input Amt\n");
			TopRelative_LCDTPrintXY(1, 3, "( 0...9999999 )");
                        TopRelative_LCDTPrintXY(1, 7, "                     ");
                        TopRelative_LCDTPrintXY(1, 8, "                     ");
			break;
		}	
		case d_PAGE_TRANSACTION_INPUT_CB_AMOUNT:
		{
			PageClean();
			TopRelative_LCDTPrintXY(1, 2, "Input CB Amt\n");
			TopRelative_LCDTPrintXY(1, 3, "( 0...9999999 )");
			break;
		}	
		
		//======================== Remote ============================
		case d_PAGE_REMOTE :
		{
			ShowTitle("Remote");
			PageClean();
			break;
		}	
			
		
		
		
		
		default:
			;
	}

}