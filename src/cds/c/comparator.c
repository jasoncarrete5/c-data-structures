/*
 * comparator.c
 *
 * Author: Jason R. Carrete
 */

#include "CDS/comparator.h"

/*
 * Lexicographical char comparator
 */
int cds_CharComparator(void *a, void *b) {
	char *chA = (char *)a, *chB = (char *)b;
	return *chA - *chB;
}

int cds_ShortComparator(void *a, void *b) {
	short *shortA = (short *)a, *shortB = (short *)b;
	return *shortA - *shortB;
}

int cds_IntComparator(void *a, void *b) {
	int *intA = (int *)a, *intB = (int *)b;
	return *intA - *intB;
}

int cds_LongIntComparator(void *a, void *b) {
	long *longA = (long int *)a, *longB = (long int *)b;
	return *longA - *longB;
}

int cds_LongLongComparator(void *a, void *b) {

}

int cds_UCharComparator(void *a, void *b) {

}

int cds_UShortComparator(void *a, void *b) {

}

int cds_UIntComparator(void *a, void *b) {

}

int cds_ULongIntComparator(void *a, void *b) {

}

int cds_ULongLongComparator(void *a, void *b) {

}

int cds_CStringComparator(void *a, void *b) {

}
