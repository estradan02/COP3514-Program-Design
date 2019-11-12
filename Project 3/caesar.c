//Program by Nicholas Estrada. This program is designed to emulate the Caesar cipher. Reads user input and applies the cipher.
#include <stdio.h>

#define MAX_LEN 100
int key; //Global variable

void shift(char *ch);

int main(void)
{
  int i, j;
  char ch, msgLen[MAX_LEN];
	
  //Read key from user
	printf("Enter a key: ");
	scanf("%d", &key);
  key %= 26;
  if (key < 0)
    key += 26; //For negative user inputs

  //Read user input
  printf("Enter a message: "); 
  ch = getchar();
  for(j = 0; j < MAX_LEN; j++) //Store ch into character array
  {
    if((ch = getchar()) == '\n')
    break;
    msgLen[j] = ch; //Stores individual ch in array
  }
  printf("Output: ");
  for(i = 0; i < j; i++) //Loop to modify constant array individually
  {
    shift(&msgLen[i]); //Call shift funtion to shirt array address
    putchar(msgLen[i]); 
  }
  
return 0;
}
   
void shift(char *ch)
{
   if((*ch >= 'a') && (*ch <= 'z'))
   {    
     *ch = ((*ch - 'a') + key) % 26 + 'a';
   }
        else if((*ch >= 'A') && (*ch <= 'Z'))
        {
          *ch = ((*ch - 'A') + key) % 26 + 'A';
        }
	
}