#include "../proc/matrix_operations.hpp"
#include <thread>
// #include <mutex>
// #include <condition_variable>
#include <chrono>


#define RESULT_FILE "result.txt"
#define THREADS_AMOUNT 3


void setDefaultMatricesParams(int& rowsA, int& columnsA, int& rowsB, int& columnsB, int& maxValue) {
    rowsA = 3;
    columnsA = rowsB = 3;
    columnsB = 3;
    maxValue = 10;
}


void thMultiplyMatrixBlock(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB, std::vector<std::vector<int>>& result, std::vector<std::pair<int, int>> blockPositions) {
    // std::lock_guard<std::mutex>lg(m);
    for (int i = 0; i < blockPositions.size(); i++){
        for (int j = 0; j < matrixB.size(); j++) {
            result[blockPositions[i].first][blockPositions[i].second] += matrixA[blockPositions[i].first][j] * matrixB[j][blockPositions[i].second];
        }
    }
    std::cout << "matrices block is multiplied" << std::endl;
}


int main(){
    int rowsA, columnsA, rowsB, columnsB, maxValue;
    setDefaultMatricesParams(rowsA, columnsA, rowsB, columnsB, maxValue);
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(columnsB));
    std::vector<std::thread> threads;

    auto timer_start = std::chrono::high_resolution_clock::now();

    const std::vector<std::vector<int>> matrixA = generateMatrix(rowsA, columnsA, maxValue);
    const std::vector<std::vector<int>> matrixB = generateMatrix(rowsB, columnsB, maxValue);
    printMatrix(matrixA);
    printMatrix(matrixB);
    std::cout << "matrices is generated" << std::endl;

    // multiplication
    int blockSize = std::ceil((double)rowsA * columnsB / THREADS_AMOUNT);
    std::cout << blockSize << std::endl;
    std::vector<std::pair<int,int>> blockPositions;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            blockPositions.push_back(std::pair(i,j));
            if (blockPositions.size() == blockSize || (i + 1 == rowsA && j + 1 == columnsB)) {
                threads.push_back(std::thread(thMultiplyMatrixBlock, std::ref(matrixA), std::ref(matrixB), std::ref(result), blockPositions));
                blockPositions.clear();
            }
        }
    }

    for (auto& th : threads) {
        th.join();
    }

    writeMatrixInFile(RESULT_FILE, result);
    std::cout << "matrices is written" << std::endl;

    auto timer_stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = timer_stop - timer_start;

    std::cout << "Duration: " << elapsed.count() << "ms" << std::endl;

    return 0;
}