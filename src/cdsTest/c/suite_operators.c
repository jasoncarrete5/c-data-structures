/*
 * Tests each data structure implementation.
 *
 * Author: Jason R. Carrete
 */

#include <CUnit/Basic.h>
#include "gradle_cunit_register.h"
#include "tests.h"

int suite_init() {
	return 0;
}

int suite_clean() {
	return 0;
}

void gradle_cunit_register() {
	CU_pSuite pSuiteLinkedList = CU_add_suite("LinkedList implementation tests", suite_init, suite_clean);
	CU_add_test(pSuiteLinkedList, "LinkedList_creation", test_create_linked_list);
}
