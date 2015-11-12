##Author: Alicia Broederdorf
##Date: May 31, 2015
##Assignment: Final Project


####Variables####
#Compiler
CXX = g++

#Language version
CXXFLAGS = -std=c++0x

#Turns on all warnings
#CXXFLAGS += -Wall

#Enforces standard
CXXFLAGS += -pedantic-errors

#Debug information
CXXFLAGS += -g



####Files####
#Source Files
SRC1 = House.cpp
SRC2 = Room.cpp
SRC3 = BoolRoom.cpp
SRC4 = ClueBoolRoom.cpp
SRC5 = PuzzleRoom.cpp
SRC6 = Puzzle1.cpp
SRC7 = Puzzle2.cpp
SRC8 = Puzzle3.cpp
SRC9 = GoingCamping.cpp
SRC10 = inputValidation.cpp
SRCS1 = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10}

#Headers
HEADER1 = House.hpp
HEADER2 = Room.hpp
HEADER3 = BoolRoom.hpp
HEADER4 = ClueBoolRoom.hpp
HEADER5 = PuzzleRoom.hpp
HEADER6 = Puzzle1.hpp
HEADER7 = Puzzle2.hpp
HEADER8 = Puzzle3.hpp
HHEADER9 = inputValidation.hpp
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8} ${HEADER9}

#Executable files
PROG1 = GoingCamping
PROGS = ${PROG1}




####Build####
all: ${PROGS}

${PROG1}: ${SRCS1} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS1} ${HEADERS} -o ${PROG1}

clean:
	rm -f ${PROGS} *.o *~
