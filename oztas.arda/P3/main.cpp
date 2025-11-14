#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

#include "matrix.hpp"
#include "tasks.hpp"

namespace oztas
{
    int run(int argc, char* argv[])
    {
        if (argc != 4) {
            std::cerr << "invalid arguments\n";
            return 1;
        }

        char* end = nullptr;
        const long rawTask = std::strtol(argv[1], &end, 10);
        if (argv[1][0] == '\0' || *end != '\0') {
            std::cerr << "first argument must be integer task number\n";
            return 1;
        }

        if (rawTask < 1 || rawTask > 20) {
            std::cerr << "task number out of range\n";
            return 1;
        }

        const int task = static_cast<int>(rawTask);
        const char* const inputName = argv[2];
        const char* const outputName = argv[3];

        if (task != 8 && task != 18) {
            std::cerr << "unsupported task\n";
            return 1;
        }

        std::ifstream input(inputName);
        if (!input) {
            std::cerr << "cannot open input file\n";
            return 2;
        }

        int** matrix = nullptr;
        int rows = 0;
        int cols = 0;

        if (!readMatrix(input, matrix, rows, cols)) {
            std::cerr << "invalid matrix data\n";
            freeMatrix(matrix, rows);
            return 2;
        }

        std::ofstream output(outputName);
        if (!output) {
            std::cerr << "cannot open output file\n";
            freeMatrix(matrix, rows);
            return 2;
        }

        if (task == 18) {
            const int count = countNonZeroDiagonals(matrix, rows, cols);
            output << count << '\n';
        }
        else {
            applyFillIncreasingWave(matrix, rows, cols);
            writeMatrix(output, matrix, rows, cols);
        }

        freeMatrix(matrix, rows);
        return 0;
    }
}

int main(int argc, char* argv[])
{
    return oztas::run(argc, argv);
}
