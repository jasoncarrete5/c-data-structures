/*
 * comparator.c
 *
 * Author: Jason R. Carrete
 */

#include "CDS/comparator.h"
#include <string.h>

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
	long long *longA = (long long *)a, *longB = (long long *)b;
	return *longA - *longB;
}

int cds_UCharComparator(void *a, void *b) {
	unsigned char *chA = (unsigned char *)a, *chB = (unsigned char *)b;
	return *chA - *chB;
}

int cds_UShortComparator(void *a, void *b) {
	unsigned short *shortA = (unsigned short *)a;
	unsigned short *shortB = (unsigned short *)b;
	return *shortA - *shortB;
}

int cds_UIntComparator(void *a, void *b) {
	unsigned int *intA = (unsigned int *)a;
	unsigned int *intB = (unsigned int *)b;
	return *intA - *intB;
}

int cds_ULongIntComparator(void *a, void *b) {
	unsigned long int *longA = (unsigned long int *)a;
	unsigned long int *longB = (unsigned long int *)b;
	return *longA - *longB;
}

int cds_ULongLongComparator(void *a, void *b) {
	unsigned long long *longA = (unsigned long long *)a;
	unsigned long long *longB = (unsigned long long *)b;
	return *longA - *longB;
}

int cds_CStringComparator(void *a, void *b) {
	const char *strA = (const char *)a;
	const char *strB = (const char *)b;
	return strcmp(strA, strB);
}
