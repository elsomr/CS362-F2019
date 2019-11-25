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
	int pre4Count, post4Count, postPlayCount, preCards, postCards;
    int k[10] = {adventurer, council_room, estate, gardens, mine
               , remodel, ambassador, village, baron, great_hall};

    struct gameState G;
    int maxHandCount = 8;
	int counter = 0;
	int* failCounter = &counter;
	char tmpResult[5];
	int nextPlayer;
	

	int estates[MAX_HAND];
	int coppers[MAX_HAND];
	int minions[MAX_HAND];
	
	for (i = 0; i < MAX_HAND; i++)	{
		estates[i] = estate;
		coppers[i] = copper;
		minions[i] = minion;
	}
	
    printf ("TESTING tributeCardEffect():\n");


    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
			

			printf("\nTest player %d with %d cards and player on left has 2 treasure cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.handCount[nextPlayer] = handCount;

				memcpy(G.hand[nextPlayer], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempCoins = G.coins;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 2 cards = %d == %d", tempCards-2, G.handCount[nextPlayer]);
				assertEq(tempCards-2, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains coins = %d == %d", tempCoins + 4, G.coins);
				assertEq(tempCoins + 4, G.coins, failCounter, tmpResult);
				
				
			
			
			printf("\nTest player %d with %d cards and player on left has 2 action cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.handCount[nextPlayer] = handCount;

				memcpy(G.hand[nextPlayer], minions, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempActions = G.numActions;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 2 cards = %d == %d", tempCards-2, G.handCount[nextPlayer]);
				assertEq(tempCards-2, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains actions = %d == %d", tempActions + 4, G.numActions);
				assertEq(tempActions + 4, G.numActions, failCounter, tmpResult);
				
			printf("\nTest player %d with %d cards and player on left has 2 victory cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.handCount[nextPlayer] = handCount;

				memcpy(G.hand[nextPlayer], minions, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				preCards = G.handCount[p];
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 2 cards = %d == %d", tempCards-2, G.handCount[nextPlayer]);
				assertEq(tempCards-2, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains 4 cards = %d == %d", preCards + 4, G.handCount[p]);
				assertEq(preCards + 4, G.handCount[p], failCounter, tmpResult);
		
		
			printf("\nTest player %d with %d cards and player on left has 1 card in discard pile.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.deckCount[nextPlayer] = 0;
				G.discardCount[nextPlayer] = 1;

				memcpy(G.hand[nextPlayer], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempCoins = G.coins;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 1 card = %d == %d", tempCards-1, G.handCount[nextPlayer]);
				assertEq(tempCards-1, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains coins = %d == %d", tempCoins+ 2, G.coins);
				assertEq(tempCoins + 2, G.coins, failCounter, tmpResult);
		
			printf("\nTest player %d with %d cards and player on left has 1 card in deck pile.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.deckCount[nextPlayer] = 1;
				G.discardCount[nextPlayer] = 0;

				memcpy(G.hand[nextPlayer], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempCoins = G.coins;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 1 card = %d == %d", tempCards-1, G.handCount[nextPlayer]);
				assertEq(tempCards-1, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains coins = %d == %d", tempCoins + 2, G.coins);
				assertEq(tempCoins + 2, G.coins, failCounter, tmpResult);
			
			printf("\nTest player %d with %d cards and player on left has 0 cards.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.deckCount[nextPlayer] = 0;
				G.discardCount[nextPlayer] = 1;

				memcpy(G.hand[nextPlayer], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempCoins = G.coins;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 0 cards = %d == %d", tempCards, G.handCount[nextPlayer]);
				assertEq(tempCards-1, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player does not gain coins = %d == %d", tempCoins, G.coins);
				assertEq(tempCoins, G.coins, failCounter, tmpResult);
				
				
			printf("\nTest player %d with %d cards and player on left has 0 cards in deck pile.\n", p, handCount);
				memset(&G, 23, sizeof(struct gameState));   // clear the game state
				r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
				
				if (p < (numPlayer - 1)) {
					nextPlayer = p + 1;//Still safe to increment
				}
				else {
					nextPlayer = 0;//Max player has been reached, loop back around to player 1
				}
				G.handCount[p] = handCount;                 // set the number of cards on
				G.deckCount[nextPlayer] = 0;
				G.discardCount[nextPlayer] = 5;

				memcpy(G.hand[nextPlayer], coppers, sizeof(int) * handCount); 
				
				tempCards = G.handCount[nextPlayer];
				tempCoins = G.coins;
				
				
				tributeCardEffect(p, &G);
				
				printf("Player on left loses 1 card = %d == %d", tempCards-1, G.handCount[nextPlayer]);
				assertEq(tempCards-1, G.handCount[nextPlayer], failCounter, tmpResult);
				printf("Player gains coins = %d == %d", tempCoins + 2, G.coins);
				assertEq(tempCoins + 2, G.coins, failCounter, tmpResult);
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


