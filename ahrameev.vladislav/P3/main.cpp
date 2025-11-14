#include <iostream>
#include <fstream>

namespace ahrameev {
    bool checkArguments(int argc, char* argv[]) {
        if (argc != 4) {
            std::cerr << "Error: Wrong number of arguments\n";
            return false;
        }

        std::string num = argv[1];
        if (num != "1" && num != "2") {
            std::cerr << "Error: First argument must be 1 or 2\n";
            return false;
        }

        return true;
    }

    bool readMatrixSize(std::ifstream& input, int& rows, int& cols, const std::string& num) {
        input >> rows >> cols;

        if (rows < 0 || cols < 0) {
            std::cerr << "Error: Wrong matrix size\n";
            return false;
        }

        if (num == "1" && rows * cols > 10000) {
            std::cerr << "Error: Matrix too big for fixed array\n";
            return false;
        }

        return true;
    }

    int** createMatrix(int rows, int cols, const std::string& num) {
        int** matrix;

        if (num == "1") {
            matrix = new int*[100];
            for (int i = 0; i < 100; i++) {
                matrix[i] = new int[100];
            }
        } else {
            matrix = new int*[rows];
            for (int i = 0; i < rows; i++) {
                matrix[i] = new int[cols];
            }
        }

        return matrix;
    }

    void freeMatrix(int** matrix, const std::string& num, int rows) {
        if (num == "1") {
            for (int i = 0; i < 100; i++) {
                delete[] matrix[i];
            }
        } else {
            for (int i = 0; i < rows; i++) {
                delete[] matrix[i];
            }
        }
        delete[] matrix;
    }

    int calculateSum(int** matrix, int rows, int cols) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
}

int main(int argc, char* argv[]) {
    if (!ahrameev::checkArguments(argc, argv)) {
        return 1;
    }

    std::string num = argv[1];
    std::string inputFile = argv[2];
    std::string outputFile = argv[3];

    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "Error: Cannot open input file\n";
        return 2;
    }

    int rows, cols;
    if (!ahrameev::readMatrixSize(input, rows, cols, num)) {
        return 2;
    }


    int** matrix = ahrameev::createMatrix(rows, cols, num);


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(input >> matrix[i][j])) {
                std::cerr << "Error: Wrong matrix data\n";
                ahrameev::freeMatrix(matrix, num, rows);
                return 2;
            }
        }
    }
    input.close();


    int sum = ahrameev::calculateSum(matrix, rows, cols);
    std::cout << "Sum of elements: " << sum << "\n";


    ahrameev::freeMatrix(matrix, num, rows);
    return 0;
}

