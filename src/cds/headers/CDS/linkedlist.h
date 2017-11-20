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

void cds_createLinkedList(cds_LinkedList* list);
unsigned int cds_size();
