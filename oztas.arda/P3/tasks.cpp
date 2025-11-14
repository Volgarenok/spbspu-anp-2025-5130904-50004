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
        int value = 1;

        for (int i = 0; i < rows; ++i) {
            if (i % 2 == 0) {
                // Left to Right
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] += value++;
                }
            }
            else {
                // Right to Left
                for (int j = cols - 1; j >= 0; --j) {
                    matrix[i][j] += value++;
                }
            }
        }
    }
}
