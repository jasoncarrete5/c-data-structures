/*
 * Author: Jason R. Carrete
 */
 
#include <stdlib.h>
#include "CDS/linkedlist.h"

cds_LinkedList *cds_createLinkedList() {
    cds_LinkedList *list = malloc(sizeof(cds_LinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void cds_deleteLinkedList(cds_LinkedList *list) {
    // TODO recursivly free LinkedNodes
    free(list);
}
