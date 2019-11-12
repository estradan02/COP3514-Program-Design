//This program is written by Nicholas Estrada. Its purpose is to count the number of words, characters and frequency of each character in the user provided sentence.

#include <stdio.h>

#define MAX_INPUT 200

int read_line(char* string, int n);

int main(void)
{
  int wrds = 1, chrs = 0, i, count;
  int freq[256] = {0};
  char input[MAX_INPUT];
  
  //Prompt user to enter a sentence
  printf("Enter a sentence: ");
  count = read_line(input, MAX_INPUT);
  
  for(i = 0; input[i] != '\0'; ++i)
  {
    //Loop counts the completed words entered
    if(input[i] == ' ')
    {  
      ++wrds;
    }   
      chrs++; //As for loop runs characters increment
      freq[input[i]]++; 
  }
  
  //Output
  printf("\n Your sentence has: %d word(s)", wrds);
  printf("\n Your sentence has: %d character(s)", chrs);
  
  for(i = 0; i < 256; i++)
  {
    //Loop counting the frequency of characters appearing in the entered sentence
    if(freq[i] != 0)
    {
      printf("\n Your sentence has: %d %c", freq[i], i);
    } 
  }
  printf("\n");
  return 0;
  }

//Function reading the entered sentence
int read_line(char* string, int n)
{
  int ch, i = 0;
  
  while((ch = getchar()) != '\n')
  {
    if(i < n) 
      *string++= ch;
       i++;
  }
  *string = '\0';
  return i;
}  