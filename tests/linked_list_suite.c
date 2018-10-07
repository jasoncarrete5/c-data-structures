#include <CUnit/Basic.h>
#include "tests.h"
#include "CDS/linkedlist.h"
#include <stdlib.h>

// Increments each element
unsigned char increment(void *data) {
	int *iData = (int *)data;
	(*iData)++;
	return 0;
}

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

void test_foreach_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListAppend(&list, &i);
	}

	cds_LinkedListForEach(&list, NULL);
	cds_LinkedListForEach(&list, increment);

	cds_LinkedNode *cur = list.head;
	int i = 1;
	while (cur) {
		CU_ASSERT_EQUAL(*(int*)(cur->data), i++);
		cur = cur->next;
	}

	cds_LinkedListDelete(&list);
}

void test_prepend_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListPrepend(&list, &i);
	}

	cds_LinkedNode *cur = list.head;
	int i = 9;
	while (cur) {
		CU_ASSERT_EQUAL(*(int*)(cur->data), i--);
		cur = cur->next;
	}

	cds_LinkedListDelete(&list);
}

void test_insert_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListAppend(&list, &i);
	}

	int n = 26;
	cds_LinkedListInsert(&list, 0, &n);
	cds_LinkedListInsert(&list, list.logicalLength - 1, &n);
	cds_LinkedListInsert(&list, 5, &n);

	// Should've probably implemented a get function first, eh?

	cds_LinkedListDelete(&list);
}

void test_get_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListAppend(&list, &i);
	}

	int *value = (int *)cds_LinkedListGet(&list, 3);
	CU_ASSERT_EQUAL(*value, 3);

	cds_LinkedListDelete(&list);
}

void test_remove_index_linked_list() {
	cds_LinkedList list;
	cds_LinkedListCreate(&list, sizeof(int), NULL);
	for (int i = 0; i < 10; i++) {
		cds_LinkedListAppend(&list, &i);
	}

	int *value = (int *)cds_LinkedListRemoveIndex(&list, 8);
	CU_ASSERT_EQUAL(*value, 8);
	CU_ASSERT_EQUAL(list.logicalLength, 9);

	cds_LinkedListDelete(&list);
}
