
#include <stdio.h>
#include "tool.h"

int main(int argc, const char *argv[])
{
      IntList *list = createIntList();
      int value, i;
      int n = 0;
      printf("Щоб додати значення введіть в термінал 1 та натисніть Enter: ");
      scanf("%d", &i);
      while(i==1){
            if(n<3){
               printf("Внесіть 3 елемента в список: \n\n");    
                while(n<3){
                    printf("Введіть значення нового елементу: ");
                    scanf("%d", &value);
                    addValueToList(list, value);
                    n++;
                }
                i = 0;
                printf("\nЩоб додати введіть в термінал 1 та натисніть Enter,\nабо 'іншу клавішу'+Enter, для виводу списку: ");
                scanf("%d", &i);
            } else {
                printf("\nВведіть значення нового елементу: ");
                scanf("%d", &value);
                addValueToList(list, value);
                i = 0;
                printf("\nЩоб додати значення введіть в термінал 1 та натисніть Enter,\n або 'іншу клавішу'+Enter, для виводу списку: ");
                scanf("%d", &i);
            }
      }
      printf("Заданий список:");
      printIntList(list);

      IntList *listC = createIntList();
      printf("Список без повторень:");
      reList(list, listC);
      printIntList(listC);
      deleteIntList(listC);
}
