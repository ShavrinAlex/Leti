#include "utils.hpp"


cl_platform_id getPlatform() {
    cl_int CL_err = CL_SUCCESS;
    cl_uint countPlatforms = 0;
    CL_err = clGetPlatformIDs(0, nullptr, &countPlatforms);
    if (CL_err != CL_SUCCESS || countPlatforms == 0) {
        std::string errorMessage = "Error: No OpenCL platforms found or clGetPlatformIDs failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    std::vector<cl_platform_id> platforms(countPlatforms);
    CL_err = clGetPlatformIDs(countPlatforms, platforms.data(), nullptr);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: clGetPlatformIDs failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    // Используем первую платформу
    cl_platform_id platform = platforms[0]; 

    return platform;
};


cl_device_id getDevice(cl_platform_id platform) {
    cl_int CL_err = CL_SUCCESS;
    cl_uint countDevices = 0;
    CL_err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 0, nullptr, &countDevices);
    if (CL_err != CL_SUCCESS || countDevices == 0) {
        std::string errorMessage = "Error: No OpenCL devices found or clGetDeviceIDs failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    } 
    std::vector<cl_device_id> devices(countDevices);
    CL_err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, countDevices, devices.data(), nullptr);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: clGetDeviceIDs failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    // Используем первое устройство
    cl_device_id device = devices[0]; 
    
    return device;
};


cl_context getContext(cl_device_id device) {
    cl_int CL_err = CL_SUCCESS;
    cl_context context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &CL_err);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Create context failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    return context;
};


cl_command_queue getQueue(cl_context context, cl_device_id device) {
    cl_int CL_err = CL_SUCCESS;
    cl_command_queue queue = clCreateCommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &CL_err);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Create queue failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    return queue;
};


void checkBufferCreateError(cl_int CL_err, const std::string& bufferName) {
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Create buffer " + bufferName + " failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
};


std::string loadKernel(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Open kernel file\" " + filename + "\" failed with error" );
    }

    std::ostringstream oss;
    oss << file.rdbuf();
    return oss.str();
};


cl_program getProgramm(cl_context context, const std::string& kernelSource) {
    cl_int CL_err = CL_SUCCESS;
    const char* source = kernelSource.c_str();
    cl_program program = clCreateProgramWithSource(context, 1, &source, nullptr, &CL_err);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Create programm failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    return program;
};


void buildProgram(cl_program program, cl_device_id device) {
    cl_int CL_err = CL_SUCCESS;
    CL_err = clBuildProgram(program, 1, &device, nullptr, nullptr, nullptr);
    if (CL_err != CL_SUCCESS) {
        size_t logSize;
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, nullptr, &logSize);
        std::vector<char> log(logSize);
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, logSize, log.data(), nullptr);
        std::string errorMessage = "Error: Build program faild with error:\n" + std::string(log.begin(), log.end()) +"\n";
        throw std::runtime_error(errorMessage);
    }
};


cl_kernel getKernel(cl_program program, const std::string& task) {
    cl_int CL_err = CL_SUCCESS;
    cl_kernel kernel = clCreateKernel(program, task.c_str(), &CL_err);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Create kernel failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    return kernel;
};


void runKernel(
    cl_kernel kernel,
    cl_command_queue queue,
    size_t localWorkSize[2],
    size_t globalWorkSize[2]
) {
    cl_int CL_err = CL_SUCCESS;
    cl_event event;

    CL_err = clEnqueueNDRangeKernel(queue, kernel, 2, nullptr, globalWorkSize, localWorkSize, 0, nullptr, &event);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Run kernel failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
    clFinish(queue);

    cl_ulong startTime, endTime;
    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong), &startTime, nullptr);
    clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong), &endTime, nullptr);

    double kernelDuration = (endTime - startTime) / 1000000.0; // Время в миллисекундах
    std::cout << "Kernel time duration: " << kernelDuration << " ms" << std::endl;

    // Освобождаем ресурсы профилирования
    clReleaseEvent(event);
};


void readResult(cl_command_queue queue, cl_mem bufferC, std::vector<int>& C) {
    cl_int CL_err = CL_SUCCESS;
    CL_err = clEnqueueReadBuffer(queue, bufferC, CL_TRUE, 0, sizeof(int) * C.size(), C.data(), 0, nullptr, nullptr);
    if (CL_err != CL_SUCCESS) {
        std::string errorMessage = "Error: Read buffer failed with error code " + std::to_string(CL_err);
        throw std::runtime_error(errorMessage);
    }
};
