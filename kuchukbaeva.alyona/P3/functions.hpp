#ifndef FUNCTIONS2_HPP
#define FUNCTIONS2_HPP
#include <cstdlib>
namespace kuchukbaeva
{
  bool CntLocMax(int** matrix, size_t rows, size_t cols, size_t i, size_t j);
  int countLocMax(int** matrix, size_t rows, size_t cols);
  void LftBotClk(int** matrix, size_t rows, size_t cols);
  bool readMatrix(const char* filename, int*** matrix, size_t& rows, size_t& cols);
  bool readMatrixStatic(const char* filename, int** matrix, size_t& rows, size_t& cols, size_t max_rows, size_t max_cols);
  void freMatrix(int** matrix, size_t rows);
  bool Res(const char* filename, int res);
  bool writeMatrix(const char* filename, int** matrix, size_t rows, size_t cols, int locMaxCount);
}
#endif

