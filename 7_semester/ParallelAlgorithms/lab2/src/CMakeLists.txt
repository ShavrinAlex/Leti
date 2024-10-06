set(CMAKE_CXX_STANDARD 23)

cmake_minimum_required(VERSION 3.13)
project(lab2)

set(SOURCE_EXE main.cpp ./producer/producer.cpp ./consumer/consumer.cpp ./matrix/matrix_operations.cpp ./timer/timer.cpp)


add_executable(main ${SOURCE_EXE})
