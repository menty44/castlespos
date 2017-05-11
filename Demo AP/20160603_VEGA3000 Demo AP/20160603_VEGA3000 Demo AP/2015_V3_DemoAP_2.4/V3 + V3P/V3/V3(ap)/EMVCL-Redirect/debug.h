#ifndef _DEBUG_H
#define	_DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif


#define _DEBUG_LOG_		1
#define _DEBUG_RS232_	0
#define _DEBUG_USB_		0
	
#define d_DEBUG_PORT_USB		0xFF
	
#if _DEBUG_LOG_ == 1
void DebugInit(void);
void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len);
void DebugAddINT(BYTE *title, ULONG value);
void DebugAddSTR(BYTE *title);

#define __DebugInit						DebugInit	
#define __DebugAddHEX					DebugAddHEX
#define __DebugAddINT					DebugAddINT
#define __DebugAddSTR					DebugAddSTR

#else

#define __DebugInit()
#define __DebugAddHEX(title, hex, len)
#define __DebugAddINT(title, value)
#define __DebugAddSTR(title)

#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _DEBUG_H */

