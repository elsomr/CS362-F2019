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


int checkMinionCard(struct gameState *post, int handPos, int choice1, int choice2, int numPlayers, int p) {
    struct gameState pre;
	int failCounter = 0;
	int i;
	char* tmpResult;
    memcpy (&pre, post, sizeof(struct gameState));

    int r;
	int pre5Count=0;
	int post4Count=0;
	int pre4Count=0;
	int post5Count=0;
    printf ("Minion Effect PRE: choice1 %d choice2 %d p %d Coins %d Actions %d HC %d",
    	  choice1, p, pre.coins, pre.numActions, pre.handCount[p]);

    minionEffect (post, handPos, choice1, choice2);

    printf ("Minion Effect POST: chioce %d p %d Coins %d Actions %d HC %d\n\n\n",
    	  choice1, p, post->coins, post->numActions, post->handCount[p]);


	//get number of players with more than 5 cards or 4 cards both pre and post
	for (i = 0; i < numPlayers; i++)	{
		if (pre.handCount[i] >= 5)	{
			pre5Count++;
		}
		if (pre.handCount[i] == 4)	{
			pre4Count++;
		}
		if (post->handCount[i] == 4)	{
			post4Count++;
		}
		if (post->handCount[i] >= 5)	{
			post5Count++;
		}
	}
		
	if (choice1 > 0)	{

		printf("Coins increased = ");
		assertEq(pre.coins+2, post->coins, &failCounter, tmpResult);
		printf("Actions increase = ");
		assertEq( pre.numActions + 1,  post->numActions, &failCounter, tmpResult);
		printf("Card count is static = "); 
		assertEq(pre.handCount[p], post->handCount[p], &failCounter, tmpResult);
		printf("Players with 5 cards did not discard = %d < %d", pre5Count, post5Count);
		assertEq(pre5Count, post5Count, &failCounter, tmpResult);
		printf("Players with 4 cards stayed the same = ");
		assertEq(pre4Count, post4Count, &failCounter, tmpResult);
		
	}
	else if (choice2 > 0)	{
		printf("Coins static = ");
		assertEq(pre.coins, post->coins, &failCounter, tmpResult);
		printf("Actions increase = ");
		assertEq( pre.numActions + 1,  post->numActions, &failCounter, tmpResult);
		printf("Card count is static = "); 
		assertEq(pre.handCount[p], post->handCount[p], &failCounter, tmpResult);
		printf("Players with 5 cards discarded and now have 4 = %d < %d", pre5Count, post5Count);
		assertEq(post4Count, pre5Count + pre4Count, &failCounter, tmpResult);
		printf("No players with more than 5 cards = 0 == %d", post5Count);
		assertEq(0, post5Count, &failCounter, tmpResult);
		
	}
	
	return failCounter;
}

int main () {
	srand(time(0));

    int i, j, it, n, r, p, deckCount, discardCount, handCount, choice1, choice2, numPlayers, handPos;
	int failCounter = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    struct gameState G;
	

    printf ("Testing Baron Card.\n");

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() * 256;
        }
		//pick a random choices (either 0 or 1)
		choice1 = rand() % 2;
		choice2 = rand() % 2;
		//pick a random number of player(between 2 - 4)
		numPlayers = rand() % 3 + 2;
		//pick a random player
        p = rand() % numPlayers;
		//pick random deck, discard, and handcount values
		for (j = 0; j < numPlayers; j++)	{
			G.deckCount[j] = rand() % MAX_DECK;
			G.discardCount[j] = rand() % MAX_DECK;
			G.handCount[j] = rand() % MAX_HAND;
		}

		//set action amount
		G.numActions = rand() % 100;
		//set coin amoint
		G.coins = rand() % 1000;
		//store whose turn it is
		G.whoseTurn = p;
		//get random hand position
		if (G.handCount[p] > 0)	{
			handPos = rand() % G.handCount[p];
		}
		else	{
			handPos = 0;
		}

		//call check function
        failCounter += checkMinionCard(&G, handPos, choice1, choice2, numPlayers, p);
    }

	if (failCounter == 0)	{
		printf ("ALL TESTS OK\n");
	}
	else	{
		printf( "%d TEST(s) FAILED\n", failCounter);
	}

    exit(0);

}
