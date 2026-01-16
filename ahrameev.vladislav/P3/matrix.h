#ifndef MATRIX
#define MATRIX

#include <fstream>

namespace ahrameev
{
    bool checkArguments(int argc, char* argv[]);
    bool readMatrixSize(std::ifstream& input, size_t* rows, size_t* cols);
    void processSpiralDecrease(const int* src, size_t rows, size_t cols, std::ofstream& output);
    void processLowerTriangle(const int* matrix, size_t rows, size_t cols, std::ofstream& output);
}

#endif
