#include <CL/cl.h>
#include <map>
#include <chrono>
#include "io/io.hpp"
#include "utils/utils.hpp"

#define CL_FILE_PATH "kernel.cl"
#define OUTPUT_FILE "result.txt"
#define SIZE 2048
#define LOCAL_BLOCK_SIZE 16


size_t align(int x, int y) {
    return (x + y - 1) / y * y;
};


int main(){
    std::vector<int> A = generateMatrix(SIZE);
    std::vector<int> B = generateMatrix(SIZE);
    writeMatrixInFile("A.txt", A, SIZE);
    writeMatrixInFile("B.txt", B, SIZE);
    std::vector<int> C(SIZE * SIZE);
    try {
        cl_platform_id platform = getPlatform();
        printPlatformInfo(platform);
        cl_device_id device = getDevice(platform);
        printDeviceInfo(device); 
        cl_context context = getContext(device);
        cl_command_queue queue = getQueue(context, device);
        //auto [bufferA, bufferB, bufferC] = getBuffers(context, A, B, C);
        cl_int CL_err = CL_SUCCESS;
        cl_mem bufferA = clCreateBuffer(context, CL_MEM_USE_HOST_PTR, sizeof(int) * A.size(), A.data(), &CL_err);
        checkBufferCreateError(CL_err, "A");
        cl_mem bufferB = clCreateBuffer(context, CL_MEM_USE_HOST_PTR, sizeof(int) * B.size(), B.data(), &CL_err);
        checkBufferCreateError(CL_err, "B");
        cl_mem bufferC = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(int) * C.size(), nullptr, &CL_err);
        checkBufferCreateError(CL_err, "C");
        std::string kernelSource = loadKernel(CL_FILE_PATH);
        cl_program program = getProgramm(context, kernelSource);
        buildProgram(program, device);
        cl_kernel kernel = getKernel(program, "multiply");
        
        // Установка аргументов ядра
        clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
        clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferB);
        clSetKernelArg(kernel, 2, sizeof(cl_mem), &bufferC);
        const int size = SIZE;
        clSetKernelArg(kernel, 3, sizeof(const int), &size);

        // Установка размерности глобальной и локальной работы
        size_t localWorkSize[2] = {LOCAL_BLOCK_SIZE, LOCAL_BLOCK_SIZE};
        size_t globalWorkSize[2] = {align(SIZE, LOCAL_BLOCK_SIZE), align(SIZE, LOCAL_BLOCK_SIZE)};
        
        // Запуск ядра
        auto startTime = std::chrono::high_resolution_clock::now();
        runKernel(kernel, queue, localWorkSize, globalWorkSize);
        auto stopTime = std::chrono::high_resolution_clock::now();
        auto hostDuration = std::chrono::duration<double, std::milli>(stopTime - startTime).count();
        std::cout << "Host programm time duration: " << hostDuration <<" ms"<< std::endl;
        
        readResult(queue, bufferC, C);
        writeMatrixInFile(OUTPUT_FILE, C, SIZE);

        // Очистка ресурсов
        clReleaseKernel(kernel);
        clReleaseMemObject(bufferA);
        clReleaseMemObject(bufferB);
        clReleaseMemObject(bufferC);
        clReleaseCommandQueue(queue);
        clReleaseProgram(program);
        clReleaseContext(context);
    } catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    return 0;
}
