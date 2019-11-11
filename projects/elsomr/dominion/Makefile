CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/




interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)


assertEq.o: assertEq.h assertEq.c
	gcc -c assertEq.c -g $(CFLAGS)

unitTest1: unitTest1.c dominion.o rngs.o assertEq.o
	gcc -o unitTest1 -g unitTest1.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
unitTest2: unitTest2.c dominion.o rngs.o assertEq.o
	gcc -o unitTest2 -g unitTest2.c dominion.o rngs.o assertEq.o $(CFLAGS)

unitTest3: unitTest3.c dominion.o rngs.o assertEq.o
	gcc -o unitTest3 -g unitTest3.c dominion.o rngs.o assertEq.o $(CFLAGS)

unitTest4: unitTest4.c dominion.o rngs.o assertEq.o
	gcc -o unitTest4 -g unitTest4.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
unitTest5: unitTest5.c dominion.o rngs.o assertEq.o
	gcc -o unitTest5 -g unitTest5.c dominion.o rngs.o assertEq.o $(CFLAGS)
	
runtests: unitTest1 unitTest2 unitTest3 unitTest4 unitTest5
	./unitTest1 &> unittestresult.out
	#gcov dominion.c >> unittestresult.out
	#cat dominion.c.gcov >> unittestresult.out
	
	./unitTest2 &> unittestresult.out
	# gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out
	
	./unitTest3 &> unittestresult.out
	# gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out
	
	./unitTest4 &> unittestresult.out
	# gcov dominion.c >> unittestresult.out
	# cat dominion.c.gcov >> unittestresult.out
	
	./unitTest5 &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player runtests 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe \
	unitTest1 unitTest2 unitTest3 unitTest4 unitTest5
