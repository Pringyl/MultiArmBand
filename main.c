/*
 * main.c for EAS 240 Multi-armed bandit project
 * EAS 240 Introduction to Programming for Engineers
 * Authors: Anjali Omer and Nick Mastronarde
 */
#include <stdio.h>
#include <stdlib.h>
#include "bandit.h"

int main() {
   const int numArms = 5;
   const int numSteps = 100;
   const int UCBConfidenceValue = 2;
   int seed;
   int selectedArm;
   double receivedReward;

   Arm arms[numArms]; // Array of Arm structs

   printf("Enter the random seed:\n");
   printf("LKDSJFLDSKFJ");
   scanf("%d", &seed);

   /* Seed the random number generator */
   srand(seed);

   /* *** <COMPLETE ME> Complete the rest of main() *** */


   return 0;
}
