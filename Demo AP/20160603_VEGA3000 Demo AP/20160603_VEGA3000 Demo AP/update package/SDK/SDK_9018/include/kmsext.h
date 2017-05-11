/********************************************************************
Copyright (c) Castles Technology Co., Ltd. 2003-2005

Module Name:
	ctosapi.h

Abstract:

Created:
	2005/11/25

Author:
	Peril Chen

Revision History:

*********************************************************************/
#ifndef __KMS_EXT_H__
#define __KMS_EXT_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "typedef.h"
#include "ctoserr.h"

//=============================================================================================================================
//
// KMS2 Functions non-PCI Function & Structure & Method
//
//=============================================================================================================================

//---------------------------------------------------------------------------------------------
// KeySets

// Common KeySets
#define KMS2_COMMON_KEY_SETS_START				0xC000
#define KMS2_COMMON_KEY_SETS_END				0xCFFF		

//---------------------------------------------------------------------------------------------

// Key Type
#define KMS2_KEYTYPE_AES						0x03
#define KMS2_KEYTYPE_RSA						0x04
#define KMS2_KEYTYPE_DES_DUKPT					0x05 	// ANS X9.24 - 1998

// Key Attribute
#define KMS2_KEYATTRIBUTE_PIN											0x00000001
#define KMS2_KEYATTRIBUTE_ENCRYPT										0x00000002
#define KMS2_KEYATTRIBUTE_MAC											0x00000004
#define KMS2_KEYATTRIBUTE_KPK											0x00000008
#define KMS2_KEYATTRIBUTE_DECRYPT										0x00000010
#define KMS2_KEYATTRIBUTE_KBPK										0x00000020
#define KMS2_KEYATTRIBUTE_SK_ENCRYPT									0x00000040
#define KMS2_KEYATTRIBUTE_INTERMEDIATE									0x00000080
#define KMS2_KEYATTRIBUTE_FREEZE_RSA_WRITE_KEY_BY_CERTIFICATE			0x00000100
#define KMS2_KEYATTRIBUTE_FREEZE_RSA_ENCRYPT							0x00000200
#define KMS2_KEYATTRIBUTE_CONSIDER_INVALID_BIT_AS_VALID_FOR_KEY_VALUE_UNIQUE	0x10000000
#define KMS2_KEYATTRIBUTE_VALUE_UNIQUE									0x20000000
#define KMS2_KEYATTRIBUTE_PROTECTED										0x40000000

// Key Protection Mode
#define KMS2_KEYPROTECTIONMODE_PLAINTEXT		0x00 // 
#define KMS2_KEYPROTECTIONMODE_KPK_ECB			0x01 // 3DES, AES, 3DES_DUKPT for cipher
#define KMS2_KEYPROTECTIONMODE_KPK_CBC			0x05 // 3DES, AES, 3DES_DUKPT for cipher

// Key Verification Method
#define KMS2_KEYVERIFICATIONMETHOD_DEFAULT		0x00

// Cipher method
#define KMS2_DATAENCRYPTCIHERMETHOD_ECB_REVERSED_KEY_ORDER         0x80

//---------------------------------------------------------------------------------------------

typedef struct
{
	// Should be 0x00 or 0x01	
	IN BYTE Version;
	
	struct
	{				
		// Note that 0x0000 and 0xFF00 to 0xFFFF are reserved for system.
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
		
		IN BYTE KeyType;		
						
		IN BYTE KeyVersion;	
		
		// For KeyType RSA, only accepts KMS2_KEYATTRIBUTE_PROTECTED
		IN DWORD KeyAttribute;
	}Info;
	
	// This is not used for KeyType RSA
	struct
	{
		IN BYTE Mode;
		
		// This is used for KPK_ECB and TR31 Mode
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		
		struct
		{
			// This is used for TR31 Mode
			// This is used as ICV for SELF_UPDATE_CBC mode
			IN USHORT Length;
			IN BYTE* pData;
		}AdditionalData;
						
	}Protection;			
	
	struct
	{
		IN USHORT KeyLength;
		// For KeyType RSA, this is used for Modulus.
		IN BYTE* pKeyData;
	}Value;
	
	// This is not used if Protection.Mode is KMS2_KEYPROTECTIONMODE_PLAINTEXT
	// This is not used for KeyType RSA
	struct
	{
		IN BYTE Method;
		IN USHORT KeyCheckValueLength;
		IN BYTE* pKeyCheckValue;
	}Verification;
	
	// Optional. Used only for KeyType RSA
	struct
	{
		IN USHORT Length;
		IN BYTE* pValue; 
	}Exponent;
	
	// Optional. Used only for KeyType 3DES_DUKPT
	struct
	{		
		IN BYTE KSNLength;
		IN BYTE *pKSN;
	}DUKPT_DATA;
	
}CTOS_KMS2KEYWRITE_PARA;

