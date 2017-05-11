#ifndef _APPMAIN_H
#define	_APPMAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <ctosapi.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

	
#define d_Device_V3				0x01
#define d_Device_V5S			0x02
#define d_Device_MP200			0x03
	

extern BYTE g_DeviceModel;	

void DeviceIdenti(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _APPMAIN_H */

