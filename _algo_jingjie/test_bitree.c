#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "bitree.h"

#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);

void test_bitree1()
{
	BiTree *t;
	int ret;	
	int i = 1;
	BiTreeNode *n;

	t = bitree_create();
	assert(t);
	
	for(; i <= 16; ++i) {
		n = bitree_insert(t, i);
		assert(n);
	}
		
	bitree_show(t);

	bitree_destroy(t);
}

void test_bitree()
{
	BiTree *t;
	int ret;	

	t = bitree_create();
	assert(t);

	ret = bitree_ins_left(t, NULL, 1);
	assert(ret >= 0);
	
	ret = bitree_ins_left(t, t->root, 2);
	assert(ret >= 0);
	
	ret = bitree_ins_right(t, t->root, 3);
	assert(ret >= 0);
	

	bitree_show(t);
	

	ret = bitree_remove_left(t, t->root);	
	
	assert(ret >= 0);
	bitree_show(t);
	

	ret = bitree_remove_right(t, t->root);	
	
	assert(ret >= 0);
	bitree_show(t);
	
	
	bitree_destroy(t);
	
}


int main()
{
	//test_bitree();

	test_bitree1();

	return 0;
}
