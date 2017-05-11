/* 
 * File:   ctos_tls2.h
 * Author: Barry_Lai
 *
 * Created on 2014年7月24日, 下午 3:07
 */

#ifndef CTOS_TLS2_H
#define	CTOS_TLS2_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef d_OK
#define d_OK            0x0000
#endif
    
#define d_TLS2_INVALID_PARA         0x2F01
#define d_TLS2_FAILURE              0X2F02
#define d_TLS2_NULL_POINTER         0X2F03
#define d_TLS2_NO_MEM               0X2F04
#define d_TLS2_REACHES_LIMIT        0X2F05    
#define d_TLS2_BAD_FILETYPE         0X2F20    
#define d_TLS2_BAD_FILE             0X2F21
#define d_TLS2_MEMORY_E             0X2F22
#define d_TLS2_ASN_INPUT_E          0X2F23
#define d_TLS2_BAD_PATH_ERROR       0X2F24
#define d_TLS2_NO_PASSWORD          0X2F25
#define d_TLS2_CREATE_FAIL          0X2F26    
#define d_TLS2_READ_FAIL            0X2F27
#define d_TLS2_WRITE_FAIL           0X2F28
#define d_TLS2_SESSION_IS_CLOSE		0x2F29
#define d_TLS2_CYASSL_LOADING_FAIL	0x2F30
#define d_TLS2_GET_CYASSL_FAIL		0x2F31
#define d_TLS2_UNDEFINED_ERROR      0x2FFF
    
//=============================================================	
USHORT CTOS_TLS2_Init(void);

USHORT CTOS_TLS2_Cleanup(void);

//=============================================================

#define d_TLS2_FILETYPE_ASN1    2
#define d_TLS2_FILETYPE_PEM     1    
    
USHORT CTOS_TLS2_CTX_LoadCACertificationFromBuffer(IN UINT CTX_ID, IN const BYTE* pCA, IN LONG Length, IN UINT Format);

USHORT CTOS_TLS2_CTX_LoadCACertificationFromFile(IN UINT CTX_ID, IN const BYTE* pFile);

USHORT CTOS_TLS2_CTX_LoadPrivateKeyFromBuffer(IN UINT CTX_ID, IN const BYTE* pPrivateKey, IN LONG Length, IN UINT Format);

USHORT CTOS_TLS2_CTX_LoadPrivateKeyFromFile(IN UINT CTX_ID, IN const BYTE* pFile, IN UINT Format);

USHORT CTOS_TLS2_CTX_LoadCertificateFromBuffer(IN UINT CTX_ID, IN const BYTE* pCertificate, IN LONG Length, IN UINT Format);

USHORT CTOS_TLS2_CTX_LoadCertificateFromFile(IN UINT CTX_ID, IN const BYTE* pFile, IN UINT Format);

USHORT CTOS_TLS2_LoadPrivateKeyFromBuffer(IN UINT SSL_ID, IN const BYTE* pPrivateKey, IN LONG Length, IN UINT Format);

USHORT CTOS_TLS2_LoadCertificateFromBuffer(IN UINT SSL_ID, IN const BYTE* pCertificate, IN LONG Length, IN UINT Format);

//=============================================================
#define d_TLS2_METHOD_CLIENT_SSL_V3  		1
#define d_TLS2_METHOD_CLIENT_SSL_V23 		2
#define d_TLS2_METHOD_CLIENT_TLS_V1     	3
#define d_TLS2_METHOD_CLIENT_TLS_V1_1   	4
#define d_TLS2_METHOD_CLIENT_TLS_V1_2   	5

USHORT CTOS_TLS2_CTX_New(IN INT Method, OUT UINT* pCTX_ID);

//=============================================================

USHORT CTOS_TLS2_CTX_Free(IN UINT CTX_ID);

USHORT CTOS_TLS2_New(IN UINT CTX_ID, OUT UINT* pSSL_ID);

USHORT CTOS_TLS2_Free(IN UINT SSL_ID);

//=============================================================

#define d_TLS2_VERSION_TLSV1        1
#define d_TLS2_VERSION_TLSV1_1      2
#define d_TLS2_VERSION_TLSV1_2      3

USHORT CTOS_TLS2_SetProtocolVersion(IN UINT SSL_ID, IN UINT ProtocolVersion);

//=============================================================

USHORT CTOS_TLS2_EnableDomainNameCheck(IN UINT SSL_ID, IN const BYTE* pDomainName);

