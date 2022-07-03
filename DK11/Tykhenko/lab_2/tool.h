#ifndef TOOL_H_INCLUDED
#define TOOL_H_INCLUDED
#include <stdio.h>


typedef struct el
{
      int value;
      struct el *next;
} el;

typedef struct List
{
      el *head;
      el *tail;
} IntList;

el *createElement(int value);
void deleteElement(el *element);
void printElement(el *element);

IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

void addValueToList(IntList *list, int value);

void reList(IntList *listI, IntList *listCor);

#endif 
