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
	int pre4Count, post4Count, postPlayCount;
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, ambassador, village, baron, great_hall};

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
				tempSupply = G.supplyCount[copper];
				
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
				printf("Card is added to supply pile = %d == %d", tempSupply - 0, G.supplyCount[copper]);
				assertEq(tempSupply-0, G.supplyCount[copper], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResult);
				}

				
				
			
			
			printf("\nTest player %d with %d cards and chooses to lose 1 card.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[copper];
				
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
				printf("Card is added to supply pile = %d == %d", tempSupply - 1, G.supplyCount[copper]);
				assertEq(tempSupply-1, G.supplyCount[copper], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResult);
				}
				
				
			printf("\nTest player %d with %d cards and chooses to lose 2 cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[copper];
				
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
				printf("Card is added to supply pile = %d == %d", tempSupply - 2, G.supplyCount[copper]);
				assertEq(tempSupply-2, G.supplyCount[copper], failCounter, tmpResult);
				printf("Each player gained the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i]+1, postPlayCardCount[i]);
					assertEq(prePlayCardCount[i]+1, postPlayCardCount[i], failCounter, tmpResult);
				}

			printf("\nTest player %d with %d cards and chooses to lose more cards than they have.\n", p, handCount);

				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				//make hand have all estates
				memcpy(G.hand[p], estates, sizeof(int) * handCount); 
				
				printf("PASS\n\n\n");
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[copper];
				
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
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is not discarded = %d == %d", tempCards, G.handCount[p]);
				assertEq(tempCards, G.handCount[p], failCounter, tmpResult);
				printf("Card is not added to supply pile = %d == %d", tempSupply, G.supplyCount[copper]);
				assertEq(tempSupply, G.supplyCount[copper], failCounter, tmpResult);
				printf("Each player did not gain the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i], postPlayCardCount[i]);
					assertEq(prePlayCardCount[i], postPlayCardCount[i], failCounter, tmpResult);
				}
			printf("\nTest player %d with %d cards and chooses to discard an invalid amount.\n", p, handCount);

				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				

				memset(prePlayCardCount, 0, numPlayer);
				memset(postPlayCardCount, 0, numPlayer);
				//make hand have all estates
				memcpy(G.hand[p], estates, sizeof(int) * handCount); 
				
				tempCards = G.handCount[p];
				tempSupply = G.supplyCount[copper];
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i!=p && G.hand[i][j] == copper)	{
							prePlayCardCount[i]++;
						}
					}
				}
				
				ambassadorEffect(copper, 5, &G, 0);
				
				//count number of cards all other players have
				for (i = 0; i < numPlayer; i++)	{
					for (j = 0; j < handCount; j++)	{
						if (i != p && G.hand[i][j] == copper)	{
							postPlayCardCount[i]++;
							postPlayCardCount[i]++;
						}
					}
				}
				
				printf("Card is not discarded = %d == %d", tempCards, G.handCount[p]);
				assertEq(tempCards, G.handCount[p], failCounter, tmpResult);
				printf("Card is not added to supply pile = %d == %d", tempSupply, G.supplyCount[copper]);
				assertEq(tempSupply, G.supplyCount[copper], failCounter, tmpResult);
				printf("Each player did not gain the shown card");
				for (i=0; i< numPlayer; i++)	{
					printf("Player %d: %d == %d", i, prePlayCardCount[i], postPlayCardCount[i]);
					assertEq(prePlayCardCount[i], postPlayCardCount[i], failCounter, tmpResult);
				}
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


