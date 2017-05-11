#include <string.h>
#include <ctosapi.h>
#include "Printer.h"

void PRT_Draw_Pixel(UINT x, UINT y, BOOL draw)
{
	ULONG yindex, mkbit;
	
	yindex = (y/8)*384;
	mkbit = 1 << (y%8);

	if ((yindex + x) >= 384*(PRT_BUFFER_PIXEL/8))
		return ;
	
	if (draw)
		PRT_BUFFER[yindex + x] |= mkbit;
	else
		PRT_BUFFER[yindex + x] &= ~mkbit;	
}

void PRT_Clear_Buffer( void )
{
	PRT_FILL_Y_PIXEL = 0;
	memset( PRT_BUFFER, 0, 384*( PRT_BUFFER_PIXEL / 8 )*sizeof( UCHAR ) );
}

void PRT_Put_Text_ATTRIB_In_Buffer(BYTE *strASCII, CTOS_FONT_ATTRIB FONT_ATTRIB)
{
	USHORT high;	

	high = (FONT_ATTRIB.FontSize & 0x00FF) * FONT_ATTRIB.Y_Zoom;
	if( (PRT_FILL_Y_PIXEL + high) > PRT_BUFFER_PIXEL )
		return;
	
	CTOS_PrinterBufferPutString(PRT_BUFFER, 0, PRT_FILL_Y_PIXEL, strASCII, &FONT_ATTRIB);
	PRT_FILL_Y_PIXEL = PRT_FILL_Y_PIXEL + high;
}

void PRT_Put_Text_In_Buffer(BYTE *strASCII, USHORT fontSize, USHORT xZoom, USHORT yZoom)
{
	USHORT high;
	CTOS_FONT_ATTRIB FONT_ATTRIB;	
	
	FONT_ATTRIB.FontSize = fontSize;	
	FONT_ATTRIB.X_Zoom = xZoom; 	
	FONT_ATTRIB.Y_Zoom = yZoom; 
	FONT_ATTRIB.X_Space = 0; 
	FONT_ATTRIB.Y_Space = 0;

	high = (fontSize & 0x00FF) * yZoom;
	if( (PRT_FILL_Y_PIXEL + high) > PRT_BUFFER_PIXEL )
		return;
	
	CTOS_PrinterBufferPutString(PRT_BUFFER, 0, PRT_FILL_Y_PIXEL, strASCII, &FONT_ATTRIB);
	PRT_FILL_Y_PIXEL = PRT_FILL_Y_PIXEL + high;
	
}
void PRT_Put_Logo_In_Buffer(USHORT usXPos, USHORT usYPos, USHORT usWidth, USHORT usHeight, BYTE *baPat)
{	
	CTOS_PrinterBufferLogo(usXPos, PRT_FILL_Y_PIXEL, usWidth, usHeight, baPat);
	PRT_FILL_Y_PIXEL = PRT_FILL_Y_PIXEL + usHeight;
}

// Roll line.
void PRT_Put_Fline_In_Buffer(USHORT usLines)
{
	PRT_FILL_Y_PIXEL = PRT_FILL_Y_PIXEL + usLines;
}

// This function can print out the buffer content.
USHORT PRT_Printer_Text_In_Buffer(void) 
{
	UINT Y8Size;
	
	if(PRT_FILL_Y_PIXEL == 0 || PRT_FILL_Y_PIXEL > PRT_BUFFER_PIXEL ) {
		return d_NO;
	}
	
	//CTOS_PrinterSetHeatLevel( PRT_HEAT_LEVEL );
	Y8Size = PRT_FILL_Y_PIXEL/8;
	if( (PRT_FILL_Y_PIXEL%8) != 0 )
		Y8Size++;
	return CTOS_PrinterBufferOutput( PRT_BUFFER, Y8Size );
}


void PRT_Put_String_In_Buffer(BYTE *strASCII)
{
	USHORT high;
	CTOS_FONT_ATTRIB FONT_ATTRIB;	
	
	FONT_ATTRIB.FontSize = d_FONT_12x24;	
	FONT_ATTRIB.X_Zoom = 1; 	
	FONT_ATTRIB.Y_Zoom = 1; 
	FONT_ATTRIB.X_Space = 0; 
	FONT_ATTRIB.Y_Space = 0;

	high = (FONT_ATTRIB.FontSize & 0x00FF) * FONT_ATTRIB.Y_Zoom ;
	if( (PRT_FILL_Y_PIXEL + high) > PRT_BUFFER_PIXEL )
		return;
	
	CTOS_PrinterBufferPutString(PRT_BUFFER, 0, PRT_FILL_Y_PIXEL, strASCII, &FONT_ATTRIB);
	PRT_FILL_Y_PIXEL = PRT_FILL_Y_PIXEL + high;
	
}