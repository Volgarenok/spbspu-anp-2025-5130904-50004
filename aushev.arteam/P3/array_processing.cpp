#include "array_processing.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace aushev {

int findLongestSeriesColumn(int* matrix, int rows, int cols) {
  if (rows == 0 || cols == 0) {
    return 0;
  }

  int maxLen = 0;
  int colNum = 0;

  for (int j = 0; j < cols; j++) {
    int currentLen = 1;
    int maxCurrent = 1;

    for (int i = 1; i < rows; i++) {
      if (matrix[i * cols + j] == matrix[(i - 1) * cols + j]) {
        currentLen++;
        if (currentLen > maxCurrent) {
          maxCurrent = currentLen;
        }
      } else {
        currentLen = 1;
      }
    }

    if (maxCurrent > maxLen) {
      maxLen = maxCurrent;
      colNum = j + 1;
    }
  }

  return colNum;
}

int findMinSumAntiDiagonals(int* matrix, int rows, int cols) {
  if (rows == 0 || cols == 0) {
    return 0;
  }

  int numDiags = rows + cols - 1;
  int* sums = static_cast<int*>(malloc(numDiags * sizeof(int)));
  if (!sums) {
    return 0;
  }

  for (int k = 0; k < numDiags; k++) {
    sums[k] = 0;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int diagIdx = i + j;
      sums[diagIdx] += matrix[i * cols + j];
    }
  }

  int minSum = sums[0];
  for (int k = 1; k < numDiags; k++) {
    if (sums[k] < minSum) {
      minSum = sums[k];
    }
  }

  free(sums);
  return minSum;
}

void processFixedArray(std::ifstream& input, std::ofstream& output) {
  int rows = 0;
  int cols = 0;
  if (!(input >> rows >> cols)) {
    throw "Invalid matrix dimensions";
  }

  if (rows < 0 || cols < 0) {
    throw "Invalid matrix dimensions";
  }
  if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
    throw "Invalid matrix dimensions";
  }
  if (rows == 0 && cols == 0) {
    output << "0\n";
    return;
  }

  const int maxSize = 10000;
  if (static_cast<long long>(rows) * cols > maxSize) {
    throw "Matrix size exceeds maximum allowed";
  }

  const int maxDim = 100;
  if (rows > maxDim || cols > maxDim) {
    throw "Matrix dimensions exceed fixed array limits";
  }

  int fixedMatrix[maxDim][maxDim] = {};

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(input >> fixedMatrix[i][j])) {
        throw "Invalid matrix element";
      }
    }
  }

  int* matrix = new int[rows * cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i * cols + j] = fixedMatrix[i][j];
    }
  }

  int result = findLongestSeriesColumn(matrix, rows, cols);
  delete[] matrix;
  output << result << "\n";
}

void processDynamicArray(std::ifstream& input, std::ofstream& output) {
  int rows = 0;
  int cols = 0;
  if (!(input >> rows >> cols)) {
    throw "Invalid matrix dimensions";
  }

  if (rows < 0 || cols < 0) {
    throw "Invalid matrix dimensions";
  }
  if ((rows == 0 && cols > 0) || (rows > 0 && cols == 0)) {
    throw "Invalid matrix dimensions";
  }
  if (rows == 0 && cols == 0) {
    output << "0\n";
    return;
  }

  int* matrix = static_cast<int*>(malloc(rows * cols * sizeof(int)));
  if (!matrix) {
    throw "Memory allocation failed";
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!(input >> matrix[i * cols + j])) {
        free(matrix);
        throw "Invalid matrix element";
      }
    }
  }

  int result = findMinSumAntiDiagonals(matrix, rows, cols);
  free(matrix);
  output << result << "\n";
}

}
  