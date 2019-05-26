#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//This tests the embargo card

int main(){
    struct gameState state;
    //Declaring the cards in the array
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int handPos = 0;
    int choice1 = 1;
    int choice2= 0;
    int choice3 = 0;
    int bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int temp, newTemp;

    printf("***Testing Embargo Card***\n");

    //Initialize the game
    initializeGame(numPlayers, k, seed, &state);

    printf("Test 1: Verifying 2 coins added\n");

    temp = state.coins;

    cardEffect(embargo, choice1, choice2, choice3, &state, handPos, &bonus);

    newTemp = state.coins;

    if(newTemp == (temp + 2)){
        printf("Test Passed: Player added 2 coins\n");
    } else {
        printf("Test Failed: Player did not add 2 coins\n");
    }

    printf("Test 2: Testing embargo token count\n");

    temp = state.embargoTokens[choice1];

    cardEffect(embargo, choice1, choice2, choice3, &state, handPos, &bonus);

    newTemp = state.embargoTokens[choice1];

    if(newTemp == (temp + 1)){
        printf("Test Passed: Embargo token added\n");
    } else {
        printf("Test Failed: Embargo token not added\n");
    }

    return 0;

}