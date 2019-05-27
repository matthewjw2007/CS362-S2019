#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//This tests the smithy card

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
    int temp, newTemp;
    int count = 0;
    int newCount = 0;

    //Initialize the game
    initializeGame(numPlayers, k, seed, &state);

    //Check how many cards the player has in their hand before smithy is called
    temp = numHandCards(&state);

    printf("***Testing Smithy Card***\n");

    for(int i = 0; i<state.handCount[0]; i++){
        if(state.hand[0][i] == smithy){
            count++;
        }
    }

    //Call the cardEffect function
    cardEffect(smithy, choice1, choice2, choice3, &state, handPos, &bonus);

    for(int j = 0; j<state.handCount[0]; j++){
        if(state.hand[0][j] == smithy){
            newCount++;
        }
    }

    //Verify that the player drew three cards
    newTemp = numHandCards(&state);

    if(newTemp > (temp + 2)){
        printf("Test Passed: Player drew 3 cards\n");
    } else {
        printf("Test Failed: Player did not draw the correct amount of cards\n");
    }

    if(newCount < count){
        printf("Test Passed: Card was discarded\n");
    } else {
        printf("Test Failed: Card was not discarded\n");
    }

    return 0;
}