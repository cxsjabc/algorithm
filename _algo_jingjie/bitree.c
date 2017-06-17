#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "bitree.h"

BiTree *		bitree_create()
{
	BiTree *t;
	t = (BiTree *)malloc(sizeof(BiTree));

	if(!t)
		return NULL;

	memset(t, 0, sizeof(BiTree));
	return t;	
}

void			bitree_destroy_branch(BiTreeNode *n)
{
	if(!n)
		return;

	if(n->left)
		bitree_destroy_branch(n->left);
	if(n->right)
		bitree_destroy_branch(n->right);
	free(n);
}

void			bitree_destroy(BiTree *t)
{
	BiTreeNode *root;
	if(!t)
		return;

	root = t->root;
	bitree_destroy_branch(root);
	free(t);
}

int				bitree_ins_left(BiTree *t, BiTreeNode *n, int v)
{
	BiTreeNode *nn;
	if(!t)
		return -1;
	nn = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if(!nn)
		return -2;
	if(n == NULL) {
		if(t->size > 0) {
			free(nn);
			return -3;
		}
		nn->v = v;
		nn->left = nn->right = NULL;
		t->root = nn;
		t->size = 1;
		return 0;
	}
	if(n->left != NULL)
		return -4;
	n->left = nn;
	nn->v = v;
	nn->left = nn->right = NULL;
	++(t->size);
	return 0;
}

int				bitree_ins_right(BiTree *t, BiTreeNode *n, int v)
{
	BiTreeNode *nn;
	if(!t)
		return -1;
	nn = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	if(!nn)
		return -2;
	if(n == NULL) {
		if(t->size > 0) {
			free(nn);
			return -3;
		}
		nn->v = v;
		nn->left = nn->right = NULL;
		t->root = nn;
		t->size = 1;
		return 0;
	}
	if(n->right != NULL)
		return -4;
	n->right = nn;
	nn->v = v;
	nn->left = nn->right = NULL;
	++(t->size);
	return 0;
}

int				bitree_remove_left(BiTree *t, BiTreeNode *n)
{
	BiTreeNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->left);
	if(*pos != NULL) {
		bitree_remove_left(t, *pos);
		bitree_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		--(t->size);
	}
	return 0;
}

int				bitree_remove_right(BiTree *t, BiTreeNode *n)
{
	BiTreeNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->right);
	if(*pos != NULL) {
		bitree_remove_left(t, *pos);
		bitree_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		--(t->size);
	}
	return 0;

}

void			bitree_show_branch(BiTreeNode *n)
{
	if(!n)
		return;
	printf("%d ", n->v);
	bitree_show_branch(n->left);	
	bitree_show_branch(n->right);	
}

void			bitree_show(BiTree *tree)
{	
	BiTreeNode *n;
	if(!tree)
		return;

	n = tree->root;
	bitree_show_branch(n);
	printf("\n");
}

