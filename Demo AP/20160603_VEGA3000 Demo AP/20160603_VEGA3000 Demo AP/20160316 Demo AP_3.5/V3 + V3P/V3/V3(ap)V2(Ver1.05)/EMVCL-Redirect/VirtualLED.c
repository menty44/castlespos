#include <string.h>
#include <ctosapi.h>
#include <ctos_redirect.h>
#include "VirtualLED.h"
#include "../debug3.h"

extern USHORT g_usDeviceID1;

USHORT LCDShowBMP(USHORT usX, USHORT usY, BYTE* BMPFileName)
{
  return CTOS_LCDGShowBMPPic(usX, usY, BMPFileName);
}

void VirtualLEDSetColor(BYTE bLEDNum, BYTE bOnColor, BYTE bOffColor)
{
	BYTE *p;
	ULONG ulSize;
	
	if(!(bLEDNum >= 1 && bLEDNum <= 4))
	{
		return;
	}
	
	switch(bOnColor)
	{
		case d_VIRTUAL_LED_COLOR_BLUE:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OnColorBMP, "fs_data/blue1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_YELLOW:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OnColorBMP, "fs_data/Yellow3.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_GREEN:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OnColorBMP, "fs_data/green1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_RED:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OnColorBMP, "fs_data/Red1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_GRAY:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OnColorBMP, "fs_data/gray1.BMP");
			break;
		default:
			break;
	}
	
	switch(bOffColor)
	{
		case d_VIRTUAL_LED_COLOR_BLUE:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OffColorBMP, "fs_data/blue1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_YELLOW:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OffColorBMP, "fs_data/Yellow3.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_GREEN:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OffColorBMP, "fs_data/green1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_RED:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OffColorBMP, "fs_data/Red1.BMP");
			break;
		case d_VIRTUAL_LED_COLOR_GRAY:
          strcpy(stLEDColor.stOneLEDColor[bLEDNum-1].OffColorBMP, "fs_data/gray1.BMP");
			break;
		default:
			break;
	}
	
}

