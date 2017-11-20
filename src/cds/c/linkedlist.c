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

unsigned int cds_size(cds_LinkedList* list) {
    return list->size;
}
