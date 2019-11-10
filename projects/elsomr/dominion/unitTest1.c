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
#include "assert.c"
#include "rngs.h"



int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxEstate = 10;
    int p, r, handCount;
	int tempCoins, tempSupply;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
	int failCounter = 0;
	
	
	
	int estate[MAX_HAND];
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
			
			printf("Test player %d with %d cards and discarding an estate for coins.\n", p, handCount);

				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 				
				
				//add esate card to handCount
				gainCard(estate, G, 0, p);
				tempCoins = G.coins;
				
				//try to discard
				baronEffect(1, G);
				printf("Coin check = %s\n", assert(tempCoins+4, G.coins, failCounter));
				printf("Hand Descreases check = %s\n", assert(handCount-1, G->handCount[p], failCounter));
				printf("Card is put in discard pile check = %s\n", assert(estate, G->disard[p][G->discardCount[p]], failCount));
			
			
			printf("Test player %d with %d cards and discarding an estate for coins without an estate card.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				
				tempCoins = G.coins;
				//set all the cards to copper so no estate cards are in the players handCount
				memcpy(G.hand[p], coppers, sizeof(int) * handCount); 
				baronEffect(1, G);
				printf("Coin check = %s\n", assert(tempCoins, G.coins, failCounter));
				printf("Hand Increases Check = %s\n", assert(handCount+1, G->handCount[p], failCounter));
				printf("Estate Card is added to players hand = %s\n", assert(estate, G->deck[p][G->deckCount[p]], failCount));
				printf("Estate supply decreases = %s\n", assert(tempSupply-1, G->supplyCount[estate], failCounter));
				
			
			printf("Test player %d with %d cards and gaining an estate card with estate cards in supply.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				
				//set the supply deck to 5
				G->supplyCount[estate] = 5;
				tempCoins = G.coins;
				tempSupply = G->supplyCount[estate];
				baronEffect(0, G);
				
				printf("Coin check = %s\n", assert(tempCoins, G.coins, failCounter));
				printf("Hand Increases Check = %s\n", assert(handCount+1, G->handCount[p], failCounter));
				printf("Estate Card is added to players hand = %s\n", assert(estate, G->deck[p][G->deckCount[p]], failCount));
				printf("Estate supply decreases = %s\n", assert(tempSupply-1, G->supplyCount[estate], failCounter));
				

			printf("Test player %d with %d cards and gaining an estate card with no estate cards in supply.\n", p, handCount);
			
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				G.handCount[p] = handCount;                 // set the number of cards on 			
				tempCoins = G.coins;
				
				//set the supply deck to 0 to test for no supply cards
				G->supplyCount[estate] = 0;
				baronEffect(0, G);
				
				printf("Coin is static = %s\n", assert(tempCoins, G.coins, failCounter));
				printf("Hand is static = %s\n", assert(handCount, G->handCount[p], failCounter));
				printf("Estate supply is static = %s\n", assert(0, G->supplyCount[estate], failCounter));
				printf("Estate supply is static = %s\n", assert(0, G->supplyCount[estate], failCounter));
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


