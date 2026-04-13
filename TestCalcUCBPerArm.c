/*
 * main file for testing TestCalcUCBPerArm()
 * EAS 240 Multi-armed bandit project
 * EAS 240 Introduction to Programming for Engineers
 * Authors: Anjali Omer and Nick Mastronarde
 *
 * Note: arms[] and step are initialized randomly to test CalcUCBPerArm()
 */
#include <stdio.h>
#include <stdlib.h>
#include "bandit.h"

int main() {
   const int numArms = 5;
   const int UCBConfidenceValue = 2;
   int seed;
   int step;

   Arm arms[numArms]; // Array of Arm structs

   printf("Enter random seed:\n");
   scanf("%d", &seed);

   /* Seed the random number generator */
   srand(seed);

   /* Initialize each arm */
   for (int i = 0; i < numArms; i++) {
      arms[i].UCB = 10000.0;
      arms[i].count = rand() % 100;
      arms[i].estValue = rand() % 100;
      arms[i].sumReward = 0.0; // Initialize sumReward to 0
      arms[i].value = 0.0; // Initialize trueValue to 0
      arms[i].rewardStdDev = 0.0; // Initialize rewardStdDev to 0
   }
   step = rand() % 1000;

   /* Calculate upper confidence bound value for each arm */
   CalcUCBPerArm(arms, UCBConfidenceValue, numArms, step);

   /* Print UCB values in a formatted table */
   printf("\nArm  UCB Value\n");
   for (int i = 0; i < numArms; i++) {
      printf("%3d  %9.2lf\n", i, arms[i].UCB);
   }
   printf("\n");

   return 0;
}