#include "EMV_appmain.h"
#include <vwdleapi.h>
#include "emv_cl.h"
#include "wub_lib.h"
#include "Transaction.h"
#include "Setting.h"
#include "VirtualLED.h"
#include "ScreenDispaly.h"
#include "debug.h"

//------------------------------------------------------------------------------
EMVCL_INIT_DATA emvcl_initdat;
#define d_EMVCL_EVENTID_LED_PIC_SHOW						0x01
BYTE g_DeviceModel;

BYTE Dollar_Sign;

#define	d_EMVCL_UITYPE_1	d_EMVCL_UITYPE_NORMAL
#define d_EMVCL_UITYPE_2	d_EMVCL_UITYPE_EUR

void Transaction(void);
void Contact_MSR(void);

//const BYTE baLCDLogo[]={ //Width=128, Height=142
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xE0,0xE0,0xE0,0xE0,0x38,0x38,0x38,0x38,0x38,0x18,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x18,0x38,0x38,0x38,0x38,0x38,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xC0,0x70,0x70,0x38,0x38,0x0E,0x0E,0x0E,0x07,0x07,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x07,0x07,0x07,0x0E,0x0E,0x38,0x38,0x78,0x70,0xF0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0x70,0x1C,0x1E,0x0E,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x0E,0x1E,0x1C,0x70,0xF0,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0x38,0x1C,0x07,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFC,0xFC,0xFC,0xFC,0xF8,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x1F,0x3C,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0xC0,0xF8,0x3C,0x1F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFC,0xFC,0xFC,0xFC,0xF8,0xE0,0x00,0x00,0x00,0x00,0x03,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xF8,0xF8,0x38,0xF8,0xF8,0xF8,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x03,0x1F,0x3C,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0xC0,0xF8,0x3F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFE,0xFE,0xFE,0xF8,0xF0,0xC0,0x00,0x00,0x00,0x00,0x07,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x80,0x00,0x00,0x00,0x00,0x07,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0x07,0x00,0x00,0x00,0x00,0x80,0x80,0x81,0x81,0x81,0x81,0x01,0x07,0x07,0x07,0x07,0x0F,0x0F,0xFF,0xFE,0xF8,0x80,0x87,0xBF,0xF8,0xC0,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x80,0xFC,0x7F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0xFE,0xFE,0xFC,0xF0,0xE0,0x00,0x00,0x00,0x01,0x0F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFE,0xE0,0x00,0x00,0x00,0x00,0x01,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x7F,0x01,0x00,0x00,0xF0,0xFC,0xFE,0x1F,0x0F,0x0F,0x0F,0x0F,0x1F,0x1E,0x7C,0xFC,0xF0,0xE0,0xE0,0xFC,0xFF,0x7F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0E,0x1E,0x1E,0x7C,0xFC,0xF0,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xE0,0xC0,0xC0,0xC0,0xC3,0x1F,0x3F,0xFC,0xF8,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x1F,0x1F,0x3C,0xFC,0xF8,0xE0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1F,0xFF,0xFC,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x07,0x07,0x07,0x07,0x1F,0x1F,0x1F,0xFF,0xFF,0xFF,0xFC,0xF8,0xF8,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x07,0x1F,0x1F,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1F,0xFF,0xFC,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x07,0x7F,0xF8,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x07,0x00,0x00,0x00,0x80,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x3F,0x7F,0xF8,0xF0,0xC0,0x81,0x87,0x0F,0x3F,0x7E,0xF8,0xF0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x7F,0xFE,0xF0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x0F,0x7F,0xF0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x03,0x00,0x00,0x00,0x00,0xE0,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFD,0xFF,0x1F,0x1F,0x1F,0x7E,0x7C,0xF0,0xE1,0xE3,0xE3,0xEF,0xFE,0xFC,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x1F,0xFE,0xFC,0xE0,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x03,0x07,0x3F,0xF8,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x07,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x1F,0x1F,0x3C,0x3C,0xF8,0xF8,0xE0,0xE0,0xE3,0xC3,0xC3,0xC3,0xC3,0xC7,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0xFF,0xFC,0xE0,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x1C,0x38,0xE0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,0xFB,0x3F,0x1F,0x07,0x07,0x07,0x03,0x03,0x03,0x07,0x1F,0x3F,0xFC,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x03,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x0F,0x3E,0x38,0x70,0xF0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x07,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0xC0,0xF0,0x70,0x38,0x3E,0x0E,0x07,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x07,0x0F,0x0F,0x0E,0x3E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x0E,0x0E,0x1C,0x1C,0x70,0x70,0xE0,0xE0,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0xE0,0xE0,0x70,0x70,0x7C,0x1C,0x1E,0x0E,0x0F,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x07,0x07,0x07,0x1C,0x1C,0x1C,0x1C,0x38,0x38,0x38,0x38,0x38,0x38,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x20,0x38,0x38,0x38,0x38,0x38,0x1C,0x1C,0x1C,0x1C,0x04,0x07,0x07,0x07,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//};



