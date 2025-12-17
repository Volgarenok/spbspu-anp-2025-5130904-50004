#ifndef MATRIX
#define MATRIX

#include <fstream>

namespace ahrameev
{
    bool checkArguments(int argc, char* argv[]);

    bool readMatrixSize(std::ifstream& input, int* rows, int* cols);

    void processSpiralDecrease(const int* src, int rows, int cols, std::ofstream& output);

    void processLowerTriangle(const int* matrix, int rows, int cols, std::ofstream& output);
}

#endif
