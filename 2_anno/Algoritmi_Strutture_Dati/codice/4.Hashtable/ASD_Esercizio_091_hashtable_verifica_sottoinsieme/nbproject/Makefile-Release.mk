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
	${OBJECTDIR}/_ext/67d5c58a/THT.o \
	${OBJECTDIR}/_ext/67d5c58a/TInfo.o \
	${OBJECTDIR}/_ext/67d5c58a/TList.o \
	${OBJECTDIR}/_ext/67d5c58a/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_091_hashtable_verifica_sottoinsieme

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_091_hashtable_verifica_sottoinsieme: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/asd_esercizio_091_hashtable_verifica_sottoinsieme ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/67d5c58a/THT.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/THT.c
	${MKDIR} -p ${OBJECTDIR}/_ext/67d5c58a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67d5c58a/THT.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/THT.c

${OBJECTDIR}/_ext/67d5c58a/TInfo.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/TInfo.c
	${MKDIR} -p ${OBJECTDIR}/_ext/67d5c58a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67d5c58a/TInfo.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/TInfo.c

${OBJECTDIR}/_ext/67d5c58a/TList.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/TList.c
	${MKDIR} -p ${OBJECTDIR}/_ext/67d5c58a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67d5c58a/TList.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/TList.c

${OBJECTDIR}/_ext/67d5c58a/main.o: /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/main.c
	${MKDIR} -p ${OBJECTDIR}/_ext/67d5c58a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/67d5c58a/main.o /home/emanueletocci/Documents/ClionProjects/ASD_Esercizio_091_hashtable_verifica_sottoinsieme_2/main.c

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