//------------------------------------------------------------------------------

BOOL CancelTransactionEvent(void) {
    BYTE k;

    CTOS_KBDHit(&k);

    if (k == '1') {
        return TRUE;
    }

    return FALSE;
}
//------------------------------------------------------------------------------

void ShowMessageEvent(BYTE bKernel, EMVCL_USER_INTERFACE_REQ_DATA *stUserInterfaceRequestData) {
    //__DebugAddSTR("Enter Show Message Event");

    //__DebugAddINT("Current Kernel", bKernel);
    //__DebugAddHEX("Usr Req Data", (BYTE*) stUserInterfaceRequestData, sizeof (EMVCL_USER_INTERFACE_REQ_DATA));
}
//------------------------------------------------------------------------------

ULONG OnEVENT_EMVCL_LED_SHOW(BYTE bLedIndex, BYTE bOnOff) {

    if (g_DeviceModel == d_Device_V3) {
        VirtualLedShow(bLedIndex, bOnOff, FALSE);
    } else if (g_DeviceModel == d_Device_V5S) {
        VW_SetLED(bLedIndex, bOnOff);
    } else {

    }


}
//------------------------------------------------------------------------------

//void DeviceIdenti(void) {
//    BYTE bKey;
//
//    g_usScreenTopOffset = 0;
//    g_ScreenSize_X = 16;
//    g_ScreenSize_Y = 8;
//
//    ShowTitle("Set Device Model");
//    TopRelative_LCDTPrintXY(1, 2, "1. Vega3000");
//    TopRelative_LCDTPrintXY(1, 3, "2. Vega5000S");
//
//    TopRelative_LCDTPrintXY(1, 5, "Set wrong may");
//    TopRelative_LCDTPrintXY(1, 6, "result error !!");
//
//    TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
//
//
//    while (1) {
//        CTOS_KBDGet(&bKey);
//
//        switch (bKey) {
//            case d_KBD_1:
//                g_DeviceModel = d_Device_V3;
//                return;
//            case d_KBD_2:
//                g_DeviceModel = d_Device_V5S;
//                return;
//            case d_KBD_CANCEL:
//                exit(0);
//
//            default:
//                ;
//        }
//
//    }
//}
int EMV_Main(void){
	BYTE bKey;
    ULONG ulRtn;
	
	CTOS_LCDSelectMode(0x01);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "Welcome_V3.bmp");
	
	g_usScreenTopOffset = 0;
    g_ScreenSize_X = 20;
    g_ScreenSize_Y = 6;
	
    while (1) {
		ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset); //clear screen from relative first line to screen last line
        //CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
		//TopRelative_LCDTPrintXY(1, 3, "Input Amount:       ");
        //TopRelative_LCDTPrintXY(1, 4, "( 0...999999 )      ");
		
		//__DebugInit();
		emvcl_initdat.stOnEvent.OnCancelTransaction = CancelTransactionEvent;
		emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;          
		emvcl_initdat.bConfigFilenameLen = strlen("emvcl_config.xml");
		emvcl_initdat.pConfigFilename = "emvcl_config.xml";           
		ulRtn = EMVCL_Initialize(&emvcl_initdat);          
		if (ulRtn != 0) {
			ShowRtn(4, "EMVCL Init Fail ", ulRtn);
			CTOS_KBDGet(&bKey);
			return 0;
		}
		ulRtn = EMVCL_SetLED(0x0F, 0x08);           
		//__DebugAddINT("EMVCL_SetLED Rtn", ulRtn);     

		//Select UI
		CTOS_LCDFontSelectMode(d_FONT_TTF_MODE);
		CTOS_LCDTTFSelect("kaiu.ttf", 0);//
	
UI_Select:	
		CTOS_LCDGShowBMPPic(0, 0, "UI_Select.bmp");
		CTOS_KBDGet(&bKey);
		
		if(bKey == d_KBD_1){
			EMVCL_SetUIType(d_EMVCL_UITYPE_1);
			Dollar_Sign = 1;
		}else if(bKey == d_KBD_2){
			EMVCL_SetUIType(d_EMVCL_UITYPE_2);
			Dollar_Sign = 2;
		}else if(bKey == d_KBD_CANCEL){
			return 0;
		}else{
			goto UI_Select;
		}		

		g_isForcedOnl = FALSE;
		Wave2TransactionEnable();
		
		Transaction();  
		
		return 0;
    }

