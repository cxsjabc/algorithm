#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h> 

#include <assert.h> 

#include "bitree_exp.h"
#include "stack.h"

// assume that: operator and operand are single character.
void			infix_to_postfix(const char *in, char *post)
{
	int i = 0;
	Stack	*sta;

	sta = stack_create();
	assert(sta);

	while(*in) {
		char ch = *in;
		if(isdigit(ch)) {	 // is operand
			post[i++] = *in;
		} else if(ch == '(')
			assert(stack_push(sta, ch) >= 0);
		else if(ch == ')') {
			char temp = (char)stack_top(sta);
			while(temp != '(') {
				temp = (char)stack_top(sta);
				stack_pop(sta);
				post[i++] = temp;
				temp = (char)stack_top(sta);
			}
			stack_pop(sta);
		} else { // is operator
			if(stack_empty(sta))
				stack_push(sta, ch);
			else {
				char temp = (char)stack_top(sta);
				if(temp == '(')
					stack_push(sta, ch);
				else if(temp == '+' || temp == '-') {
					if(ch == '*' || ch == '/')
						stack_push(sta, ch);
					else {
						temp = (char)stack_top(sta);	
						stack_pop(sta);
						post[i++] = temp;
						continue;
					}
				} else if(temp == '*' || temp == '/') {
					stack_pop(sta);
					post[i++] = temp;
					continue;
				}
			}
		}
		++in;
	}
	while(!stack_empty(sta)) {
		char temp = stack_top(sta);
		post[i++] = temp;
		stack_pop(sta);
	}
	post[i] = '\0';
	stack_destroy(sta);
	printf("post expression:%s\n", post);
}

BiTreeExp *		bitree_exp_create()
{
	BiTreeExp *t;
	t = (BiTreeExp *)malloc(sizeof(BiTreeExp));

	if(!t)
		return NULL;

	memset(t, 0, sizeof(BiTreeExp));
	return t;	
}

BiTreeExp *		bitree_exp_create_by_str(const char *exp_str)
{
	Stack *sta;
	const char *s = exp_str;
	BiTreeExpNode *n, *left, *right;
	int ret;
	BiTreeExp *t;

	t = bitree_exp_create();
	assert(t);
	sta = stack_create();
	assert(sta);

	while(*s) {
		printf("processing: %c\n", *s);
		if((*s) >= '0' && (*s) <= '9') {	// means operand 
			n = (BiTreeExpNode *)malloc(sizeof(BiTreeExpNode));
			assert(n);
			n->v = *s - '0';
			n->left = n->right = NULL;
			ret = stack_push(sta, (long long)n);
			assert(ret >= 0);
		} else { // means operator
			n = (BiTreeExpNode *)malloc(sizeof(BiTreeExpNode));
			assert(n);
			n->op = *s;
			n->left = n->right = NULL;
			right = (BiTreeExpNode *)stack_pop(sta);
			left = (BiTreeExpNode *)stack_pop(sta);
			n->left = left;
			n->right = right;
			ret = stack_push(sta, (long long)n);		
			assert(ret >= 0);
		}
		++s;
	}
	t->root = (BiTreeExpNode *)stack_pop(sta);
	t->size = bitree_exp_cal_size(t);
	return t;
}

void			bitree_exp_destroy_branch(BiTreeExpNode *n)
{
	if(!n)
		return;

	if(n->left)
		bitree_exp_destroy_branch(n->left);
	if(n->right)
		bitree_exp_destroy_branch(n->right);
	free(n);
}

void			bitree_exp_destroy(BiTreeExp *t)
{
	BiTreeExpNode *root;
	if(!t)
		return;

	root = t->root;
	bitree_exp_destroy_branch(root);
	free(t);
}

int				bitree_exp_ins_left(BiTreeExp *t, BiTreeExpNode *n, int v)
{
	BiTreeExpNode *nn;
	if(!t)
		return -1;
	nn = (BiTreeExpNode *)malloc(sizeof(BiTreeExpNode));
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

int				bitree_exp_ins_right(BiTreeExp *t, BiTreeExpNode *n, int v)
{
	BiTreeExpNode *nn;
	if(!t)
		return -1;
	nn = (BiTreeExpNode *)malloc(sizeof(BiTreeExpNode));
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

int				bitree_exp_remove_left(BiTreeExp *t, BiTreeExpNode *n)
{
	BiTreeExpNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->left);
	if(*pos != NULL) {
		bitree_exp_remove_left(t, *pos);
		bitree_exp_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		--(t->size);
	}
	return 0;
}

int				bitree_exp_remove_right(BiTreeExp *t, BiTreeExpNode *n)
{
	BiTreeExpNode	** pos;
	if(!t)
		return -1;
	if(n == NULL)
		pos = &(t->root);
	else
		pos = &(n->right);
	if(*pos != NULL) {
		bitree_exp_remove_left(t, *pos);
		bitree_exp_remove_right(t, *pos);
		free(*pos);
		*pos = NULL;
		--(t->size);
	}
	return 0;

}

void			bitree_exp_visit_node(BiTreeExpNode *n)
{
	if(n->left == NULL && n->right == NULL)
		printf("%d ", n->v);
	else
		printf("%c ", n->op);
}

void			bitree_exp_show_branch(BiTreeExpNode *n)
{
	if(!n)
		return;
	bitree_exp_visit_node(n);
	bitree_exp_show_branch(n->left);	
	bitree_exp_show_branch(n->right);	
}

void			bitree_exp_show(BiTreeExp *tree)
{	
	BiTreeExpNode *n;
	if(!tree)
		return;

	n = tree->root;
	printf("preorder:");
	bitree_exp_show_branch(n);
	printf("\n");
}

void			bitree_exp_inorder_internal(BiTreeExpNode *n)
{
	if(!n)
		return;
	bitree_exp_inorder_internal(n->left);	
	bitree_exp_visit_node(n);
	bitree_exp_inorder_internal(n->right);	
}

void			bitree_exp_inorder(BiTreeExp *t)
{
	printf("inorder:");
	if(t) {
		bitree_exp_inorder_internal(t->root);
	}	
	printf("\n");
}

void			bitree_exp_postorder_internal(BiTreeExpNode *n)
{
	if(!n)
		return;
	bitree_exp_postorder_internal(n->left);	
	bitree_exp_postorder_internal(n->right);	
	bitree_exp_visit_node(n);
}

void			bitree_exp_postorder(BiTreeExp *t)
{
	printf("postorder:");
	if(t)
		bitree_exp_postorder_internal(t->root);
	printf("\n");
}

int			bitree_exp_cal_size_internal(BiTreeExpNode *n) 
{
	if(!n)
		return 0;
	return 1 + bitree_exp_cal_size_internal(n->left) + bitree_exp_cal_size_internal(n->right);
}

int			bitree_exp_cal_size(BiTreeExp *t)
{
	int size= bitree_exp_cal_size_internal(t->root);
	t->size = size;	
	return size;
}

