#ifndef FUNC_H
#define FUNC_H

namespace Khvaevskii
{

bool readMatrixFixed(const char* filename, int matrix[100][100], int& rows, int& cols);

int** readMatrixDynamic(const char* filename, int& rows, int& cols);

void freeMatrix(int** matrix, int rows);

long long maxSumDiagonal(int** matrix, int rows, int cols);

int countSaddlePoints(int** matrix, int rows, int cols);

bool isValidNumber(long long num);

}

#endif

