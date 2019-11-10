CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c -g $(CFLAGS)

runtests: testme
	./testme

all: testme runtests

clean:
	rm -f *.o testme testme.exe  *.gcov *.gcda *.gcno *.so *.out 
