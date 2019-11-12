 /*Program completed by Nicholas Estrada. This program performs functions needed to create the user interface in worldcup.c*/

/* country.c */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "country.h"


/**********************************************************
 * search_by_country: Prompts the user to enter a country *
 *                    name, then prints the record of     *
 *                    that country if it exists.          *
 **********************************************************/
void search_by_country(struct country countries[])
{
  int i;
  char country_name[100];
  
  printf("Enter country name: ");
  scanf("%[^\n]s", country_name);
  printf("Country       Group   Goals   Points\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    if(strcmp(countries[i].name, country_name) == 0)
    {
      printf("%s\t\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
    }
  }
}


/**********************************************************
 * search_by_group: Prompts the user to enter a group,    *
 *                  then prints the records of that group *
 *                  if it exists.                         *
 **********************************************************/
void search_by_group(struct country countries[])
{
  int i, len;
  char group_letter;
  
  printf("Enter group: ");
  scanf("%c", &group_letter);
  printf("Country       Group   Goals   Points\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    
    if(countries[i].group == group_letter)
    {
      //Formatting output
      len = strlen(countries[i].name);
      if(len == 8)
        printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
      else if(len < 9)
        printf("%s\t\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
      else
        printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
    }
  }
}


/**********************************************************
 * search_by_points: Prompts the user to enter a point,   *
 *                   then prints the records having       *
 *                   that many points, if it exists.      *
 **********************************************************/
void search_by_points(struct country countries[])
{
  int pts, i,len;
  
  printf("Enter points: ");
  scanf("%d", &pts);
  printf("Country       Group   Goals   Points\n");
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    if(countries[i].points == pts)
    {
      //Formatting output
      len = strlen(countries[i].name);
      if(len == 8)
        printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
      else if(len < 9)
        printf("%s\t\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
      else
        printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
    }
  }
}


/**********************************************************
 * print_sorted_by_goals: Sorts the records in acending   *
 *                        order according to goal scored  *
 *                        and prints them                 *
 **********************************************************/
void print_sorted_by_goals(struct country countries[])
{
  int i, len;
  
  selection_sort(countries, NUM_COUNTRIES);
  printf("Country       Group   Goals   Points\n"); 
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    //Formatting output
    len = strlen(countries[i].name);
    if(len == 8)
      printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
    else if(len < 9)
      printf("%s\t\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
    else
      printf("%s\t%c\t%d\t%d\n", countries[i].name,countries[i].group,countries[i].goals,countries[i].points);
  }
}


void selection_sort(struct country countries[], int n)
{
  int i, j;
  struct country temp;
  
  for(i = 0; i < NUM_COUNTRIES; i++)
  {
    for(j = i + 1; j < NUM_COUNTRIES; j++)
    {
      if(countries[i].goals > countries[j].goals)
      {
         temp = countries[i];
         countries[i] = countries[j];
         countries[j] = temp;
      }
    }
  }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';
  return i;
}