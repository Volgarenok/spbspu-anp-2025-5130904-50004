#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace dolenko {

constexpr size_t k_max_fixed_size = 10000;
constexpr size_t k_max_rows = 100;
constexpr size_t k_max_cols = 100;

std::istream& read_matrix(std::istream& in, int* arr, size_t rows, size_t cols);
std::ostream& write_matrix(std::ostream& out, size_t res);
int find_longest_column(const int* data, size_t rows, size_t cols);
int count_local_mins(const int* data, size_t rows, size_t cols);

}
#endif
