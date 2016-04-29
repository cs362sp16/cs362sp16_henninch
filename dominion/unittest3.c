#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"


void main(){
	printf("\n Unit test 3: ");
	struct gameState g;
	struct gameState * y = &g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};
	int r = initializeGame(2, k, 5, &g);
	assert(numHandCards(y)==5);
	drawCard(0,y);
	printf("%i",numHandCards(y));
	if(numHandCards(y)==6){;
		printf("Passed \n");
	}
	else{
		printf("Failed \n");
	}

}
