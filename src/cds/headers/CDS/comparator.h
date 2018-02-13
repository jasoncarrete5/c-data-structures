/*
 * comparator.h
 *
 * Author: Jason R. Carrete
 */

/*
 * Compares the data for two void pointers. If a < b, then the
 * comparator returns '< 0'. If a > b, then the comparator returns '> 0'.
 * If a == b, then the comparator returns '0';
 */
typedef int (*cds_Comparator)(void *a, void *b);

// Built-in comparators
int cds_CharComparator(void *a, void *b);
int cds_ShortComparator(void *a, void *b);
int cds_IntComparator(void *a, void *b);
int cds_LongIntComparator(void *a, void *b);
int cds_LongLongComparator(void *a, void *b);
int cds_UCharComparator(void *a, void *b);
int cds_UShortComparator(void *a, void *b);
int cds_UIntComparator(void *a, void *b);
int cds_ULongIntComparator(void *a, void *b);
int cds_ULongLongComparator(void *a, void *b);
int cds_CStringComparator(void *a, void *b);
