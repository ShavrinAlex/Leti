set(CMAKE_CXX_COMPILER "D:/Program Files/msys64/ucrt64/bin/g++.exe")
set(CMAKE_C_COMPILER "D:/Program Files/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_STANDARD 23)

cmake_minimum_required(VERSION 3.13)
project(lab4)

include_directories("C:\\Users\\Pavel\\Desktop\\LETI_Windows\\PA\\lab4\\src\\CTPL")

set(SOURCE_EXE main.cpp ./blocksMultiplication/blocksMultiplication.cpp ./strassenMultiplication/strassenMultiplication.cpp ./matrix/matrix.cpp ./checker/checker.cpp)


add_executable(main ${SOURCE_EXE})
