//This program is written by Nicholas Estrada. This program is designed tosort a list of given integers from the command line in a specified ascending or descending order. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char* argv[])
{
  int input[100];
  int i, j, count, swap;
  
  //As loop runs it assigns converted numbers into the array
  for(i = 2; i < argc; i++)
  {
    input[j] = atoi(argv[i]);
    j++;
  }
  
  //Corrects number of elements in array
  count = j + 1;
  //if loop for sorting numbers in ascending order
  if(strcmp(argv[1], "-a") == 0)
  {
    for(i = 0; i < count; ++i)
    {
      for(j = i + 1; j < count; ++j)
      {
        //Array comparison
        if(input[i] > input[j])
        {
          swap = input[i];
          input[i] = input[j];
          input[j] = swap;
        }
      }
    }
  }
  
  //else if loop for sorting numbers in descending order
  else if(strcmp(argv[1], "-d") == 0)
  {
    for(i = 0; i < count; ++i)
    {
      for(j = i + 1; j < count; ++j)
      {
        if(input[i] < input[j])
        {
          swap = input[i];
          input[i] = input[j];
          input[j] = swap;
        }
      }
    }
  }
  
  //Output
  for(i = 0; i < count; ++i)
  {
    printf("%d ", input[i]);
  }
  
return 0;
}