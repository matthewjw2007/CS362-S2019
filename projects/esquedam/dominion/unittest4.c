/***********
Unit Test 4
************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//This unit test tests the getCost function
int main(){
    int card, returnNumber;

    printf("***Testing getCost Function***\n");

    for(card = 0; card < 27; card++)
    {
        returnNumber = getCost(card);

        if(card == 0){
            if(returnNumber == 0){
                printf("Test Passed: Curse returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Curse should have returned 0, but returned %d\n", returnNumber);
            }
        }
        else if(card == 1){
            if(returnNumber == 2){
                printf("Test Passed: Estate returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Estate should have returned 2, but returned %d\n", returnNumber);
            }
        }
        else if(card == 2){
            if(returnNumber == 5){
                printf("Test Passed: Duchy returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Duchy should have returned 5, but returned %d\n", returnNumber);
            }
        }
        else if(card == 3){
            if(returnNumber == 8){
                printf("Test Passed: Province returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Province should have returned 8, but returned %d\n", returnNumber);
            }
        }
        else if(card == 4){
            if(returnNumber == 0){
                printf("Test Passed: Copper returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Copper should have returned 0, but returned %d\n", returnNumber);
            }
        }
        else if(card == 5){
            if(returnNumber == 3){
                printf("Test Passed: Silver returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Silver should have returned 3, but returned %d\n", returnNumber);
            }
        }
        else if(card == 6){
            if(returnNumber == 6){
                printf("Test Passed: Gold returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Gold should have returned 6, but returned %d\n", returnNumber);
            }
        }
        else if(card == 7){
            if(returnNumber == 6){
                printf("Test Passed: Adventurer returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Adventurer should have returned 6, but returned %d\n", returnNumber);
            }
        }
        else if(card == 8){
            if(returnNumber == 5) {
                printf("Test Passed: Council Room returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Council Room should have returned 6, but returned %d\n", returnNumber);
            }
        }
        else if(card == 9){
            if(returnNumber == 4){
                printf("Test Passed: Feast returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Feast should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 10){
            if(returnNumber == 4){
                printf("Test Passed: Gardens returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Gardens should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 11){
            if(returnNumber == 5){
                printf("Test Passed: Mine returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Mine should have returned 5, but returned %d\n", returnNumber);
            }
        }
        else if(card == 12){
            if(returnNumber == 4){
                printf("Test Passed: Remodel returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Remodel should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 13){
            if(returnNumber == 4){
                printf("Test Passed: Smithy returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Smithy should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 14){
            if(returnNumber == 3){
                printf("Test Passed: Village returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Village should have returned 3, but returned %d\n", returnNumber);
            }
        }
        else if(card == 15){
            if(returnNumber == 4){
                printf("Test Passed: Baron returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Baron should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 16){
            if(returnNumber == 3){
                printf("Test Passed: Great Hall returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Great Hall should have returned 3, but returned %d\n", returnNumber);
            }
        }
        else if(card == 17){
            if(returnNumber == 5){
                printf("Test Passed: Minion returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Minion should have returned 5, but returned %d\n", returnNumber);
            }
        }
        else if(card == 18){
            if(returnNumber == 3){
                printf("Test Passed: Steward returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Steward should have returned 3, but returned %d\n", returnNumber);
            }
        }
        else if(card == 19){
            if(returnNumber == 5){
                printf("Test Passed: Tribute returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Tribute should have returned 5, but returned %d\n", returnNumber);
            }
        }
        else if(card == 20){
            if(returnNumber == 3){
                printf("Test Passed: Ambassador returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Ambassador should have returned 3, but returned %d\n", returnNumber);
            }
        }
        else if(card == 21){
            if(returnNumber == 4){
                printf("Test Passed: Cutpurse returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Cutpurse should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 22){
            if(returnNumber == 2){
                printf("Test Passed: Embargo returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Embargo should have returned 2, but returned %d\n", returnNumber);
            }
        }
        else if(card == 23){
            if(returnNumber == 5){
                printf("Test Passed: Outpost returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Outpost should have returned 5, but returned %d\n", returnNumber);
            }
        }
        else if(card == 24){
            if(returnNumber == 4){
                printf("Test Passed: Salvager returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Salvager should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 25){
            if(returnNumber == 4){
                printf("Test Passed: Sea Hag returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Sea Hag should have returned 4, but returned %d\n", returnNumber);
            }
        }
        else if(card == 26){
            if(returnNumber == 4){
                printf("Test Passed: Treasure Map returned with return number %d\n", returnNumber);
            } else {
                printf("Test Failed: Treasure Map should have returned 4, but returned %d\n", returnNumber);
            }
        }
    }

    return 0;
}