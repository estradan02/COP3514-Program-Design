//Nicholas Estrada. This file holds functions used by store.c.
/* items.c */

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "items.h"


/*********************************************************
 * append_item: Add an item to the end of the linked     *
 * list if it doesn't already exist. If the item already *
 * exist, do not add anything to the list. This function *
 * returns the list.                                     *
 *********************************************************/
struct item *append_item(struct item *item_list)
{
  struct item *temp, *p;
  char addName[NAME_LEN+1];
  char *itemName;
  float addPrice;
  
  //Prompts user to enter item
  printf("Enter item name: ");
  read_line(addName, NAME_LEN+1);

  //Compares list to name input, prints message if name already exists in the list
  for(p = item_list; p != NULL; p = p->next)
  {
    itemName = p->name;
    if(strcmp(itemName, addName) == 0)
    {
      printf("Item already exists.\n");
      return item_list;
    }
  }
  //Prompts user to input price of item
  printf("Enter price: ");
  scanf("%f", &addPrice);
  
  //Creating a temporary node and stores input info in temporary node      
  temp = malloc(sizeof(struct item));
  strcpy(temp->name, addName);
  temp->price = addPrice;
  
  //Adds temp node to end of linked list, as long as the list isn't empty
  if(item_list == NULL)
  {
    temp->next = item_list;
    return temp;
  }
  for(p = item_list; p!= NULL; p = p->next)
  {
    if(p->next == NULL)
    {
      p->next = temp;
      temp->next = NULL;
      return item_list;
    }
  }
  return NULL;
}


/*********************************************************
 * search_item: Search an item with the given name in    *
 * the linked list. Function should print out the name   *
 * and price of the item if it exist. If the item doesn't*
 * exist simply print that the item was not found.       *
 *********************************************************/
void search_item(struct item *item_list)
{
  struct item *p;
  char name[NAME_LEN+1];
  
  //Prompts user to enter desired item search
  printf("Enter item: ");
  scanf("%s", name);
  
  while(item_list != NULL && strcmp(item_list->name, name) != 0)
    item_list = item_list->next; 
  
  //Searches list with the following conditions  
  for(p = item_list; p != NULL && strcmp(item_list->name, name) != 0; p = p->next);
        
  if(p != NULL && strcmp(item_list->name, name) == 0)
    printf("Price of    %s is $%.2f\n", name,item_list->price);
  else
    printf("Item not found.\n");  
}


/*********************************************************
 * print_items: Print out all the items in the linked    *
 * list, each item with its price in a new line.         *
 *********************************************************/
void print_items(struct item *item_list)
{
  struct item *p;
  
  //Loops through list for printing until item_list is NULL
  for(p = item_list; p != NULL; p = p->next)
  {
    printf("Price of\t\t%s is $%.2f\n", p->name, p->price);
  }
}


/*********************************************************
 * clear_items: Clear all the items in the linked list.  *
 * All dynamically allocated nodes must be freed.        *
 *********************************************************/
void clear_items(struct item *item_list)
{
  struct item *p;
  
  while(item_list != NULL)
  {
    p = item_list;
    item_list = item_list->next;
    if(p != NULL)
      free(p);
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
