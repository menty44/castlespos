/*============================================================================
 *
 *      typedef.h
 *      
 *==========================================================================*/
/*============================================================================
 * 
 * Author(s):    Peril Chen
 * Date:          
 * Description:	
 * 
 *==========================================================================*/
#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

#define IN
#define OUT
#define INOUT

#define CHAR	char
#define UCHAR	unsigned char
#define BYTE	unsigned char

#ifndef STR
	#define STR		unsigned char	
#endif


#define SHORT	short				// 2byte
#define USHORT	unsigned short		// 2byte
#define WORD	unsigned short		// 2byte
#define INT		int					// 4byte	
#define UINT	unsigned int		// 4byte
#define DWORD	unsigned int		// 4byte
#define BOOL	unsigned char		// 1byte
#define LONG	long				// 4byte
#define ULONG	unsigned long		// 4byte

#ifndef TRUE
#define TRUE	1
#endif
#ifndef FALSE
#define FALSE	0
#endif

#ifndef NULL
#define NULL	0
#endif

#define IN
#define OUT

#define K_STATUS		BYTE

#endif

