#include "common_local.h"
#include "tree.h"

int tree_height(Tree *t)
{
	if(t == NULL)
		return 0;
	return MAX(tree_height(t->left), tree_height(t->right)) + 1;
}

int main()
{
	
    return 0;
}
