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

unitTest7: unitTest7.c dominion.o rngs.o
	gcc  -o unitTest7 -g  unitTest7.c dominion.o rngs.o $(CFLAGS)
	
unitTest9: unitTest9.c dominion.o rngs.o
	gcc  -o unitTest9 -g  unitTest9.c dominion.o rngs.o $(CFLAGS)
	
unitTest10: unitTest10.c dominion.o rngs.o
	gcc  -o unitTest10 -g  unitTest10.c dominion.o rngs.o $(CFLAGS)


runtests: untiTest7 unitTest9 unitTest10
	
	./unitTest9 &> testresults.out
	#gcov -b -f dominion.c >> testresults.out
	./unitTest7 >> testresults.out
	./unitTest10 >> testresults.out
	gcov -b -f dominion.c >> testresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player runtests

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
