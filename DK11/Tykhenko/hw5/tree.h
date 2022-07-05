#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
      int value;
      struct Element *left;
      struct Element *right;
} Element;

typedef struct tree
{
      Element *root;
} tree;

tree *createTree();
void deleteTree(tree *aTree);
Element *createElement(int Value);
void destroyElement(Element *El);
Element *findElement(tree *aTree, int Value);
void insertElement(tree *aTree, int Value);
void enter_El(tree *aTree, int n);
void deleteElement(tree *aTree, int Value);
void printTree(tree *aTree);
void printEl(tree *aTree, int n);
int getValueForRange(int min, int max);
#endif
