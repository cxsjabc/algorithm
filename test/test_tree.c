#define _LOG_ENABLE 1
#define	_LOG_LEVEL  LOG_LEVEL_WARNING

#include "common_local.h"

int main()
{
	PTree tree = NULL;
	PTreeNode node;
	
	bst_make_empty(NULL);
	tree = bst_insert(tree, 100);
	LOG_D("tree:%p", tree);	
	LOG_W("tree:%p", tree);	

	bst_insert(tree, 40);
	bst_insert(tree, 60);
	bst_insert(tree, 200);
	bst_insert(tree, 10);
	bst_insert(tree, 180);
	bst_insert(tree, 400);
	bst_insert(tree, 800);

	PD(bst_get_depth(tree));
	bst_show(tree);
	printf("\n");

	node = bst_find(tree, 150);
	PP(node);
	
	node = bst_find(tree, 180);
	PN(node->data);

	bst_free(tree);
	
	return 0;
}
