/*============================================================================
 *
 *      ctoserr.h
 *
 *==========================================================================*/
/*============================================================================
 *
 * Author(s):    Peril Chen
 * Date:
 * Description:
 *
 *==========================================================================*/
#ifndef __CTOSERR_H__
#define __CTOSERR_H__

// Error Class
#define d_ERR_COMMON						0x0000
#define d_ERR_SYSTEM						0x0200
#define d_ERR_TIMER							0x0400
#define d_ERR_RTC							0x0600
#define d_ERR_CRYPTO						0x0800
#define d_ERR_RS232							0x0A00
#define d_ERR_SPI							0x0B00
#define d_ERR_FLASH							0x0C00
#define d_ERR_LED							0x0E00
#define d_ERR_BUZZER						0x1000
#define d_ERR_MSR							0x1200
#define d_ERR_KBD							0x1300
#define d_ERR_SC							0x1400
#define d_ERR_PRINTER						0x1600

#define	d_ERR_PRINTER_BUF					0x1700

#define d_ERR_LCD							0x1A00
#define d_ERR_USB							0x1C00
#define d_ERR_CRADLEUSB						0x1D00
#define d_ERR_FONT							0x1E00
#define d_ERR_BKLIT							0x1F00
#define d_ERR_KMS							0x2800
#define d_ERR_POWER							0x3000
#define d_ERR_MODEM							0x4000
#define d_ERR_ETHERNET						0x4200
#define d_ERR_WIFI							0x4300
#define d_ERR_BLUETOOTH						0x4500
#define d_ERR_GSM							0x4600
#define d_ERR_WIFI_IO						0x6000
#define d_ERR_BLUETOOTH_IO					0x7000
#define d_ERR_RFU							0xFF00

// Common Status
#define d_OK                    			0x0000
#define d_NO								0x0001
#define d_YES								0x0002
#define d_MORE_PROCESSING					0x0010
#define d_USER_CANCEL						0x0020

// General Error
#define d_NOT_SUPPORT						0xFF70
#define d_IOCTL_FAILED						0xFF80
#define d_CHANNEL_IO_BUSY					0xFF90
#define d_FUNCTION_NOT_READY				0xFFFE
#define d_INVALID_FUNCTION					0xFFFF

// System Error
#define d_SYSTEM_INVALID_PARA				0x0201
#define d_SYSTEM_HALT_FAULT					0x0202
#define d_SYSTEM_SYS_PARA_ABSENT			0x0203
#define d_SYSTEM_RMK_NOT_EXIST			0x0204

// Timer Error
#define d_TIMER_INVALID_PARA				0x0401
#define d_TIMER_HAL_FAULT					0x0402

// RTC Error
#define d_RTC_INVALID_PARA					0x0601
#define d_RTC_HAL_FAULT						0x0602
#define d_RTC_TZ_OVERRANGE                  0x0603

// Crypto Error
#define d_CRYPTO_INVALID_PARA				0x0801
#define d_CRYPTO_HAL_FAULT					0x0802
#define d_CRYPTO_RNG_TIMEOUT				0x0803
#define d_CRYPTO_RSA_GEN_KEY_FAILED			0x0804

// Crypto Lib Error
#define d_CRYPTO_LIB_BAD_PARAMETER        	0x0901
#define d_CRYPTO_LIB_MK_NOT_LOAD          	0x0902
#define d_CRYPTO_LIB_MK_LOCK              	0x0903
#define d_CRYPTO_LIB_MK_BAD_CV            	0x0904
#define d_CRYPTO_LIB_MK_STATUS_NOT_MATCH  	0x0905
#define d_CRYPTO_LIB_PIN_TIMEOUT			0x090a //Get PIN time out
#define d_CRYPTO_LIB_PIN_ABORT				0x090B //User abort the PIN Input
#define d_CRYPTO_LIB_PIN_NULLPIN			0x090c //User does not input any digits
#define d_CRYPTO_LIB_DUKPT_OVERFLOW       	0x090E
#define d_CRYPTO_LIB_DUKPT_FAILED         	0x090F
#define d_CRYPTO_LIB_CERT_INVALID         	0x0911
#define d_CRYPTO_LIB_PIN_BLOCK_30          	0x0912
#define d_CRYPTO_LIB_NO_PRIVILEGE         	0x0913
#define d_CRYPTO_LIB_KEY_TYPE_ERR         	0x0914
#define d_CRYPTO_LIB_KEY_CORRUPT         	0x0915


// RS232 Error
#define d_RS232_INVALID_PARA				0x0A01
#define d_RS232_HAL_FAULT					0x0A02
#define d_RS232_BUSY						0x0A03
#define d_RS232_NOT_OPEN					0x0A04
#define d_RS232_NOT_SUPPORT					0x0A05

// SPI Error
#define d_SPI_INVALID_PARA					0x0B01
#define d_SPI_FAILED						0x0B02
#define d_SPI_ALREADY_OPEN					0x0B03
#define d_SPI_NOT_OPEN						0x0B04
#define d_SPI_NOT_SUPPORT					0x0B05

// Flash Error
#define d_FLASH_INVALID_PARA				0x0C01
#define d_FLASH_HAL_FAULT					0x0C02
#define d_FLASH_INVALID						0x0C03

// GPIO Error
#define d_GPIO_INVALID_PARA					0x0D01

// LED Error
#define d_LED_INVALID_PARA					0x0E01
#define d_LED_HAL_FAULT						0x0E02

// Buzzer Error
#define d_BUZZER_INVALID_PARA				0x1001
#define d_BUZZER_HAL_FAULT					0x1002

