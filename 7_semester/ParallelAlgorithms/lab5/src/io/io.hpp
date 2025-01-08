#pragma once
#include <CL/cl.h>
#include <iostream>
#include <fstream>
#include <vector>


void printPlatformInfo(cl_platform_id platform);
void printDeviceInfo(cl_device_id device);
std::vector<int> generateMatrix(const int size, const int maxValue = 10);
void writeMatrixInFile(const std::string& filename, const std::vector<int>& result, const int size);
void printMatrix(const std::vector<int>& result, const int size);
