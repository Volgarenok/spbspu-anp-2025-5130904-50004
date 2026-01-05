#include "matrix.hpp"
#include <istream>

namespace oztas
{
  bool readMatrix(std::istream& input,
                  int matrix[],
                  int& rows,
                  int& cols)
  {
    if (!(input >> rows >> cols)) {
      return false;
    }
    
    if (rows < 0 || cols < 0) {
      return false;
    }
    
    if (rows == 0 || cols == 0) {
      return true;
    }

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (!(input >> matrix[i * cols + j])) {
          return false;
        }
      }
    }
    return true;
  }

  void writeMatrix(std::ostream& output,
                   const int matrix[],
                   int rows,
                   int cols)
  {
    output << rows << " " << cols;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        output << " " << matrix[i * cols + j];
      }
    }
  }
}
