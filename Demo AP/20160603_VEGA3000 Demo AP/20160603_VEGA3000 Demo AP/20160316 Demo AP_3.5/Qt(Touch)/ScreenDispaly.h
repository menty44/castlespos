#ifndef SCREENDISPALY_H
#define	SCREENDISPALY_H

#ifdef	__cplusplus
extern "C" {
#endif
	

//#include "appmain.h"
#include "wub_lib.h"
#include "emv_cl.h"
#include "Transaction.h"
#include "debug.h"
	

#define d_PAGE_MAIN						0	
#define d_PAGE_SETTING					100

//================== TAG ========================
#define d_PAGE_SETTING_TAG				110
#define d_PAGE_SETTING_TAG_SET_FAIL		111
#define d_PAGE_SETTING_TAG_SET_OK		112
#define d_PAGE_SETTING_TAG_GET_FAIL		113
#define d_PAGE_SETTING_TAG_GET_OK		114
#define d_PAGE_SETTING_TAG_DEL_FAIL		115
#define d_PAGE_SETTING_TAG_DEL_OK		116		
#define d_PAGE_SETTING_TAG_DELALL_FAIL	117
#define d_PAGE_SETTING_TAG_DELALL_OK	118		
//================== CAPK ========================	
#define d_PAGE_SETTING_CAPK					120
#define d_PAGE_SETTING_CAPK_SET_FAIL		121
#define d_PAGE_SETTING_CAPK_SET_OK			122	
#define d_PAGE_SETTING_CAPK_GET_FAIL		123
#define d_PAGE_SETTING_CAPK_GET_OK			124		
#define d_PAGE_SETTING_CAPK_DEL_FAIL		125
#define d_PAGE_SETTING_CAPK_DEL_OK			126	
#define d_PAGE_SETTING_CAPK_DELALL_FAIL		127
#define d_PAGE_SETTING_CAPK_DELALL_OK		128		

//================== UI TYPE ========================	
#define d_PAGE_SETTING_UI_TYPE					130
#define d_PAGE_SETTING_UI_TYPE_NORMAL_FAIL		131
#define d_PAGE_SETTING_UI_TYPE_EUR_FAIL 		132
//=================== Date ========================	
#define d_PAGE_SETTING_DATE						140	
#define d_PAGE_SETTING_DATE_SET_FAIL			141
#define d_PAGE_SETTING_DATE_SET_OK				142
//=================== Capability ====================	
#define d_PAGE_SETTING_CAPABILITY				150	
#define d_PAGE_SETTING_CAPABILITY_SET_FAIL		151
#define d_PAGE_SETTING_CAPABILITY_GET_FAIL		152
//=================== Transaction =====================	
#define d_PAGE_TRANSACTION										210
#define d_PAGE_TRANSACTION_CL_TRNSACTION						211 
#define d_PAGE_TRANSACTION_PRESENT_CARD							212
#define d_PAGE_TRANSACTION_NO_CARD_AND_USE_OTHER_CARD			213
#define d_PAGE_TRANSACTION_ENTER_ONLINE_PIN						214
#define d_PAGE_TRANSACTION_PIN_BY_PASS							215
#define	d_PAGE_TRANSACTION_SHOW_SCHEME_ID						216
#define d_PAGE_TRANSACTION_OUTCOME_UNKNOWN						217
#define d_PAGE_TRANSACTION_OUTCOME_OFFLINE_APPROVAL				218
#define d_PAGE_TRANSACTION_OUTCOME_OFFLINE_DECLINED				219
#define d_PAGE_TRANSACTION_OUTCOME_GO_ONL						220
#define d_PAGE_TRANSACTION_OUTCOME_ONLINE_APPROVAL				221
#define d_PAGE_TRANSACTION_OUTCOME_ONLINE_DECLINED				222
#define d_PAGE_TRANSACTION_INPUT_AMOUNT							223
#define d_PAGE_TRANSACTION_INPUT_CB_AMOUNT						224
	
//================= Select Transaction Type =============
#define d_PAGE_TRANSACTION_SELECT_TYPE						230
#define d_PAGE_TRANSACTION_SELECT_TYPE_SET_OK				231
//========================================================
#define d_PAGE_TRANSACTION_FORCE_ONLINE						240	

#define d_PAGE_REMOTE										300	
	
	
	
	
	
extern CTOS_RTC g_RTCTempSetting;
extern USHORT g_usScreenTopOffset;
extern USHORT g_ScreenSize_X;
extern USHORT g_ScreenSize_Y;
extern ULONG g_ulDisplayPara[10];
extern BYTE g_str[50];
extern BYTE g_str2[50];

USHORT PageSetParameter(BYTE bNum, ULONG *ulPara);
USHORT PageSetString(BYTE bID, BYTE *str);
void TopRelative_LCDTPrintXY(BYTE bX, BYTE bY, BYTE *str);
void TopRelative_LCDTPrintY_RightAlign(BYTE bY, BYTE *str);
void TopRelative_LCDTPutchXY(BYTE bX, BYTE bY, BYTE bKey);
void ShowTitle(BYTE *str);
void ShowRtn(BYTE usY, BYTE *baMessage, ULONG ulRtn);
void ClearScreen(USHORT usY, USHORT usNoOfRows);
void PageClean(void);
void PageShow(USHORT PageNo);



#ifdef	__cplusplus
}
#endif

#endif	/* SCREENDISPALY_H */

