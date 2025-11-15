#include <iostream>
#include <fstream>

namespace ahrameev
{
    bool checkArguments(int argc, char* argv[])
    {
        if (argc != 4)
        {
            std::cerr << "Error: Wrong number of arguments\n";
            return false;
        }

        std::string num = argv[1];
        if (num != "1" && num != "2")
        {
            std::cerr << "Error: First argument must be 1 or 2\n";
            return false;
        }

        return true;
    }

    bool readMatrixSize(std::ifstream& input, int& rows, int& cols, const std::string& num)
    {
        rows = 0;
        cols = 0;

        if (!(input >> rows >> cols)) {
            std::cerr << "Error: Cannot read matrix dimensions\n";
            return false;
        }

        if (rows < 0 || cols < 0)
        {
            std::cerr << "Error: Wrong matrix size\n";
            return false;
        }

        if (num == "1" && rows * cols > 10000)
        {
            std::cerr << "Error: Matrix too big for fixed array\n";
            return false;
        }

        return true;
    }

    int** createMatrix(int rows, int cols, const std::string& num)
    {
        int** matrix;

        if (num == "1")
        {
            matrix = new int* [100];
            for (int i = 0; i < 100; i++)
            {
                matrix[i] = new int[100]();
            }
        }
        else
        {
            matrix = new int* [rows];
            for (int i = 0; i < rows; i++)
            {
                matrix[i] = new int[cols]();
            }
        }

        return matrix;
    }

    void freeMatrix(int** matrix, const std::string& num, int rows)
    {
        if (matrix == nullptr) return;

        if (num == "1")
        {
            for (int i = 0; i < 100; i++)
            {
                delete[] matrix[i];
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
        }
        delete[] matrix;
    }

    void processSpiralDecrease(int** matrix, int rows, int cols, std::ofstream& output)
    {
        if (rows == 0 || cols == 0)
        {
            output << "Empty matrix\n";
            return;
        }
        int** result = new int* [rows];
        for (int i = 0; i < rows; i++)
        {
            result[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                result[i][j] = matrix[i][j];
            }
        }

        int decreaseValue = 1;
        int totalElements = rows * cols;
        int count = 0;

        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;

        while (count < totalElements)
        {
            for (int i = bottom; i >= top && count < totalElements; i--)
            {
                result[i][left] -= decreaseValue;
                decreaseValue++;
                count++;
            }
            left++;

            for (int j = left; j <= right && count < totalElements; j++)
            {
                result[top][j] -= decreaseValue;
                decreaseValue++;
                count++;
            }
            top++;

            for (int i = top; i <= bottom && count < totalElements; i++)
            {
                result[i][right] -= decreaseValue;
                decreaseValue++;
                count++;
            }
            right--;

            for (int j = right; j >= left && count < totalElements; j--)
            {
                result[bottom][j] -= decreaseValue;
                decreaseValue++;
                count++;
            }
            bottom--;
        }

        output << "Spiral decrease result:\n";
        output << rows << " " << cols << " ";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                output << result[i][j] << " ";
            }
        }
        output << "\n";

        for (int i = 0; i < rows; i++)
        {
            delete[] result[i];
        }
        delete[] result;
    }

    bool isLowerTriangular(int** matrix, int rows, int cols)
    {
        if (rows != cols) return false;

        for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < cols; j++)
            {
                if (matrix[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void processLowerTriangle(int** matrix, int rows, int cols, std::ofstream& output)
    {
        if (rows == 0 || cols == 0)
        {
            output << "Empty matrix\n";
            return;
        }

        bool isTriangular = isLowerTriangular(matrix, rows, cols);

        output << "Lower triangular check: ";
        if (isTriangular)
        {
            output << "YES - matrix is lower triangular\n";
        }
        else
        {
            output << "NO - matrix is not lower triangular\n";
        }
    }

    void writeOriginalMatrix(std::ofstream& output, int** matrix, int rows, int cols)
    {
        output << "Original matrix:\n";
        output << rows << " " << cols << " ";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                output << matrix[i][j] << " ";
            }
        }
        output << "\n";
    }
}

int main(int argc, char* argv[])
{
    if (!ahrameev::checkArguments(argc, argv))
    {
        return 1;
    }

    std::string num = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    std::ifstream input(inputFile);
    if (!input.is_open())
    {
        std::cerr << "Error: Cannot open input file\n";
        return 2;
    }

    input.peek();
    if (input.eof())
    {
        std::cerr << "Error: Empty file\n";
        input.close();
        return 2;
    }

    int rows = 0, cols = 0;
    if (!ahrameev::readMatrixSize(input, rows, cols, num))
    {
        input.close();
        return 2;
    }

    int** matrix = ahrameev::createMatrix(rows, cols, num);

    if (rows > 0 && cols > 0)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!(input >> matrix[i][j]))
                {
                    std::cerr << "Error: Wrong matrix data\n";
                    ahrameev::freeMatrix(matrix, num, rows);
                    input.close();
                    return 2;
                }
            }
        }
    }
    input.close();

    std::ofstream output(outputFile);
    if (!output.is_open())
    {
        std::cerr << "Error: Cannot open output file\n";
        ahrameev::freeMatrix(matrix, num, rows);
        return 2;
    }

    output << "=== TASK 1: Spiral Decrease ===\n";
    ahrameev::processSpiralDecrease(matrix, rows, cols, output);

    output << "\n=== TASK 2: Lower Triangle Check ===\n";
    ahrameev::processLowerTriangle(matrix, rows, cols, output);

    output << "\n=== ORIGINAL MATRIX ===\n";
    ahrameev::writeOriginalMatrix(output, matrix, rows, cols);

    output.close();
    ahrameev::freeMatrix(matrix, num, rows);

    return 0;
}
