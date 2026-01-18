#include <iostream>
#include <fstream>
#include <cstdlib>
#include "func.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " num input output" << std::endl;
        return 1;
    }

    char* endptr;
    long num = strtol(argv[1], &endptr, 10);

    if (*endptr != '\0' || (num != 1 && num != 2))
    {
        std::cerr << "First parameter is out of range" << std::endl;
        return 1;
    }

    char* input_filename = argv[2];
    char* output_filename = argv[3];

    int rows, cols;

    if (num == 1)
    {
        int matrix[100][100];

        if (!Khvaevskii::readMatrixFixed(input_filename, matrix, rows, cols))
        {
            std::cerr << "Error reading matrix from file" << std::endl;
            return 2;
        }

        int** temp_matrix = static_cast<int**>(malloc(rows * sizeof(int*)));
        if (!temp_matrix)
        {
            std::cerr << "Memory allocation failed" << std::endl;
            return 2;
        }

        for (int i = 0; i < rows; i++)
        {
            temp_matrix[i] = static_cast<int*>(malloc(cols * sizeof(int)));
            if (!temp_matrix[i])
            {
                for (int k = 0; k < i; k++)
                {
                    free(temp_matrix[k]);
                }
                free(temp_matrix);
                std::cerr << "Memory allocation failed" << std::endl;
                return 2;
            }
            for (int j = 0; j < cols; j++)
            {
                temp_matrix[i][j] = matrix[i][j];
            }
        }

        long long result = Khvaevskii::maxSumDiagonal(temp_matrix, rows, cols);

        std::ofstream outfile(output_filename);
        if (!outfile.is_open())
        {
            for (int i = 0; i < rows; i++)
            {
                free(temp_matrix[i]);
            }
            free(temp_matrix);
            return 2;
        }
        outfile << result << std::endl;
        outfile.close();

        for (int i = 0; i < rows; i++)
        {
            free(temp_matrix[i]);
        }
        free(temp_matrix);
    }
    else
    {
        int** matrix = Khvaevskii::readMatrixDynamic(input_filename, rows, cols);

        if (!matrix)
        {
            std::cerr << "Error reading matrix from file" << std::endl;
            return 2;
        }

        int result = Khvaevskii::countSaddlePoints(matrix, rows, cols);

        std::ofstream outfile(output_filename);
        if (!outfile.is_open())
        {
            Khvaevskii::freeMatrix(matrix, rows);
            return 2;
        }
        outfile << result << std::endl;
        outfile.close();

        Khvaevskii::freeMatrix(matrix, rows);
    }

    return 0;
}
