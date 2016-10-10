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
	node root;
	root.data = 1;
	list.root = &root;
	printf("%d\n", ll_size(&list));
	return 0;
}
