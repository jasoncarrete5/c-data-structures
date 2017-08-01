/*
 * cds_linkedlist.h
 *
 * Author: Jason R. Carrete
 */

#pragma once

typedef struct cds_LinkedNode {
	struct cds_LinkedNode* prev;
	struct cds_LinkedNode* next;
	void* data;
} cds_LinkedNode;

typedef struct {
	unsigned int size;
	cds_LinkedNode* head;
	cds_LinkedNode* tail;
} cds_LinkedList;

cds_LinkedList* cds_createLinkedList();
void cds_deleteLinkedList(cds_LinkedList* list);
