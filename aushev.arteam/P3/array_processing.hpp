#ifndef ARRAY_PROCESSING_HPP
#define ARRAY_PROCESSING_HPP

#include <fstream>

namespace aushev {

int findLongestSeriesColumn(int* matrix, int rows, int cols);
int findMinSumAntiDiagonals(int* matrix, int rows, int cols);
void processFixedArray(std::ifstream& input, std::ofstream& output);
void processDynamicArray(std::ifstream& input, std::ofstream& output);

}

#endif
