#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

//Testing the refactored village function
int main(){
    srand(time(NULL));
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int player = 0;
    int handPos = 0;
    int seed = 1000;
    int initActions;
    int postActions;
    int passedHandTests = 0, failedHandTests = 0, passedActionTests = 0, failedActionTests = 0;
    int initHandCount, postHandCount;
    int numPlayers;

    printf("Starting Village Card Random Testing\n");

    for(int i=0; i<100; i++){
        printf("Test %d\n", (i+1));

        //Generate a random number of players between 2 and 10
        numPlayers = rand() % 10 + 2;

        initializeGame(numPlayers, k, seed, &state);

        state.handCount[player] = rand() % 8 + 2;

        state.numActions = rand() % 5 + 1;

        initHandCount = state.handCount[player];

        initActions = state.numActions;

        villageFunction(player, &state, handPos);

        postHandCount = state.handCount[player];

        postActions = state.numActions;

        if(postHandCount == (initHandCount + 1)){
            printf("Hand Count Test Passed\n");
            passedHandTests++;
        } else {
            printf("Hand Count Test Failed\n");
            failedHandTests++;
        }

        if(postActions == (initActions + 2)){
            printf("Action Count Test Passed\n");
            passedActionTests++;
        } else {
            printf("Action Count Test Failed\n");
            failedActionTests++;
        }
    }

    printf("***Village Card Testing Done***\n");
    printf("Hand Count Tests\n");
    printf("Hand Count Tests Passed: %d\n", passedHandTests);
    printf("Hand Count Tests Failed: %d\n", failedHandTests);
    printf("Action Tests\n");
    printf("Action Tests Passed: %d\n", passedActionTests);
    printf("Action Tests Failed: %d\n", failedActionTests);

    return 0;
}