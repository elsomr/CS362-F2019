/* -----------------------------------------------------------------------
 * Random Test for the Baron Card
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


int checkBaronCard(int choice1, int Numplayers, int p, struct gameState *post) {
    struct gameState pre;
	int failCounter = 0;
	int i;
	char* tmpResult;
    memcpy (&pre, post, sizeof(struct gameState));

    int r;
    // printf ("\nBaron Effect PRE: choice %d p %d Coins %d HC %d DiC %d\n",
    	  // choice1, p, pre.coins, pre.handCount[p], pre.discardCount[p]);

    r = baronCardEffect (choice1, post);

    // printf ("Baron Effect POST: chioce %d p %d Coins %d HC %d DiC %d\n",
    	  // choice1, p, post->coins, post->handCount[p], post->discardCount[p]);


	if (choice1 > 0)	{
		printf("\nCoin check = ");
		assertEq(pre.coins+4, post->coins, &failCounter, tmpResult);
		printf("Hand Increases Check = ");
		assertEq( pre.handCount[p]+1,  post->handCount[p], &failCounter, tmpResult);
		printf("Card is put in discard pile check = "); 
		assertEq(estate, post->discard[p][post->discardCount[p]], &failCounter, tmpResult);
		printf("Estate supply decreases = ");
		assertEq(pre.supplyCount[estate], post->supplyCount[estate], &failCounter, tmpResult);
		printf("Note: only one of the last two tests should pass\n");
		
		
	}
	else if (choice1 == 0)	{
		printf("Coin is static = ");
		assertEq(pre.coins, post->coins, &failCounter, tmpResult);
		printf("Hand is static = ");
		assertEq(pre.handCount[p], post->handCount[p], &failCounter, tmpResult);
		printf("Estate supply is static = ");
		assertEq(pre.supplyCount[estate], post->supplyCount[estate], &failCounter, tmpResult);
		
	}
	
	return failCounter;
}

int main () {
	srand(time(0));

    int i, j, it, n, r, p, deckCount, discardCount, handCount, choice1, numPlayers;
	int failCounter = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall
                };

    struct gameState G;
	

    printf ("Testing Baron Card.\n");

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 10000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = rand() * 256;
        }
		//pick a random choice (either 0 or 1)
		choice1 = rand() % 2;
		//pick a random number of player(between 2 - 4)
		numPlayers = rand() % 3 + 2;
		//pick a random player
        p = rand() % numPlayers;
		//pick random deck, discard, and handcount values
        G.deckCount[p] = rand() % MAX_DECK;
        G.discardCount[p] = rand() % MAX_DECK;
        G.handCount[p] = rand() % MAX_HAND;
		//get random coin amoint
		G.coins = 100;
		G.whoseTurn = p;
		G.supplyCount[estate] = rand() % 12;
		//randomly gain an estate card 50% of the time when the player has cards in their hand
		if ((rand() %2)  && G.handCount[p] != 0)	{
			G.hand[p][rand() % G.handCount[p]] = estate;
		}

		//call check function
		printf("\n++++++++++++++ TEST %d +++++++++++++\n", n);
        failCounter += checkBaronCard(choice1, numPlayers, p, &G);
    }

	if (failCounter == 0)	{
		printf ("ALL TESTS OK\n");
	}
	else	{
		printf( "%d TEST(s) FAILED\n", failCounter);
	}

    exit(0);

}