// MSR Error
#define d_MSR_NO_SWIPE						0x1201
#define d_MSR_TRACK_ERROR					0x1202

//KBD Error
#define d_KBD_INVALID_KEY					0x1301

#define d_PKE_NO_RESOURCE 					0x1310
#define d_PKE_ALREADY_REGISTER 				0x1311
#define d_PKE_INVALID_PARA 					0x1312

// Smart Card Error
#define d_SC_NOT_PRESENT					0x1401
#define d_SC_NOT_ACTIVATED					0x1402
#define d_SC_COMM_ERROR						0x1403
#define d_SC_MUTE							0x1404
#define d_SC_PARITY_ERROR					0x1405
#define d_SC_EDC_ERROR						0x1406
#define d_SC_BUFFER_OVERRUN					0x1407
#define d_SC_HW_ERROR						0x1408
#define d_SC_DEACTIVATED_PROTOCOL			0x1409
#define d_SC_BAD_TS							0x140A
#define d_SC_ATR_TOO_LONG					0x140B
#define d_SC_ATR_INVALID					0x140C
#define d_SC_TA1_NOT_SUPPORTED				0x140D
#define d_SC_PTS_RESPONSE_ERROR				0x140E
#define d_SC_PROCEDURE_BYTE_CONFLICT		0x140F
#define d_SC_POWER_FAILED					0x1410
#define d_SC_INVALID_PARAMETER				0x1411
#define d_SC_INSUFFICIENT_BUF				0x1420
#define d_SC_SOCKET_NOT_EXIST				0x1430
#define d_SC_BUF_TOO_SMALL					0x1431

//Memory Card Error
#define	d_MC_NOT_PRESENT 					0x1501
#define	d_MC_NOT_ACTIVATED           		0x1502
#define	d_MC_MUTE             			  	0x1504
#define	d_MC_PARITY_ERROR            		0x1505
#define	d_MC_EDC_ERROR               		0x1506
#define	d_MC_BUFFER_OVERRUN          		0x1507
#define	d_MC_HW_ERROR                		0x1508
#define	d_MC_DEACTIVATED_PROTOCOL    		0x1509
#define	d_MC_POWER_FAILED            		0x1510
#define	d_MC_INVALID_PARAMETER       		0x1511
#define	d_MC_SOCKET_NOT_EXIST     			0x1530
#define	d_MC_BUF_TOO_SMALL           		0x1531
#define	d_MC_COMM_ERROR              		0x15A3
#define	d_MC_COMMAND_ERROR 	        		0x15A4
#define	d_MC_LOCKED_Memory           		0x15A5
#define	d_MC_VERIFY_FAIL             		0x15A6
#define	d_MC_WRITE_ERROR             		0x15A7
#define	d_MC_NOT_SUPPORTED           		0x15AB

// Printer Error
#define d_PRINTER_HEAD_OVERHEAT				0x1602
#define d_PRINTER_PAPER_OUT					0x1603
#define d_PRINTER_BARCODE_GENERATE_ERR		0x1604
#define d_PRINTER_BARCODE_CONTENT_ERR		0x1605
#define d_PRINTER_BARCODE_CONTENT_LEN_ERR	0x1606
#define d_PRINTER_BARCODE_OUTSIDE_PAPER		0x1607
#define d_PRINTER_PARA_ERR					0x1608
#define d_PRINTER_PIC_FORMAT_NOT_SUPPORT	0x1609
#define d_PRINTER_PIC_OPEN_FAILED			0x160A
#define d_PRINTER_PIC_OVER_SIZE				0x160B
#define d_PRINTER_HAL_FAULT					0x160C
#define d_PRINTER_NOT_SUPPORT				0x1612
#define d_PRINTER_LANGUAGE_NOT_SUPPORT		0x1613

// Printer Buffer Error
#define d_PRTBUF_NOT_INIT					0x1701
#define d_PRTBUF_PARA_ERR 					0x1702
#define d_PRTBUF_CANVAS_OVERFLOW			0x1703
#define d_PRTBUF_PIC_FORMAT_NOT_SUPPORT		0x1704
#define d_PRTBUF_PIC_OPEN_FAILED			0x1705
#define d_PRTBUF_PIC_OVER_SIZE				0x1706
#define d_PRTBUF_LANGUAGE_NOT_SUPPORT		0x1707

// LCD Error
#define d_LCD_OUT_OF_RANGE					0x1A01
#define d_LCD_MODE_NOT_SUPPORT				0x1A02
#define d_LCD_LANGUAGE_NOT_SUPPORT			0x1A03
#define d_LCD_FONT_SIZE_NOT_SUPPORT			0x1A04
#define d_LCD_PARAMETER_NOT_SUPPORT			0x1A05
#define d_LCD_WINDOW_REACH_BOTTOM			0x1A06
#define d_LCD_PIC_FORMAT_NOT_SUPPORT		0x1A07
#define d_LCD_PIC_OPEN_FAILED				0x1A08
#define d_LCD_NOT_SUPPORT					0x1A09

// UI Error
#define d_MENU_LCD_PAGE_OVERFLOW	      	0x1B01
#define d_MENU_LCD_NOT_SUPPORT		      	0x1B02

// USB Error
#define d_USB_INVALID_PARA					0x1C01
#define d_USB_NOT_OPEN						0x1C02
#define d_USB_ALREADY_OPEN					0x1C03
#define d_USB_FAILED						0x1C04
#define d_USB_BUSY							0x1C05
#define d_USB_NOT_READY						0x1C06
#define d_USB_NOT_EXIST						0x1C07
#define d_USB_TIMEOUT						0x1C08
#define d_USB_INCORRECT_MODE				0x1C09
#define d_USB_ID_CONFLICT             		0x1C0A

