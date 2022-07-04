#include "list.h"
#include <stdlib.h>
#include <string.h>

Element *create_element(int value)
{   
    Element *el;
    el = (Element *)calloc(0, sizeof(Element));
    if (el != NULL)
    {
    	el->value = value;
    }
    
    return el;
}

void delete_element(Element *element)
{
	if (element != NULL)
	{
		free(element);
	}
}

void print_el(Element *element)
{
    if(NULL != element)
    {
    	printf("%d", element->value);
    }

}

List *createlist(void)
{
	return (List *)calloc(0, sizeof(List));
}

void init_list( List *hlist)
{
    hlist->head = NULL;
}

void deleteList(List *hlist)
{
      if (NULL == hlist)
      {
            return;
      }

      Element *element = hlist->head;

      while (NULL != element)
      {
            Element *tmp = element->next;
            delete_element(element);
            element = tmp;
      }
      
          free(hlist);
}



void add_to_tail(List *hlist, int value)
{
	Element *element = create_element(value);
	
    if (hlist->head == NULL) {
        hlist->head = element;
        element->next = NULL;
        element->prev = NULL;
        hlist->last = element;
    } else {
        hlist->last->next = element;
        element->prev = hlist->last;
        element->next = NULL;
        hlist->last = element;
    }

}
long countoOfList(List *hlist)
{
	long count = 0;
	Element *el;
	for (el = hlist->head; el; el=el->next, count++);
	return count;
}

void printCount(List *hlist)
{
	int count = countoOfList(hlist);
	printf("Розмір списку: %d\n", count);
}

void print_all_list(List *hlist)
{
	Element *el;
    printf("\n");
	printf("[");
    for (el = hlist->head; el; el=el->next) {
        print_el(el);
        if(el-> next != NULL){
        	printf(",");
        }
    }
    printf("]\n");
}


void printSeparateEl(List *hlist, int num)
{
	
	if (NULL == hlist){
            printf("Invalid a pointer to the list\n");
            return;
	}
	
	int i = 1;
   	Element *el;
    printf("\n");
	printf("Елемент %d: ", num);
    for (el = hlist->head; el; el=el->next, i++) {
    	if(i==num){
        	print_el(el);
        	printf("\n");
        	return;
    	}
	}

}
void insertElementToListAtIndex(List *hlist, int index, int value)
{
	if(hlist == NULL){
	    return;
    }
    long count = countoOfList(hlist);

    if(count == index){
       return add_to_tail(hlist, value);
    }
    Element *element = create_element(value);
    if(element == NULL){
        return;
    }
    if(index == 0){
        element->next = hlist->head;
        hlist->head = element;
    } else{
        int current = 0;
        Element *prev_el = hlist->head;
        while(prev_el != NULL && current < index-1){
            prev_el = prev_el->next;
            current++;
        }

        element->next = prev_el->next;
        prev_el->next = element;

    }
}



