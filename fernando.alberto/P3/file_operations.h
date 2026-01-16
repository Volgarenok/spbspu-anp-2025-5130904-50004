#ifndef FILE_OPERATIONS_HPP
#define FILE_OPERATIONS_HPP

namespace fernando
{
  int* read_matrix(const char* filename, int& rows, int& cols);
  bool write_result(const char* filename, int result);
}

#endif
