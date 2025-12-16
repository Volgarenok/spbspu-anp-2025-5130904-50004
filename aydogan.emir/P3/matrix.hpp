#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iosfwd>

namespace aydogan
{
std::istream& readMatrix(std::istream& input, int* arr, int count);
int numColLsr(int r, int c, const int* a);
long long minSumMDG(int r, int c, const int* a);
void work_static(int r, int c, std::istream& in, std::ostream& out, int task);
void work_dynamic(int r, int c, std::istream& in, std::ostream& out, int task);
}

#endif
