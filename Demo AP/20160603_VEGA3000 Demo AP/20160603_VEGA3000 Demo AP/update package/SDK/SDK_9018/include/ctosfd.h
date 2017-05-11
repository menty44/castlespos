#ifndef __CTOSFD_H__
#define __CTOSFD_H__

#include "typedef.h"

#define SECURITY_HANDLE_ID		0
#define SYSUPD_HANDLE_ID		1
#define KMODEM_HANDLE_ID		2
#define CADRV_HANDLE_ID			3
#define CAUSB_HANDLE_ID			4
#define SCDRV_HANDLE_ID			5
#define KMSDRV_HANDLE_ID		2
#define CLDRV_HANDLE_ID                 6

int GetDrvHandle(BYTE ID);
int CloseDrvHandle(BYTE ID);
int CloseAllDrvHandle(void);

#endif
