#ifndef MATRIX_ACTIONS_HPP
#define MATRIX_ACTIONS_HPP
#include <iostream>
#include <cstddef>

namespace chadin
{

std::istream& readArr(std::istream& input, int* arr, std::size_t rows, std::size_t cols);

std::ostream& writeArr(std::ostream& output, const int* arr, std::size_t rows, std::size_t cols, int result);

void increaseElements(int* arr, std::size_t rows, std::size_t cols);

int countDiagonals(const int* arr, std::size_t rows, std::size_t cols);

}

#endif
