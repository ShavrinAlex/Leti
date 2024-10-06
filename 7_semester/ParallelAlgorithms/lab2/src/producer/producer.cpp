#include "producer.hpp"
#include "../matrix/matrix_operations.hpp"


myPair produceMatrices() {
    auto A = generateMatrix(ROWS_A, COLUMNS_A, MAX_VALUE);
    auto B = generateMatrix(ROWS_B, COLUMNS_B, MAX_VALUE);
    return std::make_pair(A, B);
};
