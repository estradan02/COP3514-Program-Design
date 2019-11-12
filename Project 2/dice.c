//Program by Nicholas Estrada. This program is designed to emulate a dice being rolled a specific amount of times determined by the user.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6

int main(void)
{

	int roll, num_rolls, count = 0, total_rolls;
	const char a[6] = {'0', '1', '2', '3', '4', '5'};
	double prob;

  //Randomize seed
	srand(time(NULL));

	//Prompts user to enter data
  printf("How many times to roll? ");
	scanf("%d", &num_rolls);
	total_rolls = num_rolls;

  //Runs through each dice roll and stores the winning rolls  
	while(num_rolls > 0) {
	  roll = a[rand() % NUM_SIDES];
	  
		if(roll == '0') {
		  		  
	 	  count++;  
	 	
		}		 
		  num_rolls--;			  	   
	        }

	 //Determines user's probability of winning
   prob = ((double)count / total_rolls);
	 
   //Output
   printf("You won %d out of %d times.", count, total_rolls);
	 printf("Your probability of winning is %f.", prob);	
	 printf("\n");
	 return 0;
}
