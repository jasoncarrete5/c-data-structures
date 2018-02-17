/*
 * Tests each data structure implementation.
 *
 * Author: Jason R. Carrete
 */

#include <CUnit/Basic.h>
#include "gradle_cunit_register.h"
#include "tests.h"
#include <stdio.h>

int suite_linked_list_init() {
	printf("*** Init LinkedList Suite ***\n");
	return 0;
}

int suite_linked_list_clean() {
	printf("*** Clean LinkedList Suite ***\n");
	return 0;
}

int suite_comparator_init() {
	printf("*** Init Comparator Suite ***\n");
	return 0;
}

int suite_comparator_clean() {
	printf("*** Clean Comparator Suite ***\n");
	return 0;
}

void gradle_cunit_register() {
	CU_pSuite pSuiteLinkedList = CU_add_suite("LinkedList implementation tests", suite_linked_list_init, suite_linked_list_clean);
	CU_add_test(pSuiteLinkedList, "LinkedList_creation", test_create_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_append", test_append_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_foreach", test_foreach_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_prepend", test_prepend_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_insert", test_insert_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_get", test_get_linked_list);
	CU_add_test(pSuiteLinkedList, "LinkedList_removeIndex", test_remove_index_linked_list);

	CU_pSuite pSuiteComparator = CU_add_suite("Comparator implentation tests", suite_comparator_init, suite_comparator_clean);
	CU_add_test(pSuiteComparator, "Comparator_Char", test_char_comparator);
	CU_add_test(pSuiteComparator, "Comparator_Short", test_short_comparator);
	CU_add_test(pSuiteComparator, "Comparator_Int", test_int_comparator);
	CU_add_test(pSuiteComparator, "Comparator_Long_Int", test_long_int_comparator);
	CU_add_test(pSuiteComparator, "Comparator_Long_Long", test_long_long_comparator);
}
