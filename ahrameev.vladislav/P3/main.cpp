#include <iostream>
#include <fstream>
#include <cstring>
#include "matrix.h"

int main(int argc, char* argv[])
{
    if (!ahrameev::checkArguments(argc, argv))
    {
        std::cerr << "Error: Wrong arguments\n";
        return 1;
    }

    const char* numArg = argv[1];
    const char* inputFile = argv[2];
    const char* outputFile = argv[3];

    std::ifstream input(inputFile);
    if (!input.is_open())
    {
        std::cerr << "Error: Cannot open input file\n";
        return 2;
    }

    size_t rows = 0;
    size_t cols = 0;
    if (!ahrameev::readMatrixSize(input, &rows, &cols))
    {
        std::cerr << "Error: Bad matrix size or empty file\n";
        input.close();
        return 2;
    }

    int fixedMatrix[10000] = {};
    int* dynMatrix = nullptr;
    int* matrix = nullptr;

    if (strcmp(numArg, "1") == 0)
    {
        matrix = fixedMatrix;
    }
    else if (strcmp(numArg, "2") == 0)
    {
        dynMatrix = new int[rows * cols]();
        matrix = dynMatrix;
    }
    else
    {
        std::cerr << "Error: Invalid mode\n";
        input.close();
        return 1;
    }

    bool readSuccess = true;
    if (rows > 0 && cols > 0)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                if (!(input >> matrix[i * cols + j]))
                {
                    readSuccess = false;
                    break;
                }
            }
            if (!readSuccess) break;
        }

        if (!readSuccess || input.fail())
        {
            std::cerr << "Error: Wrong matrix data\n";
            delete[] dynMatrix;
            input.close();
            return 2;
        }
    }
    input.close();

    std::ofstream output(outputFile);
    if (!output.is_open())
    {
        std::cerr << "Error: Cannot open output file\n";
        delete[] dynMatrix;
        return 2;
    }

    ahrameev::processSpiralDecrease(matrix, rows, cols, output);
    ahrameev::processLowerTriangle(matrix, rows, cols, output);

    output.close();
    delete[] dynMatrix;
}
