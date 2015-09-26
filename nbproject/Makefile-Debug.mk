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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1264606667/Observable.o \
	${OBJECTDIR}/_ext/1264606667/Observer.o \
	${OBJECTDIR}/_ext/1264606667/ReferenceTable.o \
	${OBJECTDIR}/_ext/1264606667/SDSMMemoryNode.o \
	${OBJECTDIR}/_ext/1264606667/Server.o \
	${OBJECTDIR}/_ext/1264606667/dHeap.o \
	${OBJECTDIR}/_ext/1264606667/dHeapReferenceTable.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smart-distributed-shared-memory-sdms

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smart-distributed-shared-memory-sdms: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smart-distributed-shared-memory-sdms ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1264606667/Observable.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Observable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/Observable.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Observable.cpp

${OBJECTDIR}/_ext/1264606667/Observer.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Observer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/Observer.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Observer.cpp

${OBJECTDIR}/_ext/1264606667/ReferenceTable.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/ReferenceTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/ReferenceTable.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/ReferenceTable.cpp

${OBJECTDIR}/_ext/1264606667/SDSMMemoryNode.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/SDSMMemoryNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/SDSMMemoryNode.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/SDSMMemoryNode.cpp

${OBJECTDIR}/_ext/1264606667/Server.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Server.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/Server.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/Server.cpp

${OBJECTDIR}/_ext/1264606667/dHeap.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/dHeap.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/dHeap.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/dHeap.cpp

${OBJECTDIR}/_ext/1264606667/dHeapReferenceTable.o: /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/dHeapReferenceTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1264606667
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1264606667/dHeapReferenceTable.o /home/david/NetBeansProjects/Smart\ Distributed\ Shared\ Memory/dHeapReferenceTable.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/smart-distributed-shared-memory-sdms

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
