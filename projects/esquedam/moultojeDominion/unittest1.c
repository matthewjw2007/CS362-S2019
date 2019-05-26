/***********
Unit Test 1
************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//This unit test tests the isGameOver function

int main(){
    struct gameState state;
    int returnNumber = 0;

    //Fill supply pile with cards
    for(int i=0; i<25; i++){
        state.supplyCount[i] = 1;
    }

    //Make province supply empty
    state.supplyCount[province] = 0;

    printf("Starting Tests of isGameOver Function\n");

    printf("***Test 1: Testing with empty province stack count***\n");

    //If the stack of province cards is empty the function should return 1
    returnNumber = isGameOver(&state);

    if(returnNumber == 1){
        printf("Test Passed: Province supply is empty and returned value is %d\n", returnNumber);
    } else {
        printf("Test Failed: Province supply is empty but returned value is %d\n", returnNumber);
    }

    state.supplyCount[province] = 1;

    //If the stack of province cards is not empty the function should return 0
    printf("***Test 2: Testing with a non-empty province stack count***\n");

    returnNumber = isGameOver(&state);

    if(returnNumber == 1){
        printf("Test Failed: Province supply was not empty and returned number %d\n", returnNumber);
    } else {
        printf("Test Passed: Province supply is not empty and game is not over\n");
    }

    return 0;
}