typedef struct
{
	struct
	{
		IN BYTE Length;
		IN BYTE Name[20];
	}KeyOwner;

	CTOS_KMS2KEYWRITE_PARA KeyWritePara;

}CTOS_KMS2KEYWRITEEX_PARA;

typedef struct
{
	struct
	{
		IN BYTE Length;
		IN BYTE Name[20];
	}KeyOwner;

	CTOS_KMS2KEYWRITEBYTR31_PARA KeyWriteByTR31Para;

}CTOS_KMS2KEYWRITEBYTR31EX_PARA;

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;

	struct
	{
		// Indicate the RSA key for decrypting the certificate.
		// The default RSA private key is in KMS2_DEFAULT_RSA_KEY_SET
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
	}Protection;

	struct
	{
		IN USHORT Length;
		IN BYTE* pData;
	}Certificate;

}CTOS_KMS2KEYWRITEBYCERTIFICATE_PARA;

#define d_CERTIFICATE_FORMAT_PKCS1_2	0x00

typedef struct
{
	// Should be 0x02
	IN BYTE Version;
	
		struct
	{
		// Indicate the RSA key for decrypting the certificate.
		// The default RSA private key is in KMS2_DEFAULT_RSA_KEY_SET
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
	}Protection;
	
	struct
	{
		//0x00 : PKCS#1.2
		IN BYTE Format;		

		IN USHORT Length;
		IN BYTE* pData;
	}Certificate;
	
	struct
	{
		struct
		{
			IN BYTE Length;
			IN BYTE Name[20];
		}KeyOwner;
		
		struct
		{
			// Note that 0x0000 and 0xFF00 to 0xFFFF are reserved for system.
			IN USHORT KeySet;
	
			IN USHORT KeyIndex;
	
			IN BYTE KeyType;
	
			IN BYTE KeyVersion;
	
			// For KeyType RSA, only accepts KMS2_KEYATTRIBUTE_PROTECTED
			IN DWORD KeyAttribute;
		}KeyInfo;
		
		// This is not used for KeyType RSA
		struct
		{
			IN BYTE Method;
			IN USHORT KeyCheckValueLength;
			IN BYTE* pKeyCheckValue;
		}Verification;
		
		// Optional. Used only for KeyType 3DES_DUKPT
		struct
		{
			IN BYTE KSNLength;
			IN BYTE *pKSN;
		}DUKPT_DATA;
		
	}KMS2_Info;
}CTOS_KMS2KEYWRITEBYCERTIFICATE_PARA_VERSION_2;

