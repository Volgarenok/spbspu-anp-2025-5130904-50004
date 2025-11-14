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
        // static array
        int matrix[10][10] = {};
        if (!oztas::readMatrix(input, matrix, rows, cols)) {
            return 0;
        }
        oztas::applyFullIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
        return 0;
    }

    if (mode == 2) {
        // dynamic array
        int** matrix = nullptr;
        if (!oztas::readMatrix(input, matrix, rows, cols)) {
            return 0;
        }
        oztas::applyFullIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
        oztas::freeMatrix(matrix, rows);
        return 0;
    }

    return 0;
}