// Cradle USB Error
#define d_CRADLEUSB_INVALID_PARA			0x1D01
#define d_CRADLEUSB_NOT_OPEN				0x1D02
#define d_CRADLEUSB_ALREADY_OPEN			0x1D03
#define d_CRADLEUSB_FAILED					0x1D04
#define d_CRADLEUSB_BUSY					0x1D05
#define d_CRADLEUSB_NOT_READY				0x1D06


// Language Error
#define d_FONT_LANGUAGE_NOT_SUPPORT			0x1E01
#define d_FONT_SIZE_NOT_SUPPORT	   			0x1E02
#define d_FONT_STYLE_NOT_SUPPORT   			0x1E03
#define d_FONT_TYPE_ERROR		   			0x1E04
#define d_FONT_INVALID_FONT_FILE   			0x1E05
#define d_FONT_INDEX_NOT_SUPPORT			0x1E06
#define d_FONT_PARA_ERR						0x1E07
#define d_FONT_FONTID_NOT_SUPPORT			0x1E08
// BKLit Error
#define d_BKLIT_NOT_SUPPORT					0x1F01
#define d_BKLIT_INVALID_PARA				0x1F02

// File System Error
#define	d_FS_INVALID_PARAMETER				0x2001
#define	d_FS_FHT_FULL						0x2002
#define	d_FS_FILE_ALREADY_OPENED			0x2003
#define	d_FS_FILE_NOT_OPENED				0x2004
#define	d_FS_FILE_NOT_FOUND					0x2005
#define	d_FS_FILE_INVALID_HANDLE			0x2006
#define	d_FS_DATA_FULL						0x2007
#define	d_FS_NOT_INITIALED					0x2008
#define	d_FS_CHECKSUM_ERROR					0x2009
#define	d_FS_FILE_ALREADY_EXISTED			0x200A
#define	d_FS_NOT_OWNER						0x200B
#define	d_FS_OPEN_FAILED					0x200C
#define	d_FS_FUNCTION_NOT_SUPPORTED			0x200F
#define d_FS_STORAGE_TYPE_NOT_SUPPORTED		0x2010
#define	d_FS_OPERATION_ERROR				0x20FF

// TMS Status & Error
#define	d_TMS_OK							0x2100
#define d_TMS_CONNECTION_INCORRECT			0x2101
#define	d_TMS_FILE_OPEN_FAILED				0x2180
#define	d_TMS_FILE_SEEK_FAILED				0x2181
#define	d_TMS_FILE_WRITE_FAILED				0x2182
#define	d_TMS_FILE_READ_FAILED				0x2183
#define	d_TMS_FILE_NAME_SIZE_OVER			0x2184
#define	d_TMS_FILE_NOT_EXISTENT				0x2185
#define	d_TMS_FILE_NOT_OPEND				0x2186
#define	d_TMS_FILE_COPY_FAILED				0x2187
#define	d_TMS_FILE_NAME_INVALID				0x2188
#define	d_TMS_FILE_DELETE_FAILED			0x2189
#define	d_TMS_PARAM_ERROR					0x21A0
#define	d_TMS_RTC_SET_FAILED				0x21A1
#define	d_TMS_RTC_GET_FAILED				0x21A2
#define	d_TMS_CAP_TYPE_INVALID				0x21A3
#define	d_TMS_AP_NUM_OVER					0x21A4
#define	d_TMS_FW_NUM_OVER					0x21A5
#define	d_TMS_AUTH_FAILED					0x21A6
#define	d_TMS_UPDATE_FAILED					0x21A7
#define	d_TMS_USER_CANCEL					0x21FF

