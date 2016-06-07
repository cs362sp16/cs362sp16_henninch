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
	int a = 5;
	int b = 3;
	myassert(compare(&a,&b)==1," ");
	a = a-2;
	b= b+ 2;
	myassert(compare(&a,&b)==-1," ");
	a=a+2;
	myassert(compare(&a,&b)==0, " ");
	if(compare(&a,&b)==0){
		printf("+Passed Unit test 4 \n");
	}
	return 0;
}
