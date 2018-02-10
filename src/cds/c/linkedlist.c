/*
 * Author: Jason R. Carrete
 */

#include <stdlib.h>
#include "CDS/linkedlist.h"

void cds_LinkedListCreate(cds_LinkedList* list, size_t elementSize, cds_FreeFunction freeFn) {
	list->logicalLength = 0;
	list->elementSize = elementSize;
	list->freeFn = freeFn;
	list->head = NULL;
	list->tail = NULL;
}

void cds_LinkedListDelete(cds_LinkedList *list) {
	cds_LinkedNode *cur;
	while (list->head) {
		cur = list->head;
		list->head = cur->next;

		if (list->freeFn) {
			list->freeFn(cur->data);
		}

		free(cur->data);
		free(cur);
	}
}

void cds_LinkedListAppend(cds_LinkedList *list, void *data) {
	cds_LinkedNode *node = malloc(sizeof(cds_LinkedNode));
	node->data = malloc(list->elementSize);
	node->next = NULL;
	memcpy(node->data, data, list->elementSize);

	if (!list->tail) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	list->logicalLength++;
}
