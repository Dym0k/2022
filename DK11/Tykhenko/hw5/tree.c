#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void printElement(Element *El);

tree *createTree()
{
      tree *aTree = (tree *)calloc(0, sizeof(tree));

      if(aTree != NULL){
            aTree->root = NULL;
      }

      return aTree;
}
void deleteTree(tree *aTree)
{
      if (NULL != aTree)
      {
            destroyElement(aTree->root);
            free(aTree);
      }
}

Element *createElement(int value)
{
      Element *El = (Element *)malloc(sizeof(Element));

      if (NULL != El)
      {
            El->left = NULL;
            El->right = NULL;
            El->value = value;
      }

      return El;
}
void destroyElement(Element *El)
{
      if (NULL != El)
      {
            destroyElement(El->left);
            destroyElement(El->right);

            free(El);
      }
}
Element *getSuccessor(tree *aTree, Element *toDelete)
{
      Element *successParent = toDelete;
      Element *successor = toDelete;
      Element *current = toDelete->right;

      while (NULL != current)
      {
            successParent = successor;
            successor = current;
            current = current->left;
      }
      if (successor != toDelete->right)
      {
            successParent->left = successor->right;
            successor->right = toDelete->right;
      }
      successor->left = toDelete->left;
      return successor;
}

void insertElement(tree *aTree, int Value)
{
      {
            if (NULL == aTree)
            {
                  return;
            }
            Element *newEl = createElement(Value);
            if (NULL == newEl)
            {
                  return;
            }

            if (NULL == aTree->root)
            {
                  aTree->root = newEl;
            }
            else
            {
                  Element *theCurrent = aTree->root;
                  Element *theParent = NULL;
                  while (1)
                  {
                        theParent = theCurrent;

                        if (Value < theCurrent->value)
                        {
                              theCurrent = theCurrent->left;
                              if (NULL == theCurrent)
                              {
                                    theParent->left = newEl;
                                    break;
                              }
                        }
                        else
                        {
                              theCurrent = theCurrent->right;
                              if (NULL == theCurrent)
                              {
                                    theParent->right = newEl;
                                    break;
                              }
                        }
                  }
            }
      }
}

int getValueForRange(int min, int max, int type)
{
	if(type==1)
	{
		int num;
		printf("Введіть кількість елментів, які ви хочете внести до дерева від %d до %d: \n", min, max );
		do{
			printf("Ввод: ");
			scanf("%d", &num);
			if(num<min || num>max){
				printf("Введено кількість не за умовою, спробуйте ще раз: \n");
			}
		}while(num<min || num>max);
		return num;
	}if(type==2){
		int value;
			do{
			printf("Введіть елемент: ");
			scanf("%d", &value);
			if(value<min || value>max){
				printf("Введено елемент не за умовою, спробуйте ще раз: \n");
			}
		}while(value<min || value>max);
		return value;
	}
}
		
void enter_El(tree *aTree, int n)
{
	int value;
	printf("\nВведіть %d елементів від -100 до 100: \n", n);
	for(int i=0; i<n; i++)
	{
		insertElement(aTree, getValueForRange(-100, 100, 2));
	}
}
Element *findElement(tree *aTree, int Value)
{
      Element *theCurrentNode = NULL;

      if (NULL != aTree && NULL != aTree->root)
      {
            theCurrentNode = aTree->root;
            while (Value != theCurrentNode->value)
            {
                  theCurrentNode = (Value < theCurrentNode->value)
                                       ? theCurrentNode->left
                                       : theCurrentNode->right;

                  if (NULL == theCurrentNode)
                  {
                        break;
                  }
            }
      }

      return theCurrentNode;
}


void deleteElement(tree *aTree, int Value)
{
      if (NULL == aTree || NULL == aTree->root)
      {
            return ;
      }

      Element *current = aTree->root;
      Element *parent = aTree->root;

      while (Value != current->value)
      {
            parent = current;
            if (Value < current->value)
            {
                  current = current->left;
            }
            else
            {
                  current = current->right;
            }

            if (NULL == current)
            {
                  return ;
            }
      }

      if (NULL == current->left && NULL == current->right)
      {
            if (aTree->root == current)
            {
                  aTree->root = NULL;
            }
            else if (parent->left == current)
            {
                  parent->left = NULL;
            }
            else
            {
                  parent->right = NULL;
            }
      }
      else if (NULL == current->right)
      {
            if (aTree->root == current)
            {
                  aTree->root = current->left;
            }
            else if (parent->left == current)
            {
                  parent->left = current->left;
            }
            else
            {
                  parent->right = current->right;
            }
      }
      else if (NULL == current->left)
      {
            if (aTree->root == current)
            {
                  aTree->root = current->right;
            }
            else if (parent->right == current)
            {
                  parent->right = current->right;
            }
            else
            {
                  parent->left = current->left;
            }
      }
      else
      {
            Element *successor = getSuccessor(aTree, current);
            if (aTree->root == successor)
            {
                  aTree->root = NULL;
            }
            else if (parent->left == current)
            {
                  parent->left = successor;
            }
            else
            {
                  parent->right = successor;
            }
            current->left = NULL;
            current->right = NULL;
      }

      destroyElement(current);
}


void printTree(tree *aTree)
{
      Element *El = aTree->root;
      printElement(El);
}
void printElement(Element *El)
{
      if (El == NULL)
            return;
      printElement(El->left);
      printf("element: %d\n", El->value);
      printElement(El->right);
}
