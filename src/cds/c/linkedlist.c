/*
 * Author: Jason R. Carrete
 */

#include <stdlib.h>
#include "CDS/linkedlist.h"

/*
 * Initializes a new LinkedNode with data.
 */
static cds_LinkedNode * newLinkedNode(size_t elementSize, void *data) {
	cds_LinkedNode *node = malloc(sizeof(cds_LinkedNode));
	node->data = malloc(elementSize);
	node->next = NULL;
	node->prev = NULL;
	memcpy(node->data, data, elementSize);
	return node;
}

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
	cds_LinkedNode *node = newLinkedNode(list->elementSize, data);
	node->prev = list->tail;

	if (!list->tail) {
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}

	list->logicalLength++;
}

void cds_LinkedListPrepend(cds_LinkedList *list, void *data) {
	cds_LinkedNode *node = newLinkedNode(list->elementSize, data);
	node->next = list->head;

	list->head = node;

	if (!list->tail) {
		list->tail = list->head;
	}

	list->logicalLength++;
}

void cds_LinkedListForEach(cds_LinkedList *list, cds_ListIterator iter) {
	cds_LinkedNode *cur = list->head;
	unsigned char stop = 0;
	while (cur && !stop) {
		if (iter) {
			stop = iter(cur->data);
		}
		cur = cur->next;
	}
}

void cds_LinkedListInsert(cds_LinkedList *list, size_t index, void *data) {
	if (index > list->logicalLength || index < 0) {
		return;
	}

	if (index == 0) {
		cds_LinkedListPrepend(list, data);
		return;
	} else if (index == list->logicalLength) {
		cds_LinkedListAppend(list, data);
		return;
	}

	cds_LinkedNode *node = newLinkedNode(list->elementSize, data);
	cds_LinkedNode *cur;
	size_t i = 0;

	if (index <= list->logicalLength / 2) {
		cur = list->head;
		while (cur && i < index) {
			cur = cur->next;
			i++;
		}
	} else {
		i = list->logicalLength - 1;
		cur = list->tail;
		while (cur && i > index) {
			cur = cur->prev;
			i--;
		}
	}

	node->next = cur;
	node->prev = cur->prev;
	if (cur->prev) {
		cur->prev->next = node;
	}
	cur->prev = node;

	list->logicalLength++;
}

void * cds_LinkedListGet(cds_LinkedList *list, size_t index) {
	if (index < 0 || index >= list->logicalLength) return NULL;

	cds_LinkedNode *cur;
	if (index <= list->logicalLength / 2) {
		size_t i = 0;
		cur = list->head;
		while (i++ < index && cur) {
			cur = cur->next;
		}
	} else {
		size_t i = list->logicalLength - 1;
		cur = list->tail;
		while (i-- > index && cur) {
			cur = cur->prev;
		}
	}

	return cur->data;
}
