/* -----------------------------------------------------------------------
 * Random Test for the Minion Card
 * 
 * Note: Using code and code structure from testdrawcard.c in dominion files
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "assertEq.h"
#include "rngs.h"
#include <time.h>


int checkTributeCard(struct gameState *post, int numPlayers, int p, int nextPlayer) {
    struct gameState pre;
	int failCounter = 0;
	int j;
	char* tmpResult;
	int treasureCount = 0;
	int victoryCount = 0;
	int actionCount = 0;
	int tributeCards[2];
	
	
	
    memcpy (&pre, post, sizeof(struct gameState));

    // printf ("Tribute Effect PRE: choice1 %d choice2 %d p %d Coins %d Actions %d HC %d",
    	  // choice1, p, pre.coins, pre.numActions, pre.handCount[p]);
	//get tribute cards
	if (pre.discardCount[nextPlayer] + pre.deckCount[nextPlayer] <= 1)	{
		if (pre.deckCount[nextPlayer] > 0)	{
			tributeCards[0] = pre.deck[nextPlayer][pre.deckCount[nextPlayer]-1];
		else if (pre.discardCount[nextPlayer] > 0)	{
			tributeCards[c] = pre.discard[nextPlayer][pre.discardCount[nextPlayer]-1];
		}
	
	else	{
		tributeCards[0] = pre.deck[nextPlayer][pre.deckCount[nextPlayer]-1];
		tributeCards[1] = pre.deck[nextPlayer][pre.deckCount[nextPlayer]-2];
	}
	
	printf("Tribute Cards %d %d\n\n", post->deck[nextPlayer][post->deckCount[nextPlayer]-1], post->deck[nextPlayer][post->deckCount[nextPlayer]-2]);

    tributeEffect (post);

    // printf ("Tribute Effect POST: chioce %d p %d Coins %d Actions %d HC %d\n\n\n",
    	  // choice1, p, post->coins, post->numActions, post->handCount[p]);

	
	
	
	//count post treasure, action, and victory cards
	for (j=0; j < 2; j++)	{
		//4-6
		if (tributeCards[i] == copper || tributeCards[i] == silver ||  tributeCards[i] == gold)	{
			treasureCount++;
		}
		
		//1-3, 10, 16
		else if ( tributeCards[i] == estate ||  tributeCards[i] == duchy || tributeCards[i] == province\
		||  tributeCards[i] == gardens ||  tributeCards[i] == great_hall)	{
			victoryCount++;
		}	
		else {
			actionCount++;
		}
	}
	printf("\nTreasure %d, Action %d, Victory %d\n", treasureCount, actionCount, victoryCount);

	//if a treasure was taken out of next players hand
	if (treasureCount > 0)	{
		printf("\n%d Treasure Card(s) were Revealed", treasureCount);
		printf("\nCoins increased = ");
		assertEq(pre.coins+ (treasureCount*2), post->coins, &failCounter, tmpResult);
		printf("Actions increase = ");
		assertEq( pre.numActions + (treasureCount * 2),  post->numActions, &failCounter, tmpResult);
		printf("Next player hand decreased by number of treasure cards revealed= "); 
		assertEq(pre.handCount[nextPlayer] - treasureCount, post->handCount[nextPlayer], &failCounter, tmpResult);
		
		
	}
	//if an action card was revealed
	if (actionCount > 0)	{
		printf("\n%d Action Card(s) were Revealed", actionCount);
		printf("\nCoins static = ");
		assertEq(pre.coins, post->coins, &failCounter, tmpResult);
		printf("Actions increase = ");
		assertEq( pre.numActions + ((actionCount) * 2),  post->numActions, &failCounter, tmpResult);
		printf("Next player hand decreased by number of action cards revealed= "); 
		assertEq(pre.handCount[nextPlayer] - (actionCount), post->handCount[nextPlayer], &failCounter, tmpResult);
		
	}
	//if a victory card was revealed
	if (victoryCount > 0)	{
		printf("\n%d Victory Card(s) were Revealed", victoryCount);
		printf("\nCoins static = ");
		assertEq(pre.coins, post->coins, &failCounter, tmpResult);
		printf("Actions increase = ");
		assertEq( pre.numActions + (victoryCount) * 2,  post->numActions, &failCounter, tmpResult);
		printf("Current Player gains cards = ");
		assertEq(pre.handCount[p] + ((victoryCount) * 2), post->handCount[p], &failCounter, tmpResult);
		printf("Next player hand decreased by number of victory cards revealed= "); 
		assertEq(pre.handCount[nextPlayer] - (victoryCount), post->handCount[nextPlayer], &failCounter, tmpResult);
	}
	return failCounter;
}

int main () {
	srand(time(0));

    int i, j, n, p, numPlayers, nextPlayer, index;
	int failCounter = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    struct gameState G;
	

    printf ("Testing TributeS Card.\n");

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 10000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() * 256;
        }
		//pick a random number of player(between 2 - 4)
		numPlayers = rand() % 3 + 2;
		//pick a random player
        p = rand() % numPlayers;
		
		//get next player position
		if (p < (numPlayers - 1)) {
			nextPlayer = p + 1;
		}
		else {
			nextPlayer = 0;
		}
		//pick random deck, discard, and handcount values for all players
		for (j = 0; j < numPlayers; j++)	{
			G.deckCount[j] = rand() % MAX_DECK;
			G.discardCount[j] = rand() % MAX_DECK;
			G.handCount[j] = rand() % MAX_HAND;
		}
		
		//set coin amount
		G.coins = rand() % 1000;
		//store whose turn it is
		G.whoseTurn = p;
		G.numPlayers = numPlayers;
		//store random cards in nextPlayers hand
		for (j=0; j < G.deckCount[nextPlayer] ; j++)	{
			index = rand() % 10;
			G.deck[nextPlayer][j] = rand() % 20;
		}

		//call check function
		printf("\n++++++++++++++ TEST %d +++++++++++++\n", n);
        failCounter += checkTributeCard(&G, numPlayers, p, nextPlayer);
    }

	if (failCounter == 0)	{
		printf ("ALL TESTS OK\n");
	}
	else	{
		printf( "%d TEST(s) FAILED\n", failCounter);
	}

    exit(0);

}
