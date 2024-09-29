#include "../processes/matrix_operations.hpp"
#include <thread>
#include <chrono>


#define RESULT_FILE "result.txt"


void thGenerateMatrices(std::vector<std::vector<int>>& matrixA, std::vector<std::vector<int>>& matrixB, int maxValue) {
    matrixA = generateMatrix(matrixA.size(), matrixA[0].size(), maxValue);
    matrixB = generateMatrix(matrixB.size(), matrixB[0].size(), maxValue);
    // std::cout << "matrices is generated" << std::endl;
}


void thMultiplyMatrices(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result) {
    result = multiplyMatrices(matrixA, matrixB);
    // std::cout << "matrices is multiplied" << std::endl;
}


void thWriteMatrixInFile(const std::vector<std::vector<int>>& result) {
    writeMatrixInFile(RESULT_FILE, result);
    // std::cout << "matrices is written" << std::endl;
}


int main(){
    int rowsA, columnsA, rowsB, columnsB, maxValue;
    setDefaultMatricesParams(rowsA, columnsA, rowsB, columnsB, maxValue);
    std::vector<std::vector<int>> matrixA(rowsA, std::vector<int>(columnsA)), matrixB(rowsB, std::vector<int>(columnsB)), result(rowsA, std::vector<int>(columnsB));
    
    auto timer_start = std::chrono::high_resolution_clock::now();

    std::thread th1(thGenerateMatrices, std::ref(matrixA), std::ref(matrixB), maxValue);
    th1.join();
    
    std::thread th2(thMultiplyMatrices, std::ref(matrixA), std::ref(matrixB), std::ref(result));
    th2.join();

    std::thread th3(thWriteMatrixInFile, std::ref(result));
    th3.join();

    auto timer_stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = timer_stop - timer_start;

    std::cout << "Duration: " << elapsed.count() << "ms" << std::endl;

    return 0;
}