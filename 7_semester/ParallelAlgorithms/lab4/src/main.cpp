#include <iostream>
#include <chrono>
#include "matrix/matrix.hpp"
#include "checker/checker.hpp"
#include "blocksMultiplication/blocksMultiplication.hpp"
#include "strassenMultiplication/strassenMultiplication.hpp"
#include "CTPL/ctpl_stl.h"



#define MATRIX_SIZE 512
#define THREADS_COUNT 1
#define MAX_VALUE 10
#define BLOCKS_FILE "blocksResult.txt"
#define STRASSEN_FILE "strassenResult.txt"



void testMatrixMultiplication(const int size, const int threadsCount) {    
    const std::vector<int> matrixA = generateMatrix(size, MAX_VALUE);
    const std::vector<int> matrixB = generateMatrix(size, MAX_VALUE);

    std::chrono::duration<double, std::milli> t1, t2;

    auto timer_start = std::chrono::high_resolution_clock::now();
    std::vector<int> blocksResult = multiplyMatricesByBlocks(matrixA, matrixB, size, threadsCount);
    auto timer_stop = std::chrono::high_resolution_clock::now();
    t1 = timer_stop - timer_start;
    std::cout << "Blocks Multiplication: " << t1.count() << std::endl;
    
    ctpl::thread_pool threadPool(threadsCount); // Создаем пул потоков
   
    timer_start = std::chrono::high_resolution_clock::now();
    std::vector<int> strassenResult = multiplyMatricesByStrassen(matrixA, matrixB, size, &threadPool);
    timer_stop = std::chrono::high_resolution_clock::now();
    t2 = timer_stop - timer_start;
    std::cout << "Strassen Multiplication: " << t2.count() << std::endl;
    writeMatrixInFile(BLOCKS_FILE, blocksResult, size);
    writeMatrixInFile(STRASSEN_FILE, strassenResult, size);

    //check equality
    bool isCorrect = isResultMatches(BLOCKS_FILE, STRASSEN_FILE);   
    std::cout << "Result: " << (isCorrect ? "Matches" : "Not matches") << std::endl;
    return;
};



int main(int argc, char* argv[]) {
    int size, threadsCount;
    
    if (argc == 3) {
        size = std::stoi(argv[1]); 
        threadsCount = std::stoi(argv[2]); 
    } else {
        size = MATRIX_SIZE;
        threadsCount = THREADS_COUNT;
    }

    testMatrixMultiplication(size, threadsCount);

    return 0;
};
