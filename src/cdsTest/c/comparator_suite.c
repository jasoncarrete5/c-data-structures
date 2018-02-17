#include "CUnit/Basic.h"
#include "tests.h"
#include "CDS/comparator.h"


void test_char_comparator() {
	char a = 'A', b = 'B';
	int result;

	result = cds_CharComparator(&a, &b);
	CU_ASSERT(result < 0);

	result = cds_CharComparator(&b, &a);
	CU_ASSERT(result > 0);

	b = 'A';
	result = cds_CharComparator(&a, &b);
	CU_ASSERT_EQUAL(result, 0);
}

void test_short_comparator() {
	short a = 1, b = 2;
	int result;

	result = cds_ShortComparator(&a, &b);
	CU_ASSERT(result < 0);

	result = cds_ShortComparator(&b, &a);
	CU_ASSERT(result > 0);

	b = 1;
	result = cds_ShortComparator(&a, &b);
	CU_ASSERT_EQUAL(result, 0);
}

void test_int_comparator() {
	int a = 1, b = 2;
	int result;

	result = cds_IntComparator(&a, &b);
	CU_ASSERT(result < 0);

	result = cds_IntComparator(&b, &a);
	CU_ASSERT(result > 0);

	b = 1;
	result = cds_IntComparator(&a, &b);
	CU_ASSERT_EQUAL(result, 0);
}

void test_long_int_comparator() {
	long int a = 1, b = 2;
	int result;

	result = cds_LongIntComparator(&a, &b);
	CU_ASSERT(result < 0);

	result = cds_LongIntComparator(&b, &a);
	CU_ASSERT(result > 0);

	b = 1;
	result = cds_LongIntComparator(&a, &b);
	CU_ASSERT_EQUAL(result, 0);
}
