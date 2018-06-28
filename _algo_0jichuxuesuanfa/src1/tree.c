#include "common_local.h"

typedef struct _MyTreeNode
{
	int	data;
	struct _MyTreeNode	*left;
	struct _MyTreeNode	*right;
}MyTreeNode;

MyTreeNode *	mytree_find(MyTreeNode *n, int data);

MyTreeNode *  _alloc_treenode(int data)
{
	MyTreeNode *p = (MyTreeNode *)malloc(sizeof(MyTreeNode));
	if(!p)
		return NULL;

	p->data = data;
	p->left = p->right = NULL;
	return p;
}

MyTreeNode *	mytree_create(MyTreeNode *p)
{
	return p;
}

// dir: 1 --> add at the left child, 2 --> add at the right child
MyTreeNode * mytree_add_node(MyTreeNode *parent, int data, int dir)
{
	MyTreeNode *p;

	p = _alloc_treenode(data);	
	if(!p)
		return NULL;

	if(!parent) {
		return p;		
	} else {
		if(dir == 1) {
			if(parent->left) {
				fprintf(stderr, "ERROR:left child exists!\n");
				free(p);
				return NULL;
			} else
				parent->left = p;
		} else {
			if(parent->right) {
				fprintf(stderr, "ERROR:right child exists!\n");
				free(p);
				return NULL;
			} else
				parent->right = p;
		}
	}
	return p;
}

void	mytree_add_node_from_input(MyTreeNode *t)
{
	int data, parent_data, dir;
	MyTreeNode *n;
	int flag;

	while(1) {
		printf("Input flag data parent_data dir:");

		scanf("%d%d%d%d", &flag, &data, &parent_data, &dir);	
		if(flag == -1)
			break;
		n = mytree_find(t, parent_data);	
		if(!n) {
			printf("parent_data:%d not exist!\n", parent_data);
			return;
		}
		if(dir != 1 && dir != 2) {
			printf("dir error!\n");
			return;
		}

		mytree_add_node(n, data, dir);
	}
}

void	mytree_show(MyTreeNode *n)
{
	if(n) {
		printf("%d ", n->data);
		mytree_show(n->left);
		mytree_show(n->right);
	}
}

MyTreeNode *	mytree_find(MyTreeNode *n, int data)
{
	MyTreeNode *p;

	if(!n)
		return NULL;

	if(n->data == data)
		return n;
	else {
		p = mytree_find(n->left, data);
		if(p)
			return p;
		else {
			p = mytree_find(n->right, data);
			return p;
		}	
	}
}

void	mytree_destroy(MyTreeNode *t)
{
	if(t) {
		mytree_destroy(t->left);
		mytree_destroy(t->right);
		free(t);	
	}
}

int main()
{
	MyTreeNode *t, *n;

	t = mytree_create(NULL);
	t = mytree_add_node(t, 10, 0);
	n = mytree_add_node(t, 2, 1);
	n = mytree_add_node(t, 8, 2);
	n = mytree_add_node(n, 4, 2);
	n = mytree_add_node(n, 6, 1);
	
	mytree_show(t);
	n = mytree_find(t, 4);
	printf("n:%p, data:%d\n", n, n ? n->data : -1);
	n = mytree_find(t, 7);
	printf("n:%p, data:%d\n", n, n ? n->data : -1);

	mytree_destroy(t);

	t = mytree_add_node(NULL, 100, 0);
	mytree_add_node_from_input(t);
	mytree_show(t);
	mytree_destroy(t);

    return 0;
}
