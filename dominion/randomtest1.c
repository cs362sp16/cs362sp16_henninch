#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define MAX_TESTS 100 

int main(){
printf("Random Test 1 (Council Room) Starting \n");
	
	int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
	int  i, j, n, players, player, handCount, deckCount, seed, address;
	struct gameState state1;
	struct gameState state2;
	struct gameState state3;
	
	for(i=0;i < MAX_TESTS;i++){
		seed = rand();
		players = rand() % 4;
		initializeGame(players,k,seed,&state1);
		
		state1.deckCount[player] = rand() % MAX_DECK;
		state1.discardCount[player] = rand() % MAX_DECK;
		state1.handCount[player] = rand() % MAX_HAND;
		
		handCount = state1.handCount[player];
		deckCount = state1.deckCount[player];
		
		cardEffect(council_room,1,1,1,&state1);
		
	}
	
	for(i=0;i < MAX_TESTS;i++){
		seed = rand();
		players = rand() % 4;
		initializeGame(players,k,seed,&state2);
		
		state2.deckCount[player] = rand() % MAX_DECK;
		state2.discardCount[player] = rand() % MAX_DECK;
		state2.handCount[player] = rand() % MAX_HAND;
		
		handCount = state2.handCount[player];
		deckCount = state2.deckCount[player];
		
		cardEffect(council_room,1,1,1,&state2);
		
	}
	
	for(i=0;i < MAX_TESTS;i++){
		seed = rand();
		players = rand() % 4;
		initializeGame(players,k,seed,&state3);
		
		state3.deckCount[player] = rand() % MAX_DECK;
		state3.discardCount[player] = rand() % MAX_DECK;
		state3.handCount[player] = rand() % MAX_HAND;
		
		handCount = state3.handCount[player];
		deckCount = state3.deckCount[player];
		
		cardEffect(council_room,1,1,1,&state3);
		
	}
	
	printf("Random Test 1 Complete \n");
	
	return 0;
}