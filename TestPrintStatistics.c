/*
 * main file for testing PrintStatistics()
 * EAS 240 Multi-armed bandit project
 * EAS 240 Introduction to Programming for Engineers
 * Authors: Anjali Omer and Nick Mastronarde
 *
 * Note: arms[] is initialized randomly to test PrintStatistics()
 */
#include <stdio.h>
#include <stdlib.h>
#include "bandit.h"

int main() {
   const int numArms = 5;
   int seed;

   Arm arms[numArms]; // Array of Arm structs

   printf("Enter random seed:\n");
   scanf("%d", &seed);

   /* Seed the random number generator */
   srand(seed);

   /* Initialize each arm randomly */
   for (int i = 0; i < numArms; i++) {
      arms[i].sumReward = rand() % 1000 + ((double) rand() / RAND_MAX);
      arms[i].count = rand() % 100 + ((double) rand() / RAND_MAX);
      arms[i].estValue = arms[i].sumReward / arms[i].count;
      arms[i].value = ((double) rand() / RAND_MAX) * 10;
      arms[i].UCB = 0.0; // Initialize UCB to 0
      arms[i].rewardStdDev = 0.0; // Initialize rewardStdDev to 0
   }

   /* Print simulation statistics to console */
   PrintStatistics(arms, numArms);

   return 0;
}