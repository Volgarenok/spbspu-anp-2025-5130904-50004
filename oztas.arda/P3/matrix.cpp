#include "matrix.hpp"

#include <cstdlib>
#include <istream>

namespace oztas
{
    namespace
    {
        int** allocateMatrix(int rows, int cols)
        {
            if (rows < 0 || cols < 0) {
                return nullptr;
            }

            // Handle empty matrix
            if (rows == 0 || cols == 0) {
                return nullptr;
            }

            int** matrix = static_cast<int**>(std::malloc(rows * sizeof(int*)));
            if (!matrix) {
                return nullptr;
            }

            for (int i = 0; i < rows; ++i) {
                matrix[i] = static_cast<int*>(std::malloc(cols * sizeof(int)));
                if (!matrix[i]) {
                    for (int j = 0; j < i; ++j) {
                        std::free(matrix[j]);
                    }
                    std::free(matrix);
                    return nullptr;
                }
            }

            return matrix;
        }
    }

    bool readMatrix(std::istream& input, int**& matrix, int& rows, int& cols)
    {
        matrix = nullptr;
        rows = 0;
        cols = 0;

        if (!(input >> rows >> cols)) {
            return false;
        }

        // Check for valid dimensions
        if (rows < 0 || cols < 0) {
            return false;
        }

        // Empty matrix is valid
        if (rows == 0 || cols == 0) {
            return true;
        }

        int** tmp = allocateMatrix(rows, cols);
        if (!tmp) {
            return false;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(input >> tmp[i][j])) {
                    freeMatrix(tmp, rows);
                    return false;
                }
            }
        }

        matrix = tmp;
        return true;
    }

    void writeMatrix(std::ostream& output, int* const* matrix, int rows, int cols)
    {
        output << rows << " " << cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                output << " " << matrix[i][j];
            }
        }
    }

    void freeMatrix(int** matrix, int rows)
    {
        if (!matrix) {
            return;
        }
        for (int i = 0; i < rows; ++i) {
            std::free(matrix[i]);
        }
        std::free(matrix);
    }
}