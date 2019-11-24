/* -----------------------------------------------------------------------
 * Unit test for Minion Effect functions for Assignment 3
 *
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "assertEq.h"
#include "rngs.h"


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 4;
    int p, handCount, r;
	int tempCoins, tempActions;
	int pre4Count, tempPlayCount, post4Count, postPlayCount;
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 8;
	int counter = 0;
	int* failCounter = &counter;
	char tmpResult[5];
	
	
    printf ("TESTING minionEffect():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			
			printf("\nTest player %d with %d cards and chooses to gain 2 coins.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				
				tempCoins = G.coins;
				tempActions = G.numActions;
				
				tempPlayCount = 0;
				pre4Count = 0;
				post4Count = 0;
				postPlayCount = 0;
				
				//gain a minion card
				gainCard(minion, &G, 2, p);
				
				//get number of other players with more than 5 cards
				for (i = 0; i < numPlayer; i++)	{
					if (G.handCount[i] >= 5)	{
						tempPlayCount++;
					}
					if (G.handCount[i] == 4)	{
						pre4Count++;
					}
				}
				
				//gaining coins
				minionEffect(&G, handCount, 1, 0);
				
				printf("Coin check = %d == %d", tempCoins+2, G.coins);
				assertEq(tempCoins+2, G.coins, failCounter, tmpResult);
				printf("Action Check = %d == %d", tempActions+1, G.numActions);
				assertEq(tempActions+1, G.numActions, failCounter, tmpResult);
				printf("4 cards were drawn = %d == %d", 4, G.handCount[p]);
				assertEq(4, G.handCount[p], failCounter, tmpResult);
				
				//all players with more than 5 cards discard to 4
				//get number of players with more than 5 cards
				for (i = 0; i < numPlayer; i++)	{
					if (G.handCount[i] >= 5)	{
						postPlayCount++;
					}
					if (G.handCount[i] == 4)	{
						post4Count++;
					}
				}
				//get number of players now with 4 cards (greater than or eq # w/5)
				printf("Players with 5 cards discarded = %d < %d", pre4Count, postPlayCount);
				printf("No players with more than 5 cards = 0 == %d", postPlayCount);
				assertEq(tempPlayCount, postPlayCount, failCounter, tmpResult);
				
			
			
			printf("\nTest player %d with %d cards chooses to discard hand.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				
				tempCoins = G.coins;
				tempActions = G.numActions;
				tempPlayCount = 0;
				pre4Count = 0;
				post4Count = 0;
				postPlayCount = 0;
				
				//gain a minion card
				gainCard(minion, &G, 2, p);
				
				//get number of other players with more than 5 cards
				for (i = 0; i < numPlayer; i++)	{
					if (G.handCount[i] >= 5)	{
						tempPlayCount++;
					}
					if (G.handCount[i] == 4)	{
						pre4Count++;
					}
				}
				
				minionEffect(&G, handCount, 0, 1);
				
				printf("Coin check = %d == %d", tempCoins+2, G.coins);
				assertEq(tempCoins+2, G.coins, failCounter, tmpResult);
				printf("Action Check = %d == %d", tempActions+1, G.numActions);
				assertEq(tempActions+1, G.numActions, failCounter, tmpResult);
				printf("4 cards were drawn = %d == %d", 4, G.handCount[p]);
				assertEq(4, G.handCount[p], failCounter, tmpResult);
				
				//all players with more than 5 cards discard to 4
				//get number of players with more than 5 cards
				for (i = 0; i < numPlayer; i++)	{
					if (G.handCount[i] >= 5)	{
						postPlayCount++;
					}
					if (G.handCount[i] == 4)	{
						post4Count++;
					}
				}
				//get number of players now with 4 cards (greater than or eq # w/5)
				printf("Players with 5 cards discarded = %d < %d\n", pre4Count, postPlayCount);
				printf("No players with more than 5 cards = %d == %d", 0, postPlayCount);
				assertEq(tempPlayCount, postPlayCount, failCounter, tmpResult);
				
        }
    }
	if (failCounter == 0)	{
		printf("All tests passed!\n");
	}
	else	{
		printf("%d tests failed", *failCounter);
	}

    return 0;
}


