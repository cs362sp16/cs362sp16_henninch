CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

adventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

runAdventurer: adventurer
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

Randomtest1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtest1.c rngs.c -o randomtest1 -lm -g

runRandomtest1: Randomtest1 
	./randomtest1 &> randomtest1.out
	gcov dominion.c >> randomtest1.out
	cat dominion.c.gcov >> Randomtest1.out

Randomtest2: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtest2.c rngs.c -o randomtest2 -lm -g

runRandomtest2: Randomtest2 
	./randomtest2 &> randomtest2.out
	gcov dominion.c >> randomtest2.out
	cat dominion.c.gcov >> Randomtest2.out

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS) 
	./unittest1 >> unittest1.out

unittest2:  unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS) 
	./unittest2 >> unittest2.out

unittest3:  unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS) 
	./unittest3 >> unittest3.out

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS) 
	./unittest4 >> unittest4.out

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> cardtest1.out

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> cardtest2.out

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> cardtest3.out

unittestresults: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2
	./unittest1 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom unittest1.out unittest2.out unittest3.out unittest4.out cardtest1.out cardtest2.out cardtest3.out test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtest1 randomtest2 randomtestadventurer ramdomtestplayer.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

