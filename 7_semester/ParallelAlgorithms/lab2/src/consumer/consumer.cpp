#include "consumer.hpp"
#include "../matrix/matrix_operations.hpp"


void processMatrices(const myPair& matrices) {
    std::vector<std::vector<int>> result(ROWS_A, std::vector<int>(COLUMNS_B));
    std::vector<std::vector<int>> matrixA = matrices.first;
    std::vector<std::vector<int>> matrixB = matrices.second;

    // result = multiplyMatrices(matrixA, matrixB);
    multiplyMatricesByBlocks(matrixA, matrixB, result, THREADS_AMOUNT);
    writeMatrixInFile(RESULT_FILE, result);
}