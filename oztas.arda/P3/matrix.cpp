#include "matrix.hpp"

#include <cstdlib>
#include <istream>
#include <ostream>

namespace oztas
{
    namespace
    {
        const std::size_t MAX_ELEMENTS = 10000;

        int** allocateMatrix(int rows, int cols)
        {
            if (rows <= 0 || cols <= 0) {
                return nullptr;
            }

            const std::size_t r = static_cast<std::size_t>(rows);
            const std::size_t c = static_cast<std::size_t>(cols);
            const std::size_t total = r * c;

            if (total > MAX_ELEMENTS) {
                return nullptr;
            }

            int** matrix = static_cast<int**>(std::malloc(r * sizeof(int*)));
            if (!matrix) {
                return nullptr;
            }

            for (std::size_t i = 0; i < r; ++i) {
                matrix[i] = static_cast<int*>(std::malloc(c * sizeof(int)));
                if (!matrix[i]) {
                    for (std::size_t j = 0; j < i; ++j) {
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
        output << rows << ' ' << cols << '\n';
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                output << matrix[i][j];
                if (j + 1 < cols) {
                    output << ' ';
                }
            }
            output << '\n';
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
