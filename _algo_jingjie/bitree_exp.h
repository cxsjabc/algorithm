#ifndef BITREE_EXP_H
#define BITREE_EXP_H

// expression bi-tree
typedef struct _BiTreeExpNode
{
	union {
		int		v;
		char	op;
	};
	struct _BiTreeExpNode	*left;
	struct _BiTreeExpNode	*right;
} BiTreeExpNode;


typedef struct _BiTreeExp
{
	int				size;
	BiTreeExpNode		*root;
} BiTreeExp;

// assume that: operator and operand are single character.
void			infix_to_postfix(const char *in, char *post);

BiTreeExp *		bitree_exp_create();
BiTreeExp *		bitree_exp_create_by_str(const char *exp_str);
void			bitree_exp_destroy(BiTreeExp *t);
void			bitree_exp_destroy_branch(BiTreeExpNode *n);
int				bitree_exp_ins_left(BiTreeExp *t, BiTreeExpNode *n, int v);
int				bitree_exp_ins_right(BiTreeExp *t, BiTreeExpNode *n, int v);
int				bitree_exp_remove_left(BiTreeExp *t, BiTreeExpNode *n);
int				bitree_exp_remove_right(BiTreeExp *t, BiTreeExpNode *n);

#define			bitree_exp_is_leaf(node)	(((node)->left == NULL) && ((node)->right == NULL))

void			bitree_exp_show(BiTreeExp *t);
#define			bitree_exp_prefix_show		bitree_exp_show
#define			bitree_exp_preorder		bitree_exp_prefix_show
void			bitree_exp_inorder(BiTreeExp *t);
void			bitree_exp_postorder(BiTreeExp *t);	

int				bitree_exp_cal_size(BiTreeExp *t);

#endif
