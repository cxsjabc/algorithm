#include <queue>
#include "common_local.h"

using namespace std;

typedef struct _MyTreeNode
{
	int	data;
	struct _MyTreeNode	*left;
	struct _MyTreeNode	*right;
}MyTreeNode;

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

void mytree_level_traverse(MyTreeNode *t)
{
	queue<MyTreeNode *> q;

	q.push(t);
	while(!q.empty()) {
		MyTreeNode *n = q.front();	
		q.pop();
		if(n) {
			if(n->left)
				q.push(n->left);
			if(n->right)
				q.push(n->right);
			printf("%d ", n->data);
		}
	}
}

int main()
{
	MyTreeNode *t, *n, *temp[128];

	t = mytree_create(NULL);
	t = mytree_add_node(t, 10, 0);
	temp[0] = mytree_add_node(t, 2, 1);
	temp[1] = mytree_add_node(temp[0], 9, 1);
	temp[2] = mytree_add_node(t, 8, 2);
	temp[3] = mytree_add_node(temp[2], 4, 2);
	temp[4] = mytree_add_node(temp[3], 6, 1);
	temp[5] = mytree_add_node(temp[3], 20, 2);
	
	mytree_show(t);
	n = mytree_find(t, 4);
	printf("n:%p, data:%d\n", n, n ? n->data : -1);
	n = mytree_find(t, 7);
	printf("n:%p, data:%d\n", n, n ? n->data : -1);

	mytree_level_traverse(t);
	
	mytree_destroy(t);
    return 0;
}
