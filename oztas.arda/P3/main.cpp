#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
    // Check argument count
    if (argc != 4) {
        std::cerr << "invalid arguments\n";
        return 1;
    }

    // Parse task number
    int taskNum = 0;
    try {
        taskNum = std::stoi(argv[1]);
    }
    catch (...) {
        std::cerr << "invalid task number\n";
        return 1;
    }

    if (taskNum != 1 && taskNum != 2) {
        std::cerr << "unsupported task number\n";
        return 1;
    }

    // Open input file
    std::ifstream input(argv[2]);
    if (!input) {
        std::cerr << "input file error\n";
        return 2;
    }

    // Open output file
    std::ofstream output(argv[3]);
    if (!output) {
        std::cerr << "output file error\n";
        return 2;
    }

    int rows = 0;
    int cols = 0;
    int** matrix = nullptr;

    // Read matrix (always use dynamic allocation)
    if (!oztas::readMatrix(input, matrix, rows, cols)) {
        std::cerr << "invalid matrix data\n";
        return 2;
    }

    // Handle empty matrix
    if (rows == 0 || cols == 0) {
        output << "0 0";
        if (matrix) {
            oztas::freeMatrix(matrix, rows);
        }
        return 0;
    }

    // Execute the requested task
    if (taskNum == 1) {
        int result = oztas::countNonZeroDiagonals(matrix, rows, cols);
        output << result;
    }
    else if (taskNum == 2) {
        oztas::applyFillIncreasingWave(matrix, rows, cols);
        oztas::writeMatrix(output, matrix, rows, cols);
    }

    // Cleanup
    oztas::freeMatrix(matrix, rows);
    return 0;
} 
