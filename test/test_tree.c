#define _LOG_ENABLE 1
#define	_LOG_LEVEL  LOG_LEVEL_WARNING

#include "tree.h"
#include "common_local.h"

int main()
{
	PTree tree = NULL;
	PTreeNode node;
	
	tree_make_empty(NULL);
	tree = binary_tree_insert(tree, 100);
	LOG_D("tree:%p", tree);	
	LOG_W("tree:%p", tree);	

	binary_tree_insert(tree, 40);
	binary_tree_insert(tree, 60);
	binary_tree_insert(tree, 200);
	binary_tree_insert(tree, 10);
	binary_tree_insert(tree, 180);

	tree_show(tree);
	printf("\n");

	node = binary_tree_find(tree, 150);
	PP(node);
	
	node = binary_tree_find(tree, 180);
	PN(node->data);

	tree_free(tree);
	
	return 0;
}
