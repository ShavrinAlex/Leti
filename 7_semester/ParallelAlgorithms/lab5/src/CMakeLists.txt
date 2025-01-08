cmake_minimum_required(VERSION 3.1) # 3.1 << C_STANDARD 11

project(lab5)

find_package(OpenCL CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ./main.cpp ./io/io.cpp ./utils/utils.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenCL::OpenCL)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17
                                                 CXX_STANDARD_REQUIRED ON
                                                 CXX_EXTENSIONS OFF)

target_compile_definitions(${PROJECT_NAME} PRIVATE CL_TARGET_OPENCL_VERSION=100)