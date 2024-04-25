project(stack)

add_library(stack SHARED stack.cpp)

target_include_directories(stack PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)