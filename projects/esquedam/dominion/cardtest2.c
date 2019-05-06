#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//This tests the adventurer card

int main(){
    struct gameState state;
    //Declaring the cards in the array
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int handPos = 0;
    int choice1 = 0;
    int choice2= 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int temp, newTemp, count = 0, newCount = 0;

    //Initialize the game
    initializeGame(numPlayers, k, seed, &state);

    printf("***Testing Adventurer Card***\n");

    //Test 1: Verify that the hand count decreases by 1
    printf("Test 1: Checking that player's hand count decreases by 1\n");

    temp = state.handCount[0];

    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

    newTemp = state.handCount[0];

    if(newTemp == (temp - 1)){
        printf("Test Passed: Deck count correct\n");
    } else {
        printf("Test Failed: Deck count is incorrect\n");
    }

    //Test 2: Verify player discarded the adventurer card they played
    printf("Test 2: Check that player discarded adventurer card\n");

    for(int i = 0; i<state.handCount[0]; i++){
        if(state.hand[0][i] == adventurer){
            count++;
        }
    }

    cardEffect(adventurer, choice1, choice2, choice3, &state, handPos, &bonus);

    for(int j = 0; j<state.handCount[0]; j++){
        if(state.hand[0] == adventurer){
            newCount++;
        }
    }

    if(newCount < count){
        printf("Test Passed: Card was discarded\n");
    } else {
        printf("Test Failed: Card was not discarded\n");
    }

    return 0;
}