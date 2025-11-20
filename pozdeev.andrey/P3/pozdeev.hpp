#ifndef POZDEEV_H
#define POZDEEV_H

#include <iostream>
#include <fstream>

namespace pozdeev
{
const int MAX_SIZE = 10000;

int countNonSequentialRows(const int* matrix, int rows, int cols);
void spiral(int* matrix, int rows, int cols);
int numAnalysis(const char* s, int& outVal);
int processStatic(std::ifstream& fin, std::ofstream& fout, int rows, int cols);
int processDynamic(std::ifstream& fin, std::ofstream& fout, int rows, int cols);
}

#endif
