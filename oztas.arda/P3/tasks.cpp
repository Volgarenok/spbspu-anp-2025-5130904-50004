#include "tasks.hpp"

#include <algorithm>

namespace oztas
{
    int countNonZeroDiagonals(int* const* matrix, int rows, int cols)
    {
        int result = 0;

        const int minOffset = -rows + 1;
        const int maxOffset = cols - 1;

        for (int offset = minOffset; offset <= maxOffset; ++offset) {
            bool hasElement = false;
            bool allNonZero = true;

            for (int i = 0; i < rows; ++i) {
                const int j = i + offset;
                if (j < 0 || j >= cols) {
                    continue;
                }

                hasElement = true;
                if (matrix[i][j] == 0) {
                    allNonZero = false;
                    break;
                }
            }

            if (hasElement && allNonZero) {
                ++result;
            }
        }

        return result;
    }

    void applyFillIncreasingWave(int** matrix, int rows, int cols)
    {
        const int layers = (std::min(rows, cols) + 1) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            const int add = layer + 1;

            const int top = layer;
            const int bottom = rows - 1 - layer;
            const int left = layer;
            const int right = cols - 1 - layer;

            // top row
            for (int j = left; j <= right; ++j) {
                matrix[top][j] += add;
            }

            // bottom row
            if (bottom != top) {
                for (int j = left; j <= right; ++j) {
                    matrix[bottom][j] += add;
                }
            }

            // left column (without corners)
            for (int i = top + 1; i <= bottom - 1; ++i) {
                matrix[i][left] += add;
            }

            // right column (without corners and without duplicate with left)
            if (right != left) {
                for (int i = top + 1; i <= bottom - 1; ++i) {
                    matrix[i][right] += add;
                }
            }
        }
    }
}
