#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
    if (argc < 4) {
        return 0;
    }

    int mode = 0;
    try {
        mode = std::stoi(argv[1]);
    }
    catch (...) {
        return 0;
    }

    std::ifstream input(argv[2]);
    if (!input) {
        return 0;
    }

    std::ofstream output(argv[3]);
    if (!output) {
        return 0;
    }

    int rows = 0;
    int cols = 0;

    if (mode == 1) {
        // STATIC ARRAY
        int matrix_buf[10][10] = {};
        int* matrix[10];

        for (int i = 0; i < 10; ++i) {
            matrix[i] = matrix_buf[i];
        }

        // cast to int**
        int** matrixPtr = matrix;

        if (!oztas::readMatrix(input, matrixPtr, rows, cols)) {
            return 0;
        }

        oztas::applyFillIncreasingWave(matrixPtr, rows, cols);
        oztas::writeMatrix(output, matrixPtr, rows, cols);

        return 0;
    }

    if (mode == 2) {
        // DYNAMIC ARRAY
        int** matrix = nullptr;

        if (!oztas::readMatrix(input, matrix, rows, cols)) {
            return 0;
        }

        oztas::applyFillIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
        oztas::freeMatrix(matrix, rows);
        return 0;
    }

    return 0;
}
