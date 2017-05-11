/* 
 * File:   pciutility.h
 * Author: Barry_Lai
 *
 * Created on 2015年10月21日, 下午 3:09
 */

#ifndef PCIUTILITY_H
#define	PCIUTILITY_H

#ifdef	__cplusplus
extern "C" {
#endif

#define d_PCIPAD_INEFFECTIVE_DATA                             0x0102
#define d_PCIPAD_AUTH_NOT_PERFORMED                           0x0103
#define d_PCIPAD_AUTH_FAIL                                    0x0104
#define d_PCIPAD_INEFFECTIVE_PARAMETER                        0x0105
#define d_PCIPAD_INEFFECTIVE_MODE                             0x0106
#define d_PCIPAD_INEFFECTIVE_CMD                              0x0107
    
//return code
#define d_PCIPAD_OK                                        0x0000
#define d_PCIPAD_NO_DATA                                   0x0001
//#define d_PCIPAD_KEY_INDEX_EXCEED                          0x0002
#define d_PCIPAD_USER_CANCEL                               0x0020
#define d_PCIPAD_PARAMETER_INVALID                         0x0040   
#define d_PCIPAD_FILE_BLOCK_HASH_INCORRECT                  0x0041
#define d_PCIPAD_FILE_HASH_INCORRECT                        0x0042
#define d_PCIPAD_FILE_LENGTH_INCORRECT                      0x0043    
    
#define d_PCIPAD_TIME_OUT                                  0x00FF
    
#define d_PCIPAD_PACK_DATA_FAIL                             0x0030
#define d_PCIPAD_DATA_FORMAT_INVALID                        0x0031
#define d_PCIPAD_DATA_LENGTH_INCORRECT                      0x0032
#define d_PCIPAD_EXCEPTION_ERROR                            0x0033
#define d_PCIPAD_PARAMETER_INVALID                          0x0040    
#define d_PCIPAD_EVENT_ONTXDATA_NOT_READY                   0x0041
#define d_PCIPAD_EVENT_ONRXDATA_NOT_READY                   0x0042
#define d_PCIPAD_EVENT_ONENCRYPTWITHSK_NOT_READY            0x0043
#define d_PCIPAD_EVENT_ONDECRYPTWITHSK_NOT_READY            0x0044
#define d_PCIPAD_QI_OPEN_COM_FAIL                           0x0900
#define d_PCIPAD_NOT_SUPPORT                                0x0910
#define d_PCIPAD_TIME_OUT                                   0x00FF
    
typedef struct
{
	USHORT (*OnTxData)(IN BYTE *pData, IN USHORT Len);
	USHORT (*OnRxData)(OUT BYTE *pData, INOUT USHORT *pLen);
	USHORT (*OnEncryptWithSK)(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen);
	USHORT (*OnDecryptWithSK)(IN BYTE KeyType, IN BYTE *pData, IN USHORT Len, OUT BYTE *pResult, OUT USHORT *pResultLen);
}PCIUTILITY_EVENT;

void PCIUtility_CommunicationInitialize(IN PCIUTILITY_EVENT *pstCommEvent);

USHORT PCIUtility_GetFileAttribute(IN BYTE *pFileName, OUT ULONG *pulFileSize, OUT BYTE baHash[32]);

USHORT PCIUtility_GetFile(IN BYTE *pDestFileName, IN BYTE *pSrcFileName, IN void(*OnStatus)(ULONG ulReceivedSize, ULONG ulTotalSize));


#ifdef	__cplusplus
}
#endif

#endif	/* PCIUTILITY_H */