typedef struct
{
	// Should be 0x03
	IN BYTE Version;
	
	struct
	{
		IN BYTE BlockType;
		IN BYTE PINDigitMaxLength;
		IN BYTE PINDigitMinLength;		
	}PIN_Info;
	
	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;
				
		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;
	
	struct
	{
		// This is used for PAN if BlockType is KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0.
		// Ths is used for terminal pseudo random if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;
						
	}AdditionalData;
	
	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{		
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;
	
	struct
	{				
		INOUT USHORT EncryptedBlockLength; 
		OUT	BYTE* pEncryptedBlock;
		OUT BYTE PINDigitActualLength;
	}PINOutput;
	
	struct
	{
		IN DWORD Timeout;
		IN BYTE NULLPIN;
		IN int (*piTestCancel)(void);
	}Control;
	
	struct
	{
		void (*OnGetPINDigit)(BYTE NoDigits);
		void (*OnGetPINCancel)(void);
		void (*OnGetPINBackspace)(BYTE NoDigits);			
	}EventFunction;
	
}CTOS_KMS2PINGET_PARA_VERSION_3;

typedef struct
{
	// Should be 0x04
	IN BYTE Version;
	
	struct
	{
		IN BYTE BlockType;
		IN BYTE PINDigitMaxLength;
		IN BYTE PINDigitMinLength;		
	}PIN_Info;
	
	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;
				
		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;
	
	struct
	{
		// This is used for PAN if BlockType is KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0.
		// Ths is used for terminal pseudo random if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;
						
	}AdditionalData;
	
	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{		
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;
	
	struct
	{				
		INOUT USHORT EncryptedBlockLength; 
		OUT	BYTE* pEncryptedBlock;
		OUT BYTE PINDigitActualLength;
	}PINOutput;
	
	struct
	{
		IN DWORD Timeout;
		IN BYTE NULLPIN;
		IN int (*piTestCancel)(void);
	}Control;
	
	struct
	{
		void (*OnGetPINDigit)(BYTE NoDigits);
		void (*OnGetPINCancel)(void);
		void (*OnGetPINBackspace)(BYTE NoDigits);			
		void (*OnGetPINOtherKeys)(BYTE NoDigits);
	}EventFunction;
	
}CTOS_KMS2PINGET_PARA_VERSION_4;

typedef struct
{
	// Should be 0x05
	IN BYTE Version;
	
	struct
	{
		IN BYTE BlockType;
		IN BYTE PINDigitMaxLength;
		IN BYTE PINDigitMinLength;		
	}PIN_Info;
	
	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;
				
		// This is used for KeyType is KMS2_KEYTYPE_3DES/KMS2_KEYTYPE_AES
		// If SK_Length is 0, SK will not be calculated and used.
		IN BYTE	SK_Length;
		IN BYTE* pSK;
	}Protection;
	
	struct
	{
		// This is used for PAN if BlockType is KMS2_PINBLOCKTYPE_ANSI_X9_8_ISO_0.
		// Ths is used for terminal pseudo random if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_REVERSIBLE_PIN_4B_MODE.
		// This is used for PK if BlockType	is KMS2_PINBLOCKTYPE_ISBAN_IRREVERSIBLE_PIN_4B_MODE.
		IN BYTE InLength;
		IN BYTE* pInData;
						
	}AdditionalData;
	
	// This is used for KeyType is KMS2_KEYTYPE_3DES_DUKPT
	struct
	{		
		IN BOOL IsUseCurrentKey;
	}DUKPT_PARA;
	
	struct
	{				
		INOUT USHORT EncryptedBlockLength; 
		OUT	BYTE* pEncryptedBlock;
		OUT BYTE PINDigitActualLength;
	}PINOutput;
	
	struct
	{
		IN DWORD Timeout;
		IN BYTE NULLPIN;
		IN int (*piTestCancel)(void);
		IN DWORD FirstKeyEntryTimeout;
	}Control;
	
	struct
	{
		void (*OnGetPINDigit)(BYTE NoDigits);
		void (*OnGetPINCancel)(void);
		void (*OnGetPINBackspace)(BYTE NoDigits);			
		void (*OnGetPINOtherKeys)(BYTE bFunctionKey);
	}EventFunction;
	
}CTOS_KMS2PINGET_PARA_VERSION_5;

//---------------------------------------------------------------------------------------------
#define KMS2_DATAENCRYPTCIPHERMETHOD_EXTPIN_ECB					0x02  // used for external PINPAD
#define KMS2_DATAENCRYPTCIPHERMETHOD_CBC_DECRYPTION				0x03  // used for TDES-DUKPT 

#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_1				0x11
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_2				0x12
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_3				0x13
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_4				0x14
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_5				0x15
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_30			0x30
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_CBC_POUND_31			0x31

#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_ECB_POUND_1				0x16
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_ECB_POUND_2				0x17
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_ECB_POUND_3				0x18
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_ECB_POUND_4				0x19
#define KMS2_DATAENCRYPTCIPHERMETHOD_3DUKPT_ECB_POUND_5				0x1A


//---------------------------------------------------------------------------------------------
#define KMS2_MACMETHOD_X9_19_START					0x02	// Start for Retail MAC. Retail MAC is done in three or more calls
#define KMS2_MACMETHOD_X9_19_UPDATE					0x03	// Continue for Retail MAC. Retail MAC is done in three or more calls
#define KMS2_MACMETHOD_X9_19_FINAL					0x04	// End for Retail MAC. Retail MAC is done in three or more call

//---------------------------------------------------------------------------------------------
#define KMS2_RSAENCRYPTCIPHERMETHOD_DEFAULT				0x00

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;
	
	struct
	{
		IN USHORT CipherKeySet;
		IN USHORT CipherKeyIndex;
		IN BYTE	CipherMethod;
					
	}Protection;
	
	struct
	{
		IN USHORT Length;
		IN BYTE* pData;				
	}Input;
	
	struct
	{
		OUT USHORT Length;
		OUT BYTE* pData;
	}Output;
	
}CTOS_KMS2RSAENCRYPT_PARA;

