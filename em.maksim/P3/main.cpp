#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace em {

enum AlgorithmType {LFT_BOT_CLK, BLD_SMT_MTR};

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

AlgorithmType detectAlgorithmType(const char* programName) {
    std::string name(programName);
    if (name.find("LFT-BOT-CLK") != std::string::npos) {
        return LFT_BOT_CLK;
    } else {
        return BLD_SMT_MTR;
    }
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
    rows = 0;
    cols = 0;
    *matrix = nullptr;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open input file: " << filename << std::endl;
        return false;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "File is empty: " << filename << std::endl;
        return false;
    }

    file >> rows >> cols;

    if (file.fail()) {
        std::cerr << "Cannot read matrix dimensions from: " << filename << std::endl;
        return false;
    }

    if (rows == 0 && cols == 0) {
        std::cerr << "Empty matrix (0x0) is not allowed: " << filename << std::endl;
        return false;
    }

    if (rows < 0 || cols < 0) {
        std::cerr << "Invalid matrix dimensions: " << rows << " " << cols << std::endl;
        return false;
    }

    *matrix = createMatrix(rows, cols);
    if (!*matrix) {
        std::cerr << "Memory allocation failed for matrix " << rows << "x" << cols << std::endl;
        return false;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> (*matrix)[i][j])) {
                std::cerr << "Error reading matrix element at (" << i << "," << j << ")" << std::endl;
                freeMatrix(*matrix, rows);
                *matrix = nullptr;
                return false;
            }
        }
    }

    return true;
}

bool writeMatrix(const char* filename, int** matrix, int rows, int cols, bool smoothMatrix = false) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open output file: " << filename << std::endl;
        return false;
    }

    file << rows << " " << cols;

    if (rows > 0 && cols > 0) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file << " ";
                if (smoothMatrix) {
                    int value = matrix[i][j];
                    file << value / 10 << "." << abs(value % 10);
                } else {
                    file << matrix[i][j];
                }
            }
        }
    }

    return file.good();
}

void processLeftBottomClockwise(int** matrix, int rows, int cols) {
    if (!matrix || rows <= 0 || cols <= 0) return;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int counter = 1;

    while (top <= bottom && left <= right) {
        for (int i = bottom; i >= top; --i) {
            matrix[i][left] -= counter++;
        }
        left++;
        if (left > right) break;

        for (int j = left; j <= right; ++j) {
            matrix[top][j] -= counter++;
        }
        top++;
        if (top > bottom) break;

        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] -= counter++;
        }
        right--;
        if (left > right) break;

        for (int j = right; j >= left; --j) {
            matrix[bottom][j] -= counter++;
        }
        bottom--;
    }
}

void buildSmoothMatrix(int** matrix, int rows, int cols) {
    if (!matrix || rows <= 0 || cols <= 0) return;

    int** temp = createMatrix(rows, cols);
    if (!temp) return;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int sum = 0, count = 0;

            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        sum += matrix[ni][nj];
                        count++;
                    }
                }
            }

            temp[i][j] = (count > 0) ? (sum * 10 / count) : (matrix[i][j] * 10);
        }
    }

    copyMatrix(temp, matrix, rows, cols);
    freeMatrix(temp, rows);
}

} // namespace em

int main(int argc, char* argv[]) {
    int taskNumber;
    if (!em::validateArguments(argc, argv, taskNumber)) {
        return 1;
    }

    const char* inputFile = argv[2];
    const char* outputFile = argv[3];

    int rows = 0;
    int cols = 0;
    int** matrix = nullptr;

    if (!em::readMatrix(inputFile, &matrix, rows, cols)) {
        std::cerr << "Failed to read matrix from file" << std::endl;
        return 2;
    }

    if (taskNumber == 1 && rows * cols > 10000) {
        std::cerr << "Matrix too large for fixed array (max 10000 elements)" << std::endl;
        em::freeMatrix(matrix, rows);
        return 2;
    }

    bool success = true;
    if (rows > 0 && cols > 0) {
        em::AlgorithmType algo = em::detectAlgorithmType(argv[0]);

        if (algo == em::LFT_BOT_CLK) {
            em::processLeftBottomClockwise(matrix, rows, cols);
            success = em::writeMatrix(outputFile, matrix, rows, cols, false);
        } else {
            em::buildSmoothMatrix(matrix, rows, cols);
            success = em::writeMatrix(outputFile, matrix, rows, cols, true);
        }
    } else {
        success = em::writeMatrix(outputFile, matrix, rows, cols, false);
    }

    em::freeMatrix(matrix, rows);

    if (success) {
        std::cout << "Processing completed successfully" << std::endl;
        return 0;
    } else {
        std::cerr << "Error writing output file" << std::endl;
        return 2;
    }
}
