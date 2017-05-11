#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=arm-brcm-linux-gnueabi-gcc
CCC=arm-brcm-linux-gnueabi-g++
CXX=arm-brcm-linux-gnueabi-g++
FC=g77.exe
AS=as

# Macros
CND_PLATFORM=Gnueabi-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include NbMakefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GetPin/debug4.o \
	${OBJECTDIR}/EMV_contact/utility.o \
	${OBJECTDIR}/EMVCL-Redirect/VirtualLED.o \
	${OBJECTDIR}/EMVCL-Redirect/Transaction.o \
	${OBJECTDIR}/wub_lib.o \
	${OBJECTDIR}/EMVCL-Redirect/Setting.o \
	${OBJECTDIR}/EMVCL-Redirect/contact.o \
	${OBJECTDIR}/MSR/MSR_main.o \
	${OBJECTDIR}/EMVCL-Redirect/debug.o \
	${OBJECTDIR}/EMV_contact/EMV_contact_main.o \
	${OBJECTDIR}/GetPin/GetPin_main.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/EMVCL-Redirect/ScreenDispaly.o \
	${OBJECTDIR}/EMVCL-Redirect/EMV_appmain.o


# C Compiler Flags
CFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wstrict-prototypes -Wno-trigraphs -Wimplicit -Wformat 

# CC Compiler Flags
CCFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wno-trigraphs -Wimplicit -Wformat 
CXXFLAGS="-I${SDKV3INC}" -fsigned-char -Wundef -Wno-trigraphs -Wimplicit -Wformat 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lcaethernet -lcafont -lcafs -lcakms -lcalcd -lcamodem -lcapmodem -lcaprt -lcartc -lcauart -lcauldpm -lcausbh -lcagsm -lcabarcode -lpthread -ldl -lcaclvw -lcatls -lctosapi -lcrypto -lcurl -lssl -lz -lfreetype -lcaaep -lcavap -lcaclentry -lcaclmdl -lcaemvl2 -lcaemvl2ap -lcampp -lcavpw -lcapcipad

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk dist/V3/App/V3_Demo_V3P_24.exe

dist/V3/App/V3_Demo_V3P_24.exe: ${OBJECTFILES}
	${MKDIR} -p dist/V3/App
	arm-brcm-linux-gnueabi-g++ -L . "-L${SDKV3LIB}" "-L${SDKV3LIBN}" -o dist/V3/App/V3_Demo_V3P_24  ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/GetPin/debug4.o: GetPin/debug4.c 
	${MKDIR} -p ${OBJECTDIR}/GetPin
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/GetPin/debug4.o GetPin/debug4.c

${OBJECTDIR}/EMV_contact/utility.o: EMV_contact/utility.c 
	${MKDIR} -p ${OBJECTDIR}/EMV_contact
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMV_contact/utility.o EMV_contact/utility.c

${OBJECTDIR}/EMVCL-Redirect/VirtualLED.o: EMVCL-Redirect/VirtualLED.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/VirtualLED.o EMVCL-Redirect/VirtualLED.c

${OBJECTDIR}/EMVCL-Redirect/Transaction.o: EMVCL-Redirect/Transaction.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/Transaction.o EMVCL-Redirect/Transaction.c

${OBJECTDIR}/wub_lib.o: wub_lib.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/wub_lib.o wub_lib.c

${OBJECTDIR}/EMVCL-Redirect/Setting.o: EMVCL-Redirect/Setting.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/Setting.o EMVCL-Redirect/Setting.c

${OBJECTDIR}/EMVCL-Redirect/contact.o: EMVCL-Redirect/contact.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/contact.o EMVCL-Redirect/contact.c

${OBJECTDIR}/MSR/MSR_main.o: MSR/MSR_main.c 
	${MKDIR} -p ${OBJECTDIR}/MSR
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/MSR/MSR_main.o MSR/MSR_main.c

${OBJECTDIR}/EMVCL-Redirect/debug.o: EMVCL-Redirect/debug.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/debug.o EMVCL-Redirect/debug.c

${OBJECTDIR}/EMV_contact/EMV_contact_main.o: EMV_contact/EMV_contact_main.c 
	${MKDIR} -p ${OBJECTDIR}/EMV_contact
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMV_contact/EMV_contact_main.o EMV_contact/EMV_contact_main.c

${OBJECTDIR}/GetPin/GetPin_main.o: GetPin/GetPin_main.c 
	${MKDIR} -p ${OBJECTDIR}/GetPin
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/GetPin/GetPin_main.o GetPin/GetPin_main.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/EMVCL-Redirect/ScreenDispaly.o: EMVCL-Redirect/ScreenDispaly.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/ScreenDispaly.o EMVCL-Redirect/ScreenDispaly.c

${OBJECTDIR}/EMVCL-Redirect/EMV_appmain.o: EMVCL-Redirect/EMV_appmain.c 
	${MKDIR} -p ${OBJECTDIR}/EMVCL-Redirect
	$(COMPILE.c) -O2 -I/cygdrive/C/Program\ Files/Castles/VEGA3000/include -I/cygdrive/C/Program\ Files\ \(x86\)/Castles/VEGA3000/include -o ${OBJECTDIR}/EMVCL-Redirect/EMV_appmain.o EMVCL-Redirect/EMV_appmain.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} dist/V3/App/V3_Demo_V3P_24.exe

# Subprojects
.clean-subprojects:
