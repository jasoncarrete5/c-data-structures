#include <CUnit/Basic.h>
#include "tests.h"
#include "CDS/linkedlist.h"
#include <stdlib.h>

void test_create_linked_list() {
	cds_LinkedList *list = malloc(sizeof(cds_LinkedList));
	CU_ASSERT_PTR_NOT_NULL_FATAL(list);
	cds_LinkedListCreate(list, sizeof(int), NULL);
	cds_LinkedListDelete(list);
	free(list);
	CU_PASS("LinkedList created and deleted on heap");

	cds_LinkedList list2;
	CU_ASSERT_PTR_NOT_NULL_FATAL(&list2);
	cds_LinkedListCreate(&list2, sizeof(int), NULL);
	cds_LinkedListDelete(&list2);
	CU_PASS("LinkedList created and deleted on stack");
}

void test_append_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListAppend(&list, &i);
	}

	cds_LinkedNode *cur = list.head;
	int i = 0;
	while (cur) {
		CU_ASSERT_EQUAL(*(int*)(cur->data), i++);
		cur = cur->next;
	}
	cds_LinkedListDelete(&list);
}
