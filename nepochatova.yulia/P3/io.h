#ifndef P3_IO_H
#define P3_IO_H
#include  <fstream>

namespace nepochatova
{
  int checkArgs(int argc, char ** argv);
  int ** readMatrix(const std::string& filename, size_t& n, size_t& m);
  void writeMatrix(std::ofstream& out, const int* const* arr, size_t n, size_t m);
  void transformMatrixSpiral (int** arr, size_t n, size_t m);
  void transformMatrixCircular(int** arr, size_t n, size_t m);
}

#endif
