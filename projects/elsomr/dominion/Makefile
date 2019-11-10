CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

assert.o: assert.c 
	gcc -c assert.c -g $(CFLAGS)
	
unitTest1.o: assert.o dominion.o rngs.o
	gcc -o unitTest1 -g unitTest1.c dominion.o rngs.o $(CFLAGS)

unitTest2.o: assert.o dominion.o rngs.o
	gcc -o unitTest2 -g unitTest2.c dominion.o rngs.o $(CFLAGS)

unitTest3.o: assert.o dominion.o rngs.o
	gcc -o unitTest3 -g unitTest3.c dominion.o rngs.o $(CFLAGS)
	
unitTest4.o: assert.o dominion.o rngs.o
	gcc -o unitTest4 -g unitTest4.c dominion.o rngs.o $(CFLAGS)
	
unitTest5.o: assert.o dominion.o rngs.o
	gcc -o unitTest5 -g unitTest5.c dominion.o rngs.o $(CFLAGS)


runtests: unitTest
	./unitTest1 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unitTest2 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unitTest3 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unitTest4 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
	./unitTest5 &> unittestresults.out
	gcov -b -f dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	


all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out \
	unitTest1 unitTest1.exe unitTest2 unitTest2.exe unitTest3 unitTest3.exe unitTest4 unitTest4.exe \
	unitTest5 unitTest5.exe
