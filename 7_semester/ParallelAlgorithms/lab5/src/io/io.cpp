#include "io.hpp"
#include <random>


void printPlatformInfo(cl_platform_id platform) {
    // Список атрибутов для извлечения информации
    const std::vector<std::pair<cl_platform_info, std::string>> attributes = {
        {CL_PLATFORM_NAME, "Platform Name"},
        {CL_PLATFORM_VENDOR, "Platform Vendor"},
        {CL_PLATFORM_VERSION, "Platform Version"},
    };

    for (const auto& attr : attributes) {
        size_t size = 0;
        // Получаем размер строки атрибута
        cl_int CL_err = clGetPlatformInfo(platform, attr.first, 0, nullptr, &size);
        if (CL_err != CL_SUCCESS) {
            continue;
        }

        std::vector<char> value(size);
        CL_err = clGetPlatformInfo(platform, attr.first, size, value.data(), nullptr);
        if (CL_err == CL_SUCCESS) {
            std::cout << attr.second << ": " << value.data() << std::endl;
        }
    }
};


void printDeviceInfo(cl_device_id device) {
    // Список атрибутов для извлечения информации
    const std::vector<std::pair<cl_device_info, std::string>> attributes = {
        {CL_DEVICE_NAME, "Device Name"},
        {CL_DEVICE_VENDOR, "Device Vendor"},
        {CL_DEVICE_VERSION, "Device Version"},
        {CL_DRIVER_VERSION, "Driver Version"},
        {CL_DEVICE_TYPE, "Device Type"},
        {CL_DEVICE_MAX_COMPUTE_UNITS, "Max Compute Units"},
        {CL_DEVICE_MAX_WORK_GROUP_SIZE, "Max Work Group Size"},
        {CL_DEVICE_GLOBAL_MEM_SIZE, "Global Memory Size"},
        {CL_DEVICE_LOCAL_MEM_SIZE, "Local Memory Size"},
    };

    for (const auto& attr : attributes) {
        size_t size = 0;
        cl_int CL_err = clGetDeviceInfo(device, attr.first, 0, nullptr, &size);
        if (CL_err != CL_SUCCESS) {
            continue;
        }

        if (size > sizeof(size_t)) {
            std::vector<char> value(size);
            CL_err = clGetDeviceInfo(device, attr.first, size, value.data(), nullptr);
            if (CL_err == CL_SUCCESS) {
                std::cout << attr.second << ": " << value.data() << std::endl;
            }
        } else {
            size_t value = 0;
            CL_err = clGetDeviceInfo(device, attr.first, sizeof(size_t), &value, nullptr);
            if (CL_err == CL_SUCCESS) {
                std::cout << attr.second << ": " << value << std::endl;
            }
        }
    }
};


std::vector<int> generateMatrix(const int size, const int maxValue) {
    std::vector<int> matrix(size*size);

    std::random_device random_device; 
    std::mt19937 gen(random_device()); 
    std::uniform_int_distribution<> uniform_distribution(-maxValue, maxValue);

    for (int i = 0; i < size*size; i++){
        matrix[i] = uniform_distribution(gen);
    }

    return matrix;
};


void writeMatrixInFile(const std::string& filename, const std::vector<int>& result, const int size) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::string errorMessage =  "Open file \"" + filename + "\" error";
        throw std::runtime_error(errorMessage);
    }

    for (int i = 0; i < size*size; i++) {
        char sep = ((i % size == size-1) ? '\n' : ' ');
        outputFile << result[i] << sep;
    }
    outputFile.close();
};


void printMatrix(const std::vector<int>& result, const int size) {
    for (int i = 0; i < size*size; i++) {
        char sep = ((i % size == size-1) ? '\n' : ' ');
        std::cout << result[i] << sep;
    }
};
