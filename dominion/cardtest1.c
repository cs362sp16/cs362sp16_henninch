#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"

void main(){
	printf("\n Card test 1: ");
	struct gameState g;
	struct gameState * y = &g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};
	int r = initializeGame(2, k, 5, &g);
	assert(numHandCards(y)==5);
	council_roomF(y,0,1);
	printf("%i",numHandCards(y));
	//assert(numHandCards(y)==5);
	printf("Passed \n");

}