// TCP Modem/GPRS Error
#define	d_TCP_IO_PROCESSING					0x2321
#define	d_TCP_IO_BUSY						0x2322
#define	d_TCP_GPRS_NOT_INITIALED			0x2323
#define	d_TCP_IO_READY						0x2324
#define	d_TCP_IO_REQUEST					0x2325
#define	d_TCP_SOCKET_FULL					0x2380
#define	d_TCP_CONNECTION_NOT_ESTABLISHED	0x2381
#define	d_TCP_BAD_FCS						0x2382
#define	d_TCP_PPP_TIMEOUT					0x2383
#define	d_TCP_PROTOCOL_ERROR 				0x2384
#define	d_TCP_LENGTH_ERROR					0x2385
#define	d_TCP_PPP_SEND_TIMEOUT				0x2386
#define	d_TCP_PPP_SEND_ERROR				0x2387
#define	d_TCP_SOCKET_FAILED					0x2388
#define	d_TCP_SOCKET_IO_MODE_FAILED			0x2389
#define	d_TCP_RX_RECEIVE_TIMEOUT			0x238A
#define d_TCP_INVALID_PARA					0x238B
#define	d_TCP_CONNECTION_TERMINATED			0x238C
#define	d_TCP_CONNECT_TIMEOUT				0x2390
#define	d_TCP_DISCONNECT_FAIL				0x2391
#define	d_TCP_RESET                     	0x2392
#define	d_TCP_SEQNENCE_INCORRECT        	0x2393
#define	d_TCP_NO_SERVER						0x2394
#define	d_TCP_RETRANSMISSION				0x2395
#define	d_TCP_PROTOCOL						0x2396
#define	d_TCP_IP_FORMAT_WRONG				0x2397
#define	d_TCP_FORMAT_WRONG					0x2398
#define	d_TCP_SEND_TIMEOUT					0x2399
#define	d_TCP_NO_ACK						0x239A
#define	d_TCP_BUF_FULL						0x239B
#define	d_TCP_RECEIVE_NON_UDP_PACKAGE		0x239C
#define	d_TCP_IP_ADDRESS_NOT_EXIST			0x239D
#define	d_TCP_RECEIVE_DATA_FAILED			0x239E
#define	d_TCP_SEND_DATA_FAILED				0x239F
#define	d_TCP_LCP_TIMEOUT					0x23A0
#define	d_TCP_LCP_ACK						0x23A1
#define	d_TCP_LCP_NAK						0x23A2
#define	d_TCP_LCP_REJECT					0x23A3
#define	d_TCP_LCP_CODE_REJECT				0x23A4
#define	d_TCP_LCP_PROTO_REJECT				0x23A5
#define	d_TCP_LCP_TERM_REJECT				0x23A6
#define	d_TCP_PEER_LCP_ACK					0x23A7
#define	d_TCP_PEER_LCP_NAK					0x23A8
#define	d_TCP_PEER_LCP_REJ					0x23A9
#define	d_TCP_PEER_LCP_CODE_REJECT			0x23AA
#define	d_TCP_PEER_LCP_PROTO_REJECT	 		0x23AB
#define	d_TCP_PEER_LCP_TERM_REQUEST			0x23AC
#define	d_TCP_PEER_LCP_TERM_ACK				0x23AD
#define	d_TCP_SEND_EPIPE_FAILED				0x23AE
#define	d_TCP_RECEIVE_EPIPE_FAILED			0x23AF
#define	d_TCP_CHAP_TIMEOUT					0x23B0
#define	d_TCP_CHAP_RESPONSE					0x23B1
#define	d_TCP_CHAP_CODE_REJECT				0x23B2
#define	d_TCP_PEER_CHAP_SUCCESS				0x23B3
#define	d_TCP_PEER_CHAP_AUTH_FAIL			0x23B4
#define	d_TCP_IPCP_TIMEOUT					0x23C0
#define	d_TCP_IPCP_ACK						0x23C1
#define	d_TCP_IPCP_REJECT					0x23C2
#define	d_TCP_IPCP_CODE_REJECT				0x23C3
#define	d_TCP_IPCP_PROTO_REJECT				0x23C4
#define	d_TCP_PEER_IPCP_ACK					0x23C5
#define	d_TCP_PEER_IPCP_NAK					0x23C6
#define	d_TCP_IPCP_TOSS						0x23C7
#define	d_TCP_PEER_IPCP_REJ					0x23C8
#define	d_TCP_CCP_REJECT					0x23CA
#define	d_TCP_BIND_FAILED					0x23CB
#define	d_TCP_MODEM_DIALUP_TIMEOUT			0x23D0
#define	d_TCP_MODEM_OPEN_FAILED				0x23D1
#define	d_TCP_MODEM_ATCMD_FAILED			0x23D2
#define	d_TCP_MODEM_DIALUP_FAILED			0x23D3
#define	d_TCP_MODEM_CLOSE_FAILED			0x23D4
#define	d_TCP_MODEM_HOOKON_FAILED			0x23D5
#define	d_TCP_MODEM_STATUS_FAILED			0x23D6
#define	d_TCP_MODEM_CONNECTION_FAILED		0x23D7
#define	d_TCP_MODEM_NO_DIAL_TONE			0x23D8
#define	d_TCP_MODEM_LINE_BUSY				0x23D9
#define	d_TCP_MODEM_RING_BACK				0x23DA
#define	d_TCP_MODEM_REMOTE_NOT_ANSWER		0x23DB
#define	d_TCP_MODEM_NO_CARRIER				0x23DC
#define	d_TCP_MODEM_OTHER_ERROR				0x23DD
#define	d_TCP_MODEM_ALREADY_OPENED			0x23DE
#define	d_TCP_MODEM_AUTHENTICATION_FAILED	0x23DF
#define	d_TCP_CHANNEL_TYPE_FAILED			0x23E0
#define	d_TCP_CHANNEL_OFFLINE				0x23E1
#define	d_TCP_GPRS_AUTH_SETTING_FAILED		0x23E2
#define	d_TCP_GSM_OPEN_FAILED				0x23E3
#define	d_TCP_GPRS_ATTACH_FAILED			0x23E4
#define	d_TCP_GPRS_PPP_CONNECT_FAILED		0x23E5
#define	d_TCP_GPRS_IS_CONNECTED				0x23E6
#define	d_TCP_USER_INTERRUPT				0x23FF
#define	d_TCP_URL_NOT_FOUND					0x2370
#define	d_TCP_PING_FAILED					0x2371
#define 	d_TCP_PPP_CONNECTION_TERMINATED		0x2372
#define 	d_TCP_PPP_CLOSE_TIMEOUT				0x2373
#define 	d_TCP_CAPSET_FAILED					0x2374
#define 	d_TCP_BINDTODEVICE_FAILED			0x2375
#define 	d_TCP_SELECTDEFAULTDEVICE_FAILED		0x2376
#define 	d_TCP_NOT_SUPPORT_ANY_DEVICE		0x2377

