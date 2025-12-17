#ifndef AUSHEV_ARTEAM_P3_ARRAY_PROCESSING_HPP
#define AUSHEV_ARTEAM_P3_ARRAY_PROCESSING_HPP

#include <fstream>

namespace aushev {

int isLowerTriangularMatrix(const int* matrix, int rows, int cols);
int countLocalMaxima(const int* matrix, int rows, int cols);
void processFixedArray(std::ifstream& input, std::ofstream& output);
void processDynamicArray(std::ifstream& input, std::ofstream& output);

}

#endif
