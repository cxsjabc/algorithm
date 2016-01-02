#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "list.h"

LHead 	list_create(LPNode p)
{
	LHead head = (LHead)malloc(sizeof(LNode));
	LPNode node;
	if(!head)
		return NULL;

	head->next = NULL;
	if(p) {
		node = (LPNode)malloc(sizeof(LNode));
		if(!node)
			goto fail;
		head->next = node;
		node->data = p->data;
		node->next = NULL;
	}

	return head;
fail:
	if(node)
		free(node);
	if(head)
		free(head);
	return NULL;
}

int		list_is_empty(LHead list)
{
	return (list->next == NULL);
}


int		list_is_last(LHead list, LPNode node)
{
	return node->next == NULL;
}

LPNode	list_find(LHead list, int data)
{
	LPNode node = list->next;
	while(node) {
		if(node->data == data)
			return node;
		node = node->next;
	}
	return NULL;	
}

LPNode	list_insert(LHead list, LPNode node, int data)
{
	LPNode prev = list_get_prev(list, node);
	LPNode new_node = (LPNode)malloc(sizeof(LNode));
	
	if(!new_node)
		return NULL;
	prev->next = new_node;
	new_node->data = data;
	new_node->next = node;	

	return new_node;
}

LPNode	list_get_prev(LHead list, LPNode node)
{
	LPNode prev = NULL;
	while(list->next) {
		if(list->next == node) {
			prev = list;
			break;
		}
		else
			list = list->next;
	}	
	return prev;
}

void list_show(LHead list)
{
	LPNode node = list->next;
	while(node) {
		printf("%d ", node->data);
		node = node->next;	
	}
	printf("\n");
}

void 	list_free(LHead list) 
{
	LPNode curr = list;
	LPNode next = list->next;
	while(next) {
		LPNode temp = next;
		free(curr);
		curr = temp;
		next = temp->next;
	}
	free(curr);
}

int main()
{
	LNode node = {1, NULL};		
	LHead head;

	head = list_create(&node);
	if(!head) {
		printf("list_create failed!\n");
		return -1;
	}
			
	PN(list_is_empty(head));
	list_insert(head, head->next, 2);
	list_show(head);
	list_insert(head, head->next, 3);
	list_show(head);
	list_free(head);

	head = list_create(NULL);
	PN(list_is_empty(head));
	list_free(head);
	
	return 0;
}
