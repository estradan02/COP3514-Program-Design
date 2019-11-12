/* country.h */

#ifndef COUNTRY_H
#define COUNTRY_H

#define NAME_LEN 25
#define NUM_COUNTRIES 32

struct country {
  char name[NAME_LEN+1];
  char group;
  int goals;
  int points;
};

void search_by_country(struct country countries[]);
void search_by_group(struct country countries[]);
void search_by_points(struct country countries[]);
void print_sorted_by_goals(struct country countries[]);
int  read_line(char str[], int n);
void selection_sort(struct country countries[], int n);

#endif