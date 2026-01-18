#include "func.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace Khvaevskii
{

bool isValidNumber(long long num)
{
    return (num >= -1000000 && num <= 1000000);
}

bool readMatrixFixed(const char* filename, int matrix[100][100], int& rows, int& cols)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }

    long long temp_rows, temp_cols;
    if (!(file >> temp_rows >> temp_cols))
    {
        file.close();
        return false;
    }

    if (temp_rows < 0 || temp_cols < 0 || temp_rows > 100 || temp_cols > 100)
    {
        file.close();
        return false;
    }

    rows = static_cast<int>(temp_rows);
    cols = static_cast<int>(temp_cols);

    if (static_cast<long long>(rows) * cols > 10000)
    {
        file.close();
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            long long temp_val;
            if (!(file >> temp_val))
            {
                file.close();
                return false;
            }
            if (!isValidNumber(temp_val))
            {
                file.close();
                return false;
            }
            matrix[i][j] = static_cast<int>(temp_val);
        }
    }

    file.close();
    return true;
}

int** readMatrixDynamic(const char* filename, int& rows, int& cols)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return nullptr;
    }

    long long temp_rows, temp_cols;
    if (!(file >> temp_rows >> temp_cols))
    {
        file.close();
        return nullptr;
    }

    if (temp_rows < 0 || temp_cols < 0)
    {
        file.close();
        return nullptr;
    }

    rows = static_cast<int>(temp_rows);
    cols = static_cast<int>(temp_cols);

    int** matrix = static_cast<int**>(malloc(rows * sizeof(int*)));
    if (!matrix)
    {
        file.close();
        return nullptr;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = static_cast<int*>(malloc(cols * sizeof(int)));
        if (!matrix[i])
        {
            for (int k = 0; k < i; k++)
            {
                free(matrix[k]);
            }
            free(matrix);
            file.close();
            return nullptr;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            long long temp_val;
            if (!(file >> temp_val))
            {
                for (int k = 0; k < rows; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);
                file.close();
                return nullptr;
            }
            if (!isValidNumber(temp_val))
            {
                for (int k = 0; k < rows; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);
                file.close();
                return nullptr;
            }
            matrix[i][j] = static_cast<int>(temp_val);
        }
    }

    file.close();
    return matrix;
}

void freeMatrix(int** matrix, int rows)
{
    if (matrix)
    {
        for (int i = 0; i < rows; i++)
        {
            free(matrix[i]);
        }
        free(matrix);
    }
}

long long maxSumDiagonal(int** matrix, int rows, int cols)
{
    if (rows == 0 || cols == 0)
    {
        return 0;
    }

    long long max_sum = -9223372036854775807LL - 1;

    for (int col_offset = 0; col_offset < cols; col_offset++)
    {
        long long sum = 0;
        int i = 0;
        int j = col_offset;
        while (i < rows && j < cols)
        {
            sum += matrix[i][j];
            i++;
            j++;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }

    for (int row_offset = 1; row_offset < rows; row_offset++)
    {
        long long sum = 0;
        int i = row_offset;
        int j = 0;
        while (i < rows && j < cols)
        {
            sum += matrix[i][j];
            i++;
            j++;
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }

    return max_sum;
}

int countSaddlePoints(int** matrix, int rows, int cols)
{
    if (rows == 0 || cols == 0)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        int min_in_row = matrix[i][0];
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] < min_in_row)
            {
                min_in_row = matrix[i][j];
            }
        }

        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == min_in_row)
            {
                bool is_max_in_col = true;
                for (int k = 0; k < rows; k++)
                {
                    if (matrix[k][j] > matrix[i][j])
                    {
                        is_max_in_col = false;
                        break;
                    }
                }

                if (is_max_in_col)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

}

