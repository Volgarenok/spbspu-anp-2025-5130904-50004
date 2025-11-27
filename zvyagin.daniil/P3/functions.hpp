#ifndef ZVYAGIN_FUNCTIONS_HPP
#define ZVYAGIN_FUNCTIONS_HPP

#include <cstddef>
#include <fstream>
namespace zvyagin
{
    size_t count_columns_no_same_adjacent(const int* data, size_t rows, size_t cols);
    size_t count_local_maxima(const int* data, size_t rows, size_t cols);
    bool readMatrix(std::ifstream& input, int* data, size_t size);
}

#endif
