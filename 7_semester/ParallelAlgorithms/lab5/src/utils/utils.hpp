#pragma once
#include <CL/cl.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>


cl_platform_id getPlatform();
cl_device_id getDevice(cl_platform_id platform);
cl_context getContext(cl_device_id device);
cl_command_queue getQueue(cl_context context, cl_device_id device);
void checkBufferCreateError(cl_int CL_err, const std::string& bufferName);
std::string loadKernel(const std::string &filename);
cl_program getProgramm(cl_context context, const std::string& kernelSource);
void buildProgram(cl_program program, cl_device_id device);
cl_kernel getKernel(cl_program program, const std::string& task);
void runKernel(
    cl_kernel kernel,
    cl_command_queue queue,
    size_t localWorkSize[2],
    size_t globalWorkSize[2]
);
void readResult(cl_command_queue queue, cl_mem bufferC, std::vector<int>& C);
