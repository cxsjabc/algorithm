#include <stdio.h>
#include <stdlib.h>

#include "common_local.h"
#include "queue.h"

LHead 	queue_create(LPNode p)
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

int		queue_is_empty(LHead queue)
{
	return (queue->next == NULL);
}


int		queue_is_last(LHead queue, LPNode node)
{
	return node->next == NULL;
}

LPNode	queue_find(LHead queue, int data)
{
	LPNode node = queue->next;
	while(node) {
		if(node->data == data)
			return node;
		node = node->next;
	}
	return NULL;	
}

LPNode	queue_insert(LHead queue, LPNode node, int data)
{
	LPNode prev = queue_get_prev(queue, node);
	LPNode new_node = (LPNode)malloc(sizeof(LNode));
	
	if(!new_node)
		return NULL;
	prev->next = new_node;
	new_node->data = data;
	new_node->next = node;	

	return new_node;
}

void	queue_delete(LHead queue, int data)
{
	LPNode node = queue->next;
	LPNode prev = queue;

	while(node) {
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

LPNode	queue_get_prev(LHead queue, LPNode node)
{
	LPNode prev = NULL;
	while(queue->next) {
		if(queue->next == node) {
			prev = queue;
			break;
		}
		else
			queue = queue->next;
	}	
	return prev;
}

void queue_show(LHead queue)
{
	LPNode node = queue->next;
	while(node) {
		printf("%d ", node->data);
		node = node->next;	
	}
	printf("\n");
}

void 	queue_free(LHead queue) 
{
	LPNode curr = queue;
	LPNode next = queue->next;
	while(next) {
		LPNode temp = next;
		free(curr);
		curr = temp;
		next = temp->next;
	}
	free(curr);
}


LPNode queue_enque(LHead queue, int data)
{
	LPNode last = queue->next;
	LPNode node;	

	while(last->next != NULL)
		last = last->next;

	node = (LPNode)malloc(sizeof(LNode));
	if(!node)
		goto label_alloc_fail;
	node->data = data;
	node->next = NULL;

	last->next = node;

	return node;

label_alloc_fail:
	return NULL;
}

int		queue_deque(LHead queue)
{
	LPNode deq_node = queue->next;
	LPNode deq_next_node = deq_node->next;
	int 	value;

	value = deq_node->data;
	queue->next = deq_next_node;
	free(deq_node);

	return value;
}

