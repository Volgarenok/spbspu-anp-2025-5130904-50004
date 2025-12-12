#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

namespace em {

bool validate_arguments(int argc, char* argv[]);

void read_matrix(const char* filename, int* matrix, int& rows, int& cols, int max_size);
void read_matrix(const char* filename, int** matrix, int& rows, int& cols);

void write_matrix(const char* filename, const int* matrix, int rows, int cols, bool smooth_matrix = false);

void process_left_bottom_clockwise(int* matrix, int rows, int cols);
void build_smooth_matrix(int* matrix, int rows, int cols);

}

#endif
