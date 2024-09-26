#include "matrix_operations.hpp"


std::vector<std::vector<int>> generateMatrix(const int rows, const int columns, const int maxValue) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));

    std::random_device random_device; 
    std::mt19937 gen(random_device()); 
    std::uniform_int_distribution<> uniform_distribution(-maxValue, maxValue);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = uniform_distribution(gen);
        }
    }

    return matrix;
}


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int columnsA = A[0].size();
    int columnsB = B[0].size();
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(columnsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}


void writeMatrixInFile(const std::string& filename, const std::vector<std::vector<int>>& result) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open())
    {
        std::cerr << "Open file err: " << filename << std::endl;
        exit(-1);
    }

    for (const auto& row : result) {
        for (const auto& val : row) {
            outputFile << val << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();
}


void printMatrix(const std::vector<std::vector<int>>& result) {
    for (const auto& row : result) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
