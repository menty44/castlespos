#include "sharedef.h"
#include "debug3.h"


//For Device ID
#define d_DEVICE_ID_MAIN_DEVICE										0x00
#define d_DEVICE_ID_EXTERNAL_DEVICE									0x01
//For Para, Bit Mask
#define d_FUNC_REDIRECT_FORCED_REESTABLISH_SESSION							0x00000001

//-------------- new CTOS API
USHORT CTOS_FunRedirectSetDevice(USHORT usDeviceID, ULONG ulPara);
USHORT CTOS_FunRedirectGetDevice(USHORT* usDeviceID, ULONG* ulPara);
USHORT CTOS_FunRedirectSetPort(BYTE bPort);
USHORT CTOS_FunRedirectGetPort(BYTE* bPort);
// --------------

BYTE g_bCOM;
USHORT g_usDeviceID = 0x00;
ULONG g_ulPara = 0x00;
BYTE g_bPort;

USHORT MSR_main(void);
USHORT EMV_Contact_main(void);
USHORT EMV_Contactless_main(void);
USHORT GetPin_main(void);
extern int EMV_Main(void);

USHORT ForceMainDevice_KBDGet(BYTE *bKey) {
    USHORT usRtn;
    BYTE str[50];


    usRtn = CTOS_FunRedirectGetDevice(&g_usDeviceID, &g_ulPara);
    if (usRtn != 0) {
        sprintf(str, " CTOS_GetDevice Fail\nRtn=%04X  \n", usRtn);
        CTOS_LCDTPrintXY(1, 12, str);
        return usRtn;
    }

    if (g_usDeviceID == d_DEVICE_ID_EXTERNAL_DEVICE) {
        usRtn = CTOS_FunRedirectSetDevice(d_DEVICE_ID_MAIN_DEVICE, 0x00);
        if (usRtn != d_OK) {
            sprintf(str, "KBD E2M  \n%04x\n", usRtn);
            CTOS_LCDTPrintXY(1, 12, str);
            //CTOS_KBDGet(bKey);
            return usRtn;
        }

        CTOS_KBDGet(bKey);

        usRtn = CTOS_FunRedirectSetDevice(d_DEVICE_ID_EXTERNAL_DEVICE, 0x00);
        if (usRtn != d_OK) {
            sprintf(str, "KBD M2E fail \n%04x\n", usRtn);
            CTOS_LCDTPrintXY(1, 12, str);
            //CTOS_KBDGet(bKey);
            return usRtn;
        }

    } else {
        CTOS_KBDGet(bKey);
    }


    return 0;
}

USHORT ForceMainDevice_KBDHit(BYTE *bKey) {
    USHORT usRtn;
    BYTE str[50];


    usRtn = CTOS_FunRedirectGetDevice(&g_usDeviceID, &g_ulPara);
    if (usRtn != 0) {
        sprintf(str, " CTOS_GetDevice Fail\nRtn=%04X  \n", usRtn);
        CTOS_LCDTPrintXY(1, 6, str);
        return usRtn;
    }

    if (g_usDeviceID == d_DEVICE_ID_EXTERNAL_DEVICE) {
        usRtn = CTOS_FunRedirectSetDevice(d_DEVICE_ID_MAIN_DEVICE, 0x00);
        if (usRtn != d_OK) {
            sprintf(str, "KBD E2M  \n%04x\n", usRtn);
            CTOS_LCDTPrintXY(1, 6, str);
            //CTOS_KBDGet(bKey);
            return usRtn;
        }

        CTOS_KBDHit(bKey);

        usRtn = CTOS_FunRedirectSetDevice(d_DEVICE_ID_EXTERNAL_DEVICE, 0x00);
        if (usRtn != d_OK) {
            sprintf(str, "KBD M2E fail \n%04x\n", usRtn);
            CTOS_LCDTPrintXY(1, 6, str);
            //CTOS_KBDGet(bKey);
            return usRtn;
        }

    } else {
        CTOS_KBDHit(bKey);
    }


    return 0;
}

void ShowMainScreen(void) {
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "background00.bmp");
//    CTOS_LCDTPrintXY(1, 3, "1:Swtich Ctrl Device");
//    CTOS_LCDTPrintXY(1, 4, "2:EMV Transaction");    

}

