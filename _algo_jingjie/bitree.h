#ifndef BITREE_H
#define BITREE_H

typedef struct _BiTreeNode
{
	int		v;
	struct _BiTreeNode	*left;
	struct _BiTreeNode	*right;
} BiTreeNode;


typedef struct _BiTree
{
	int				size;
	BiTreeNode		*root;
} BiTree;

BiTree *		bitree_create();
void			bitree_destroy(BiTree *t);
void			bitree_destroy_branch(BiTreeNode *n);
int				bitree_ins_left(BiTree *t, BiTreeNode *n, int v);
int				bitree_ins_right(BiTree *t, BiTreeNode *n, int v);
int				bitree_remove_left(BiTree *t, BiTreeNode *n);
int				bitree_remove_right(BiTree *t, BiTreeNode *n);

BiTreeNode *	bitree_insert(BiTree *t, int v);		
BiTreeNode *	bitree_remove(BiTree *t, int v);		

#define			bitree_is_leaf(node)	(((node)->left == NULL) && ((node)->right == NULL))

void			bitree_show(BiTree *t);

#define			bitree_prefix_show		bitree_show
#define			bitree_preorder		bitree_prefix_show
void			bitree_inorder(BiTree *t);
void			bitree_postorder(BiTree *t);	

int				bitree_cal_size(BiTree *t);

#endif
