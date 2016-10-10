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
	linkedlist list;
	node node1;
	node1.data = 1;
	node node2;
	node2.data = 2;

	ll_add(&list, &node1);
	printf("Size: %d\n", ll_size(&list));
	return 0;
}
