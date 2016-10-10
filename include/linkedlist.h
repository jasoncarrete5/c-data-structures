/*
 * linkedlist.h
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/*******
 * Node
 *******/

typedef struct node node;

/*************
 * LinkedList
 *************/

typedef struct linkedlist linkedlist;

linkedlist* ll_construct();
void ll_destruct(linkedlist* list);
void ll_add(linkedlist* list, void* data);
int ll_size(linkedlist* list);
void ll_clear(linkedlist* list);

#endif /* LINKEDLIST_H_ */
