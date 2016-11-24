cmake_minimum_required (VERSION 3.5)
project (data-structures)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib/)

include_directories (include/)

set (LIB_SRC src/linkedlist.c)
add_library (imgdecode ${LIB_SRC})

set (TEST_SRC test/test.c)
add_executable(tests ${TEST_SRC})
target_link_libraries(tests structure)

enable_testing()
add_test(linkedlist_test tests linkedlist)