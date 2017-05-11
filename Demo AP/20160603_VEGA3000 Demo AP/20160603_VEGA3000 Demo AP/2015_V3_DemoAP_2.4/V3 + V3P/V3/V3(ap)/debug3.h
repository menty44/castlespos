#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif


	//Debug Setting------------------------------------------------------------------------------------
	#define _DEBUG_LOG_					1
	#define _OUTCOME_LOG_				0
	#define _APDUDEKDET_LOG_			0

	#if _DEBUG_LOG_ == 1
		
		#define _DEBUG_VIA_PORT_			1
		#define _DEBUG_VIA_BUF_				0
	
		#if _DEBUG_VIA_PORT_ == 1
			#define _DEBUG_DEFAULT_OPEN				0
		#else
			#define _DEBUG_DEFAULT_OPEN				0
		#endif
			#define d_DEFAULT_DEBUG_COM				d_DEBUG_PORT_USB

		#define d_COM_OPEN_AT_OTHER_MODULUS			0

		#define d_DEBUG_PORT_USB		0xFF
		#define d_DEBUG_PORT_COM1		d_COM1
		#define d_DEBUG_PORT_COM2		d_COM2
		#define d_DEBUG_PORT_COM3		d_COM3
		#define d_DEBUG_PORT_BUFOUT		0xF0

		#if _DEBUG_VIA_PORT_ == 1

			//#define _DEBUG_METHOD_DEFINED_		1
			#define _DEBUG_METHOD_DEFINED_		3

			#if _DEBUG_METHOD_DEFINED_ == 1
				#define __DebugInit()						DebugInit()
				#define __DebugEnable(bPort)				DebugEnable(bPort)
				#define __DebugDisable()					DebugDisable()
				#define __DebugAddHEX(title, hex, len)		DebugAddHEX(title, hex, len)
				#define __DebugAddINT(title, value)			DebugAddINT(title, value)
				#define __DebugAddSTR(title)				DebugAddSTR(title)
				#define __DebugAddTSTR(title, str)			DebugAddTSTR(title, str)
				#define __DebugAddLineFeed(bLine)			DebugAddLineFeed(bLine)

				#define RS232_INIT()						DebugInit()						
				#define RS232_PRINT(str, len)                                   
				#define RS232_PRINTSTR(str)					DebugAddSTR(str)
				#define RS232_PRINTSTR_SAMELINE(str)
				#define RS232_PRINTBUF(buf, len)			                             
				#define RS232_PRINTBUF2(buf, len)                              
				#define RS232_PRINTSTRVAL(str, value, len)	DebugAddINT(str, value)            
				#define RS232_PRINTSTRHEX(str, value, len)	                  
				#define RS232_PRINTSTRBUF(str, buf, len)	DebugAddHEX(str, buf, len)
				#define RS232_PRINTFLONG(str, num)			DebugAddINT(str, num)

				#define RS232_DISABLE()						
				#define RS232_ENABLE()						
				#define RS232_WAITALLSENT()                                    
				#define RS232_REINIT()	
				#define WaitForAnyKey() 
				#define WaitTime(msTime) 
			#elif _DEBUG_METHOD_DEFINED_ == 3
				#define __DebugInit()						DebugInit()
				#define __DebugEnable(bPort)				DebugEnable(bPort)	
				#define __DebugDisable()					DebugDisable()		
				#define __DebugAddHEX(title, hex, len)		DebugAddHEX(title, hex, len)
				#define __DebugAddINT(title, value)			DebugAddINT(title, value)
				#define __DebugAddSTR(title)				DebugAddSTR(title)
				#define __DebugAddTSTR(title, str)			DebugAddTSTR(title, str)
				#define __DebugAddLineFeed(bLine)			DebugAddLineFeed(bLine)

				#define __DebugInit3()						
				#define __DebugEnable3(bPort)				DebugEnable(bPort)
				#define __DebugDisable3()					DebugDisable()
				#define __DebugAddHEX3(title, hex, len)		
				#define __DebugAddINT3(title, value)		
				#define __DebugAddSTR3(title)				
				#define __DebugAddTSTR3(title, str)			
				#define __DebugAddLineFeed3(bLine)			
			#endif

		#elif _DEBUG_VIA_BUF_ == 1

			#define _DEBUG_METHOD_DEFINED_		2
		
			void CLMW_DebugBufReset(void);
			void CLMW_DebugBufAddINT(BYTE *title, BYTE *str, ULONG ulvalue);
			void CLMW_DebugBufAddHEX(BYTE *title, BYTE *str, BYTE *hex, USHORT len);
			void CLMW_DebugBufAddSTR(BYTE *title, BYTE *str);
			void CLMW_DebugBufAddTSTR(BYTE *title, BYTE *tstr, BYTE *str);

		#define d_DEBUG_TITLE_	"MPP:"
		
			#define __DebugInit()						CLMW_DebugBufReset()
			#define __DebugEnable(bPort)				
			#define __DebugDisable()					
			#define __DebugAddHEX(str, hex, len)		CLMW_DebugBufAddHEX(d_DEBUG_TITLE_, str, hex, len)
			#define __DebugAddINT(str, value)			CLMW_DebugBufAddINT(d_DEBUG_TITLE_, str, value)
			#define __DebugAddSTR(str)					CLMW_DebugBufAddSTR(d_DEBUG_TITLE_, str)
			#define __DebugAddTSTR(title, str)			CLMW_DebugBufAddTSTR(d_DEBUG_TITLE_, title, str)
			#define __DebugAddLineFeed(bLine)
		
			#define RS232_INIT()						//CLMW_DebugBufReset()
			#define RS232_PRINT(str, len)                                   
			#define RS232_PRINTSTR(str)					//CLMW_DebugBufAddSTR(d_DEBUG_TITLE_, str)
			#define RS232_PRINTSTR_SAMELINE(str)
			#define RS232_PRINTBUF(buf, len)			                             
			#define RS232_PRINTBUF2(buf, len)                              
			#define RS232_PRINTSTRVAL(str, value, len)	//CLMW_DebugBufAddINT(d_DEBUG_TITLE_, str, value)
			#define RS232_PRINTSTRHEX(str, value, len)	                  
			#define RS232_PRINTSTRBUF(str, buf, len)	//CLMW_DebugBufAddHEX(d_DEBUG_TITLE_, str, buf, len)
			#define RS232_PRINTFLONG(str, num)			//CLMW_DebugBufAddINT(d_DEBUG_TITLE_, str, num)

			#define WaitTime(msTime)
		#endif
	#endif

	
	#ifndef _DEBUG_METHOD_DEFINED_
	
		#define __DebugInit()
		#define __DebugEnable(bPort)
		#define __DebugDisable()
		#define __DebugAddHEX(title, hex, len)
		#define __DebugAddINT(title, value)
		#define __DebugAddSTR(title)
		#define __DebugAddTSTR(title, str)
		#define __DebugAddLineFeed(bLine)

		#define RS232_INIT()						
		#define RS232_PRINT(str, len)                                   
		#define RS232_PRINTSTR(str)                                    
		#define RS232_PRINTSTR_SAMELINE(str)                           
		#define RS232_PRINTBUF(buf, len)                              
		#define RS232_PRINTBUF2(buf, len)                              
		#define RS232_PRINTSTRVAL(str, value, len)                     
		#define RS232_PRINTSTRHEX(str, value, len)                    
		#define RS232_PRINTSTRBUF(str, buf, len)  
		#define RS232_PRINTFLONG(str, num)	

		#define RS232_DISABLE()						
		#define RS232_ENABLE()						
		#define RS232_WAITALLSENT()                                    
		#define RS232_REINIT()	
		#define WaitForAnyKey() 
		#define WaitTime(msTime)  
	
	#endif
	
	
	void DebugInit(void);
	void DebugEnable(BYTE bPort);
	void DebugDisable(void);
	void DebugAddHEX(BYTE *title, BYTE *hex, USHORT len);
	void DebugAddINT(BYTE *title, ULONG value);
	void DebugAddSTR(BYTE *title);
	void DebugAddTSTR(BYTE *title, BYTE *str);
	void DebugAddLineFeed(BYTE bLine);
	
