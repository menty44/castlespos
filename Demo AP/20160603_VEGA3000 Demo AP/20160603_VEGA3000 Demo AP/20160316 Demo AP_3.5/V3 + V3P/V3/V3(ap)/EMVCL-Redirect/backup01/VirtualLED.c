#include "EMV_appmain.h"
#include "graph_p.h"
#include "VirtualLED.h"
#include "ScreenDispaly.h"



USHORT LCDShowPic(USHORT usX, USHORT usY, BYTE* baPattern, USHORT usPatLen, USHORT usXSize)
{
    USHORT usRet;
    
    usRet = CTOS_LCDGShowPicEx(d_LCD_SHOWPIC_RGB, usX, usY, baPattern, usPatLen, usXSize);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
    return d_OK;
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
			p = baLCDShowBlue;
			ulSize = sizeof(baLCDShowBlue);
			break;
		case d_VIRTUAL_LED_COLOR_YELLOW:
			p = baLCDShowYellow;
			ulSize = sizeof(baLCDShowYellow);
			break;
		case d_VIRTUAL_LED_COLOR_GREEN:
			p = baLCDShowGreen;
			ulSize = sizeof(baLCDShowGreen);
			break;
		case d_VIRTUAL_LED_COLOR_RED:
			p = baLCDShowRed;
			ulSize = sizeof(baLCDShowRed);
			break;
		case d_VIRTUAL_LED_COLOR_GRAY:
			p = baLCDShowGray;
			ulSize = sizeof(baLCDShowGray);
			break;
		default:
			p = baLCDShowBlack;
			ulSize = sizeof(baLCDShowBlack);
			break;
	}
	
	stLEDColor.stOneLEDColor[bLEDNum-1].OnColorPic_p = p;
	stLEDColor.stOneLEDColor[bLEDNum-1].ulOnPicSize = ulSize;
	
	switch(bOffColor)
	{
		case d_VIRTUAL_LED_COLOR_BLUE:
			p = baLCDShowBlue;
			ulSize = sizeof(baLCDShowBlue);
			break;
		case d_VIRTUAL_LED_COLOR_YELLOW:
			p = baLCDShowYellow;
			ulSize = sizeof(baLCDShowYellow);
			break;
		case d_VIRTUAL_LED_COLOR_GREEN:
			p = baLCDShowGreen;
			ulSize = sizeof(baLCDShowGreen);
			break;
		case d_VIRTUAL_LED_COLOR_RED:
			p = baLCDShowRed;
			ulSize = sizeof(baLCDShowRed);
			break;
		case d_VIRTUAL_LED_COLOR_GRAY:
			p = baLCDShowGray;
			ulSize = sizeof(baLCDShowGray);
			break;
		default:
			p = baLCDShowBlack;
			ulSize = sizeof(baLCDShowBlack);
			break;
	}
	
	stLEDColor.stOneLEDColor[bLEDNum-1].OffColorPic_p = p;
	stLEDColor.stOneLEDColor[bLEDNum-1].ulOffPicSize = ulSize;
	
}

