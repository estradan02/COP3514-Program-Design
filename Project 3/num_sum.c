//Program by Nicholas Estrada. This program is designed to ask the user to input a positive integer, read how many digits were entered, and find their sum. 
#include <stdio.h>

void num_sum(int n, int *num, int *sum);

int main(void)
{
  int n, num = 0, sum = 0;

  printf("Enter a positive integer: "); //Prompt user to enter numbers
  scanf("%d", &n);
  
  num_sum(n, &num, &sum); //Calling num_sum function
  
  printf("The number has %d digit(s), sum of which is %d\n", num, sum);
  
  return 0;
  
}

void num_sum(int n, int *num, int *sum) //Function to identify the sum of the digits entered by user
{
  while (n > 0)
  {
    *num += + 1;
    *sum += n % 10;
     n /= 10;
  }
}  