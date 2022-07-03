#include <stdlib.h>
#include <string.h>
#include "tool.h"



el *createElement(int value)
{
      el *i = (el *)calloc(0, sizeof(el));

      if (i != NULL)
      {
            i->value = value;
      }

      return i;
}

void deleteElement(el *element)
{
      if (element != NULL)
      {
            free(element);
      }
}

void printElement(el *element)
{
      if (NULL != element)
      {
            printf("%d", element->value);
      }
}


IntList *createIntList(void)
{
      IntList *i = (IntList *)calloc(0, sizeof(IntList));
      return i;
}

void deleteIntList(IntList *list)
{
      if (NULL == list)
      {
            return;
      }

      el *element = list->head;

      while (NULL != element)
      {
            el *tmp = element->next;
            deleteElement(element);
            element = tmp;
      }
      
          free(list);
}

void printIntList(IntList *list)
{

      if (NULL == list)
      {
            printf("Invalid a pointer to the list\n");
            return;
      }

      printf("[");

      el *element = NULL;
      for (element = list->head; element != list->tail; element = element->next)
      {
            printElement(element);
            printf(",");
      }

      if (element != NULL)
      {
            printElement(element);
      }

      printf("]\n");
}

void addValueToList(IntList *list, int value)
{
      if (NULL == list || (list->head == NULL && list->head != list->tail))
      {
            return;
      }

      el *element = createElement(value);
      if (NULL == element)
      {
            return;
      }
         if (NULL == list->head)
      {
            list->head = element;
            list->tail = list->head;
            return ;
      }

      list->tail->next = element;
      list->tail = element;

      return ;
}

void reList(IntList *listI, IntList *listCor)
{
      el *in_line = (el *)calloc(0, sizeof(el));
      el *not_in_line = (el *)calloc(0, sizeof(el));
      for (in_line = listI->head; in_line != NULL; in_line = in_line->next)
      {
            if (in_line->value != 0){
            addValueToList(listCor, in_line->value);
            for (not_in_line = in_line->next; not_in_line != NULL; not_in_line = not_in_line->next)
            {
                  if (not_in_line->value == in_line->value )
                  {
                        not_in_line->value = 0;
                  }
            }
            }
      }
      deleteIntList(listI);
}
