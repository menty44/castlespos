#ifndef __PEM_ENC_H__
#define	__PEM_ENC_H__

#ifdef	__cplusplus
extern "C" {
#endif

#define d_PEM_FILE_FORMAT_ERROR             0x0300
#define d_PEM_FILE_BEEN_ENCRYPTED           0x0301
#define d_PEM_KMS_KEY_FULL                  0x0302    
#define d_PEM_ENC_PARAMETER_INVALID         0x0303    
#define d_PEM_PRIVATE_KEY_FILE_OVERSIZE     0x0304    

//EncSysType
#define d_PEM_OTP_SYSTEM    0
#define d_PEM_KMS_SYSTEM    1 
    
typedef struct
{
        // Should be 0x00 or 0x01
        IN BYTE Version;
        // OTP: 00, KMS: 01
        IN BYTE EncSysType;
 
        struct
        {
                IN BYTE *pSrcFileName; 
                IN BYTE *pDestFileName;
        }Input;  
 
}CTOS_PEMENCRYPTEX_PARA;

USHORT CTOS_LibPEMENCGetVersion(BYTE* verion_str);

USHORT CTOS_PEMEncryptEx(CTOS_PEMENCRYPTEX_PARA* pPEMEncryptExPara);    
    
USHORT CTOS_PEMEncrypt(IN BYTE *baIn_file_Name, IN BYTE *baOut_file_name);


#ifdef	__cplusplus
}
#endif

#endif	

