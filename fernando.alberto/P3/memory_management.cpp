#include "memory_management.h"
#include <cstdlib>

namespace fernando {
    int* allocate_matrix(int rows, int cols) {
        return (int*)malloc(rows * cols * sizeof(int));
    }

    void free_matrix(int* matrix) {
        free(matrix);
    }
}
