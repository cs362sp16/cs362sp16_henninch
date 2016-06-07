#include "dominion.h"
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
	int a;
	a = whoseTurn(y);
	myassert(a==0,"Unit test 1 Did not start properly");
	endTurn(y);
	a = whoseTurn(y);
	myassert(a==1,"Unit test 1 failed");
	if(a==1){
		printf("+Passed Unit test 1 \n");
	}
	return 0;
}
