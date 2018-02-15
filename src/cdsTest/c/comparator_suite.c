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
