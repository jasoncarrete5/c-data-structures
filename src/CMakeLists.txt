project(cds C VERSION 0.0.0)

set(SOURCES
	comparator.c
	linkedlist.c
	)

add_library("${PROJECT_NAME}_static" STATIC ${SOURCES})
set_target_properties("${PROJECT_NAME}_static" PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories("${PROJECT_NAME}_static" PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_library("${PROJECT_NAME}" SHARED ${SOURCES})
target_include_directories("${PROJECT_NAME}" PUBLIC "${CMAKE_SOURCE_DIR}/include")
