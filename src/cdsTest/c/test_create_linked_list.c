#include <CUnit/Basic.h>
#include "CDS/linkedlist.h"

void test_create_linked_list() {
	cds_LinkedList list;
	cds_createLinkedList(&list);
	printf("Created LinkedList: %p\n", list);
}
