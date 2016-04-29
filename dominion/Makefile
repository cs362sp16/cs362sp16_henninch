CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unittest1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest1.c rngs.c -o unittest1 -lm -g 
	
unittest2: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest2.c rngs.c -o unittest2 -lm -g 

unittest3: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest3.c rngs.c -o unittest3 -lm -g 

unittest4: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest4.c rngs.c -o unittest4 -lm -g 
cardtest1:
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest1.c rngs.c -o cardtest1 -lm -g

cardtest2:
        gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest2.c rngs.c -o cardtest2 -lm -g

unittestresults.out: unittest1 unittest2 unittest3 unittest4
        ./unittest1 &> unittestresult.out
        ./unittest2 >> unittestresult.out
        ./unittest3 >> unittestresult.out
        ./unittest4 >> unittestresult.out
        ./cardtest1 >> unittestresult.out
        ./cardtest2 >> unittestresult.out
        gcov dominion.c.gcov >> unittestresult.out
        cat dominion.c.gcov >> unittestresult.out


interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

