/*
 * test.c
 *
 *  Created on: Oct 9, 2016
 *      Author: Jason
 */

#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#define TEST_PROTO(suffix) int test_##suffix();
TEST_PROTO(linkedlist);
#undef TEST_PROTO

int main(int argc, char** argv) {
	if(argc <= 1) {
		return 1;
	} else {
		if(strcmp(argv[1], "linkedlist") == 0) {
			return test_linkedlist();
		} else {
			return 1;
		}
	}
}

int test_linkedlist() {
	linkedlist* list = ll_construct();
	int a = 1, b = 9;
	ll_add(list, &a);
	ll_add(list, &b);
	printf("Size: %d\n", ll_size(list));
	ll_destruct(list);

	return 0;
}
