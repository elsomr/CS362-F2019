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


testBaronCard: randomtestcard1.c dominion.o rngs.o assertEq.o
	gcc  -o testBaronCard -g  randomtestcard1.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
testMinionCard: randomtestcard2.c dominion.o rngs.o assertEq.o
	gcc  -o testMinionCard -g  randomtestcard2.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
testTributeCard: randomtestcard3.c dominion.o rngs.o assertEq.o
	gcc  -o testTributeCard -g  randomtestcard3.c dominion.o rngs.o assertEq.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testBaronCard testMinionCard testTributeCard
	./testBaronCard &> unittestresult.out
	gcov -b -f dominion.c >> unittestresult.out
	#cat dominion.c.gcov >> unittestresult.out
	
	./testMinionCard &> unittestresult.out
	gcov -b -f dominion.c >> unittestresult.out
	#cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: runtests

clean:
	rm -f *.o playdom.exe testBaronCard testBaronCard.exe testMinionCard testMinionCard.exe playdom player\
	player.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
