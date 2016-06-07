
#include"dominion.h"
#include <stdio.h>
#include <stdlib.h>

/* from dominion.c */ 
int myassert(int b, char* msg){
        if (!b) {
     printf("-FAILED ASSERTION: %s\n",msg);
        }
}


 

int main()
{
	struct gameState G;
	struct gameState *p = &G;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	  
  	initializeGame(2, k, 5, p);	
  	
  int currentPlayer = whoseTurn(p);

  int temphand[MAX_HAND];
  int drawntreasure=0;
  int cardDrawn;
  int z = 0;
	adventurerF(p,currentPlayer,0,drawntreasure);
	myassert(drawntreasure==2, "Adventurer card drawntreasure failed");
	if(drawntreasure ==2 ){
		printf("+Passed Card test 3 \n");
	}
return 0;
}
