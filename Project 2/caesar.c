//Program by Nicholas Estrada. This program is designed to emulate the Caesar cipher. Reads user input and applies the cipher.
#include <stdio.h>

#define MAX_LEN 100

int main(void)
{
	int i, j, key, count;
	char msgLen[MAX_LEN] ,ch;
	
  //Read key from user
	printf("Enter a key: ");
	scanf("%d", &key);

  //Read user input
	printf("Enter a message: "); 
	scanf("%c", &ch);
 
  //Stores user input in array 
  while((ch = getchar()) != '\n') { 
    msgLen[i++] = ch;
    count++;
  }     
    
  printf("Output: ");
    for(j = 0; j < count; j++) {
      
      if(msgLen[j] != ' ') {
        
        if((msgLen[j] >= 'a' && msgLen[j] <= 'z')) {
          
          msgLen[j] = ((msgLen[j] - 'a') + key) % 26 + 'a';
        }
        else if((msgLen[j] >= 'A' && msgLen[j] <= 'Z')) {
        
          msgLen[j] = ((msgLen[j] - 'A') + key) % 26 + 'A';
        }
	
	}
	
	printf("%c", msgLen[j]);
}
	return 0;
} 	
