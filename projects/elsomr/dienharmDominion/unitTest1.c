/* -----------------------------------------------------------------------
 * Unit test for Baron functions for Assignment 3
 *
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "assertEq.h"
#include "rngs.h"

// char* assertEq(int expected, int outcome, int failCounter)	{
	// static char* result;
	
	// if (expected == outcome) 	{
		// result = "PASS";
	// }
	// else	{
		// failCounter++;
		// result = "FAIL";
	// }
	// result[4] = '\0';
	// return result;
// }

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxEstate = 10;
    int p, r, handCount;
	int tempCoins, tempSupply;
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
	int counter = 0;
	int* failCounter = &counter;
	char tmpResult[5];
	
	
	
	int estates[MAX_HAND];
	int coppers[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++)	{
		estates[i] = estate;
		coppers[i] = copper;
	}
	
	
    printf ("TESTING baronEffect():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			
			printf("\nTest player %d with %d cards and discarding an estate for coins.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				
				//add esate card to handCount
				gainCard(estate, &G, 2, p);
				tempCoins = G.coins;
				
				//try to discard
				baronEffect(1, &G);
				
				printf("Coin check = %d == %d", tempCoins+4, G.coins);
				assertEq(tempCoins+4, G.coins, failCounter, tmpResult);\
				//hand count should stay same after gaining and then discarding a card
				printf("Hand Descreases check = %d == %d", handCount, G.handCount[p]);
				assertEq(handCount-1, G.handCount[p], failCounter, tmpResult);				
			
			
			printf("\nTest player %d with %d cards and discarding an estate for coins without an estate card.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				
				
				//set all the cards to copper so no estate cards are in the players handCount
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCoins = G.coins;
				tempSupply = G.supplyCount[estate];
				baronEffect(1, &G);
				
				printf("Coin check = %d == %d", tempCoins, G.coins);
				assertEq(tempCoins, G.coins, failCounter, tmpResult);
				printf("Hand Increases Check = %d == %d", handCount+1, G.handCount[p]);
				assertEq(handCount+1, G.handCount[p], failCounter, tmpResult);
				printf("Estate supply decreases = %d == %d", tempSupply-1, G.supplyCount[estate]);
				assertEq(tempSupply-1, G.supplyCount[estate], failCounter, tmpResult);
				
				
			
			printf("\nTest player %d with %d cards and gaining an estate card with estate cards in supply.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				
				//set the supply deck to 5
				G.supplyCount[estate] = 5;
				tempCoins = G.coins;
				tempSupply = G.supplyCount[estate];
				baronEffect(0, &G);
				
				printf("Coin check = %d == %d", tempCoins, G.coins);
				assertEq(tempCoins, G.coins, failCounter, tmpResult);
				printf("Hand Increases Check = %d == %d", handCount+1, G.handCount[p]);
				assertEq(handCount+1, G.handCount[p], failCounter, tmpResult);
				printf("Estate supply decreases = %d == %d", tempSupply-1, G.supplyCount[estate]);
				assertEq(tempSupply-1, G.supplyCount[estate], failCounter, tmpResult);
				
				

			printf("\nTest player %d with %d cards and gaining an estate card with no estate cards in supply.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				tempCoins = G.coins;
				
				//set the supply deck to 0 to test for no supply cards
				G.supplyCount[estate] = 0;
				baronEffect(0, &G);
				
				printf("Coin is static = %d == %d", tempCoins, G.coins);
				assertEq(tempCoins, G.coins, failCounter, tmpResult);
				printf("Hand is static = %d == %d", handCount, G.handCount[p]);
				assertEq(handCount, G.handCount[p], failCounter, tmpResult);
				printf("Estate supply is static = %d == %d", 0, G.supplyCount[estate]);
				assertEq(0, G.supplyCount[estate], failCounter, tmpResult);
				
        }
    }
	if (failCounter == 0)	{
		printf("All tests passed!\n");
	}
	else	{
		printf("%f tests failed", failCounter);
	}

    return 0;
}


