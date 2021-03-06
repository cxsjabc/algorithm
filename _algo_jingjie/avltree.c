#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#include "avltree.h"

AvlTree *		avltree_create()
{
	AvlTree *t;
	
	t = (AvlTree *)malloc(sizeof(AvlTree));

	if(!t)
		return NULL;

	memset(t, 0, sizeof(AvlTree));
	return t;	
}

void			avltree_destroy_branch(AvlTreeNode *n)
{
	if(!n)
		return;

	if(n->left)
		avltree_destroy_branch(n->left);
	if(n->right)
		avltree_destroy_branch(n->right);
	free(n);
}

void			avltree_destroy(AvlTree *t)
{
	AvlTreeNode *root;
	if(!t)
		return;

	root = t->root;
	avltree_destroy_branch(root);
	free(t);
}

int				avltree_ins_left(AvlTree *t, AvlTreeNode *n, int v)
{
	AvlTreeNode *nn;
	if(!t)
		return -1;
	nn = (AvlTreeNode *)malloc(sizeof(AvlTreeNode));
	if(!nn)
		return -2;
	if(n == NULL) {
		if(t->size > 0) {
			free(nn);
			return -3;
		}
		nn->v = v;
		nn->left = nn->right = NULL;
		nn->h = 1;
		t->root = nn;
		t->size = 1;
		
		return 0;
	}
	if(n->left != NULL)
		return -4;
	n->left = nn;

	nn->v = v;
	nn->left = nn->right = NULL;
	nn->h = 1;

	n->h = avltree_cal_height_internal(n);

	++(t->size);
	return 0;
}

int				avltree_ins_right(AvlTree *t, AvlTreeNode *n, int v)
{
	AvlTreeNode *nn;
	if(!t)
		return -1;
	nn = (AvlTreeNode *)malloc(sizeof(AvlTreeNode));
	if(!nn)
		return -2;
	if(n == NULL) {
		if(t->size > 0) {
			free(nn);
			return -3;
		}
		nn->v = v;
		nn->h = 1;
		nn->left = nn->right = NULL;
		t->root = nn;
		t->size = 1;
		return 0;
	}
	if(n->right != NULL)
		return -4;
	n->right = nn;
	nn->v = v;
	nn->h = 1;
	nn->left = nn->right = NULL;
	n->h = avltree_cal_height_internal(n);
	++(t->size);
	return 0;
}

int				avltree_remove_left(AvlTree *t, AvlTreeNode *n)
{
	AvlTreeNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->left);
	if(*pos != NULL) {
		avltree_remove_left(t, *pos);
		avltree_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		n->h = avltree_cal_height_internal(n);	
		
		--(t->size);
	}
	return 0;
}

int				avltree_remove_right(AvlTree *t, AvlTreeNode *n)
{
	AvlTreeNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->right);
	if(*pos != NULL) {
		avltree_remove_left(t, *pos);
		avltree_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		n->h = avltree_cal_height_internal(n);	
		--(t->size);
	}
	return 0;

}

AvlTreeNode *				avltree_insert_internal(AvlTreeNode **t, int v)
{
	AvlTreeNode *n = *t;
	if(n == NULL) {
		n = (AvlTreeNode *)malloc(sizeof(AvlTreeNode));
		if(!n)
			return NULL;
		n->v = v;
		n->h = 1;
		n->left = n->right = NULL;
		*t = n;  // need it?
	} else {
		if(v == n->v)
			return n;
		else if(v < n->v) {
			int balance;
			n->left = avltree_insert_internal(&(n->left), v);
			balance = avltree_get_node_height(n->left) - avltree_get_node_height(n->right);
			if(balance == 2) {
				if(v < n->left->v) { // LL
					n = singleRightRotate(n);
					*t = n;
				} else {	// LR
					n = leftRightRotate(n);
				}
			}
		}
		else { // v > n->v
			int balance;
			n->right = avltree_insert_internal(&(n->right), v);
			balance = avltree_get_node_height(n->right) - avltree_get_node_height(n->left);
			if(balance == 2) {
				if(v > n->right->v) { // RR 
					n = singleLeftRotate(n);
					*t = n;
				} else {	// RL
					n = rightLeftRotate(n);
				}
			}
		}
	}
	n->h = max(avltree_get_node_height(n->left), avltree_get_node_height(n->right)) + 1;
	return n;
}

AvlTreeNode *				avltree_insert(AvlTree *t, int v)
{
	return avltree_insert_internal(&(t->root), v);
}

