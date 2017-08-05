/*
 * Author: Jason R. Carrete
 */
 
#include <stdlib.h>
#include "CDS/linkedlist.h"

void cds_createLinkedList(cds_LinkedList* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void cds_deleteLinkedList(cds_LinkedList* list) {
    // TODO recursivly free LinkedNodes
    free(list);
}

unsigned int cds_size(cds_LinkedList* list) {
    return list->size;
}