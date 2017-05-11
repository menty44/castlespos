#ifndef _DEBUG_H
#define	_DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif


#define _DEBUG_LOG_		0
#define _DEBUG_RS232_	0
#define _DEBUG_USB_		1
	
#if _DEBUG_LOG_ == 1
void DebugInit(void);
void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len);
void DebugAddINT(BYTE *title, ULONG value);
void DebugAddSTR(BYTE *title);

#else



#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _DEBUG_H */

