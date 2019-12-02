// bug9_unit.c
// This program performs unit testing on the cardEffect() function for the
// Tribute card per Bug #9.
//
// Author: Robert Elsom
// Date: 12-2-2019

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void custom_assert(int condition) {
   if (condition) {
      printf("PASSED\n");
   } else {
      printf("FAILED\n");
   }

   return;
}

int main() {
   // set up card array
   int k[10] = { adventurer, council_room, feast, gardens, baron,
                 remodel, smithy, village, mine, great_hall };

   // declare the game state
   struct gameState G;

   printf("Begin testing the tribute card within cardEffect():\n");

   // set up the game state for testing
   int seed = 5; // arbitrary seed for RNG
   G.whoseTurn = 0; //player 1 is the current player
   int player = G.whoseTurn;
   int bonus = 0;
   int handCount;
   
   // set up test-specific conditions
   
   // player attempts to trash a copper card and gain a silver card
   printf(" -- Testing Bug #9 --\n");
   initializeGame(2, k, seed, &G);
   G.handCount[player] = 2;
   G.hand[player][0] = tribute;
   G.hand[player][1] = copper;
   handCount = G.handCount[player];
   //initialize next players hand
   G.handCount[player+1] = 2;
   G.hand[player+1][0] = copper;
   G.hand[player+1][1] = copper;
   G.coins = 0;
   G.numActions = 2;

   cardEffect(tribute, copper, silver, 0, &G, 0, &bonus);

   // show test result
   printf("Checking if Player 1's coins have increased by 4: %d = 4", G.coins);
   custom_assert(G.coins == 4);
   printf("Checking if Player 1's number of cards have decreased by 1 %d = %d", G.handCount[player], handCount);
   custom_assert(G.handCount[player] == handCount - 1);


   printf("Testing completed.\n");

   return 0;
}