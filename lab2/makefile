#
#Simple make-file
#Files: Monetary.cc Monetary.h Lab2.cc 

CCC = clang++
CCFLAGS = -pedantic -Wall -Wextra
LDFLAGS = -static-libstdc++ -std=c++11

main: Monetaryclass.o Monetary.o Lab2.o 
	$(CCC) $(CCFLAGS) $(LDFLAGS) Monetaryclass.o Monetary.o Lab2.o -o main

Monetaryclass.o: Monetary.h
	$(CCC) $(CCFLAGS) -c Monetary.h -o Monetaryclass.o

Monetary.o: Monetary.cc
	$(CCC) $(CCFLAGS) -c Monetary.cc

Lab2.o: lab2.cc 
	$(CCC) $(CCFLAGS) -c lab2.cc

