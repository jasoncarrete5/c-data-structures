/*
 * cds_linkedlist.h
 *
 * Author: Jason R. Carrete
 */

#pragma once

#include <stddef.h>

// Used to free dynamic data
typedef void (*FreeFunction)(void *);
typedef void (*ListIterator)(void *);

typedef struct cds_LinkedNode {
	struct cds_LinkedNode *prev;
	struct cds_LinkedNode *next;
	void *data;
} cds_LinkedNode;

typedef struct {
	size_t logicalLength;
	size_t elementSize;
	FreeFunction freeFn;
	cds_LinkedNode *head;
	cds_LinkedNode *tail;
} cds_LinkedList;

/*
 * Initializes a new LinkedList.
 */
void cds_LinkedListCreate(cds_LinkedList *list, size_t elementSize, FreeFunction freeFn);

/*
 * Frees all dynamically allocated memory used by the LinkedList but not the LinkedList itself.
 */
void cds_LinkedListDelete(cds_LinkedList *list);

/*
 * Appends data to the end of the LinkedList.
 */
void cds_LinkedListAppend(cds_LinkedList *list, void *data);
