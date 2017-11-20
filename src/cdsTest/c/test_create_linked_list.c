#include <CUnit/Basic.h>
#include "CDS/linkedlist.h"

void test_create_linked_list() {
	cds_LinkedList *list = malloc(sizeof(cds_LinkedList));
	cds_createLinkedList(list);
	printf("Created LinkedList: %p\n", list);
	cds_deleteLinkedList(list);
	printf("Deleted LinkedList: %p\n", list);
}
