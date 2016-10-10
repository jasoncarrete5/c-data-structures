/*
 * linkedlist.c
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#include <linkedlist.h>
#include <stdlib.h>

/*******
 * Node
 *******/

struct node {
	node* next;
	void* data;
};

/*************
 * LinkedList
 *************/

struct linkedlist {
	node* head;
};

linkedlist* ll_construct() {
	linkedlist* list = malloc(sizeof(linkedlist));
	list->head = NULL;
	return list;
}

void ll_destruct(linkedlist* list) {
	ll_clear(list);
	free(list);
}

void ll_clear(linkedlist* list) {
	node* cur = list->head;
	while(cur != NULL) {
		node* delete = cur;
		cur = cur->next;
		free(delete);
	}
	list->head = NULL;
}

void ll_add(linkedlist* list, void* data) {
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if(list->head == NULL) {
		list->head = newNode;
		return;
	}

	node* parent = list->head;
	while(parent->next != NULL) {
		parent = parent->next;
	}
	parent->next = newNode;
}

int ll_size(linkedlist* list) {
	int size = 0;

	node* n = list->head;
	while(n != NULL) {
		size++;
		n = n->next;
	}

	return size;
}
