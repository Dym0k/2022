#include <stdio.h>
#include "tree.h"

void main(int argc, const char *argv[])
{
	tree *Tree = createTree();
	enter_El(Tree, getValueForRange(3, 8, 1));
	printTree(Tree);

	deleteTree(Tree);
}
