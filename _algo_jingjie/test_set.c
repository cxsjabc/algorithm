#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <assert.h> 

#include "set.h"

#define LOG_HERE	printf("[%s@%d]\n", __func__, __LINE__);

void test_set()
{
	PSet s1, s2, s3;
	int i;
	PSetNode node;
	int v;

	s1 = set_create();
	s2 = set_create();
	s3 = set_create();
	assert(s1);
	assert(s2);
	assert(s3);

	i = 1;	
	while(i < 5) {
		assert(set_insert(s1, i) == 0);
		++i;
	}

	i = 1;
	while(i < 5) {
		assert(set_insert(s2, i) == 0);
		++i;
	}

	set_show(s1);
	set_show(s2);
	assert(set_is_member(s1, 4));
	assert(!set_is_member(s1, 6));
	assert(set_is_equal(s1, s2));

	set_remove(s1, 3);
	assert(!set_is_equal(s1, s2));
	set_show(s1);

	assert(set_is_subset(s1, s2));
	assert(!set_is_subset(s2, s1));

	set_insert(s1, 3);
	set_show(s1);
	assert(set_is_equal(s1, s2));

	set_insert(s2, 100);
	set_union(s3, s1, s2);
	set_show(s3);

	set_clear(s3);
	set_show(s3);	
	set_intersection(s3, s1, s2);
	set_show(s3);

	set_insert(s1, 9);
	set_insert(s2, 8);
	set_clear(s3);
	set_difference(s3, s2, s1);
	set_show(s3);

	set_destroy(s1);
	set_destroy(s2);
	set_destroy(s3);
}

int main()
{
	test_set();

	return 0;
}
