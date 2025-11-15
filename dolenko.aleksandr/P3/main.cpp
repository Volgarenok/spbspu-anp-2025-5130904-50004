#include <iostream>
#include <fstream>
#include <cstdlib>

namespace dolenko {

const int MAX_FIXED_SIZE = 10000;

struct Matrix {
    int** data;
    int rows;
    int cols;
    bool is_dynamic;
};

bool parseNumArg(const char* str, int& num);
Matrix* allocateDynamicMatrix(int rows, int cols);
void freeDynamicMatrix(Matrix* m);
bool readMatrix(std::istream& input, Matrix*& matrix, int num);
int findLongestColumn(const Matrix* matrix);
int countLocalMins(const Matrix* matrix);

bool parseNumArg(const char* str, int& num)
{
    if (str[0] == '\0' || str[1] != '\0') {
        return false;
    }
    if (str[0] == '1') {
        num = 1;
        return true;
    }
    if (str[0] == '2') {
        num = 2;
        return true;
    }
    return false;
}

Matrix* allocateDynamicMatrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0) {
        return nullptr;
    }
    
    Matrix* m = static_cast<Matrix*>(malloc(sizeof(Matrix)));
    if (m == nullptr) {
        return nullptr;
    }
    
    m->data = static_cast<int**>(malloc(rows * sizeof(int*)));
    if (m->data == nullptr) {
        free(m);
        return nullptr;
    }
    
    for (int i = 0; i < rows; ++i) {
        m->data[i] = static_cast<int*>(malloc(cols * sizeof(int)));
        if (m->data[i] == nullptr) {
            for (int j = 0; j < i; ++j) {
                free(m->data[j]);
            }
            free(m->data);
            free(m);
            return nullptr;
        }
    }
    
    m->rows = rows;
    m->cols = cols;
    m->is_dynamic = true;
    return m;
}

void freeDynamicMatrix(Matrix* m)
{
    if (m != nullptr && m->is_dynamic) {
        if (m->data != nullptr) {
            for (int i = 0; i < m->rows; ++i) {
                if (m->data[i] != nullptr) {
                    free(m->data[i]);
                }
            }
            free(m->data);
        }
        free(m);
    }
}

bool readMatrix(std::istream& input, Matrix*& matrix, int num)
{
    int rows = 0;
    int cols = 0;
    if (!(input >> rows >> cols)) {
        std::cerr << "Cannot read matrix dimensions from input" << std::endl;
        return false;
    }
    
    if (rows <= 0 || cols <= 0) {
        std::cerr << "Invalid matrix dimensions" << std::endl;
        return false;
    }
    
    if (num == 1) {
        if (static_cast<long long>(rows) * cols > MAX_FIXED_SIZE) {
            std::cerr << "Matrix size has maximum allowed for fixed array" << std::endl;
            return false;
        }
    }
    
    matrix = allocateDynamicMatrix(rows, cols);
    if (matrix == nullptr) {
        std::cerr << "Memory allocation failed for matrix" << std::endl;
        return false;
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(input >> matrix->data[i][j])) {
                std::cerr << "Cannot read element" << std::endl;
                freeDynamicMatrix(matrix);
                matrix = nullptr;
                return false;
            }
        }
    }
    
    return true;
}

int findLongestColumn(const Matrix* matrix)
{
    if (matrix == nullptr || matrix->rows == 0 || matrix->cols == 0) {
        return 0;
    }
    if (matrix->rows == 1) {
        return 1;
    }
    
    int maxLength = 0;
    int columnWithMax = 0;
    
    for (int j = 0; j < matrix->cols; ++j) {
        int currentLength = 1;
        int maxCurrentCol = 1;
        
        for (int i = 1; i < matrix->rows; ++i) {
            if (matrix->data[i][j] == matrix->data[i - 1][j]) {
                currentLength++;
            } else {
                if (currentLength > maxCurrentCol) {
                    maxCurrentCol = currentLength;
                }
                currentLength = 1;
            }
        }
        
        if (currentLength > maxCurrentCol) {
            maxCurrentCol = currentLength;
        }
        if (maxCurrentCol > maxLength) {
            maxLength = maxCurrentCol;
            columnWithMax = j + 1;
        }
    }
    
    return columnWithMax;
}

int countLocalMins(const Matrix* matrix)
{
    if (matrix == nullptr || matrix->rows < 3 || matrix->cols < 3) {
        return 0;
    }
    
    int count = 0;
    
    for (int i = 1; i < matrix->rows - 1; ++i) {
        for (int j = 1; j < matrix->cols - 1; ++j) {
            int current = matrix->data[i][j];
            bool isLocalMin = true;
            
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    int neighbor = matrix->data[i + di][j + dj];
                    if (current >= neighbor) {
                        isLocalMin = false;
                        break;
                    }
                }
                if (!isLocalMin) {
                    break;
                }
            }
            
            if (isLocalMin) {
                count++;
            }
        }
    }
    
    return count;
}

}

bool validateArguments(int argc, char** argv, int& num)
{
    if (argc != 4) {
        std::cerr << "Not enough arguments or too many arguments" << std::endl;
        return false;
    }
    if (!dolenko::parseNumArg(argv[1], num)) {
        std::cerr << "First parameter is not a number or first parameter is out of range" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    int num = 0;
    
    if (!validateArguments(argc, argv, num)) {
        return 1;
    }
    
    const char* input_filename = argv[2];
    const char* output_filename = argv[3];
    
    std::ifstream input(input_filename);
    if (!input.is_open()) {
        std::cerr << "Cannot open input" << std::endl;
        return 2;
    }
    
    dolenko::Matrix* matrix = nullptr;
    if (!dolenko::readMatrix(input, matrix, num)) {
        std::cerr << "Failed to read matrix" << input_filename << std::endl;
        input.close();
        return 2;
    }
    input.close();
    
    int result1 = dolenko::countLocalMins(matrix);
    int result2 = dolenko::findLongestColumn(matrix);
    
    std::ofstream output(output_filename);
    if (!output.is_open()) {
        std::cerr << "Cannot open output" << std::endl;
        dolenko::freeDynamicMatrix(matrix);
        return 1;
    }
    
    output << result1 << std::endl;
    output << result2 << std::endl;
    output.close();
    
    dolenko::freeDynamicMatrix(matrix);
    return 0;
}
