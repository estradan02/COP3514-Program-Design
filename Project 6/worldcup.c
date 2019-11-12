 /*Program completed by Nicholas Estrada. This program reads records from the CSV file, worldcup.csv, and calls functions from country.c to create a user interface. This interface allows users to search the records according to country name, group, and points scored during the World Cup 2018.*/
/********************************************************* 
 * worldcup.c:                                           *
 * Program to read in country records from worldcup.csv  *
 * and search records by country, group, or points.      *
 *                                                       *
 *                                                       *
 * compile: gcc -Wall -o worldcup worldcup.c country.c   *
 * usage:   ./worldcup <input filename>                  *
 * example: ./worldcup worldcup.csv                      *
 *********************************************************/

#include <stdio.h>
#include <string.h>
#include "country.h"

int main(int argc, char *argv[])
{
  struct country countries[NUM_COUNTRIES];
  char code;
  char header_line[100];
  FILE *input;
  int i = 0;

  //Determines if user entered in the command line correctly
  if(argc != 2)
  {
    printf("Usage: ./worldcup <input filename\n");
    return 1;
  }
  
  //Opens file containing records
  input = fopen(argv[1], "r");
  //Verifies the file is opened correctly
  if(input == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }
 
  if(fscanf(input,"%[^\n]",header_line)==1);
  
  //Checks for these errors
  while(!feof(input) && !ferror(input))
  {
    //Reads data from each line of the input file
    if(fscanf(input," %[^,], %c, %d, %d", countries[i].name,&countries[i].group,&countries[i].goals,&countries[i].points)==4);
      i++;
  }
  
  // Uncomment the following line if you have done extra credit
  print_sorted_by_goals(countries); // THIS IS FOR EXTRA CREDIT

  for (;;) {
    printf("Search by country: c\n");
    printf("Search by group:   g\n");
    printf("Search by points:  p\n");
    printf("Quit:              q\n");
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'c': search_by_country(countries);
                break;
      case 'g': search_by_group(countries);
                break;
      case 'p': search_by_points(countries);
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
  //Performs necessary closure of file
  fclose(input);
  return 0;
}