#include <stdlib.h>
#include "tree.h"

#include "common.h"


void tree_make_empty(PTree tree)
{
	if(tree == NULL)
		return;
	
	tree_make_empty(tree->left);
	tree_make_empty(tree->right);
	free(tree);
}

PTreeNode	tree_find(PTree tree, int data)
{
	PTree node;
	if(tree == NULL)
		return NULL;

	if(tree->data == data)
		return tree;
	
	node = tree_find(tree->left, data);
	if(node != NULL)
		return node;
	node = tree_find(tree->right, data);
	return node;
}

PTreeNode	binary_tree_find(PTree tree, int data)
{
	if(tree == NULL)
		return NULL;
	if(tree->data == data)
		return tree;
	
	if(tree->data < data)
		return binary_tree_find(tree->right, data);
	else
		return binary_tree_find(tree->left, data);
}

int			binary_tree_find_min(PTree tree)
{
	if(tree->left == NULL)
		return tree->data;
	else
		return binary_tree_find_min(tree->left);
}

int			binary_tree_find_max(PTree tree)
{
	if(tree->right == NULL)
		return tree->data;
	else
		return binary_tree_find_max(tree->right);
}


PTree		binary_tree_insert(PTree tree, int data)
{
	if(tree == NULL) {
		PTree root = (PTree)malloc(sizeof(Tree));
		if(!root)
			return NULL;
		
		root->data = data;
		root->left = root->right = NULL;
		tree = root;
//		LOG_HERE;
	}
	else if(tree->data == data)
		return tree;
	else if(tree->data < data) {
		tree->right = binary_tree_insert(tree->right, data);
	} else {
		tree->left = binary_tree_insert(tree->left, data);
	}
	//printf("tree:%p\n", tree);
	return tree;	
}

void		tree_show(PTree tree)
{
	if(tree == NULL)
		return;
	printf("%d ", tree->data);
	tree_show(tree->left);
	tree_show(tree->right);
}

void		tree_free(PTree tree)
{
	if(tree) {
		tree_free(tree->left);
		tree_free(tree->right);
		free(tree);
	}
}
