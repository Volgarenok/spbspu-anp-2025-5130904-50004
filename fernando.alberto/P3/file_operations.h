#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

namespace fernando {
    int* read_matrix(const char* filename, int& rows, int& cols);
    bool write_result(const char* filename, int result);
}

#endif
