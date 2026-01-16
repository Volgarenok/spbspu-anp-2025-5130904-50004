#include "matrix.h"
#include <cstring>

namespace ahrameev
{
    bool readMatrixSize(std::ifstream& input, size_t* rows, size_t* cols)
    {
        size_t r = 0, c = 0;
        if (!(input >> r >> c))
            return false;
        *rows = r;
        *cols = c;
        return true;
    }
}

void ahrameev::processSpiralDecrease(const int* src, size_t rows, size_t cols, std::ofstream& output)
{
    output << rows << " " << cols;
    if (rows == 0 || cols == 0)
    {
        output << "\n";
        return;
    }

    int* dst = new int[rows * cols];
    for (size_t i = 0; i < rows * cols; ++i)
        dst[i] = src[i];

    size_t total = rows * cols;
    int val = 1;
    size_t count = 0;

    size_t top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (count < total)
    {
        for (size_t i = bottom; i >= top && count < total; --i)
        {
            dst[i * cols + left] -= val++;
            ++count;
        }
        ++left;

        for (size_t j = left; j <= right && count < total; ++j)
        {
            dst[top * cols + j] -= val++;
            ++count;
        }
        ++top;

        for (size_t i = top; i <= bottom && count < total; ++i)
        {
            dst[i * cols + right] -= val++;
            ++count;
        }
        --right;

        for (size_t j = right; j >= left && count < total; --j)
        {
            dst[bottom * cols + j] -= val++;
            ++count;
        }
        --bottom;
    }

    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            output << " " << dst[i * cols + j];
        }
    }

    delete[] dst;
    output << "\n";
}

void ahrameev::processLowerTriangle(const int* matrix, size_t rows, size_t cols, std::ofstream& output)
{
    bool isTriangular = false;
    if (rows == cols && rows > 0)
    {
        isTriangular = true;
        for (size_t i = 0; i < rows && isTriangular; ++i)
        {
            for (size_t j = i + 1; j < cols; ++j)
            {
                if (matrix[i * cols + j] != 0)
                {
                    isTriangular = false;
                    break;
                }
            }
        }
    }
    output << (isTriangular ? "true" : "false") << "\n";
}
