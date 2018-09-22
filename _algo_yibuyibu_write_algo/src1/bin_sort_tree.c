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

bin_sort_node *bin_sort_tree_create_from_arr(int arr[], int size, int **ppindex)
{
	pbin_sort_node node;
	int v;
	int index;
	int *pindex = *ppindex;

	index = *pindex;
	v = arr[index];
	if(v == 0) {
		node = NULL;
		*pindex = *pindex + 1;
	}
	else {
		node = (pbin_sort_node)malloc(sizeof(bin_sort_node));
		if(!node) {
			printf("no memory!\n");
			return NULL;
		}
		node->v = v;
		*pindex = *pindex + 1; 
		node->left = bin_sort_tree_create_from_arr(arr, size, ppindex);
		node->right = bin_sort_tree_create_from_arr(arr, size, ppindex);
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

pbin_sort_node	find_max_node(pbin_sort_node node)
{
	if(node->right) {
		return find_max_node(node->right);
	} else
		return node;
}

pbin_sort_node find_right_child_parent(pbin_sort_tree node, pbin_sort_node right_child)
{
	pbin_sort_node temp;

	if(node == NULL)
		return NULL;
	if(node && node->right == right_child)
		return node;
	if((temp = find_right_child_parent(node->left, right_child)) != NULL)
		return temp;
	if((temp = find_right_child_parent(node->right, right_child)) != NULL)
		return temp;
	return NULL;
}

pbin_sort_node find_child_parent(pbin_sort_tree node, pbin_sort_node child)
{
	pbin_sort_node temp;

	if(node == NULL)
		return NULL;
	if(node && (node->left == child || node->right == child))
		return node;
	if((temp = find_child_parent(node->left, child)) != NULL)
		return temp;
	if((temp = find_child_parent(node->right, child)) != NULL)
		return temp;
	return NULL;
}

int	bin_sort_tree_delete(pbin_sort_tree *pt, int v)
{
	pbin_sort_node node;

	if(pt == NULL || *pt == NULL)
		return -1;
	node = bin_sort_tree_find(*pt, v);
	if(!node)
		return -2;

	if(*pt == node) {
		if(node->left == NULL && node->right == NULL) {
			*pt = NULL;
			free(node);
			return 0;
		} else if(node->left != NULL && node->right == NULL) {
			*pt = node->left;
			free(node);
			return 0;
		} else if(node->left == NULL && node->right != NULL) {
			*pt = node->right;
			free(node);
			return 0;
		} else {
			pbin_sort_node left_max;
			left_max = find_max_node(node->left);	
			if(left_max == node->left) {
				*pt = left_max;
				(*pt)->right = node->right;
				free(node);
				return 0;
			} else {
				pbin_sort_node left_max_parent;
				node->v = left_max->v;
				left_max_parent = find_right_child_parent(node, left_max);
				left_max_parent->right = left_max->left;
				free(left_max);
				return 0;
			}
		}
	} else {
		if(node->left == NULL && node->right == NULL) {
			pbin_sort_node parent = find_child_parent(*pt, node);
			if(parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;
			free(node);
			return 0;
		} else if(node->left != NULL && node->right == NULL) {
			pbin_sort_node parent = find_child_parent(*pt, node);
			if(parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
			free(node);
			return 0;
		} else if(node->left == NULL && node->right != NULL) {
			pbin_sort_node parent = find_child_parent(*pt, node);
			if(parent->left == node)
				parent->left = node->right;
			else
				parent->right = node->right;
			free(node);
			return 0;
		} else {
			pbin_sort_node parent = find_child_parent(*pt, node);
			pbin_sort_node left_max = find_max_node(node->left);
			if(left_max == node->left) {
				if(parent->left == node)
					parent->left = left_max;
				else
					parent->right = left_max;
				left_max->right = node->right;
			} else {
				node->v = left_max->v;
				parent = find_child_parent(*pt, left_max);
				parent->right = left_max->left;
				node = left_max;	
			}
			free(node);
			return 0;
		}
	}
	return -3;
}

int main()
{
	pbin_sort_tree tree;
	int index = 0;	
	int *pindex = &index;
	int arr[] = {6, 3, 2, 0, 0, 5, 4, 0, 0, 0, 8, 0, 0};

	//tree = bin_sort_tree_create();
	tree = bin_sort_tree_create_from_arr(arr, ARR_SIZE(arr), &pindex);
	bin_sort_tree_show(tree);
	
	PP(bin_sort_tree_find(tree, 5));
	PP(bin_sort_tree_find(tree, 9));
	PP(bin_sort_tree_find(tree, 1));

	PD(bin_sort_tree_insert(&tree, 3));
	PD(bin_sort_tree_insert(&tree, 10));
	PD(bin_sort_tree_insert(&tree, 7));
	PD(bin_sort_tree_insert(&tree, 5));

	//bin_sort_tree_show(tree);
	//PD(bin_sort_tree_delete(&tree, 6));
	bin_sort_tree_show(tree);
	PD(bin_sort_tree_delete(&tree, 100));
	bin_sort_tree_show(tree);
	PD(bin_sort_tree_delete(&tree, 3));
	bin_sort_tree_show(tree);

    return 0;
}
