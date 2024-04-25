project(stack)

set(EXECUTABLE_OUTPUT_PATH ../)


add_executable(test test.cpp)

target_link_libraries(test PRIVATE stack linked_list)