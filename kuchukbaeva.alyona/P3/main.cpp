#include "functions2.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  int num;
  char* endp = nullptr;
  long res = 0;
  res = std::strtol(argv[1], &endp, 10);
  if (endp == argv[1] || *endp != '\0')
  {
    std::cerr << "First parameter is not a number" << "\n";
    return 1;
  }
  num = static_cast<int>(res);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  size_t rows = 0;
  size_t cols = 0;

  if (num == 1)
  {
    const size_t stm = 100;
    int static_matrix[stm][stm];
    int* row_po[stm];
    for (size_t i = 0; i < stm; ++i)
    {
      row_po[i] = static_matrix[i];
    }
    if (!kuchukbaeva::readMatrixStatic(inputFile, row_po, rows, cols, stm, stm))
    {
      std::cerr << "Cannot read matrix from file" << "\n";
      return 2;
    }
    if (rows == 0 || cols == 0)
    {
      kuchukbaeva::Res(outputFile, 0);
    }
    else
    {
      int locMaxCount = kuchukbaeva::countLocMax(row_po, rows, cols);
      kuchukbaeva::LftBotClk(row_po, rows, cols);
      kuchukbaeva::writeMatrix(outputFile, row_po, rows, cols, locMaxCount);
    }
  }
  else
  {
    int** matrix = nullptr;
    if (!kuchukbaeva::readMatrix(inputFile, &matrix, rows, cols))
    {
      std::cerr << "Cannot read matrix from file" << "\n";
      return 2;
    }
    if (matrix == nullptr)
    {
      kuchukbaeva::Res(outputFile, 0);
    }
    else
    {
      int locMaxCount = kuchukbaeva::countLocMax(matrix, rows, cols);
      kuchukbaeva::LftBotClk(matrix, rows, cols);
      kuchukbaeva::writeMatrix(outputFile, matrix, rows, cols, locMaxCount);
    }
    if (matrix != nullptr)
    {
      kuchukbaeva::freMatrix(matrix, rows);
    }
  }
  return 0;
}

