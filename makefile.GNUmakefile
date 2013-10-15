#
#Simple make-file
#
#Files: Monetary.cc Monetary.h

CCC = clang++
CCFLAGS =  -pedantic -Wall -Wextra
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++

main: Monetary.o Monetaryclass.o
	$(CCC) $(CCFLAGS) $(LDFLAGS) -o main Monetary.o Lab2.o Monetaryclass.o

Monetaryclass.o: Monetary.h
	$(CCC) $(CCFLAGS) -c Monetary.h

Monetary.o: Monetary.cc
	$(CCC) $(CCFLAGS) -c Monetary.cc

main.o: Monetary.cc lab2.cc 
	$(CCC) $(CCFLAGS) -c lab2.cc

clean:
	@ \rm -f *.o a.out

zap: clean
	@ \rm -f main *~