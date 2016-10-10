/*
 * linkedlist_test.c
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
	linkedlist* list = ll_construct();
	int a = 1, b = 9;
	ll_add(list, &a);
	ll_add(list, &b);
	printf("Size: %d\n", ll_size(list));
	ll_destruct(list);

	return 0;
}
