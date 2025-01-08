set(CMAKE_CXX_COMPILER "D:/Program Files/msys64/ucrt64/bin/g++.exe")
set(CMAKE_C_COMPILER "D:/Program Files/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_STANDARD 23)

cmake_minimum_required(VERSION 3.13)
project(lab3)

set(SOURCE_EXE main.cpp ./producer/producer.cpp ./consumer/consumer.cpp ./matrix/matrix_operations.cpp ./timer/timer.cpp)


add_executable(main ${SOURCE_EXE})
add_compile_options(-latomic)