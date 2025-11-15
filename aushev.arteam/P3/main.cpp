#include <iostream>
#include <fstream>
#include <cstdlib>

namespace aushev {

int find_longest_series_column(int** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int max_len = 0;
    int col_num = 0;

    for (int j = 0; j < cols; j++) {
        int current_len = 1;
        int max_current = 1;

        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] == matrix[i-1][j]) {
                current_len++;
                if (current_len > max_current) {
                    max_current = current_len;
                }
            } else {
                current_len = 1;
            }
        }

        if (max_current > max_len) {
            max_len = max_current;
            col_num = j + 1;
        }
    }

    return col_num;
}

int find_min_sum_anti_diagonals(int** matrix, int rows, int cols) {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int num_diags = rows + cols - 1;
    int* sums = static_cast<int*>(malloc(num_diags * sizeof(int)));
    if (!sums) {
        return 0;
    }

    for (int k = 0; k < num_diags; k++) {
        sums[k] = 0;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int diag_idx = i + j;
            sums[diag_idx] += matrix[i][j];
        }
    }

    int min_sum = sums[0];
    for (int k = 1; k < num_diags; k++) {
        if (sums[k] < min_sum) {
            min_sum = sums[k];
        }
    }

    free(sums);
    return min_sum;
}

}