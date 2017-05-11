/* 
 * File:   sharedef.h
 * Author: user
 *
 * Created on 2014年8月19日, 上午 10:55
 */

#ifndef SHAREDEF_H
#define	SHAREDEF_H

#ifdef	__cplusplus
extern "C" {
#endif


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctosapi.h>
	
extern BYTE g_bCOM;	

USHORT ForceMainDevice_KBDHit(BYTE *bKey);
USHORT ForceMainDevice_KBDGet(BYTE *bKey);



#ifdef	__cplusplus
}
#endif

#endif	/* SHAREDEF_H */