//------------------------------------------------------------------------------	
//------------------------------------------------------------------------------	
	#if _OUTCOME_LOG_
	
		void CLMW_OutcomeBufReset(void);
		void CLMW_OutcomeBufAdd(BYTE bType, BYTE *baDat, BYTE bDatlen);

		#define __OutcomeReset		CLMW_OutcomeBufReset
		#define __OutcomeAdd		CLMW_OutcomeBufAdd
	
	#else
	
		#define __OutcomeReset
		#define __OutcomeAdd
	
	#endif

//------------------------------------------------------------------------------	
//------------------------------------------------------------------------------	
	#if _APDUDEKDET_LOG_
	
		void CLMW_ApduDekDetBufReset(void);
		void CLMW_ApduDekDetBufAddHEX(BYTE *title, BYTE *hex, USHORT len);
		void CLMW_ApduDekDetBufKeepData(BYTE Type, BYTE *Data, USHORT DataLen);
		void CLMW_ApduDekDetBufPutKeepData(BYTE Type);
	
		#define __ApduDekDetRest		CLMW_ApduDekDetBufReset
		#define __ApduDekDetAddHEX		CLMW_ApduDekDetBufAddHEX
		#define __ApduDekDetKeepData	CLMW_ApduDekDetBufKeepData
		#define __ApduDekDetPutKeepData	CLMW_ApduDekDetBufPutKeepData
	
	#else
	
		#define __ApduDekDetRest
		#define __ApduDekDetAddHEX
		#define __ApduDekDetKeepData
		#define __ApduDekDetPutKeepData

	#endif

#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