END:
    return 0;
}


int EMV_Contactless_main(void) {
    BYTE bKey;
    ULONG ulRtn;

//    CTOS_LCDTClearDisplay();
    CTOS_LCDSelectMode(0x01);
    CTOS_LCDTSelectFontSize(d_FONT_16x30);
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
//    CTOS_MultiLCDSetBackGndColor(0, 0x009CE4F5);

    //    DeviceIdenti();
    

    //    if (g_DeviceModel == d_Device_V5S) {
    //        ulRtn = VW_InitComm(d_VW_COMM_V5CL, 38400);
    //        if (ulRtn != d_NO_ERROR) {
    //            ShowRtn(1, "Init Comm Fail  ", ulRtn);
    //            CTOS_KBDGet(&bKey);
    //            return;
    //        }

    //        g_usScreenTopOffset = 0;
    //        g_ScreenSize_X = 20;
    //        g_ScreenSize_Y = 8;
    //
    //    } else if (g_DeviceModel == d_Device_V3) {
    g_usScreenTopOffset = 0;
    g_ScreenSize_X = 20;
    g_ScreenSize_Y = 6;


    //    }

    while (1) {
        ClearScreen(1, g_ScreenSize_Y - g_usScreenTopOffset); //clear screen from relative first line to screen last line
        CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
//        ShowTitle("Transaction Type");
//        TopRelative_LCDTPrintY_RightAlign(g_ScreenSize_Y - g_usScreenTopOffset, "X-Exit");
        TopRelative_LCDTPrintXY(1, 3, "1. Contact      ");
        TopRelative_LCDTPrintXY(1, 4, "2. Contactless  ");
        CTOS_LCDTPrintXY(1, 6, "\frX\fn:Exit");

        

        CTOS_KBDGet(&bKey);
        if (bKey == '1') {
            Contact_MSR();

        } else if (bKey == '2') {
//            EMVCL_SetDebug(TRUE, d_COM2);
            //__DebugInit();

            emvcl_initdat.stOnEvent.OnCancelTransaction = CancelTransactionEvent;
            //emvcl_initdat.stOnEvent.OnShowMessage = NULL;
            emvcl_initdat.stOnEvent.OnShowMessage = ShowMessageEvent;
            emvcl_initdat.bConfigFilenameLen = strlen("emvcl_config.xml");
            //emvcl_initdat.bConfigFilenameLen = 0;
            emvcl_initdat.pConfigFilename = "emvcl_config.xml";
            ulRtn = EMVCL_Initialize(&emvcl_initdat);
            if (ulRtn != 0) {
                ShowRtn(4, "EMVCL Init Fail ", ulRtn);
                CTOS_KBDGet(&bKey);
                goto END;
            }
            ulRtn = EMVCL_SetLED(0x0F, 0x08);
            __DebugAddINT("EMVCL_SetLED Rtn", ulRtn);

            g_isForcedOnl = FALSE;
            Wave2TransactionEnable();
            
//            TopRelative_LCDTPrintXY(1, 4, " CK TB ");
//            CTOS_KBDGet(&bKey);
            
            Transaction();
        } else if (bKey == d_KBD_CANCEL) {
            CTOS_LCDTClearDisplay();
            CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
            TopRelative_LCDTPrintXY(1, 4, " Saving Settings... ");
            
//            Wave2TransactionDisable();
            goto END;
//            break;

        }
    }



    //    EMVCL_SpecialEventRegister(d_EMVCL_EVENTID_LED_PIC_SHOW, OnEVENT_EMVCL_LED_SHOW);


    //    if (g_DeviceModel == d_Device_V3) {
    //        VirtualLEDInit();
    //        EMVCL_ShowVirtualLED(NULL);
    //    }


    //    CTOS_LCDGShowPic(25,0,(BYTE *)baLCDLogo,sizeof(baLCDLogo),142);
    //    CTOS_KBDGet(&bKey);


    //    while (1) {
    //        PageShow(d_PAGE_MAIN);
    //        EMVCL_ShowContactlessSymbol(NULL);
    //
    //getnext:
    //        CTOS_KBDGet(&bKey);
    //        if (bKey == '1') {
    //            Do_Setting();
    //        } else if (bKey == '2') {
    //            Do_Transaction();
    //        } else if (bKey == d_KBD_CANCEL) {
    //            break;
    //        } else {
    //            goto getnext;
    //        }
    //    }


END:

    return 0;
}


