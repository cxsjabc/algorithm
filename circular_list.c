#define _LOG_LEVEL LOG_LEVEL_INFO

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "circular_list.h"

LHead 	clist_create(LPNode p)
{
	LHead head = (LHead)malloc(sizeof(LNode));
	LPNode node;
	if(!head)
		return NULL;

	head->next = head;
	if(p) {
		node = (LPNode)malloc(sizeof(LNode));
		if(!node)
			goto fail;
		head->next = node;
		node->data = p->data;
		node->next = head;
	}

	return head;
fail:
	if(node)
		free(node);
	if(head)
		free(head);
	return NULL;
}

int		clist_is_empty(LHead clist)
{
	return (clist->next == clist);
}


int		clist_is_last(LHead clist, LPNode node)
{
	return node->next == clist;
}

LPNode	clist_find(LHead clist, int data)
{
	LPNode node = clist->next;
	while(node && node != clist) {
		if(node->data == data)
			return node;
		node = node->next;
	}
	return NULL;	
}

LPNode	clist_insert(LHead clist, LPNode node, int data)
{
	LPNode prev = clist_get_prev(clist, node);
	LPNode new_node = (LPNode)malloc(sizeof(LNode));
	
	if(!new_node)
		return NULL;
	if(prev == NULL)
		prev = clist;

	new_node->next = clist->next;	
	prev->next = new_node;
	new_node->data = data;

	return new_node;
}

void	clist_delete(LHead clist, int data)
{
	LPNode node = clist->next;
	LPNode prev = clist;

	while(node && node != clist) {
		if(node->data == data) {
			LPNode next = node->next;
			prev->next = next;
			free(node);
			node = next;
		} else {
			prev = node;
			node = node->next;
		}
	}
}

LPNode	clist_get_prev(LHead clist, LPNode node)
{
	LPNode prev = NULL;
	LHead	list_bak = clist;

	while(clist->next && clist->next != list_bak) {
		if(clist->next == node) {
			prev = clist;
			break;
		}
		else
			clist = clist->next;
	}	
	return prev;
}

void clist_show(LHead clist)
{
	LPNode node = clist->next;
	while(node && node != clist) {
		printf("%d ", node->data);
		node = node->next;	
	}
	printf("\n");
}

LPNode	clist_append(LHead clist, int data)
{
	LPNode node = clist->next;
	LPNode append_node;

	while(node != clist) {
		if(node->next == clist)
			break;
		node = node->next;
	}

	append_node = (LPNode)malloc(sizeof(LNode));
	if(!append_node)
		goto label_alloc_fail;
	append_node->data = data;
	append_node->next = clist;

	node->next = append_node;
	return node;

label_alloc_fail:
	return NULL;
}

void 	clist_free(LHead clist) 
{
	LPNode curr = clist;
	LPNode next = clist->next;
	if(next == curr)
	{
		LOG_D("just one node...");
		free(curr);
		return;
	}
	while(next != clist) {
		LPNode temp = next;
		if(curr != clist)
			LOG_D("free one node:%d", curr->data);
		free(curr);
		curr = temp;
		next = temp->next;
	}	
	LOG_D("free one node:%d", curr->data);
	free(curr);
}

// the clist is asc
LHead		clist_merge(LHead clist1, LHead clist2)
{
	LPNode node1, node2;
	LHead	clist;	
	LPNode	append_node;
	
	LOG_D("before clist create");
	clist = (LHead)clist_create(NULL);
	if(!clist)
		goto label_alloc_fail;

	LOG_D("after clist create");
	node1 = clist1->next;
	node2 = clist2->next;
	
	LOG_D("before merge...");
	while(node1 != clist1 && node2 != clist2) {
		LOG_D("node1->data:%d, node2->data:%d", node1->data, node2->data);
		if(node1->data <= node2->data) {
			LOG_D("append data:%d", node1->data);
			append_node = clist_append(clist, node1->data);
			if(!append_node)
				goto label_alloc_fail;
			node1 = node1->next;
		}
		else {
			LOG_D("append data:%d", node2->data);
			append_node = clist_append(clist, node2->data);
			if(!append_node)
				goto label_alloc_fail;
			node2 = node2->next;
		}
	}

	LOG_D("after merge...");
	if(node1 == clist1) {
		while(node2 != clist2) {
			append_node = clist_append(clist, node2->data);
			if(!append_node)
				goto label_alloc_fail;
			LOG_D("append data:%d", node2->data);
				
			node2 = node2->next;
		}
	}

	LOG_D("after merge1...");
	if(node2 == clist2) {
		while(node1 != clist1) {
			append_node = clist_append(clist, node1->data);
			if(!append_node)
				goto label_alloc_fail;
			LOG_D("append data:%d", node1->data);
			node1 = node1->next;
		}
	}
	
	return clist;

label_alloc_fail:
	if(clist)
		clist_free(clist);
	return NULL;	

}
