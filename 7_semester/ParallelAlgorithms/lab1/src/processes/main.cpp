#include "matrix_operations.hpp"
#include <sys/wait.h>
#include <unistd.h>
#include <chrono>


#define RESULT_FILE "result.txt"


void processMatrixWithPipe(int unpipe, std::vector<std::vector<int>>& matrix, int process) {
    ssize_t bytes;
    for (auto& row: matrix) {
        switch (process) {
        case 0:
            bytes = read(unpipe, row.data(), row.size() * sizeof(int));
            // std::cout << "read: " << bytes << "bytes" << std::endl;
            break;
        case 1:
            bytes = write(unpipe, row.data(), row.size() * sizeof(int));  
            // std::cout << "write: " << bytes << "bytes" << std::endl;    
            break;
        }
    }
}


int main(){
    int rowsA, columnsA, rowsB, columnsB, maxValue;
    setDefaultMatricesParams(rowsA, columnsA, rowsB, columnsB, maxValue);

    int unpipe_1[2], unpipe_2[2];
    if (pipe(unpipe_1) == -1 || pipe(unpipe_2) == -1) {
        perror("pipe creation err");
        return -1;
    }

    std::vector<pid_t> pids(3, 0);

    auto timer_start = std::chrono::high_resolution_clock::now();

    pids[0] = fork();
    if (pids[0] == 0) {
        close(unpipe_1[0]);

        std::vector<std::vector<int>> matrixA = generateMatrix(rowsA, columnsA, maxValue);
        std::vector<std::vector<int>> matrixB = generateMatrix(rowsB, columnsB, maxValue);
        printMatrix(matrixA);
        printMatrix(matrixB);
        processMatrixWithPipe(unpipe_1[1], matrixA, 1);
        processMatrixWithPipe(unpipe_1[1], matrixB, 1);
        // std::cout << "matrices is generated" << std::endl;

        close(unpipe_1[1]);
        exit(EXIT_SUCCESS);
    }
    pids[1] = fork();
    if (pids[1] == 0){
        waitpid(pids[0], NULL, 0);
        close(unpipe_1[1]);
        close(unpipe_2[0]);

        std::vector<std::vector<int>> matrixA(rowsA, std::vector<int>(columnsA));
        std::vector<std::vector<int>> matrixB(rowsB, std::vector<int>(columnsB));
        processMatrixWithPipe(unpipe_1[0], matrixA, 0);
        processMatrixWithPipe(unpipe_1[0], matrixB, 0);
        std::vector<std::vector<int>> result = multiplyMatrices(matrixA, matrixB);
        processMatrixWithPipe(unpipe_2[1], result, 1);
        // std::cout << "matrices is multiplied" << std::endl;
        
        close(unpipe_1[0]);
        close(unpipe_2[1]);
        exit(EXIT_SUCCESS);
    }
    pids[2] = fork();
    if (pids[2] == 0){
        waitpid(pids[1], NULL, 0);
        close(unpipe_2[1]);

        std::vector<std::vector<int>> result(rowsA, std::vector<int>(columnsB));
        processMatrixWithPipe(unpipe_2[0], result, 0);
        writeMatrixInFile(RESULT_FILE, result);
        // std::cout << "result is written" << std::endl;

        close(unpipe_2[0]);
        exit(EXIT_SUCCESS);
    }

    close(unpipe_1[0]);
    close(unpipe_1[1]);
    close(unpipe_2[0]);
    close(unpipe_2[1]);
    waitpid(pids[0], NULL, 0);
    waitpid(pids[1], NULL, 0);
    waitpid(pids[2], NULL, 0);

    auto timer_stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = timer_stop - timer_start;

    std::cout << "Duration: " << elapsed.count() << "ms" << std::endl;
    return 0;
}
