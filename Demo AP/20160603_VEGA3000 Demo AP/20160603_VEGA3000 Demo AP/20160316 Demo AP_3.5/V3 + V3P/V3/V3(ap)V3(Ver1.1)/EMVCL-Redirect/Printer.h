#define PRT_BUFFER_PIXEL 		1600
BYTE PRT_BUFFER[ 384*(PRT_BUFFER_PIXEL/8) ];
UINT PRT_FILL_Y_PIXEL;

void PRT_Draw_Pixel(UINT x, UINT y, BOOL draw);
void PRT_Clear_Buffer( void );
void PRT_Put_Text_ATTRIB_In_Buffer(BYTE *strASCII, CTOS_FONT_ATTRIB FONT_ATTRIB);
void PRT_Put_Text_In_Buffer(BYTE *strASCII, USHORT fontSize, USHORT xZoom, USHORT yZoom);
void PRT_Put_Logo_In_Buffer(USHORT usXPos, USHORT usYPos, USHORT usWidth, USHORT usHeight, BYTE *baPat);
void PRT_Put_Fline_In_Buffer(USHORT usLines);// Roll line.
USHORT PRT_Printer_Text_In_Buffer(void); // This function can print out the buffer content.
void PRT_Put_String_In_Buffer(BYTE *strASCII);
