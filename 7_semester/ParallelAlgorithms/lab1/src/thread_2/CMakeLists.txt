cmake_minimum_required(VERSION 2.8)	
project(thread_2)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB ../processes/matrix_operations.cpp)

add_library(matrix_operations STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main matrix_operations)	