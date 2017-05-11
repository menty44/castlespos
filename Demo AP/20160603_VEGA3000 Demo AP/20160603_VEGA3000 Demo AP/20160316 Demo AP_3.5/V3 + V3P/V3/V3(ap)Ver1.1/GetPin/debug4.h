#ifndef _DEBUG_H
#define	_DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define d_DEBUG_COM             d_COM1

void DebugInit(void);
void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len);
void DebugAddINT(BYTE *title, ULONG value);
void DebugAddSTR(BYTE *str);

#ifdef	__cplusplus
}
#endif

#endif	/* _DEBUG_H */

