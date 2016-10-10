/*
 * linkedlist.c
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#include <stdlib.h>
#include "linkedlist.h"

int ll_size(linkedlist* list) {
	int size = 0;

	node* n = list->root;
	while(n != NULL) {
		size++;
		n = n->next;
	}

	return size;
}
