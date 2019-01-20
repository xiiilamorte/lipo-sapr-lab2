# Compiler
CC=g++
# Flags to compile an object file from source file
CFLAGS=-c
# C++ flags
CPPFLAGS=-std=c++11
# Flags to compile an executed file from object file
OFLAG=-o
# CppUnit library flags
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
# PCRE library flag
PCRE_FLAG=-lpcrecpp
# Object files folder
OBJ=obj
# Test file
TESTFILE=test/test.txt
# Output executed file name
OFILE=main

all: $(OFILE) test

$(OFILE): $(OBJ)/main.o $(OBJ)/HeaderMatch.o $(OBJ)/HeaderMatchTest.o
	$(CC) $(OBJ)/main.o $(OBJ)/HeaderMatch.o $(OBJ)/HeaderMatchTest.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(OFILE)
	
$(OBJ)/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/HeaderMatch.o: HeaderMatch/HeaderMatch.cpp
	$(CC) $(CFLAGS) HeaderMatch/HeaderMatch.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/HeaderMatch.o
	
$(OBJ)/HeaderMatchTest.o: HeaderMatchTest/HeaderMatchTest.cpp
	$(CC) $(CFLAGS) HeaderMatchTest/HeaderMatchTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/HeaderMatchTest.o

test: $(OFILE)
	./$(OFILE) < $(TESTFILE) --test

compare: $(OFILE)
	diff (./$(OFILE) < demo) (./main.sh < demo)

clean:
	rm -rf main *.o $(OBJ)/*.o