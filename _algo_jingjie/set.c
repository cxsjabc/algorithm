#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "set.h"


PSet	set_create()
{
	PSet s;
	PSetNode node;

	s = (PSet)malloc(sizeof(Set));
	if(!s)
		return NULL;
	
	node = (PSetNode)malloc(sizeof(SetNode));
	if(!node) {
		free(s);
		return NULL;
	}
	node->v = 0x12345678;
	node->next = NULL;

	s->head = node;
	s->tail = node;
	s->size = 0;	

	return s;
}

int			set_copy_from(PSet dest, PSet src)
{
	int ret = 0;
	PSetNode n = src->head->next;

	while(n) {
		ret = set_insert(dest, n->v);
		if(ret < 0 && ret != -10)
			return -1;
		n = n->next;
	}
	return 0;
}

int		set_insert(PSet s, int v)
{
	PSetNode node;
	PSetNode tail;
	PSetNode next;

	node = (PSetNode)malloc(sizeof(SetNode));
	if(!node)
		return -1;

	if(set_is_member(s, v))
		return -10;
	
	tail = s->tail;

	node->v = v;
	node->next = NULL;

	s->tail = node;
	tail->next = node;

	++(s->size);
	return 0;
}

int			set_remove(PSet s, int v)
{
	PSetNode prv;
	PSetNode n, nn;

	if(s->size < 1)
		return -1;

	prv = s->head;
	n = prv->next;
	nn = n->next;

	while(n) {
		if(n->v == v) {
			break;
		}
		prv = n;
		n = n->next;
		if(n)
			nn = n->next;
		else	
			nn = NULL;
	}

	if(n->v != v)
		return -1;
	
	prv->next = nn;
	free(n);
	if(!nn)
		s->tail = prv;

	--(s->size);

	return 0;
}

int			set_union(PSet new_set, PSet s1, PSet s2)
{
	int ret = 0;
	PSetNode n = s2->head->next;

	ret = set_copy_from(new_set, s1);	
	if(ret < 0)
		return -1;

	while(n) {
		ret = set_insert(new_set, n->v);
		if(ret < 0 && ret != -10)
			return -1;
		n = n->next;
	}
	return 0;
}

int			set_intersection(PSet new_set, PSet s1, PSet s2)
{
	int ret = 0;
	PSetNode n = s1->head->next;

	while(n) {
		if(set_is_member(s2, n->v)) {
			ret = set_insert(new_set, n->v);
			if(ret < 0 && ret != -10)
				return -1;
			//printf("insert:%d, ret:%d\n", n->v, ret);
		}
		n = n->next;
	}
	return 0;
}

int			set_difference(PSet new_set, PSet s1, PSet s2)
{
	int ret = 0;
	PSetNode n = s1->head->next;

	while(n) {
		if(!set_is_member(s2, n->v)) {
			ret = set_insert(new_set, n->v);
			if(ret < 0 && ret != -10)
				return -1;
		}
		n = n->next;
	}
	return 0;
}

int			set_is_member(PSet s, int v)
{
	int ret = 0;
	PSetNode n = s->head->next;

	while(n) {
		if(n->v == v)
			return 1;
		n = n->next;
	}
	return ret;
}

// whether s1 is subset of s2
int			set_is_subset(PSet s1, PSet s2)
{
	int ret = 0;
	PSetNode n1 = s1->head->next;
	PSetNode n2 = s2->head->next;

	while(n1) {
		n2 = s2->head->next;
		while(n2) {
			if(n1->v == n2->v)
				break;
			n2 = n2->next;
		}
		if(!n2)
			return 0;
		n1 = n1->next;
	}
	return 1;	
}

int			set_is_equal(PSet s1, PSet s2)
{
	return set_size(s1) == set_size(s2) && set_is_subset(s1, s2);
}

void		set_show(PSet s)
{
	PSetNode node = s->head;
	node = node->next;

	while(node) {
		printf("%d ", node->v);
		node = node->next;
	}	
	printf("\n");
}

void		set_clear(PSet s)
{
	PSetNode n = s->head->next;

	while(n) {
		PSetNode nn = n->next;
		free(n);
		n = nn;
	}
	s->head->next = NULL;
	s->tail = s->head;
}

void		set_destroy(PSet s)
{
	PSetNode next;
	PSetNode node = s->head;

	while(node) {
		next = node->next;
		free(node);
		node = next;
	}
}

int			set_size(PSet s)
{
	return s->size;
}
