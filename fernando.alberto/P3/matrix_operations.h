#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

namespace fernando {
    int process_fixed_matrix(int* matrix, int rows, int cols);
    int process_dynamic_matrix(int* matrix, int rows, int cols);
    int count_local_maxima(int* matrix, int rows, int cols);
    int count_local_minima(int* matrix, int rows, int cols);
}
#endif
