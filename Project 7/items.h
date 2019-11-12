//Nicholas Estrada. File contains definitions and prototypes of functions that are defined in items.c.
/* items.h */

#ifndef ITEMS_H
#define ITEMS_H

#define NAME_LEN 50

struct item {
  float price;
  char name[NAME_LEN+1];
  struct item *next;
};

struct item *append_item(struct item *item_list);
void search_item(struct item *item_list);
void print_items(struct item *item_list);
void clear_items(struct item *item_list);
int  read_line(char str[], int n);

#endif