USHORT SwitchControlDevice(void) {
    USHORT usRtn;
    BYTE str[50];
    BYTE key;
    BYTE bDevice;


//    sprintf(str, "switching...");
//    CTOS_LCDTPrintXY(1, 5, str);

    usRtn = CTOS_FunRedirectGetDevice(&g_usDeviceID, &g_ulPara);
    if (usRtn != 0) {
        sprintf(str, " CTOS_GetDevice Fail\nRtn=%04X  \n", usRtn);
        CTOS_LCDTPrintXY(1, 6, str);
        return usRtn;
    }

    if (g_usDeviceID == d_DEVICE_ID_EXTERNAL_DEVICE) {
        bDevice = d_DEVICE_ID_MAIN_DEVICE;
    } else {
        bDevice = d_DEVICE_ID_EXTERNAL_DEVICE;
    }

    usRtn = CTOS_FunRedirectSetDevice(bDevice, d_FUNC_REDIRECT_FORCED_REESTABLISH_SESSION); //Set device and force restablish session
    //usRtn = CTOS_FunRedirectSetDevice(bDevice, 0x00);											//Set device and do not restablish session
    if (usRtn != 0) {
        sprintf(str, "Switch Fail  \nRtn = %04X ", usRtn);
        CTOS_LCDTPrintXY(1, 6, str);
        CTOS_Delay(1000);
        //CTOS_KBDGet(&key);
        return usRtn;
    }
    sprintf(str, "                  ");
    CTOS_LCDTPrintXY(1, 6, str);

    return 0;
}

/** 
 ** The main entry of the terminal application 
 **/
int main(int argc, char *argv[]) {
    BYTE bKey = 0xFF;
    USHORT usRtn;
    BYTE str[50];
    BYTE bPort = 0x80; // in example 0x87 is USBCDC,  
	int i;

    CTOS_USBSelectMode(d_USB_HOST_MODE);
    CTOS_LCDTClearDisplay();
    CTOS_LCDGShowBMPPic(0, 0, "Waiting_V3.bmp");
    //CTOS_MultiLCDSetBackGndColor(0, 0x009CE4F5);

    //Open port which communicated with external device 
	i = 0;
    while (1) {
        g_bCOM = bPort;
		
		
        usRtn = CTOS_FunRedirectSetPort(bPort);
        if (usRtn != d_OK) {
            if (usRtn == 0x0A02) {
                i = 100;
                //CTOS_LCDTPrintXY(1, 4, " Plz Wait Ext Ready ");
                //CTOS_LCDTPrintXY(1, 5, " Any Key Continue..   ");
//                CTOS_LCDTPrintXY(1, 10, " 'X' -> Exit        ");
                //CTOS_LCDTPrintXY(1, 6, " \frX\fn:Exit");
                //CTOS_KBDGet(&bKey);
                //if (bKey == d_KBD_CANCEL) {
                //    CTOS_USBSelectMode(d_USB_DEVICE_MODE);
                //    return;
                //}
            } else {
                sprintf(str, "SetPort err \nRtn = %04X  \n", usRtn);
                CTOS_LCDTPrintXY(1, 3, str);
                CTOS_Delay(1000);
				//CTOS_KBDGet(&bKey);
                return;
            }
        } else{
			if(i < 10){
				bPort = 0x87;
				i++;
				
				continue;
			}else if(i == 100){
				CTOS_Delay(8000);
				CTOS_LCDGShowBMPPic(0, 0, "PressKeyContinue_V3.bmp");
				CTOS_KBDGet(&bKey);
			}
			break;	
		}
    }



    while (1) {
//        ShowMainScreen();

Next_Key:
//        CTOS_FunRedirectGetDevice(&g_usDeviceID, &g_ulPara);
//        if (g_usDeviceID == d_DEVICE_ID_EXTERNAL_DEVICE) {
//            sprintf(str, "Ctrl Device : Ext  \n");
//        } else if (g_usDeviceID == 00) {
//            sprintf(str, "Ctrl Device : Main\n");
//        }
//        CTOS_LCDTPrintXY(1, 6, str);
        //EMV_Contactless_main();
		CTOS_LCDGShowBMPPic(0, 0, "Welcome_V3.bmp");
		EMV_Main();

        ForceMainDevice_KBDGet(&bKey);
        if (bKey == d_KBD_CANCEL) {
            break;
        }
//
//        switch (bKey) {
//            case d_KBD_1:
//                SwitchControlDevice();
//                break;
//
//            case d_KBD_2:
//                EMV_Contactless_main();
//                break;
//
//            default:
//                goto Next_Key;
//                break;
//        }
    }


    usRtn = CTOS_FunRedirectSetDevice(d_DEVICE_ID_MAIN_DEVICE, 0x00);
    CTOS_USBSelectMode(d_USB_DEVICE_MODE);
    exit(0);
}
