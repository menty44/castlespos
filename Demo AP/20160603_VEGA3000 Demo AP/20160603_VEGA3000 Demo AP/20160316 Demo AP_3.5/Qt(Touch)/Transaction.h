/* 
 * File:   Transaction.h
 * Author: SEAN
 *
 * Created on 2015年8月26日, 下午 2:20
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

#ifdef	__cplusplus
extern "C" {
#endif

// Scheme ID
#define d_VW_SID_VISA_OLD_US			0x13
#define d_VW_SID_VISA_WAVE_2			0x16
#define d_VW_SID_VISA_WAVE_QVSDC		0x17
#define d_VW_SID_VISA_WAVE_MSD			0x18
#define d_VW_SID_PAYPASS_MAG_STRIPE		0x20
#define d_VW_SID_PAYPASS_MCHIP			0x21
#define d_VW_SID_JCB_WAVE_2				0x61
#define d_VW_SID_JCB_WAVE_QVSDC			0x62
#define d_VW_SID_AE_EMV					0x50
#define d_VW_SID_AE_MAG_STRIPE			0x52
#define d_VW_DISCOVER					0x41

// Transction Result
#define d_EMV_PAYPASS_MSD_ONLINE				(USHORT)0x0001
#define d_EMV_CHIP_OFF_APPROVAL					(USHORT)0x0002
#define d_EMV_CHIP_OFF_DECLINED					(USHORT)0x0003
#define d_EMV_CHIP_ONL							(USHORT)0x0004
#define d_EMV_VISA_MSD_ONLINE					(USHORT)0x0005
#define d_EMV_CHIP_ONL_APPROVAL					(USHORT)0x0006
#define d_EMV_CHIP_ONL_DECLINED					(USHORT)0x0007
#define d_EMV_CHIP_ONL_ABORT					(USHORT)0x0008

#define d_PIN_FAIL			0x20
#define d_SIGN_FAIL			0x30

#ifdef	__cplusplus
}
#endif

#endif	/* TRANSACTION_H */