AvlTreeNode *				avltree_remove_internal(AvlTreeNode **t, int v)
{
	AvlTreeNode *n = *t;
	int		balance;

	if(n == NULL)
		return NULL;

	if(v > n->v)
		n->right = avltree_remove_internal(&(n->right), v);
	else if(v < n->v)
		n->left = avltree_remove_internal(&(n->left), v);
	else {
		if(n->left != NULL) {
			AvlTreeNode *max = n->left;
			// find max in left sub tree
			for(; max->right != NULL; max = max->right) ;
			n->v = max->v;
			n->left = avltree_remove_internal(&(n->left), max->v);
		} else if(n->right != NULL) {
			AvlTreeNode *min = n->right;
			// find min in right sub tree
			for(; min->left != NULL; min = min->left) ;
			n->v = min->v;
			n->right = avltree_remove_internal(&(n->right), min->v);
		} else {
			free(n);
			return NULL;
		}
	}
	
	balance = avltree_get_node_height(n->left) - avltree_get_node_height(n->right);
	if(balance == 2) {
		if(avltree_get_node_height(n->left->right) - avltree_get_node_height(n->left->left) == 1)
			n = leftRightRotate(n);
		else
			n = singleRightRotate(n);
	} else if(balance == -2) {
		if(avltree_get_node_height(n->right->left) - avltree_get_node_height(n->right->right) == 1)
			n = rightLeftRotate(n);
		else
			n = singleLeftRotate(n);
	} else {
		// do nothing
	}

	n->h = max(avltree_get_node_height(n->left), avltree_get_node_height(n->right)) + 1;
	return n;
}

AvlTreeNode *				avltree_remove(AvlTree *t, int v)
{
	return avltree_remove_internal(&(t->root), v);
}

AvlTreeNode	*		singleRightRotate(AvlTreeNode *n)	// LL
{	
	AvlTreeNode *anode = n;
	AvlTreeNode	*bnode = anode->left;

	anode->left = bnode->right;
	bnode->right = anode;
	
	anode->h = max(avltree_get_node_height(anode->left), avltree_get_node_height(anode->right)) + 1;
	bnode->h = max(avltree_get_node_height(bnode->left), avltree_get_node_height(bnode->right)) + 1;
	return bnode;
}

AvlTreeNode	*		singleLeftRotate(AvlTreeNode *n)	// RR
{
	AvlTreeNode	*anode = n;
	AvlTreeNode	*bnode = n->right;

	anode->right = bnode->left;
	bnode->left = anode;
	anode->h = max(avltree_get_node_height(anode->left), avltree_get_node_height(anode->right)) + 1;
	bnode->h = max(avltree_get_node_height(bnode->left), avltree_get_node_height(bnode->right)) + 1;
	return bnode;
}

AvlTreeNode	*		leftRightRotate(AvlTreeNode *n)	// LR
{
	n->left = singleLeftRotate(n->left);
	return singleRightRotate(n);
}

AvlTreeNode	*		rightLeftRotate(AvlTreeNode *n)	// RL
{
	n->right = singleRightRotate(n->right);
	return singleLeftRotate(n);
}

void			avltree_visit_node(AvlTreeNode *n)
{
	printf("%d(h:%d,l:%d,r:%d) ", n->v, n->h, n->left ? n->left->v : -1, n->right ? n->right->v : -1);
}

void			avltree_show_branch(AvlTreeNode *n)
{
	if(!n)
		return;
	avltree_visit_node(n);
	avltree_show_branch(n->left);	
	avltree_show_branch(n->right);	
}

void			avltree_show(AvlTree *tree)
{	
	AvlTreeNode *n;
	if(!tree)
		return;

	printf("preorder:");
	n = tree->root;
	avltree_show_branch(n);
	printf("\n");
}

void			avltree_inorder_internal(AvlTreeNode *n)
{
	if(!n)
		return;
	avltree_inorder_internal(n->left);	
	avltree_visit_node(n);
	avltree_inorder_internal(n->right);	
}

void			avltree_inorder(AvlTree *t)
{
	printf("inorder:");
	if(t) {
		avltree_inorder_internal(t->root);
	}	
	printf("\n");
}

void			avltree_postorder_internal(AvlTreeNode *n)
{
	if(!n)
		return;
	avltree_postorder_internal(n->left);	
	avltree_postorder_internal(n->right);	
	avltree_visit_node(n);
}

void			avltree_postorder(AvlTree *t)
{
	printf("postorder:");
	if(t)
		avltree_postorder_internal(t->root);
	printf("\n");
}

int			avltree_cal_size_internal(AvlTreeNode *n) 
{
	if(!n)
		return 0;
	return 1 + avltree_cal_size_internal(n->left) + avltree_cal_size_internal(n->right);
}

int			avltree_cal_size(AvlTree *t)
{
	int size= avltree_cal_size_internal(t->root);
	t->size = size;	
	return size;
}

int				avltree_cal_height_internal(AvlTreeNode *n)
{
	if(!n)
		return 0;
	return 1 + max(avltree_cal_height_internal(n->left), avltree_cal_height_internal(n->right));
}

int				avltree_cal_height(AvlTree *t)
{
	if(!t)
		return 0;
	return avltree_cal_height_internal(t->root);
}

int				avltree_get_node_height(AvlTreeNode *n)
{
	if(!n)
		return 0;
	return n->h;
}
