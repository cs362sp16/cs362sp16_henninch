#include "dominion.c"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void main(){
	printf("\n Unit test 1: ");
	struct gameState g;
	struct gameState * y = &g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};
	int r = initializeGame(2, k, 5, &g);
	int a;
	a = whoseTurn(y);
	assert(a==0);
	endTurn(y);
	a = whoseTurn(y);
	assert(a==1);
	printf("Passed \n");
}
