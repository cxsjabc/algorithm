#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "bitree_exp.h"

#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);

void test_bitree_exp1()
{
	BiTreeExp *t;
	int ret;
	char *s = "12+345+**";
	char *p = s;
	char buf[512];
	char post_buf[512];
	scanf("%s", buf);
	if(buf[0] != 'a') {	// infix test
		infix_to_postfix(buf, post_buf);
		p = post_buf;
	}

	
	t = bitree_exp_create_by_str(p);
	assert(t);
	
	bitree_exp_preorder(t);	
	bitree_exp_inorder(t);	
	bitree_exp_postorder(t);	


	bitree_exp_destroy(t);
}

void test_bitree_exp()
{
	BiTreeExp *t;
	int ret;	

	t = bitree_exp_create();
	assert(t);

	ret = bitree_exp_ins_left(t, NULL, 1);
	assert(ret >= 0);
	
	ret = bitree_exp_ins_left(t, t->root, 2);
	assert(ret >= 0);
	
	ret = bitree_exp_ins_right(t, t->root, 3);
	assert(ret >= 0);
	

	bitree_exp_show(t);
	

	ret = bitree_exp_remove_left(t, t->root);	
	
	assert(ret >= 0);
	bitree_exp_show(t);
	

	ret = bitree_exp_remove_right(t, t->root);	
	
	assert(ret >= 0);
	bitree_exp_show(t);
	
	
	bitree_exp_destroy(t);
	
}


int main()
{
	//test_bitree_exp();
	test_bitree_exp1();
	return 0;
}
