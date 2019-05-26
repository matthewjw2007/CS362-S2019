/***********
Unit Test 3
************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//This unit test tests the supplyCount function
int main(){
    struct gameState state;
    int j=1;
    int cardCount = 0;
    int test = 1;

    //Fill in the count of each card
    for(int i=0; i<25; i++){
        state.supplyCount[i] = j;

        j++;
    }

    j = 1;

    //Test that the correct amount of that card is returned
    printf("Starting Tests of supplyCount Function\n");

    for(int a=0; a<25; a++){
        cardCount = supplyCount(a, &state);

        if(cardCount == j){
            printf("Test Passed: Card %d amount is %d\n", test, cardCount);
        } else {
            printf("Test Failed: Value not returned\n");
        }

        test++;

        j++;
    }

    return 0;
}