// Linux System Error
#define	d_LNX_THREAD_CREATE_FAILED			0x2400
#define	d_LNX_IOCTL_FAILED					0x2401
#define	d_LNX_FORK_FAILED					0x2402
#define	d_LNX_FCNTL_FAILED					0x2403
#define	d_LNX_VFORK_RUN_PROGRAM_FAILED		0x2404
#define	d_LNX_FILE_OPEN_FAILED				0x2410
#define	d_LNX_FILE_READ_FAILED				0x2411
#define	d_LNX_FILE_WRITE_FAILED				0x2412
#define	d_LNX_FILE_IS_EMPTY					0x2413
#define	d_LNX_FILE_NOT_EXIST				0x2414
#define	d_LNX_PROCESS_NOT_EXIST				0x2415
#define	d_LNX_PROCESS_KILL_FAILED			0x2416
#define	d_LNX_EXECV_PROGRAM_FAILED			0x2417

// KMS Error
#define d_KMS_INVALID_PARA					0x2801
#define d_KMS_MASTER_KEY_INVALID			0x2802
#define d_KMS_MASTER_KEY_PRESENT			0x2803

// ULD Error
#define d_ULD_INVALID_PARA					0x2A01
#define d_ULD_PORT_OPEN_FAILED				0x2A02
#define d_ULD_KEY_NOT_RECEIVED				0x2A03
#define d_ULD_VERIFY_FAILED					0x2A04
#define d_ULD_SIGN_NOT_RECEIVED				0x2A05
#define d_ULD_HEADER_NOT_RECEIVED			0x2A06
#define d_ULD_FILE_NOT_READY				0x2A07
#define d_ULD_RECEIVE_ERROR					0x2A08
#define d_ULD_RECEIVE_TIMEOUT				0x2A09
#define d_ULD_TOTAL_TIMEOUT					0x2A0A
#define d_ULD_LOCKED						0x2A0B
#define d_ULD_INVALID						0x2A0C
#define d_ULD_PASSWORD_INCORRECT		    0x2A0D
#define d_ULD_AP_NOT_EXIST      			0x2A0E
#define d_ULD_AP_NOT_SEALED					0x2A0F
#define d_ULD_AP_ALREAD_SEALED				0x2A10
#define d_ULD_AP_PWD_CAN_NOT_BE_CHANGE		0x2A11
#define d_ULD_TIMEOUT						0x2A40



// PM Error
#define d_PM_INVALID_PARA					0x2C01
#define d_PM_INVALID_AP_TABLE				0x2C02
#define d_PM_AP_NOT_FOUND					0x2C03
#define d_PM_INVALID_AP						0x2C04
#define d_PM_SPACE_NOT_ENOUGH				0x2C05
#define d_PM_REACH_MAX_NO_AP				0x2C06
#define d_PM_NO_AP_EXECUTED					0x2C07
#define d_PM_AP_ZERO_LENGTH					0x2C08
#define d_PM_INVALID_TYPE					0x2C09
#define d_PM_SHARD_LIBRARY_OPEN				0x2C0A
#define d_PM_UNEXPECTED_ERROR				0x2C0B

// Shared Error
#define d_SHARED_INVALID_PARA				0x2E01
#define d_SHARED_FLASH_FAULT				0x2E02

// Power Error
#define d_POWER_INVALID_PARA				0x3001
#define d_POWER_HAL_FAULT					0x3002
#define d_POWER_INSUFFICIENT_RESOURCE		0x3003
#define d_POWER_ALREADY_REGISTERED			0x3004
#define d_POWER_NOT_SUPPORT					0x3005

// Touch Signature.
#define d_TOUCH_SIGNATURE_NOT_SUPPORT			0x3201
#define d_TOUCH_SIGNATURE_INVALID_PARA			0x3202
#define d_TOUCH_SIGNATURE_PROCESSING			0x3203
#define d_TOUCH_SIGNATURE_NOT_PROCESSING		0x3204
#define d_TOUCH_SIGNATURE_INSUFFICIENT_RESOURCE	0x3205


// BMP Convert.
#define d_BMP_INVALID_PARA					0x3301
#define d_BMP_IFILE_NOT_FOUND				0x3302
#define d_BMP_OPERATION_ERROR				0x3303

// Modem Error
#define d_MODEM_INVALID_PARA				0x4001
#define d_MODEM_NOT_OPEN					0x4002
#define d_MODEM_NOT_ONLINE					0x4003
#define d_MODEM_TIMEOUT						0x4004
#define d_MODEM_INSUFFICIENT_BUF			0x4005
#define d_MODEM_CMD_INVALID_RESPONSE		0x4006
#define d_MODEM_CMD_NOT_SUCCESS				0x4007
#define d_MODEM_TX_BUSY						0x4008
#define d_MODEM_NOT_SUPPORTED				0x4009
#define d_MODEM_DIALING						0x400A
#define d_MODEM_LISTENING					0x400B
#define d_MODEM_ALREADY_ONLINE				0x400C
#define d_MODEM_NOT_ASYN_MODE				0x400D
#define d_MODEM_SDLC_NOT_READY				0x400E

// Ethernet Error
#define d_ETHERNET_INVALID_PARA				0x4201
#define d_ETHERNET_NOT_OPEN					0x4202
#define d_ETHERNET_NOT_ONLINE				0x4203
#define d_ETHERNET_TIMEOUT					0x4204
#define d_ETHERNET_INSUFFICIENT_CMD_BUF		0x4205
#define d_ETHERNET_CMD_INVALID_RESPONSE		0x4206
#define d_ETHERNET_CMD_NOT_SUCCESS			0x4207
#define d_ETHERNET_TX_BUSY					0x4208
#define d_ETHERNET_NOT_SUPPORTED			0x4209
#define d_ETHERNET_NOT_DATA_MODE			0x420A
#define d_ETHERNET_SOCKET_ALREADYOPENED		0x420B
#define d_ETHERNET_ALREADY_OPENED         	0x420C
#define d_ETHERNET_HARDWARE_ERROR         	0x420D
#define d_ETHERNET_GDB_RUNNING         		0x420E