//---------------------------------------------------------------------------------------------
#define KMS2_HASH_ALGORITHM_SHA1			0x00
#define KMS2_HASH_ALGORITHM_SHA2			0x01

//---------------------------------------------------------------------------------------------

#define KMS2_INTERMEDIATE_KEY_MAX_NUMBER			16

// Index for Intermediate Key
#define KMS2_INTERMEDIATE_KEY_SET					0xFF00

#define KMS2_INTERMEDIATE_KEY_0_INDEX				0x00
#define KMS2_INTERMEDIATE_KEY_1_INDEX				0x01
#define KMS2_INTERMEDIATE_KEY_2_INDEX				0x02
#define KMS2_INTERMEDIATE_KEY_3_INDEX				0x03
#define KMS2_INTERMEDIATE_KEY_4_INDEX				0x04
#define KMS2_INTERMEDIATE_KEY_5_INDEX				0x05
#define KMS2_INTERMEDIATE_KEY_6_INDEX				0x06
#define KMS2_INTERMEDIATE_KEY_7_INDEX				0x07
#define KMS2_INTERMEDIATE_KEY_8_INDEX				0x08
#define KMS2_INTERMEDIATE_KEY_9_INDEX				0x09
#define KMS2_INTERMEDIATE_KEY_10_INDEX				0x0A
#define KMS2_INTERMEDIATE_KEY_11_INDEX				0x0B
#define KMS2_INTERMEDIATE_KEY_12_INDEX				0x0C
#define KMS2_INTERMEDIATE_KEY_13_INDEX				0x0D
#define KMS2_INTERMEDIATE_KEY_14_INDEX				0x0E
#define KMS2_INTERMEDIATE_KEY_15_INDEX				0x0F



// Operation for Intermediate Key
#define KMS2_INTERMEDIATE_KEYGEN_OP_XOR				0
#define KMS2_INTERMEDIATE_KEYGEN_OP_DES_ENCRYPT		1
#define KMS2_INTERMEDIATE_KEYGEN_OP_DES_DECRYPT		2
#define KMS2_INTERMEDIATE_KEYGEN_OP_TAKE_LEFT		3
#define KMS2_INTERMEDIATE_KEYGEN_OP_TAKE_RIGHT		4
#define KMS2_INTERMEDIATE_KEYGEN_OP_COMBINE			5
#define KMS2_INTERMEDIATE_KEYGEN_OP_AES_ENCRYPT		6
#define KMS2_INTERMEDIATE_KEYGEN_OP_AES_DECRYPT		7
#define KMS2_INTERMEDIATE_KEYGEN_OP_GEN_RANDOM_KEY	8


