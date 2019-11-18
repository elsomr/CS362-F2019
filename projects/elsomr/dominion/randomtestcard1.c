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


int checkBaronCard(int choice1, int Numplayers, int p, struct gameState *post) {
    struct gameState pre;
	int failCounter = 0;
	char* tmpResult;
    memcpy (&pre, post, sizeof(struct gameState));

    int r;
     printf ("Baron Effect PRE: p %d Coins %d HC %d DiC %d\n",
    	  p, pre.coins, pre.handCount[p], pre.discardCount[p]);

    r = baronEffect (choice1, post);

    printf ("Baron Effect POST: p %d Coins %d HC %d DiC %d\n\n\n",
    	  p, post->handCount, post->handCount[p], post->discardCount[p]);

	if (choice1 > 0)	{
		printf("Coin check = ");
		assertEq(pre.coins, post->coins, &failCounter, tmpResult);
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

    int i, n, r, p, deckCount, discardCount, handCount, choice1, numPlayers;
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
            ((char*)&G)[i] = floor(Random() * 256);
        }
		//pick a random choice (either 0 or 1)
		choice1 = (int)floor(Random()) % 2;
		//pick a random number of player(between 2 - 4)
		numPlayers = (int)floor(Random()) % 3 + 2;
		//pick a random player
        p = (int)floor(Random()) % numPlayers;
		//pick random deck, discard, and handcount values
        G.deckCount[p] = (int)floor(Random()) % MAX_DECK;
        G.discardCount[p] = (int)floor(Random()) % MAX_DECK;
        G.handCount[p] = (int)floor(Random()) % MAX_HAND;
		//get random coin amoint
		G.coins = (int)Random() % 1000000;
		//call check function
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