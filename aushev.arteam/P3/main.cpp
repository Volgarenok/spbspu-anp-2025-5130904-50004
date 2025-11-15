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

void process_fixed_array(std::ifstream& input, std::ofstream& output) {
    int rows, cols;
    if (!(input >> rows >> cols)) {
        throw "Invalid matrix dimensions";
    }

    if (rows < 0 || cols < 0) {
        throw "Invalid matrix dimensions";
    }
    if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
        throw "Invalid matrix dimensions";
    }
    if (rows == 0 && cols == 0) {
        output << "0\n";
        return;
    }

    const int MAX_SIZE = 10000;
    if (static_cast<long long>(rows) * cols > MAX_SIZE) {
        throw "Matrix size exceeds maximum allowed";
    }

    const int MAX_DIM = 100;
    if (rows > MAX_DIM || cols > MAX_DIM) {
        throw "Matrix dimensions exceed fixed array limits";
    }

    int fixed_matrix[MAX_DIM][MAX_DIM];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(input >> fixed_matrix[i][j])) {
                throw "Invalid matrix element";
            }
        }
    }

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = fixed_matrix[i][j];
        }
    }

    int result = find_longest_series_column(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    output << result << "\n";
}

void process_dynamic_array(std::ifstream& input, std::ofstream& output) {
    int rows, cols;
    if (!(input >> rows >> cols)) {
        throw "Invalid matrix dimensions";
    }

    if (rows < 0 || cols < 0) {
        throw "Invalid matrix dimensions";
    }
    if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
        throw "Invalid matrix dimensions";
    }
    if (rows == 0 && cols == 0) {
        output << "0\n";
        return;
    }

    int** matrix = static_cast<int**>(malloc(rows * sizeof(int*)));
    if (!matrix) {
        throw "Memory allocation failed";
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = static_cast<int*>(malloc(cols * sizeof(int)));
        if (!matrix[i]) {
            for (int k = 0; k < i; k++) {
                free(matrix[k]);
            }
            free(matrix);
            throw "Memory allocation failed";
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(input >> matrix[i][j])) {
                for (int k = 0; k < rows; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                throw "Invalid matrix element";
            }
        }
    }

    int result = find_min_sum_anti_diagonals(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    output << result << "\n";
}

}