//=============================================================

#define SSL_RSA_WITH_RC4_128_SHA      					"RC4-SHA"
#define SSL_RSA_WITH_RC4_128_MD5      					"RC4-MD5"
#define SSL_RSA_WITH_3DES_EDE_CBC_SHA 					"DES-CBC3-SHA"
#define TLS_RSA_WITH_AES_256_CBC_SHA  					"AES256-SHA"
#define TLS_RSA_WITH_AES_128_CBC_SHA  					"AES128-SHA"
#define TLS_RSA_WITH_NULL_SHA         					"NULL-SHA"
#define TLS_RSA_WITH_NULL_SHA256         				"NULL-SHA256"
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA 				"DHE-RSA-AES128-SHA"
#define TLS_DHE_RSA_WITH_AES_256_CBC_SHA 				"DHE-RSA-AES256-SHA"
#define TLS_RSA_WITH_HC_128_MD5      					"HC128-MD5"
#define TLS_RSA_WITH_HC_128_SHA      					"HC128-SHA"
#define TLS_RSA_WITH_HC_128_B2B256	 					"HC128-B2B256"
#define TLS_RSA_WITH_AES_128_CBC_B2B256					"AES128-B2B256"
#define TLS_RSA_WITH_AES_256_CBC_B2B256					"AES256-B2B256"
#define TLS_RSA_WITH_RABBIT_SHA      					"RABBIT-SHA"
#define TLS_NTRU_RSA_WITH_RC4_128_SHA        			"NTRU-RC4-SHA"
#define TLS_NTRU_RSA_WITH_3DES_EDE_CBC_SHA   			"NTRU-DES-CBC3-SHA"
#define TLS_NTRU_RSA_WITH_AES_128_CBC_SHA    			"NTRU-AES128-SHA"
#define TLS_NTRU_RSA_WITH_AES_256_CBC_SHA    			"NTRU-AES256-SHA"  
#define TLS_RSA_WITH_AES_128_CCM_8			 			"AES128-CCM-8"
#define TLS_RSA_WITH_AES_256_CCM_8			 			"AES256-CCM-8"
#define TLS_ECDHE_ECDSA_WITH_AES_128_CCM_8	 			"ECDHE-ECDSA-AES128-CCM-8"
#define TLS_ECDHE_ECDSA_WITH_AES_256_CCM_8	 			"ECDHE-ECDSA-AES256-CCM-8"
	
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA              "ECDHE-RSA-AES256-SHA"
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA              "ECDHE-RSA-AES128-SHA"
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA            "ECDHE-ECDSA-AES256-SHA"
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA            "ECDHE-ECDSA-AES128-SHA"
#define TLS_ECDHE_RSA_WITH_RC4_128_SHA                  "ECDHE-RSA-RC4-SHA"
#define TLS_ECDHE_ECDSA_WITH_RC4_128_SHA                "ECDHE-ECDSA-RC4-SHA"
#define TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA             "ECDHE-RSA-DES-CBC3-SHA"
#define TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA           "ECDHE-ECDSA-DES-CBC3-SHA"
#define TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256           "ECDHE-RSA-AES128-SHA256"       
#define TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256         "ECDHE-ECDSA-AES128-SHA256"         
#define TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384           "ECDHE-RSA-AES256-SHA384"    
#define TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384         "ECDHE-ECDSA-AES256-SHA384"       
#define TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256         "ECDHE-ECDSA-AES128-GCM-SHA256"  
#define TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384         "ECDHE-ECDSA-AES256-GCM-SHA384"
#define TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256           "ECDHE-RSA-AES128-GCM-SHA256"               
#define TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384           "ECDHE-RSA-AES256-GCM-SHA384" 

#define TLS_RSA_WITH_AES_128_CBC_SHA256          		"AES128-SHA256"        
#define TLS_RSA_WITH_AES_256_CBC_SHA256          		"AES256-SHA256"        
#define TLS_DHE_RSA_WITH_AES_128_CBC_SHA256      		"DHE-RSA-AES128-SHA256"
#define TLS_DHE_RSA_WITH_AES_256_CBC_SHA256      		"DHE-RSA-AES256-SHA256"

#define TLS_RSA_WITH_AES_128_GCM_SHA256          		"AES128-GCM-SHA256"
#define TLS_RSA_WITH_AES_256_GCM_SHA384          		"AES256-GCM-SHA384"
#define TLS_DHE_RSA_WITH_AES_128_GCM_SHA256      		"DHE-RSA-AES128-GCM-SHA256"
#define TLS_DHE_RSA_WITH_AES_256_GCM_SHA384      		"DHE-RSA-AES256-GCM-SHA384"

