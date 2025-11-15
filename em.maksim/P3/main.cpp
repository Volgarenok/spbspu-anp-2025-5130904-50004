#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace em {

bool validateArguments(int argc, char* argv[], int& taskNumber) {
    if (argc != 4) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return false;
    }
    
    if (std::strlen(argv[1]) != 1 || (argv[1][0] != '1' && argv[1][0] != '2')) {
        std::cerr << "First parameter is out of range or not a number" << std::endl;
        return false;
    }
    
    taskNumber = argv[1][0] - '0';
    return true;
}

int** createMatrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]();
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    if (matrix) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

void copyMatrix(int** source, int** destination, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            destination[i][j] = source[i][j];
        }
    }
}

bool readMatrix(const char* filename, int*** matrix, int& rows, int& cols) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open input file: " << filename << std::endl;
        return false;
    }
    
    file >> rows >> cols;
    if (rows < 0 || cols < 0) {
        std::cerr << "Invalid matrix dimensions" << std::endl;
        return false;
    }
    
    if (rows == 0 && cols == 0) {
        *matrix = nullptr;
        return true;
    }
    
    *matrix = createMatrix(rows, cols);
    if (!*matrix) {
        return false;
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> (*matrix)[i][j])) {
                std::cerr << "Error reading matrix element at (" << i << "," << j << ")" << std::endl;
                freeMatrix(*matrix, rows);
                return false;
            }
        }
    }
    
    return true;
}

bool writeMatrix(const char* filename, int** matrix, int rows, int cols) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open output file: " << filename << std::endl;
        return false;
    }
    
    file << rows << " " << cols;
    
    if (rows > 0 && cols > 0 && matrix) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file << " " << matrix[i][j];
            }
        }
    }
    
    return true;
}

} // namespace em

int main(int argc, char* argv[]) {
    int taskNumber;
    if (!em::validateArguments(argc, argv, taskNumber)) {
        return 1;
    }
    
    std::cout << "Valid arguments received. Task: " << taskNumber << std::endl;
    std::cout << "Input: " << argv[2] << ", Output: " << argv[3] << std::endl;
    
    return 0;
}
