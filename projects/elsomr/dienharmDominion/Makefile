CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

assertEq.o: assertEq.h assertEq.c
	gcc -c assertEq.c -g $(CFLAGS)

unitTest1: unitTest1.c dominion.o rngs.o assertEq.o
	gcc  -o unitTest1 -g  unitTest1.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
unitTest2: unitTest2.c dominion.o rngs.o assertEq.o
	gcc  -o unitTest2 -g  unitTest3.c dominion.o rngs.o assertEq.o $(CFLAGS)

unitTest3: unitTest3.c dominion.o rngs.o assertEq.o
	gcc  -o unitTest3 -g  unitTest3.c dominion.o rngs.o assertEq.o $(CFLAGS)

unitTest4: unitTest4.c dominion.o rngs.o assertEq.o
	gcc  -o unitTest4 -g  unitTest4.c dominion.o rngs.o assertEq.o $(CFLAGS)

unitTest5: unitTest5.c dominion.o rngs.o assertEq.o
	gcc  -o unitTest5 -g  unitTest5.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
testBaronCard: randomtestcard1.c dominion.o rngs.o assertEq.o
	gcc  -o testBaronCard -g  randomtestcard1.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
testMinionCard: randomtestcard2.c dominion.o rngs.o assertEq.o
	gcc  -o testMinionCard -g  randomtestcard2.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
testTributeCard: randomtestcard3.c dominion.o rngs.o assertEq.o
	gcc  -o testTributeCard -g  randomtestcard3.c dominion.o rngs.o assertEq.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runTests: testBaronCard testMinionCard testTributeCard unitTest1 unitTest2 unitTest3 unitTest4 unitTest5
	./unitTest1 &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./unitTest2 &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./unitTest3 &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./unitTest4 &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./unitTest5 &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./testBaronCard &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./testMinionCard &> testresults.out
	gcov -b -f dominion.c >> testresults.out
	
	./testTributeCard &> testresults.out
	gcov -b -f dominion.c >> testresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: runTests

clean:
	rm -f *.o playdom.exe testBaronCard testBaronCard.exe testMinionCard testMinionCard.exe playdom player\
	player.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testTributeCard testTributeCard.exe\
	unitTest1 unitTest1.exe unitTest2 unitTest2.exe unitTest3 unitTest3.exe unitTest4 unitTest4.exe unitTest5 unitTest5.exe
