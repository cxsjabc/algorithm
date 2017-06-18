#ifndef AVLTREE_H
#define AVLTREE_H

#define max(a, b)		((a) > (b) ? (a) : (b))

typedef struct _AvlTreeNode
{
	int		v;	// value
	int		h;	// height
	struct _AvlTreeNode	*left;
	struct _AvlTreeNode	*right;
} AvlTreeNode;


typedef struct _AvlTree
{
	int				size;
	AvlTreeNode		*root;
} AvlTree;

AvlTree *		avltree_create();
void			avltree_destroy(AvlTree *t);
void			avltree_destroy_branch(AvlTreeNode *n);
int				avltree_ins_left(AvlTree *t, AvlTreeNode *n, int v);
int				avltree_ins_right(AvlTree *t, AvlTreeNode *n, int v);
int				avltree_remove_left(AvlTree *t, AvlTreeNode *n);
int				avltree_remove_right(AvlTree *t, AvlTreeNode *n);

AvlTreeNode	*	avltree_insert(AvlTree *t, int v);
AvlTreeNode	*	avltree_remove(AvlTree *t, int v);

AvlTreeNode	*		singleRightRotate(AvlTreeNode *n);	// LL
AvlTreeNode	*		singleLeftRotate(AvlTreeNode *n);	// RR
AvlTreeNode	*		leftRightRotate(AvlTreeNode *n);	// LR
AvlTreeNode	*		rightLeftRotate(AvlTreeNode *n);	// RL

#define			avltree_is_leaf(node)	(((node)->left == NULL) && ((node)->right == NULL))

void			avltree_show(AvlTree *t);

#define			avltree_prefix_show		avltree_show
#define			avltree_preorder		avltree_prefix_show
void			avltree_inorder(AvlTree *t);
void			avltree_postorder(AvlTree *t);	

int				avltree_cal_size(AvlTree *t);
int				avltree_cal_height(AvlTree *t);
int				avltree_cal_height_internal(AvlTreeNode *n);
int				avltree_get_node_height(AvlTreeNode *n);

#endif
