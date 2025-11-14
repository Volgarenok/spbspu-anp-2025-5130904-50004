#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
    if (argc < 4) {
        std::cerr << "invalid arguments\n";
        return 1;
    }

    int mode = 0;
    try {
        mode = std::stoi(argv[1]);
    }
    catch (...) {
        std::cerr << "invalid mode\n";
        return 1;
    }

    std::ifstream input(argv[2]);
    if (!input) {
        std::cerr << "cannot open input file\n";
        return 1;
    }

    std::ofstream output(argv[3]);
    if (!output) {
        std::cerr << "cannot open output file\n";
        return 1;
    }

    int rows = 0;
    int cols = 0;

    if (mode == 1) {
        // STATIC ARRAY, HÝÇ MALLOC YOK
        int matrix_buf[10][10] = {};
        int* matrix[10];
        for (int i = 0; i < 10; ++i) {
            matrix[i] = matrix_buf[i];
        }

        if (!(input >> rows >> cols)) {
            std::cerr << "failed to read sizes\n";
            return 1;
        }

        if (rows < 0 || cols < 0) {
            std::cerr << "invalid sizes\n";
            return 1;
        }

        if (rows > 10 || cols > 10) {
            std::cerr << "too big matrix\n";
            return 1;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(input >> matrix[i][j])) {
                    std::cerr << "not enough data\n";
                    return 1;
                }
            }
        }

        oztas::applyFillIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
        return 0;
    }

    if (mode == 2) {
        // DYNAMIC ARRAY (malloc/free ile)
        int** matrix = nullptr;

        if (!oztas::readMatrix(input, matrix, rows, cols)) {
            std::cerr << "input error\n";
            return 1;
        }

        oztas::applyFillIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
        oztas::freeMatrix(matrix, rows);
        return 0;
    }

    std::cerr << "unsupported mode\n";
    return 1;
}
