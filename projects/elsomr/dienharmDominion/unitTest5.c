/* -----------------------------------------------------------------------
 * Unit test for Ambassador Effect functions for Assignment 3
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

    int i, j;
    int seed = 1000;
    int numPlayer = 4;
    int p, handCount, r;
	int tempCoins, tempSupply, tempActions, tempPlayCount, tempCards;
	int prePlayCardCount[numPlayer];
	int postPlayCardCount[numPlayer];
	int preSilverCount, preGoldCount, preCopperCount;
	int postSilverCount, postGoldCount, postCopperCount;
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, ambassador, village, baron, great_hall};

    struct gameState G;
    int maxHandCount = 8;
	int counter = 0;
	int* failCounter = &counter;
	char tmpResult[5];
	

	int estates[MAX_HAND];
	int coppers[MAX_HAND];
	int golds[MAX_HAND];
	int silvers[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++)	{
		golds[i] = gold;
		silvers[i] = silver;
		coppers[i] = copper;
	}
	
    printf ("TESTING mineCardEffect():\n");

    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			

			printf("\nTest player %d with %d cards and chooses to upgrade a copper card to silver.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				preCopperCount = 0;
				preSilverCount = 0;
				postCopperCount = 0;
				postSilverCount = 0;
				preGoldCount = 0;
				postGoldCount=0;
				
				tempCards = G.handCount[p];
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == copper)	{
						preCopperCount++;
					}
					else if (G.hand[p][i] == silver)	{
						preSilverCount++;
					}
				}
				
				mineCardEffect( 0, silver, p, &G,0);
				
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == copper)	{
						postCopperCount++;
					}
					else if (G.hand[p][i] == silver)	{
						postSilverCount++;
					}
				}
				
				printf("One less copper card = %d == %d", preCopperCount-1, postCopperCount);
				assertEq(preCopperCount-1, postCopperCount, failCounter, tmpResult);
				printf("One extra silver card = %d == %d", preSilverCount-1, postSilverCount);
				assertEq(preSilverCount, postSilverCount, failCounter, tmpResult);

				
				
			
			
			printf("\nTest player %d with %d cards and upgrades silver to gold.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memcpy(G.hand[p], silvers, sizeof(int) * handCount); 
				preCopperCount = 0;
				preSilverCount = 0;
				postCopperCount = 0;
				postSilverCount = 0;
				preGoldCount = 0;
				postGoldCount=0;
				
				tempCards = G.handCount[p];
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == silver)	{
						preSilverCount++;
					}
					else if (G.hand[p][i] == gold)	{
						preGoldCount++;
					}
				}
				
				mineCardEffect( 0, gold, p, &G,0);
				
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == silver)	{
						postSilverCount++;
					}
					else if (G.hand[p][i] == gold)	{
						postGoldCount++;
					}
				}
				
				printf("One less silver card = %d == %d", preSilverCount-1, postSilverCount);
				assertEq(preSilverCount-1, postSilverCount, failCounter, tmpResult);
				printf("One extra gold card = %d == %d", preGoldCount-1, postGoldCount);
				assertEq(preGoldCount-1, postGoldCount, failCounter, tmpResult);

				
			printf("\nTest player %d with %d cards and upgrades copper to gold.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				preCopperCount = 0;
				preSilverCount = 0;
				postCopperCount = 0;
				postSilverCount = 0;
				preGoldCount = 0;
				postGoldCount=0;
				
				tempCards = G.handCount[p];
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == silver)	{
						preCopperCount++;
					}
					else if (G.hand[p][i] == gold)	{
						preGoldCount++;
					}
				}
				
				mineCardEffect(0, gold, p, &G,0);
				
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == copper)	{
						postCopperCount++;
					}
					else if (G.hand[p][i] == gold)	{
						postGoldCount++;
					}
				}
				
				printf("Same amount of copper cards = %d == %d", preCopperCount, postSilverCount);
				assertEq(preCopperCount, postSilverCount, failCounter, tmpResult);
				printf("Same amount of gold card = %d == %d", preGoldCount, postGoldCount);
				assertEq(preGoldCount, postGoldCount, failCounter, tmpResult);
			
			printf("\nTest player %d with %d cards and upgrades silver to invalid card.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memcpy(G.hand[p], silvers, sizeof(int) * handCount); 
				preCopperCount = 0;
				preSilverCount = 0;
				postCopperCount = 0;
				postSilverCount = 0;
				preGoldCount = 0;
				postGoldCount=0;
				
				tempCards = G.handCount[p];
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == silver)	{
						preSilverCount++;
					}
					else if (G.hand[p][i] == estate)	{
						preGoldCount++;
					}
				}
				
				mineCardEffect( 0, estate, p, &G,0);
				
				for (i=0; i < G.handCount[p]; i++)	{
					if (G.hand[p][i] == silver)	{
						postSilverCount++;
					}
					else if (G.hand[p][i] == estate)	{
						postGoldCount++;
					}
				}
				
				printf("Same amount of Silver = %d == %d", preSilverCount, postSilverCount);
				assertEq(preSilverCount, postSilverCount, failCounter, tmpResult);
				printf("Same amount of estate = %d == %d", preGoldCount, postGoldCount);
				assertEq(preGoldCount, postGoldCount, failCounter, tmpResult);
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


