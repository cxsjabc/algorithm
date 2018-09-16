/* 6 2 1 0 0 4 3 0 0 0 8 0 0 */
#include "common_local.h"

typedef struct _bin_tree
{
	int		v;
	struct _bin_tree *left;
	struct _bin_tree *right;
}bin_tree;

typedef bin_tree *pbin_tree;

typedef bin_tree bin_node;
typedef bin_node *pbin_node;

bin_node *bin_tree_create()
{
	pbin_node node;
	int v;

	scanf("%d", &v);
	if(v == 0)
		node = NULL;
	else {
		node = (pbin_node)malloc(sizeof(bin_node));
		if(!node) {
			printf("no memory!\n");
			return NULL;
		}
		node->v = v;
		node->left = bin_tree_create();
		node->right = bin_tree_create();
	}
	return node;
}

void bin_tree_show(pbin_tree tree)
{
	if(tree) {
		printf("%d ", tree->v);
		bin_tree_show(tree->left);
		bin_tree_show(tree->right);
	}
}

int main()
{
	pbin_tree tree;
	
	tree = bin_tree_create();
	bin_tree_show(tree);

    return 0;
}
