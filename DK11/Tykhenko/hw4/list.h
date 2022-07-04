#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct Element
{
    int value;
  
    struct Element *next; 
    struct Element *prev; 
} Element;

typedef struct list {
	Element *head;
	Element *last;
} List;

Element *create_element(int value);
void delete_element(Element *element);
void print_el(Element *element);
List *createlist(void);
void init_list(List *hlist);
void add_to_tail(List *hlist, int value);
long countoOfList(List *hlist);
void printCount(List *hlist);
void print_all_list( List *hlist);
void printSeparateEl(List *hlist, int num);
void deleteList(List *hlist);
void insertElementToListAtIndex(List *hlist, int index, int value);


#endif

