#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

//Testing the adventurer card
int main(){
    srand(time(NULL));
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int player = 0;
    int seed = 1000;
    int drawnTreasure = 0;
    int tempHand[MAX_HAND];
    int initDeckCount;
    int postDeckCount;
    int cardDrawn = 0, passedDeckTests = 0, failedDeckTests = 0, passedHandTests = 0, failedHandTests = 0;
    int initHandCount, postHandCount;

    printf("Starting Adventurer Card Random Testing\n");

    for(int i=0; i<100; i++){
        printf("Test %d\n", (i+1));

        int numPlayers = rand() % 6 + 2;    //Getting a random player count between 2 and 5

        initializeGame(numPlayers, k, seed, &state);

        state.deckCount[player] = rand() % 20 + 1;  //Random number for the deck count

        state.handCount[player] = rand() % 6 + 1;   //Random number for the amount of cards in the player's hand

        initDeckCount = state.deckCount[player];

        initHandCount = state.handCount[player];

        adventurerEffect(&state, player);

        postDeckCount = state.deckCount[player];

        postHandCount = state.handCount[player];

        //Test that the deck count has decreased by 1
        if((initDeckCount - 1) == postDeckCount){
            printf("Passed test where deck count is correct\n");
            passedDeckTests++;
        } else {
            printf("Failed test where deck count is incorrect, deck count should be %d, but is at %d\n", (initDeckCount - 1), postDeckCount);
            failedDeckTests++;
        }

        //Test that the players hand count is correct and that it has decreased by 1
        if(postHandCount == (initHandCount - 1)){
            printf("Passed test where hand count is correct\n");
            passedHandTests++;
        } else {
            printf("Failed test where hand count is incorrect, hand count should be %d, but is at %d\n", (initHandCount - 1), postHandCount);
            failedHandTests++;
        }
    }

    printf("***Adventurer Tests Complete***\n");
    printf("Deck Count Tests\n");
    printf("Total Deck Count Passes: %d\n", passedDeckTests);
    printf("Total Deck Count Fails: %d\n", failedDeckTests);
    printf("Hand Count Tests\n");
    printf("Total Hand Count Passes: %d\n", passedHandTests);
    printf("Total Hand Count Fails: %d\n", failedHandTests);

    return 0;
}