#define KMS2_INTERMEDIATE_KEYGEN_MAX_OP_DATA_LENGTH		32

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;
		
	struct
	{		
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
				
	}Src1KeyID;
	
	struct
	{		
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
				
	}Src2KeyID;
	
	// Operation Length, 
	//     for XOR operation, it indicates how many bytes in Src Key and OperationData will be calculated in this opersation.
	//     for DES_ENCRYPT/DES_DECRYPT, it indicates how many bytes in Src Key and OperationData will be calculated in this opersation.
	//     for TAKE_LEFT/TAKE_RIGHT operation, it indicates how many bytes of Src Key will be taked.
	struct
	{
		IN USHORT ID;
		
		IN USHORT Length;		
		IN BYTE* pData;
		
	}Operation;
	
	// Specify the KeyAttribute to the destination intermediate key.
	// The KeyAttribute is bit mask as use in normal KMS key.
	// Besides, the destination intermediate key will be set with KMS2_KEYATTRIBUTE_INTERMEDIATE automatically.
	struct
	{		
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
		
		IN BYTE KeyType;	
		
		IN DWORD KeyAttribute;
				
	}DestIntermediateKeyInfo;
	
}CTOS_KMS2INTERMEDIATEKEYGENERATE_PARA;

typedef struct
{
	// Should be 0x00 or 0x01
	IN BYTE Version;
	
	struct
	{		
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
				
	}IntermediateKeyID;
	
	struct
	{		
		// Note that 0x0000 and 0xFF00 to 0xFFFF are reserved for system.
		IN USHORT KeySet;
		
		IN USHORT KeyIndex;
		
		IN BYTE KeyType;
		
		IN BYTE KeyVersion;	
		
		IN DWORD KeyAttribute;
	}DestKeyInfo;
		
}CTOS_KMS2INTERMEDIATEKEYWRITE_PARA;


// Management
// Check all the keys in KMS
USHORT CTOS_KMS2SelfTest(void);
// Check if first time reboot
void CTOS_KMS2CheckFirstTime(BYTE *baPVR);
// Erase the secure memory. This is equal to delete all the keys in KMS.
USHORT CTOS_KMS2Erase(void);
// Add/Remove the key attribute PROTECTED
USHORT CTOS_KMS2KeySetProtected(IN USHORT KeySet, IN USHORT KeyIndex, BOOL IsProtected);

// Key Injection
// Write Keys to be Private
USHORT CTOS_KMS2KeyWrite(CTOS_KMS2KEYWRITE_PARA* pKeyWritePara);
// Write Keys to be under the Specific Owner
USHORT CTOS_KMS2KeyWriteEx(CTOS_KMS2KEYWRITEEX_PARA* pKeyWriteExPara);
USHORT CTOS_KMS2KeyWriteByCertificate(CTOS_KMS2KEYWRITEBYCERTIFICATE_PARA* pKeyWriteByCertificate);
USHORT CTOS_KMS2KeyWriteByTR31Ex(INOUT CTOS_KMS2KEYWRITEBYTR31EX_PARA* pKeyWritebyTR31ExPara);

// Key Crypto Functions
// Can used to get online or offline
USHORT CTOS_KMS2RSAEncrypt(CTOS_KMS2RSAENCRYPT_PARA *pRSAEncryptPara);

// Intermediate key function 
USHORT CTOS_KMS2IntermediateKeyGenerate(CTOS_KMS2INTERMEDIATEKEYGENERATE_PARA* pIntermediateKeyGeneratePara);
USHORT CTOS_KMS2IntermediateKeyWrite(CTOS_KMS2INTERMEDIATEKEYWRITE_PARA* pIntermediateKeyWritePara);
USHORT CTOS_KMS2IntermediateKeyFlush(IN USHORT KeySet, IN USHORT KeyIndex);
USHORT CTOS_KMS2IntermediateKeyErase(void);


#ifdef __cplusplus
}
#endif

#endif
