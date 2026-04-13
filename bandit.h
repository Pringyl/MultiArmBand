#ifndef BANDIT_H_
#define BANDIT_H_

typedef struct {
   double UCB;            // Upper confidence bound for the arm
   int count;             // Number of times the arm has been selected
   double sumReward;      // Sum reward obtained by the arm
   double estValue;       // Estimated value of the arm
   double value;          // True value of the arm
   double rewardStdDev;   // Reward standard deviation of the arm
} Arm;

/* Selects an arm based on the upper confidence bound action selection method */
int SelectArm(Arm arms[], int numArms);

/* Calculates the upper confidence bound value for each arm */
void CalcUCBPerArm(Arm arms[], int UCBConfidenceValue, int numArms, int step);

/* Prints the simulation statistics.
 * Statistics include:
 * Total sum reward over the entire simulation
 * Number of times each arm was selected
 * Average reward obtained by each arm
 * Expected reward (value) of each arm
 */
void PrintStatistics(Arm arms[], int numArms);

/* Pulls the selected arm to receive the reward
 * The reward is generated from a Gaussian distribution
 * with mean (armValue) and standard deviation
 * (armRewardStdDev).
 */
double ReceiveReward(double armValue, double armRewardStdDev);

/* Generates a Gaussian random variable with 0 mean and
 * unit standard deviation
 */
double GetNormalRV();

#endif