#define	d_ETHERNET_DNS_INVALID_FORMAT		0x4214
#define	d_ETHERNET_DNS_SERVER_FAILURE		0x4215
#define	d_ETHERNET_DNS_REQUEST_NOT_EXIST	0x4216
#define	d_ETHERNET_DNS_OPCODE_NOT_SUPPORT	0x4217
#define	d_ETHERNET_DNS_SERVER_REFUSED		0x4218
#define	d_ETHERNET_FTP_NOT_OPEN				0x4219
#define	d_ETHERNET_FTP_GETDIR_FAILED		0x421A
#define	d_ETHERNET_FTP_CHANGEDIR_FAILED		0x421B
#define	d_ETHERNET_FTP_LIST_NOT_READY		0x421C
#define	d_ETHERNET_FTP_BUSY					0x421D
#define	d_ETHERNET_FTP_REQUEST_PASSWORD		0x421E
#define d_ETHERNET_FTP_LOGIN_FAILED			0x421F
#define d_ETHERNET_FTP_RESPONSE_TIMEOUT		0x4220
#define d_ETHERNET_FTP_DATACONN_FAILED		0x4222
#define d_ETHERNET_FTP_RECONNETION_FAILED	0x4223
#define d_ETHERNET_FTP_DOWNLOADFILE_FAILED	0x4224
#define d_ETHERNET_FTP_UPLOADFILE_FAILED	0x4225
#define d_ETHERNET_NOT_ENABLE				0x4226
#define d_ETHERNET_FTP_GETFILESIZE_FAILED	0x4228

// Wifi Error
#define d_WIFI_INVALID_PARA					0x4301
#define d_WIFI_CONFIG_ERROR					0x4302
#define d_WIFI_NOT_OPEN						0x4303
#define d_WIFI_INSUFFICIENT_CMD_BUF			0x4305
#define d_WIFI_CMD_NOT_SUCCESS				0x4307

// Wifi IO Error
#define	d_WIFI_IO_PROCESSING				0x6001
#define	d_WIFI_IO_TIMEOUT					0x6002
#define	d_WIFI_IO_CANCELED					0x6003
#define	d_WIFI_IO_SCANFAILED				0x6004
#define	d_WIFI_IO_APCONNECTFAILED			0x6005

// Bluetooth Error
#define d_BLUETOOTH_INVALID_PARA			0x4501
#define d_BLUETOOTH_CONFIG_ERROR			0x4502
#define d_BLUETOOTH_TIMEOUT             	0x4503
#define d_BLUETOOTH_SOCKET_ALREADYOPENED    0x4504
#define d_BLUETOOTH_INSUFFICIENT_CMD_BUF	0x4505
#define d_BLUETOOTH_CMD_NOT_SUCCESS			0x4507
#define d_BLUETOOTH_MODE_NOT_MATCH			0x4508
#define d_BLUETOOTH_ALREADY_OPEN			0x4509
#define d_BLUETOOTH_SYSTEM_ERROR 			0x450A
#define d_BLUETOOTH_ALREADY_CONNECTED		0x450B
#define d_BLUETOOTH_NOT_OPEN					0x450C
#define d_BLUETOOTH_NOT_SUPPORTED			0x450D

// return code of CTOS_BluetoothStatus
#define	d_BLUETOOTH_IO_PROCESSING			0x7001
#define	d_BLUETOOTH_IO_TIMEOUT				0x7002
#define	d_BLUETOOTH_IO_CANCELED				0x7003
#define	d_BLUETOOTH_IO_SCANFAILED			0x7004
#define	d_BLUETOOTH_IO_CONNECTFAILED		0x7005
#define	d_BLUETOOTH_IO_BUSY					0x7006

// GSM Error
#define d_GSM_SELECT_FAIL    				0x4601
#define d_GSM_OPEN_COMM_FAIL 				0x4602
#define d_GSM_SEND_FAIL      				0x4603
#define d_GSM_NO_RESP        				0x4604
#define d_GSM_RESP_FORMAT_ERR				0x4605
#define d_GSM_INITIAL_FAIL   				0x4606
#define d_GSM_CMD_FAIL       				0x4607
#define d_GSM_SIM_READY          			0x4608
#define d_GSM_SIM_NOT_READY      			0x4609
#define d_GSM_NO_AUTH_NEED       			0x460A
#define d_GSM_AUTH_PIN           			0x460B
#define d_GSM_AUTH_PUK           			0x460C
#define d_GSM_AUTH_PIN2          			0x460D
#define d_GSM_AUTH_PUK2          			0x460E
#define d_GSM_AUTH_OTHERS        			0x460F
#define d_GSM_SIM_LOCK           			0x4610
#define d_GSM_SIM_NOT_LOCK       			0x4611
#define d_GSM_BAD_PARAMETER      			0x4612
#define d_GSM_PHONEBOOK_FORMAT_ERR   		0x4613
#define d_GSM_BUFFER_OVERFLOW				0x4614
#define d_GSM_RECORD_NOT_FOUND  			0x4615
#define d_GSM_SMS_ONE_LINE       			0x461E
#define d_GSM_SMS_TWO_LINE       			0x461F
#define d_GSM_SIM_SELECT_FAIL      			0x4620
#define d_GSM_IO_PROCESSING					0x4621
#define d_GSM_NOT_SUPPORT					0x4622
#define d_GSM_UNKNOWN_MODULE   				0x4623
#define d_GSM_INIT_CANCEL					0x4624
#define d_GSM_IO_BUSY						0x4625
#define d_GSM_NO_CARRIER					0x4626

