#ifndef __CTOS_SSL_H__
#define	__CTOS_SSL_H__

#include "typedef.h"

// Connection type
#define		d_SSL_CONNECTION_ETHERNET			0x01
#define		d_SSL_CONNECTION_MODEM				0x02
#define		d_SSL_CONNECTION_GPRS				0x03
#define		d_SSL_CONNECTION_ETHERNET_MS		0x04

// Object type
#define		d_SSL_OBJ_X509_CERT					1		// No password required
#define		d_SSL_OBJ_X509_CACERT				2		// No password required
#define		d_SSL_OBJ_RSA_KEY					3		// AES128/AES256 PEM encryption supported
#define		d_SSL_OBJ_PKCS8						4		// RC4-128 encrypted data supported
#define		d_SSL_OBJ_PKCS12					5		// RC4-128 encrypted data supported

/* X.509/X.520 distinguished name types */
#define		d_SSL_X509_CERT_COMMON_NAME               0
#define		d_SSL_X509_CERT_ORGANIZATION              1
#define		d_SSL_X509_CERT_ORGANIZATIONAL_NAME       2
#define		d_SSL_X509_CA_CERT_COMMON_NAME            3
#define		d_SSL_X509_CA_CERT_ORGANIZATION           4
#define		d_SSL_X509_CA_CERT_ORGANIZATIONAL_NAME    5

// Error
#define		d_SSL_CONN_UNDEFINED				100
#define		d_SSL_NEW_FAILED					101
#define		d_SSL_READ_FAIL						102
#define		d_SSL_READ_BUF_NOT_ENOUGH			103
#define		d_SSL_SEND_FAIL						104
#define		d_SSL_INTERNAL_STACK_ERROR			105
#define		d_SSL_USER_CANCEL					106

/* errors that can be generated */
#define		d_SSL_NOT_OK						1
#define		d_SSL_ERROR_DEAD					2
#define		d_SSL_ERROR_CONN_LOST				256
#define		d_SSL_ERROR_SOCK_SETUP_FAILURE		258
#define		d_SSL_ERROR_INVALID_HANDSHAKE		260
#define		d_SSL_ERROR_INVALID_PROT_MSG		261
#define		d_SSL_ERROR_INVALID_HMAC			262
#define		d_SSL_ERROR_INVALID_VERSION			263
#define		d_SSL_ERROR_INVALID_SESSION			265
#define		d_SSL_ERROR_NO_CIPHER				266
#define		d_SSL_ERROR_BAD_CERTIFICATE			268
#define		d_SSL_ERROR_INVALID_KEY				269
#define		d_SSL_ERROR_FINISHED_INVALID		271
#define		d_SSL_ERROR_NO_CERT_DEFINED			272
#define		d_SSL_ERROR_NO_CLIENT_RENOG			273
#define		d_SSL_ERROR_NOT_SUPPORTED			274
#define		d_SSL_ERROR_INVALID_PRAR			275
#define 	d_SSL_X509_OK						512
#define		d_SSL_X509_NOT_OK                   513
#define		d_SSL_X509_VFY_ERR_NO_TRUSTED_CERT	514
#define		d_SSL_X509_VFY_ERR_BAD_SIGNATURE	515
#define		d_SSL_X509_VFY_ERR_NOT_YET_VALID	516
#define		d_SSL_X509_VFY_ERR_EXPIRED			517
#define		d_SSL_X509_VFY_ERR_SELF_SIGNED		518
#define		d_SSL_X509_VFY_ERR_INVALID_CHAIN	519
#define		d_SSL_X509_VFY_ERR_UNSUPPORTED_DIGEST	520
#define		d_SSL_X509_INVALID_PRIV_KEY			521
#define		d_SSL_X509_BAD_RSA_KEY_LEN			522

/* these are all the alerts that are recognized */
#define		SSL_ALERT_CLOSE_NOTIFY				0
#define		SSL_ALERT_UNEXPECTED_MESSAGE		10
#define		SSL_ALERT_BAD_RECORD_MAC			20
#define		SSL_ALERT_HANDSHAKE_FAILURE			40
#define		SSL_ALERT_BAD_CERTIFICATE			42
#define		SSL_ALERT_ILLEGAL_PARAMETER			47
#define		SSL_ALERT_DECODE_ERROR				50
#define		SSL_ALERT_DECRYPT_ERROR				51
#define		SSL_ALERT_INVALID_VERSION			70

USHORT CTOS_SSLVersion(STR baVersion[16]);
USHORT CTOS_SSLNew(BYTE bConnType, BYTE bSocket);
USHORT CTOS_SSLConnect(void);
USHORT CTOS_SSLRead(BYTE *baBuf, USHORT *usLen);
USHORT CTOS_SSLWrite(BYTE *baBuf, USHORT usLen);
USHORT CTOS_SSLDisConnect(void);
USHORT CTOS_SSLClose(void);
USHORT CTOS_SSLVerifyCert(void);
USHORT CTOS_SSLLoadObject(int iObjType, BYTE *baData, USHORT usLen, BYTE *baPassword);
USHORT CTOS_SSLSetReadTimeout(ULONG ulTimeOut);
USHORT CTOS_SSLEnableCancelKey(BOOL boEnableDisable);
USHORT CTOS_SSLGetCertDN(IN BYTE bComponent, OUT STR* strName);

#endif //	__CTOS_SSL_H__
