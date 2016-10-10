OBJS = build/obj/linkedlist.o
TEST_APPS = build/tests/linkedlist_test
CFLAGS = -Wall -I./include

all : build $(OBJS)
	ar rcs -o build/lib/libstructure.a $(OBJS)

build/obj/linkedlist.o : include/linkedlist.h src/linkedlist.c
	gcc $(CFLAGS) -o build/obj/linkedlist.o -c src/linkedlist.c

test-compile : all $(TEST_APPS)

build/tests/linkedlist_test : test/linkedlist_test.c
	gcc $(CFLAGS) -L./build/lib -o build/tests/linkedlist_test test/linkedlist_test.c -lstructure

build:
	mkdir build
	mkdir build/obj
	mkdir build/lib
	mkdir build/tests

clean:
	rm -r build