// System Wait Error
#define d_SYSWAIT_INVALID_PARA				0x5001
#define d_SYSWAIT_TIMEOUT					0x5002
#define d_SYSWAIT_KBD_ERROR					0x5003
#define d_SYSWAIT_SC_ERROR					0x5004
#define d_SYSWAIT_MSR_ERROR					0x5005
#define d_SYSWAIT_MODEM_NOT_OPEN			0x5006
#define d_SYSWAIT_MODEM_ERROR				0x5007
#define d_SYSWAIT_ETHERNT_NOT_OPEN			0x5008
#define d_SYSWAIT_ETHERNT_ERROR				0x5009
#define d_SYSWAIT_COM1_NOT_OPEN				0x500A
#define d_SYSWAIT_COM1_ERROR				0x500B
#define d_SYSWAIT_COM2_NOT_OPEN				0x500C
#define d_SYSWAIT_COM2_ERROR				0x500D

// Enter Download Mode Error
#define d_EDM_USER_CANCEL					0x5201
#define d_EDM_ABORT_DOWNLOAD				0x5202
#define d_EDM_GET_FILE_INFO_FAILED			0x5203
#define d_EDM_GET_BY_NAME_FAILED			0x5204
#define d_EDM_AP_START_ADDING_FAILED		0x5205
#define d_EDM_AP_CONTINUE_FAILED			0x5206
#define d_EDM_AP_START_UPDATING_FAILED		0x5207
#define d_EDM_AP_FINAL_FAILED				0x5208
#define d_EDM_SYSTEM_DATA_UPDATE_FAILED		0x5209
#define d_EDM_SHARE_MEMORY_UPDATE_FAILED	0x520A
#define d_EDM_AP_UPDATE_SELF_SUCCESS		0x520B
#define d_EDM_AP_UPDATE_SELF_FAILED			0x520C
#define d_EDM_INVALID_PARA					0x520D
#define d_EDM_ETHERNET_UPDATE_FAILED		0x520E
#define d_EDM_AP_UPDATE_FAILED				0x52FF

// Call AP Error
#define d_AP_NAME_NOT_EXIST					0x5401
#define d_AP_NAME_TOO_LONG					0x5402
#define d_AP_STACK_FULL						0x5403
#define d_AP_ALREADY_ASSIGNED				0x5404

// Battery Error
#define d_BATTERY_INVALID_PARA				0x5601
#define d_BATTERY_NOT_EXIST					0x5602
#define d_BATTERY_SN_NOT_INSTALL			0x5603
#define d_BATTERY_NO_EXT_POWER   			0x5604
#define d_BATTERY_BUSY						0x5605
#define d_BATTERY_INVALID					0x5606
#define d_BATTERY_NOT_SUPPORT				0x5607

// CTMS
#define d_CTMS_LOG_APID_ERROR 				0x5701
#define d_CTMS_SN_FORMAT_ERROR				0x5702
#define d_CTMS_TRIGGER_TIME_NOT_EXIT		0x5703
#define d_CTMS_NOFIND_CONFIG				0x5704
#define d_CTMS_CONFIG_ERROR					0x5705

#define d_CTMS_COMMUNICATION_NOT_READY		0x5706
#define d_CTMS_PROCESSING					0x5707
#define d_CTMS_GETTING_ERROR				0x5708
#define d_CTMS_NO_INFO_DATA					0x5709


// Mobile
#define d_MOBILE_SELECT_FAIL    				0x5801
#define d_MOBILE_OPEN_COMM_FAIL 				0x5802
#define d_MOBILE_SEND_FAIL      				0x5803
#define d_MOBILE_NO_RESP        				0x5804
#define d_MOBILE_RESP_FORMAT_ERR				0x5805
#define d_MOBILE_INITIAL_FAIL   				0x5806
#define d_MOBILE_CMD_FAIL       				0x5807
#define d_MOBILE_SIM_READY          			0x5808
#define d_MOBILE_SIM_NOT_READY      			0x5809
#define d_MOBILE_NO_AUTH_NEED       			0x580A
#define d_MOBILE_AUTH_PIN           			0x580B
#define d_MOBILE_AUTH_PUK           			0x580C
#define d_MOBILE_AUTH_PIN2          			0x580D
#define d_MOBILE_AUTH_PUK2          			0x580E
#define d_MOBILE_AUTH_OTHERS        			0x580F
#define d_MOBILE_SIM_LOCK           			0x5810
#define d_MOBILE_SIM_NOT_LOCK       			0x5811
#define d_MOBILE_BAD_PARAMETER      			0x5812
#define d_MOBILE_PHONEBOOK_FORMAT_ERR   		0x5813
#define d_MOBILE_BUFFER_OVERFLOW				0x5814
#define d_MOBILE_RECORD_NOT_FOUND  				0x5815
#define d_MOBILE_SMS_ONE_LINE       			0x581E
#define d_MOBILE_SMS_TWO_LINE       			0x581F
#define d_MOBILE_SIM_SELECT_FAIL      			0x5820
#define d_MOBILE_IO_PROCESSING					0x5821
#define d_MOBILE_NOT_SUPPORT					0x5822
#define d_MOBILE_UNKNOWN_MODULE   				0x5823
#define d_MOBILE_INIT_CANCEL					0x5824
#define d_MOBILE_UNKNOWN_NETWORK				0x5825

