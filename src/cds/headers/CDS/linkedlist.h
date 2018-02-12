/*
 * cds_linkedlist.h
 *
 * Author: Jason R. Carrete
 */

#pragma once

#include <stddef.h>

// Used to free dynamic data
typedef void (*cds_FreeFunction)(void *);
// Returns 0 if the list should continue iterating over elements, otherwise 1.
typedef unsigned char (*cds_ListIterator)(void *);

typedef struct cds_LinkedNode {
	struct cds_LinkedNode *prev;
	struct cds_LinkedNode *next;
	void *data;
} cds_LinkedNode;

typedef struct {
	size_t logicalLength;
	size_t elementSize;
	cds_FreeFunction freeFn;
	cds_LinkedNode *head;
	cds_LinkedNode *tail;
} cds_LinkedList;

/*
 * Initializes a new LinkedList.
 */
void cds_LinkedListCreate(cds_LinkedList *list, size_t elementSize, cds_FreeFunction freeFn);

/*
 * Frees all dynamically allocated memory used by the LinkedList but not the LinkedList itself.
 */
void cds_LinkedListDelete(cds_LinkedList *list);

/*
 * Appends data to the end of the LinkedList.
 */
void cds_LinkedListAppend(cds_LinkedList *list, void *data);

/*
 * Prepends data to the beginning of the LinkedList.
 */
void cds_LinkedListPrepend(cds_LinkedList *list, void *data);

/*
 * Applys iter on every element in list.
 */
void cds_LinkedListForEach(cds_LinkedList *list, cds_ListIterator iter);

/*
 *	Inserts data at the desired index in the list.
 */
void cds_LinkedListInsert(cds_LinkedList *list, size_t index, void *data);

/*
 * Gets the element at the specified index.
 */
void * cds_LinkedListGet(cds_LinkedList *list, size_t index);

/*
 * Remove and the return the data at the specified index.
 */
void * cds_LinkedListRemoveIndex(cds_LinkedList *list, size_t index);
