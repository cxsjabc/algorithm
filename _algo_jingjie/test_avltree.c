#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "avltree.h"

//#define DEBUG

#ifdef	DEBUG 
#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);
#define	LH			LOG_HERE
#else
#define LOG_HERE	
#define	LH			LOG_HERE
#endif

void test_avltree1()
{
	AvlTree *t;
	int ret;	

	t = avltree_create();
	avltree_insert(t, 10);
	avltree_insert(t, 6);
	avltree_insert(t, 20);
	avltree_insert(t, 4);
	avltree_insert(t, 8);

	avltree_inorder(t);

	avltree_destroy(t);
}

void test_avltree()
{
	AvlTree *t;
	int ret;	

	t = avltree_create();
	assert(t);
	LH
	ret = avltree_ins_left(t, NULL, 1);
	assert(ret >= 0);
	LH
	
	ret = avltree_ins_left(t, t->root, 2);
	assert(ret >= 0);
	LH
	
	ret = avltree_ins_right(t, t->root, 3);
	assert(ret >= 0);
	LH
	

	avltree_show(t);
	

	ret = avltree_remove_left(t, t->root);	
	
	assert(ret >= 0);
	avltree_show(t);
	

	ret = avltree_remove_right(t, t->root);	
	
	assert(ret >= 0);
	avltree_show(t);
	
	
	avltree_destroy(t);
	
}


int main()
{
	//test_avltree();
	test_avltree1();
	return 0;
}
