/***********
Unit Test 2
************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//This unit test is testing the councilRoom refactored function

int main(){
    struct gameState state;
    state.handCount[0] = 5;
    state.deckCount[0] = 30;
    state.numBuys = 0;
    int currentPlayer = 0;
    int handPos = 0;

    printf("Starting Test of Council Room Function\n");

    //Testing that the correct amount of cards were drawn
    councilRoom(currentPlayer, &state, handPos);

    if(state.handCount[0] == 9){
        printf("Test Passed: Player drew 4 cards\n");
    } else {
        printf("Test Failed: Player did not draw the correct amount of cards\n");
    }

    if(state.numBuys == 1){
        printf("Test Passed: Player now has %d buys\n", state.numBuys);
    } else {
        printf("Test Failed: Player's buys did not increase");
    }

    return 0;
}