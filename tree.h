#ifndef TREE_H
#define TREE_H


typedef struct _TreeNode
{
	int data;
	struct _TreeNode * 	left;
	struct _TreeNode *	right;
}TreeNode;

typedef TreeNode * 	PTreeNode;
typedef TreeNode * 	PTree;

typedef TreeNode 		Tree;

void		tree_make_empty(PTree tree);
PTreeNode	tree_find(PTree tree, int data);

PTreeNode	binary_tree_find(PTree tree, int data);
int			binary_tree_find_min(PTree tree);
int			binary_tree_find_max(PTree tree);

PTree		binary_tree_insert(PTree tree, int data);

void		tree_show(PTree tree);

void		tree_free(PTree tree);

#endif
