#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

//Testing council room - tested this in unittest2.c from assignment 3
int main(){
    srand(time(NULL));
    struct gameState state;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
    int player = 0;
    int handPos = 0;
    int seed = 1000;
    int passedTests = 0, failedTests = 0;
    int initHandCount, postHandCount;
    int numPlayers;

    printf("Starting Council Room Random Tests\n");

    for(int i=0; i<100; i++){
        printf("Test %d\n", (i+1));

        numPlayers = rand() % 5 + 2; //Getting a random player count between 2 and 5

        initializeGame(numPlayers, k, seed, &state);

        state.handCount[player] = rand() % 10 + 1;  //Giving player a random hand count between 1 and 10

        initHandCount = state.handCount[player];

        councilRoom(player, &state, handPos);

        postHandCount = state.handCount[player];

        if(postHandCount == (initHandCount + 4)){
            printf("Test Passed: Correct hand count\n");
            passedTests++;
        } else {
            printf("Test Failed: Incorrect hand count\n");
            failedTests++;
        }
    }

    printf("***Testing Complete***\n");
    printf("Total Hand Count Passes: %d\n", passedTests);
    printf("Total Hand Count Failures: %d\n", failedTests);

    return 0;
}