//NTP (Network Time Protocol) error response
#define d_NTP_INVALID_PARA                      0x5901
#define d_NTP_PARA_OVERRANGE                    0x5902
#define d_NTP_IPURL_INVALID_FORMAT              0x5803
#define d_NTP_HAL_FAULT                         0x5904
#define d_NTP_UPDATE_FAIL                       0x5905

 // Contactless
#define d_CL_UNDEFINE_ERR						0x83FF
#define d_CL_CRC_ERR							0x83FE
#define d_CL_AUTH_ERR							0x83FC
#define d_CL_PARITY_ERR							0x83FB
#define d_CL_CODE_ERR							0x83FA
#define d_CL_SERNR_ERR							0x83F8
#define d_CL_KEY_ERR							0x83F7
#define d_CL_NOTAUTH_ERR						0x83F6
#define d_CL_BITCOUNT_ERR						0x83F5
#define d_CL_BYTECOUNT_ERR						0x83F4
#define d_CL_WRITE_ERR							0x83F1
#define d_CL_OVFL_ERR							0x83ED
#define d_CL_FRAMING_ERR						0x83EB
#define d_CL_ACCESS_ERR							0x83EA
#define d_CL_UNKNOWN_COMMAND					0x83E9
#define d_CL_COLL_ERR							0x83E8
#define d_CL_INIT_ERR							0x83E7
#define d_CL_INTERFACE_ERR						0x83E6
#define d_CL_ACCESS_TIMEOUT						0x83E5
#define d_CL_NO_BITWISE_ANTICOLL    	        0x83E4
#define d_CL_CARD_CODING_ERR					0x83E1
#define d_CL_CASC_LEV_EX						0x83CC
#define d_CL_BAUDRATE_NOT_SUPPORTED				0x83CA
#define d_CL_WRONG_PARAMETER_VALUE				0x83C4
#define d_CL_NOT_IMPLEMENT						0x839C
#define d_CL_NAK								0x8384
#define d_CL_TCL_ERR							0x8383
#define d_CL_TCL_TIMEOUT						0x8382
#define d_CL_TCL_ABORT						0x8381

//NTP (Network Time Protocol) error response
#define d_NTP_INVALID_PARA						0x5901
#define d_NTP_PARA_OVERRANGE					0x5902
#define d_NTP_IPURL_INVALID_FORMAT				0x5803
#define d_NTP_HAL_FAULT							0x5904
#define d_NTP_UPDATE_FAIL						0x5905

// KMS2
#define d_KMS2_INVALID_PARA							0x2901
#define d_KMS2_FAILED								0x2902
#define d_KMS2_SYSTEM_ERROR							0x2903
#define d_KMS2_NOT_OWNER							0x2904
#define d_KMS2_KEY_NOT_EXIST						0x2905
#define d_KMS2_KEYTYPE_INCORRECT					0x2906
#define d_KMS2_KEY_NOT_ALLOWED						0x2907
#define d_KMS2_KEY_VERIFY_INCORRECT					0x2908
#define d_KMS2_NOT_SUPPORTED						0x2909
#define d_KMS2_CERTIFICATE_INCORRECT				0x290A
#define d_KMS2_HASH_INCORRECT						0x290B
#define d_KMS2_CERTIFICATE_PARA_INCORRECT			0x290C
#define d_KMS2_INSUFFICIENT_BUFFER					0x290D
#define d_KMS2_DUKPT_KEY_NOT_GENERATED				0x290E
#define d_KMS2_GET_PIN_ABORT						0x290F
#define d_KMS2_GET_PIN_TIMEOUT						0x2910
#define d_KMS2_GET_PIN_NULL_PIN						0x2911
#define d_KMS2_PKCS_FORMAT_ERROR					0x2912
#define d_KMS2_KEY_VALUE_NOT_UNIQUE					0x2913
#define d_KMS2_KEY_TYPE_NOT_MATCH					0x2914
#define d_KMS2_DUKPT_KEY_EXPIRED					0x2915
#define d_KMS2_PURPOSE_NOT_UNIQUE					0x2916
#define d_KMS2_FUNCTION_IS_FORBIDDEN				0x2917

#define d_KMS2_ERR_PATH_ILLEGAL						0x29FA
#define d_KMS2_ERR_UNSUPPORTED						0x29FB
#define d_KMS2_ERR_FTOK_FAIL						0x29FC
#define d_KMS2_ERR_SHMGET_FAIL						0x29FD
#define d_KMS2_ERR_SHMAT_FAIL						0x29FE
#define d_KMS2_ERR_IPC_FAIL							0x29FF

//Remote Key Inject
#define d_RKI_CAPKI_OUT_OF_RANGE        	0x2B01
#define d_RKI_TKI_OUT_OF_RANGE          	0x2B02
#define d_RKI_KEY_LENGTH_ILLEGAL        	0x2B03
#define d_RKI_FILENAME_LENGTH_EXCEED    	0x2B04
#define d_RKI_ROOT_KEY_NOT_FOUND        	0x2B05
#define d_RKI_TPKCRT_NOT_FOUND          	0x2B06
#define d_RKI_TERMINAL_KEY_NOT_FOUND    	0x2B07
#define d_RKI_ROOT_KEY_NOT_ALLOW_MODIFY  	0x2B08
#define d_RKI_FILE_OPERATION_FAIL       	0x2B09
#define d_RKI_SYSTEM_ERROR              	0x2B0A
#define d_RKI_GENERATE_RSA_KEY_FAIL     	0x2B0B
#define d_RKI_GENERATE_CERTFILE_FAIL    	0x2B0C

#endif

