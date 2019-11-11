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
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    struct gameState G;
    int maxHandCount = 8;
	int counter = 0;
	int* failCounter = &counter;
	char tmpResult[5];
	

	int estates[MAX_HAND];
	int coppers[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++)	{
		estates[i] = estate;
		coppers[i] = copper;
	}
	
    printf ("TESTING ambassadorEffect():\n");
	
    printf ("TESTING minionEffect():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			
			printf("\nTest player %d with %d cards and chooses to lose 0 cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[G.hand[p][copper]];
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i!=p && G.hand[i][j] == copper)	{
							prePlayCardCount[i]++;
						}
					}
				}
				
				ambassadorEffect(copper, 0, &G, 0);
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i != p && G.hand[i][j] == copper)	{
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is discarded = %d == %d", tempCards-0, G.handCount[p]);
				assertEq(tempCards-0, G.handCount[p], failCounter, tmpResult);
				printf("Card is added to supply pile = %d == %d", tempSupply - 0, G.supplyCount[G.hand[p][copper]]);
				assertEq(tempSupply-0, G.supplyCount[G.hand[p][copper]], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResults);
				}

				
				
			
			
			printf("\nTest player %d with %d cards and chooses to lose 1 card.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[G.hand[p][copper]];
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i!=p && G.hand[i][j] == copper)	{
							prePlayCardCount[i]++;
						}
					}
				}
				
				ambassadorEffect(copper, 1, &G, 0);
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i != p && G.hand[i][j] == copper)	{
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is discarded = %d == %d", tempCards-1, G.handCount[p]);
				assertEq(tempCards-1, G.handCount[p], failCounter, tmpResult);
				printf("Card is added to supply pile = %d == %d", tempSupply - 1, G.supplyCount[G.hand[p][copper]]);
				assertEq(tempSupply-1, G.supplyCount[G.hand[p][copper]], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResults);
				}
				
				
			printf("\nTest player %d with %d cards and chooses to lose 2 cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[G.hand[p][copper]];
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i!=p && G.hand[i][j] == copper)	{
							prePlayCardCount[i]++;
						}
					}
				}
				
				ambassadorEffect(copper, 2, &G, 0);
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i != p && G.hand[i][j] == copper)	{
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is discarded = %d == %d", tempCards-2, G.handCount[p]);
				assertEq(tempCards-2, G.handCount[p], failCounter, tmpResult);
				printf("Card is added to supply pile = %d == %d", tempSupply - 2, G.supplyCount[G.hand[p][copper]]);
				assertEq(tempSupply-2, G.supplyCount[G.hand[p][copper]], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResults);
				}

			printf("\nTest player %d with %d cards and chooses to lose more cards than they have.\n", p, handCount);

				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				//make hand have all estates
				memcpy(G.hand[p], estates, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[G.hand[p][copper]];
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i!=p && G.hand[i][j] == copper)	{
							prePlayCardCount[i]++;
						}
					}
				}
				
				ambassadorEffect(coppers, 2, &G, 0);
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i != p && G.hand[i][j] == copper)	{
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is not discarded = %d == %d", tempCards, G.handCount[p]);
				assertEq(tempCards, G.handCount[p], failCounter, tmpResult);
				printf("Card is not added to supply pile = %d == %d", tempSupply, G.supplyCount[G.hand[p][copper]]);
				assertEq(tempSupply, G.supplyCount[G.hand[p][copper]], failCounter, tmpResult);
				printf("Each player did not gain the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i], postPlayCardCount[i]);
					assertEq(prePlayCardCount[i], postPlayCardCount[i], failCounter, tmpResults);
				}
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


