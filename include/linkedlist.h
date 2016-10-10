/*
 * linkedlist.h
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct _node {
	struct _node* next;
	int data;
} node;

typedef struct _linkedlist {
	node* root;
} linkedlist;

void ll_add(linkedlist* list, node* newNode);
int ll_size(linkedlist* list);

#endif /* LINKEDLIST_H_ */
