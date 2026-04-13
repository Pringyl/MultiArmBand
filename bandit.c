#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bandit.h"

/* Selects an arm based on the upper confidence bound action selection method */
int SelectArm(Arm arms[], int numArms) {
   // *** <COMPLETE ME> Complete this function definition ***

   return numArms; // *** <COMPLETE ME> Replace with the correct return value ***
}

/* Calculates upper confidence bound value for each arm */
void CalcUCBPerArm(Arm arms[], int UCBConfidenceValue, int numArms, int step) {
   for (int i = 0; i < numArms; i++) {
      if (arms[i].count > 0) {
         arms[i].estValue = arms[i].sumReward / arms[i].count;
         arms[i].UCB = arms[i].estValue + UCBConfidenceValue * sqrt(log(step + 1) / arms[i].count);
      }
   }
}

/* Prints the simulation statistics */
void PrintStatistics(Arm arms[], int numArms) {
   // *** <COMPLETE ME> Complete this function definition ***
}

/* ************************************
 * The functions below this comment
 * have already been completed for you.
 * Do not modify them.
 * ************************************/

/* Pulls the selected arm to receive the reward */
double ReceiveReward(double armValue, double armRewardStdDev) {

   // *** This function is already completed for you ***

   double reward = armValue + armRewardStdDev * GetNormalRV();
   return reward;
}

/* Generates a Gaussian random variable with 0 mean and unit standard deviation */
double GetNormalRV() {

   // *** This function is already completed for you ***

   /* Get a uniform random variable */
   double randVar1 = (double) rand() / (double) RAND_MAX;
   double randVar2 = (double) rand() / (double) RAND_MAX;
   return sqrt(-2.0 * log(randVar1)) * cos(2.0 * M_PI * randVar2);
}
