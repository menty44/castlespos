
#ifndef __VIRTUALLED_H__
#define __VIRTUALLED_H__

#ifdef __cplusplus
extern "C"
{
#endif

#define d_VIRTUAL_LED_COLOR_BLACK	0
#define d_VIRTUAL_LED_COLOR_BLUE	1
#define d_VIRTUAL_LED_COLOR_YELLOW	2
#define d_VIRTUAL_LED_COLOR_GREEN	3
#define d_VIRTUAL_LED_COLOR_RED		4
#define d_VIRTUAL_LED_COLOR_GRAY	5
	
typedef struct
{
	BYTE *OnColorPic_p;
	ULONG ulOnPicSize;
	BYTE *OffColorPic_p;
	ULONG ulOffPicSize;
}tstOneLEDColor;

typedef struct
{
	tstOneLEDColor stOneLEDColor[4];
}tstLEDColor;

tstLEDColor stLEDColor;

	
USHORT VirtualLEDInit(void);
USHORT VirtualLEDSet(BYTE bLedIndex, BYTE bOnOff, BOOL bReverse);
void VirtualLEDSetColor(BYTE bLEDNum, BYTE bOnColor, BYTE bOffColor);
USHORT LCDShowPic(USHORT usX, USHORT usY, BYTE* baPattern, USHORT usPatLen, USHORT usXSize);
ULONG VirtualLedShow(BYTE bLedIndex, BYTE bOnOff, BOOL isReverse);



#ifdef __cplusplus
}
#endif

#endif