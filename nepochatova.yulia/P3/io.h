#ifndef P3_IO_H
#define P3_IO_H
#include  <fstream>

namespace Nepochatova{
int checkArgs(int argc, char ** argv);
int ** readMatrix(const std::string& filename, int& n, int& m);
void writeMatrix(std::ofstream& out, const int* const*  arr, int n, int m);
void transformMatrixSpiral (int** arr, int n, int m);
void transformMatrixCircular(int** arr, int n, int m);
}

#endif