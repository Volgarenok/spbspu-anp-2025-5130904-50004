#ifndef MATRIX_ACTIONS_HPP
#define MATRIX_ACTIONS_HPP
#include <iostream>

namespace chadin
{
int* readMatrix(std::istream& in, int& rows, int& cols);
void deleteMatrix(int* matrix);
int countNonZeroDiagonals(const int* matrix, int rows, int cols);
void transformSpiralFromBottomLeft(int* matrix, int rows, int cols);
void writeMatrix(std::ostream& out, const int* matrix, int rows, int cols);
}

#endif
