/* 
 * File:   appmain.h
 * Author: SEAN
 *
 * Created on 2015年8月26日, 下午 4:12
 */

#ifndef APPMAIN_H
#define	APPMAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <ctosapi.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
    
struct TransactionHistory{
UCHAR	CardNO[40];
BYTE	ExpDate[128];
BYTE	TransTime[128];
int		Trans_Amount;
int		Type;
BYTE    SignatureCanvas[180 * 320];
BYTE	Signature[32];
};
	

extern int TransHisCount;
extern struct TransactionHistory TransHis[50];
extern BYTE Dollar_Sign;
	
#ifdef	__cplusplus
}
#endif

#endif	/* APPMAIN_H */

