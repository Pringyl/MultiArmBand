/*
 * main file for testing SelectArm()
 * EAS 240 Multi-armed bandit project
 * EAS 240 Introduction to Programming for Engineers
 * Authors: Anjali Omer and Nick Mastronarde
 *
 * Note: arms[] is initialized randomly to test SelectArm()
 */
#include <stdio.h>
#include <stdlib.h>
#include "bandit.h"

int main() {
   const int numArms = 5;
   int seed;
   int selectedArm;

   Arm arms[numArms]; // Array of Arm structs

   printf("Enter random seed:\n");
   scanf("%d", &seed);

   /* Seed the random number generator */
   srand(seed);

   /* Initialize UCB values of each arm randomly */
   for (int i = 0; i < numArms; i++) {
      // Generate random UCBs in the interval [-49, 51]
      arms[i].UCB = (rand() % 100) - 50 + ((double) rand() / RAND_MAX);
      arms[i].count = 0; // Initialize count to 0
      arms[i].sumReward = 0.0; // Initialize sumReward to 0
      arms[i].estValue = 0.0; // Initialize estValue to 0
      arms[i].value = 0.0; // Initialize trueValue to 0
      arms[i].rewardStdDev = 0.0; // Initialize rewardStdDev to 0
   }

   /* Print UCB values in a formatted table */
   printf("\nArm  UCB Value\n");
   for (int i = 0; i < numArms; i++) {
      printf("%3d  %9.2lf\n", i, arms[i].UCB);
   }
   printf("\n");

   /* Select arm according to upper confidence bound action selection method */
   selectedArm = SelectArm(arms, numArms);
   printf("UCB arm: %d\n", selectedArm);

   return 0;
}