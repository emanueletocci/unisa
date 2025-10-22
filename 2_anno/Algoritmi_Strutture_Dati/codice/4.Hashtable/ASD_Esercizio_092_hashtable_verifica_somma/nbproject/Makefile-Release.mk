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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/61b1b74f/THT.o \
	${OBJECTDIR}/_ext/61b1b74f/TInfo.o \
	${OBJECTDIR}/_ext/61b1b74f/TList.o \
	${OBJECTDIR}/_ext/61b1b74f/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_092_hashtable_verifica_somma

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_092_hashtable_verifica_somma: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_092_hashtable_verifica_somma ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/61b1b74f/THT.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/THT.c
	${MKDIR} -p ${OBJECTDIR}/_ext/61b1b74f
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/61b1b74f/THT.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/THT.c

${OBJECTDIR}/_ext/61b1b74f/TInfo.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/TInfo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/61b1b74f
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/61b1b74f/TInfo.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/TInfo.c

${OBJECTDIR}/_ext/61b1b74f/TList.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/TList.c
	${MKDIR} -p ${OBJECTDIR}/_ext/61b1b74f
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/61b1b74f/TList.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/TList.c

${OBJECTDIR}/_ext/61b1b74f/main.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/61b1b74f
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/61b1b74f/main.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_092_hashtable_verifica_somma_2/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
