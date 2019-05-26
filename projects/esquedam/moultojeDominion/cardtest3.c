#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//This tests the minion card

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

    printf("***Testing Minion Card***\n");

    //Initialize the game
    initializeGame(numPlayers, k, seed, &state);

    //Get how many coins the player currently has
    temp = state.coins;

    printf("Running Test 1: Checking That Player Acquires 2 Coins\n");

    cardEffect(minion, choice1, choice2, choice3, &state, handPos, &bonus);

    newTemp = state.coins;

    if(newTemp == (temp + 2)){
        printf("Test Passed: 2 coins were acquired\n");
    } else {
        printf("Test Failed: Player did not draw 2 coins\n");
    }

    printf("Running Test 2: Check That Player Only Has 4 Cards If Choice 2\n");

    temp = state.handCount[0];

    choice1 = 0;
    choice2 = 1;

    cardEffect(minion, choice1, choice2, choice3, &state, handPos, &bonus);

    newTemp = state.handCount[0];

    if(newTemp == 4){
        printf("Test Passed: Player only has 4 cards\n");
    } else {
        printf("Test Failed: Player did not discard cards and does not have 4 cards\n");
    }

    return 0;
}