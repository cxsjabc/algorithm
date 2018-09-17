/* 6 3 2 0 0 5 4 0 0 0 8 0 0 */
#include "common_local.h"

typedef struct _bin_sort_tree
{
	int		v;
	struct _bin_sort_tree *left;
	struct _bin_sort_tree *right;
}bin_sort_tree;

typedef bin_sort_tree *pbin_sort_tree;

typedef bin_sort_tree bin_sort_node;
typedef bin_sort_node *pbin_sort_node;

bin_sort_node *bin_sort_tree_create()
{
	pbin_sort_node node;
	int v;

	scanf("%d", &v);
	if(v == 0)
		node = NULL;
	else {
		node = (pbin_sort_node)malloc(sizeof(bin_sort_node));
		if(!node) {
			printf("no memory!\n");
			return NULL;
		}
		node->v = v;
		node->left = bin_sort_tree_create();
		node->right = bin_sort_tree_create();
	}
	return node;
}

void bin_sort_tree_show(pbin_sort_tree tree)
{
	if(tree) {
		printf("%d ", tree->v);
		bin_sort_tree_show(tree->left);
		bin_sort_tree_show(tree->right);
	}
}

pbin_sort_node bin_sort_tree_find(pbin_sort_tree tree, int v)
{
	if(!tree)
		return NULL;
	if(v == tree->v)
		return tree;
	else if(v < tree->v)
		return bin_sort_tree_find(tree->left, v);
	else
		return bin_sort_tree_find(tree->right, v);
}

int	bin_sort_tree_insert(pbin_sort_tree *pt, int v)
{
	pbin_sort_node node;

	if(*pt == NULL) {
		node = (pbin_sort_node)malloc(sizeof(bin_sort_node));
		if(!node)
			return 0;
		node->v = v;
		node->left = node->right = NULL;
		*pt = node; 
		return 1;
	} else {
		if(v == (*pt)->v)
			return 0;
		else if(v < (*pt)->v)
			return bin_sort_tree_insert(&((*pt)->left), v);
		else
			return bin_sort_tree_insert(&((*pt)->right), v);
	}
}

int main()
{
	pbin_sort_tree tree;
	
	tree = bin_sort_tree_create();
	bin_sort_tree_show(tree);
	
	PP(bin_sort_tree_find(tree, 5));
	PP(bin_sort_tree_find(tree, 9));
	PP(bin_sort_tree_find(tree, 1));

	PD(bin_sort_tree_insert(&tree, 3));
	PD(bin_sort_tree_insert(&tree, 10));
	PD(bin_sort_tree_insert(&tree, 7));
	PD(bin_sort_tree_insert(&tree, 5));
    return 0;
}