#define TLS_ECDH_RSA_WITH_AES_256_CBC_SHA        		"ECDH-RSA-AES256-SHA"
#define TLS_ECDH_RSA_WITH_AES_128_CBC_SHA        		"ECDH-RSA-AES128-SHA" 
#define TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA      		"ECDH-ECDSA-AES256-SHA"
#define TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA      		"ECDH-ECDSA-AES128-SHA"
#define TLS_ECDH_RSA_WITH_RC4_128_SHA            		"ECDH-RSA-RC4-SHA"
#define TLS_ECDH_ECDSA_WITH_RC4_128_SHA          		"ECDH-ECDSA-RC4-SHA" 
#define TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA       		"ECDH-RSA-DES-CBC3-SHA"
#define TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA     		"ECDH-ECDSA-DES-CBC3-SHA" 
#define TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256     		"ECDH-RSA-AES128-SHA256"
#define TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256   		"ECDH-ECDSA-AES128-SHA256"
#define TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384     		"ECDH-RSA-AES256-SHA384"
#define TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384   		"ECDH-ECDSA-AES256-SHA384"
#define TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256   		"ECDH-ECDSA-AES128-GCM-SHA256"    
#define TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384   		"ECDH-ECDSA-AES256-GCM-SHA384"                                                                                            
#define TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256     		"ECDH-RSA-AES128-GCM-SHA256"    
#define TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384     		"ECDH-RSA-AES256-GCM-SHA384"    

#define TLS_RSA_WITH_CAMELLIA_128_CBC_SHA				"CAMELLIA128-SHA"	
#define TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA			"DHE-RSA-CAMELLIA128-SHA"
#define TLS_RSA_WITH_CAMELLIA_256_CBC_SHA				"CAMELLIA256-SHA"
#define TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA			"DHE-RSA-CAMELLIA256-SHA"
#define TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256			"CAMELLIA128-SHA256"
#define TLS_DHE_RSA_WITH_CAMELLIA_128_CBC_SHA256		"DHE-RSA-CAMELLIA128-SHA256"
#define TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256			"CAMELLIA256-SHA256"
#define TLS_DHE_RSA_WITH_CAMELLIA_256_CBC_SHA256		"DHE-RSA-CAMELLIA256-SHA256"

USHORT CTOS_TLS2_SetCipherList(IN UINT SSL_ID, IN const BYTE* pListString);

USHORT CTOS_TLS2_CTX_SetCipherList(IN UINT CTX_ID, IN const BYTE* pListString);

//=============================================================

USHORT CTOS_TLS2_SetSocket(IN UINT SSL_ID, IN INT Socket);

USHORT CTOS_TLS2_SetTimeout(IN INT SSL_ID, IN UINT Timeout);

USHORT CTOS_TLS2_CTX_SetTimeout(IN INT CTX_ID, IN UINT Timeout);

//=============================================================
#define d_TLS2_VERIFY_NONE              0
#define d_TLS2_VERIFY_PEER              1

USHORT CTOS_TLS2_SetVerificationMode(IN UINT SSL_ID, IN UINT VerificationMode);

USHORT CTOS_TLS2_CTX_SetVerificationMode(IN UINT CTX_ID, IN UINT VerificationMode);

//=============================================================

USHORT CTOS_TLS2_Connect(IN UINT SSL_ID);

USHORT CTOS_TLS2_GetRxLength(IN UINT SSL_ID, OUT INT *pRxLength);

USHORT CTOS_TLS2_Read(IN UINT SSL_ID, OUT BYTE* pData, INOUT INT *pLength);

USHORT CTOS_TLS2_Write(IN UINT SSL_ID, IN BYTE *pData, INOUT INT *pLength);

USHORT CTOS_TLS2_Disconnect(IN UINT SSL_ID, IN UINT Flag);

USHORT CTOS_TLS2_GetSession(IN UINT SSL_ID);

void CTOS_TLS2_GetCyaSSLVersion(OUT BYTE baCyaSSLVersion[5]);

void CTOS_TLS2_GetErrorMessage(IN UINT SSL_ID, OUT BYTE* pErrMsg);


#ifdef	__cplusplus
}
#endif

#endif	/* CTOS_TLS2_H */

