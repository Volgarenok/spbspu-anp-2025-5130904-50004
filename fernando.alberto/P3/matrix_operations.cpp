#include "matrix_operations.h"

namespace fernando {
    int process_fixed_matrix(int* matrix, int rows, int cols) {
        return count_local_maxima(matrix, rows, cols);
    }

    int process_dynamic_matrix(int* matrix, int rows, int cols) {
        return count_local_minima(matrix, rows, cols);
    }

    int count_local_maxima(int* matrix, int rows, int cols) {
        int count = 0;
        if (rows < 3 || cols < 3) {
            return 0;
        }
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                int current = matrix[i * cols + j];
                if (current > matrix[(i-1) * cols + j] &&
                    current > matrix[(i+1) * cols + j] &&
                    current > matrix[i * cols + (j-1)] &&
                    current > matrix[i * cols + (j+1)]) {
                    count++;
                }
            }
        }
        return count;
    }

    int count_local_minima(int* matrix, int rows, int cols) {
        int count = 0;
        if (rows < 3 || cols < 3) {
            return 0;
        }
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                int current = matrix[i * cols + j];
                if (current < matrix[(i-1) * cols + j] &&
                    current < matrix[(i+1) * cols + j] &&
                    current < matrix[i * cols + (j-1)] &&
                    current < matrix[i * cols + (j+1)]) {
                    count++;
                }
            }
        }
        return count;
    }
}