USHORT VirtualLEDInit(void)
{
    USHORT usRet;
    USHORT id;
    ULONG para = 0;
	
    //DebugAddINT("enter VirtualLEDInit", 0);
    
	VirtualLEDSetColor(1, d_VIRTUAL_LED_COLOR_RED, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(2, d_VIRTUAL_LED_COLOR_GREEN, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(3, d_VIRTUAL_LED_COLOR_YELLOW, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(4, d_VIRTUAL_LED_COLOR_BLUE, d_VIRTUAL_LED_COLOR_GRAY);
    
    CTOS_FunRedirectGetDevice(&id, &para);
    //DebugAddINT("[VirtualLEDInit], device id", id);
    
    do
    {
      usRet = CTOS_LCDForeGndColor(d_LCD_BLACK);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = CTOS_LCDGSetBox(2, 0, 77, 48, 1);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = CTOS_LCDGSetBox(81, 0, 77, 48, 1);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = CTOS_LCDGSetBox(160, 0, 77, 48, 1);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = CTOS_LCDGSetBox(239, 0, 77, 48, 1);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = LCDShowBMP(3, 3, stLEDColor.stOneLEDColor[3].OffColorBMP);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = LCDShowBMP(82, 3, stLEDColor.stOneLEDColor[2].OffColorBMP);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = LCDShowBMP(161, 3, stLEDColor.stOneLEDColor[1].OffColorBMP);
      if(usRet != d_OK)
      {
          break;
      }

      usRet = LCDShowBMP(240, 3, stLEDColor.stOneLEDColor[0].OffColorBMP);
      if(usRet != d_OK)
      {
        break;
      }
    }while(0);
    
    return usRet;
}

USHORT VirtualLEDSet(BYTE bLedIndex, BYTE bOnOff, BOOL bReverse)
{
    USHORT usRet;
    USHORT usX;
    USHORT usY;
    USHORT id;
    ULONG para = 0;
    
    // Check the parameter whether out off range
    if(!bLedIndex || bLedIndex > 0x0F || bOnOff > 0x0F)
    {
        return d_LCD_OUT_OF_RANGE;
    }
    
    usY = 3;
    
    do
    {
      // Blue led
      if(bLedIndex & 0x08)
      {
          if(bReverse)
          {
              usX = 240; 
          }
          else
          {
              usX = 3;
          }

          if(bOnOff & 0x08)
          {

              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[3].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[3].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      } 


      if(bLedIndex & 0x04)
      {
          if(bReverse)
          {
              usX = 161; 
          }
          else
          {
              usX = 82;
          }


          if(bOnOff & 0x04)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[2].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[2].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }

      }

      if(bLedIndex & 0x02)
      {
          if(bReverse)
          {
              usX = 82; 
          }
          else
          {
              usX = 161;
          }

          if(bOnOff & 0x02)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      }

      if(bLedIndex & 0x01)
      {
          if(bReverse)
          {
              usX = 3; 
          }
          else
          {
              usX = 240;
          }

          if(bOnOff & 0x01)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[0].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[0].OffColorBMP);
              if(usRet != d_OK)
              {
                break;
              }
          }
      }
    }while(0);
    
    return usRet;
}  

ULONG VirtualLedShow(BYTE bLedIndex, BYTE bOnOff, BOOL isReverse)
{
	USHORT usRet;
    USHORT usX;
    USHORT usY;
    USHORT id;
    ULONG para = 0;

    // Check the parameter whether out off range
    if(!bLedIndex || bLedIndex > 0x0F || bOnOff > 0x0F)
    {
        return d_LCD_OUT_OF_RANGE;
    }
    
    usY = 3;
    
    do
    {
      // Blue led
      if(bLedIndex & 0x08)
      {
          if(isReverse)
          {
              usX = 240; 
          }
          else
          {
              usX = 3;
          }

          if(bOnOff & 0x08)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[3].OnColorBMP);
              if(usRet != d_OK)
              {
                break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[3].OffColorBMP);
              if(usRet != d_OK)
              {
                break;
              }
          }
      } 


      if(bLedIndex & 0x04)
      {
          if(isReverse)
          {
              usX = 161; 
          }
          else
          {
              usX = 82;
          }


          if(bOnOff & 0x04)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[2].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[2].OffColorBMP);
              if(usRet != d_OK)
              {
                 break;
              }
          }

      }

      if(bLedIndex & 0x02)
      {
          if(isReverse)
          {
              usX = 82; 
          }
          else
          {
              usX = 161;
          }

          if(bOnOff & 0x02)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      }

      if(bLedIndex & 0x01)
      {
          if(isReverse)
          {
              usX = 3; 
          }
          else
          {
              usX = 240;
          }

          if(bOnOff & 0x01)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[0].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[0].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      }
    }while(0);
    
    return usRet;
}

ULONG VirtualLedShow2(BYTE bLedIndex, BYTE bOnOff, BOOL isReverse){
	USHORT usRet;
    USHORT usX;
    USHORT usY;
    USHORT id;
    ULONG para = 0;

    // Check the parameter whether out off range
    if(!bLedIndex || bLedIndex > 0x0F || bOnOff > 0x0F)
    {
        return d_LCD_OUT_OF_RANGE;
    }
    
    usY = 3;
    
    do
    {
      // Blue led
      if(bLedIndex & 0x08)
      {
          if(isReverse)
          {
              usX = 240; 
          }
          else
          {
              usX = 3;
          }

          if(bOnOff & 0x08)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                break;
              }
          }
      } 


      if(bLedIndex & 0x04)
      {
          if(isReverse)
          {
              usX = 161; 
          }
          else
          {
              usX = 82;
          }


          if(bOnOff & 0x04)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                 break;
              }
          }

      }

      if(bLedIndex & 0x02)
      {
          if(isReverse)
          {
              usX = 82; 
          }
          else
          {
              usX = 161;
          }

          if(bOnOff & 0x02)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      }

      if(bLedIndex & 0x01)
      {
          if(isReverse)
          {
              usX = 3; 
          }
          else
          {
              usX = 240;
          }

          if(bOnOff & 0x01)
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OnColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
          else
          {
              usRet = LCDShowBMP(usX, usY, stLEDColor.stOneLEDColor[1].OffColorBMP);
              if(usRet != d_OK)
              {
                  break;
              }
          }
      }
    }while(0);
    
    return usRet;
}