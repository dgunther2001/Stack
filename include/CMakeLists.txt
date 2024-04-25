project(stack)

add_library(linked_list SHARED IMPORTED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../external_libs/Linked_List/include)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}//../build/external_libs/Linked_List/src/linked_list.dylib)