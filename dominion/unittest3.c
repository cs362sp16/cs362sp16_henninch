#include "dominion.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int myassert(int b, char* msg){
	if (!b) {
     printf("-FAILED ASSERTION: %s\n",msg);
	}
}

int main(){
	struct gameState g;
	struct gameState * y = &g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};
	int r = initializeGame(2, k, 5, &g);
	myassert(numHandCards(y)==5, "Unit test 3 failed");
	if(numHandCards(y)==5){
		printf("+Passed Unit test 3 \n");
	}
	return 0;
}
