#include "matrix.h"
#include <cstring>

namespace ahrameev
{
    bool checkArguments(int argc, char* argv[])
    {
        if (argc != 4)
        {
            return false;
        }

        const char* n = argv[1];
        return (strcmp(n, "1") == 0) || (strcmp(n, "2") == 0);
    }

    bool readMatrixSize(std::ifstream& input, int* rows, int* cols)
    {
        int r = 0;
        int c = 0;
        if (!(input >> r >> c))
        {
            return false;
        }

        if (r < 0 || c < 0)
        {
            return false;
        }

        *rows = r;
        *cols = c;
        return true;
    }

    void processSpiralDecrease(const int* src, int rows, int cols, std::ofstream& output)
    {
        output << rows << " " << cols;

        if (rows > 0 && cols > 0)
        {
            int* dst = new int[rows * cols];
            for (int i = 0; i < rows * cols; ++i)
            {
                dst[i] = src[i];
            }

            int total = rows * cols;
            int val = 1;
            int count = 0;

            int top = 0;
            int bottom = rows - 1;
            int left = 0;
            int right = cols - 1;

            while (count < total)
            {
                for (int i = bottom; i >= top && count < total; --i)
                {
                    dst[i * cols + left] -= val;
                    ++val;
                    ++count;
                }
                ++left;

                for (int j = left; j <= right && count < total; ++j)
                {
                    dst[top * cols + j] -= val;
                    ++val;
                    ++count;
                }
                ++top;

                for (int i = top; i <= bottom && count < total; ++i)
                {
                    dst[i * cols + right] -= val;
                    ++val;
                    ++count;
                }
                --right;

                for (int j = right; j >= left && count < total; --j)
                {
                    dst[bottom * cols + j] -= val;
                    ++val;
                    ++count;
                }
                --bottom;
            }

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    output << " " << dst[i * cols + j];
                }
            }

            delete[] dst;
        }
        output << "\n";
    }

    void processLowerTriangle(const int* matrix, int rows, int cols, std::ofstream& output)
    {
        bool isTriangular = false;

        if (rows == cols && rows > 0)
        {
            isTriangular = true;
            for (int i = 0; i < rows && isTriangular; ++i)
            {
                for (int j = i + 1; j < cols; ++j)
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
}
