#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"

void main(){
	printf("\n Unit test 4: ");
	int a = 5;
	int b = 3;
	assert(compare(a,b)==1);
	a = a-2;
	b= b+ 2;
	assert(compare(a,b)==-1);
	a=a+2;
	assert(compare(a,b)==0);
	printf("Passed \n");

}