USHORT VirtualLEDInit(void)
{
    USHORT usRet;
	
	//CTOS_VirtualLEDSetColor(1, d_VIRTUAL_LED_COLOR_RED, d_VIRTUAL_LED_COLOR_GRAY);
	//CTOS_VirtualLEDSetColor(2, d_VIRTUAL_LED_COLOR_GREEN, d_VIRTUAL_LED_COLOR_GRAY);
	//CTOS_VirtualLEDSetColor(3, d_VIRTUAL_LED_COLOR_YELLOW, d_VIRTUAL_LED_COLOR_GRAY);
	//CTOS_VirtualLEDSetColor(4, d_VIRTUAL_LED_COLOR_BLUE, d_VIRTUAL_LED_COLOR_GRAY);
	
	VirtualLEDSetColor(1, d_VIRTUAL_LED_COLOR_RED, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(2, d_VIRTUAL_LED_COLOR_GREEN, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(3, d_VIRTUAL_LED_COLOR_YELLOW, d_VIRTUAL_LED_COLOR_GRAY);
	VirtualLEDSetColor(4, d_VIRTUAL_LED_COLOR_BLUE, d_VIRTUAL_LED_COLOR_GRAY);
    
    usRet = CTOS_LCDForeGndColor(d_LCD_BLACK);
    if(usRet != d_OK)
    {
        return usRet;
    }
    usRet = CTOS_LCDGSetBox(2, 0, 77, 48, 1);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
    usRet = CTOS_LCDGSetBox(81, 0, 77, 48, 1);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
    usRet = CTOS_LCDGSetBox(160, 0, 77, 48, 1);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
    usRet = CTOS_LCDGSetBox(239, 0, 77, 48, 1);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
	usRet = LCDShowPic(3, 3, stLEDColor.stOneLEDColor[3].OffColorPic_p, stLEDColor.stOneLEDColor[3].ulOffPicSize, 75);
    //usRet = LCDShowPic(3, 3, baLCDShowGray, sizeof(baLCDShowGray), 75);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
	usRet = LCDShowPic(82, 3, stLEDColor.stOneLEDColor[2].OffColorPic_p, stLEDColor.stOneLEDColor[2].ulOffPicSize, 75);
    //usRet = LCDShowPic(82, 3, baLCDShowGray, sizeof(baLCDShowGray), 75);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
	usRet = LCDShowPic(161, 3, stLEDColor.stOneLEDColor[1].OffColorPic_p, stLEDColor.stOneLEDColor[1].ulOffPicSize, 75);
    //usRet = LCDShowPic(161, 3, baLCDShowGray, sizeof(baLCDShowGray), 75);
    if(usRet != d_OK)
    {
        return usRet;
    }
    
	usRet = LCDShowPic(240, 3, stLEDColor.stOneLEDColor[0].OffColorPic_p, stLEDColor.stOneLEDColor[0].ulOffPicSize, 75);
    //usRet = LCDShowPic(240, 3, baLCDShowGray, sizeof(baLCDShowGray), 75);
    if(usRet != d_OK)
    {
        return usRet;
    }
    return d_OK;
}

USHORT VirtualLEDSet(BYTE bLedIndex, BYTE bOnOff, BOOL bReverse)
{
    USHORT usRet;
    USHORT usX;
    USHORT usY;
    
    // Check the parameter whether out off range
    if(!bLedIndex || bLedIndex > 0x0F || bOnOff > 0x0F)
    {
        return d_LCD_OUT_OF_RANGE;
    }
    
    usY = 3;
    
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
			
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[3].OnColorPic_p, stLEDColor.stOneLEDColor[3].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowBlue, sizeof(baLCDShowBlue),  75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[3].OffColorPic_p, stLEDColor.stOneLEDColor[3].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[2].OnColorPic_p, stLEDColor.stOneLEDColor[2].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowYellow, sizeof(baLCDShowYellow), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[2].OffColorPic_p, stLEDColor.stOneLEDColor[2].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[1].OnColorPic_p, stLEDColor.stOneLEDColor[1].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGreen, sizeof(baLCDShowGreen), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[1].OffColorPic_p, stLEDColor.stOneLEDColor[1].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[0].OnColorPic_p, stLEDColor.stOneLEDColor[0].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowRed, sizeof(baLCDShowRed), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[0].OffColorPic_p, stLEDColor.stOneLEDColor[0].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
    }
    
    return d_OK;
}  

ULONG VirtualLedShow(BYTE bLedIndex, BYTE bOnOff, BOOL isReverse)
{
	USHORT usRet;
    USHORT usX;
    USHORT usY;

	
    
    // Check the parameter whether out off range
    if(!bLedIndex || bLedIndex > 0x0F || bOnOff > 0x0F)
    {
        return d_LCD_OUT_OF_RANGE;
    }
    
    usY = 3;
    
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
			
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[3].OnColorPic_p, stLEDColor.stOneLEDColor[3].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowBlue, sizeof(baLCDShowBlue),  75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[3].OffColorPic_p, stLEDColor.stOneLEDColor[3].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[2].OnColorPic_p, stLEDColor.stOneLEDColor[2].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowYellow, sizeof(baLCDShowYellow), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[2].OffColorPic_p, stLEDColor.stOneLEDColor[2].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[1].OnColorPic_p, stLEDColor.stOneLEDColor[1].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGreen, sizeof(baLCDShowGreen), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[1].OffColorPic_p, stLEDColor.stOneLEDColor[1].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
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
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[0].OnColorPic_p, stLEDColor.stOneLEDColor[0].ulOnPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowRed, sizeof(baLCDShowRed), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
        else
        {
			usRet = LCDShowPic(usX, usY, stLEDColor.stOneLEDColor[0].OffColorPic_p, stLEDColor.stOneLEDColor[0].ulOffPicSize,  75);
            //usRet = LCDShowPic(usX, usY, baLCDShowGray, sizeof(baLCDShowGray), 75);
            if(usRet != d_OK)
            {
                return usRet;
            }
        }
    }
    
    return d_OK;
}
