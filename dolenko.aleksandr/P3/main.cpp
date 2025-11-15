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
}

bool parse_num_arg(const char * str, int & num) {
    if (str[1] != "0") {
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

Matrix * allocate_dynamic_matrix(int rows, int cols){
    if (rows <=0 || cols <=0){
        return nullptr;
    }
    Matrix * m = (Matrix*)malloc(sizeof(Matrix));
        if (!m) return nullptr;
        m->data = (int**)malloc(rows * sizeof(int*));
        if (!m->data) {
            free(m);
            return nullptr;
        }

        for (int i = 0; i < rows; ++i) {
            m->data[i] = (int*)malloc(cols * sizeof(int));
            if (!m->data[i]) {
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

void free_dynamic_matrix(Matrix* m) {
    if (m && m->is_dynamic) {
        if (m->data) {
            for (int i = 0; i < m->rows; ++i) {
                if (m->data[i]) {
                    free(m->data[i]);
                }
            }
            free(m->data);
        }
        free(m);
    }
}

Matrix * read_matrix(const char * input , int num) {
    std::ifstream file(argv[2]);
    if (!input.is_open()) {
        std::cerr << "Cannot open input file " << std::endl;
        return nullptr
    }
    int rows, cols;
    if (!(input>> rows >> cols)) {
        std::cerr << "Cannot read matrix dimensions from input file " << std::endl;
            return nullptr;
       }

    if (rows <= 0 || cols <= 0) {
        std::cerr << "Invalid matrix dimensions: " << std::endl;
        return nullptr;
       }

    if (num == 1) {
        if (rows * cols > MAX_FIXED_SIZE) {
            std::cerr << "Matrix size has maximum allowed for fixed array" << std::endl;
            return nullptr;
           }
       }
    
    Matrix * matrix = allocate_dynamic_matrix(rows, cols);
    if (!matrix) {
        std::cerr << "Memory allocation failed for matrix." << std::endl;
        return nullptr;
        }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(input >> matrix->data[i][j])) {
                std::cerr << "Cannot read element" << std::endl;
                free_dynamic_matrix(matrix);
                return nullptr;
                }
            }
        }
        return matrix;
    }

int find_longest_column(const Matrix * matrix) {
    if (!matrix || matrix->rows == 0 || matrix->cols == 0) {
        return 0;
    }
    if (matrix->rows == 1) {
        return 1;
    }

    int max_length = 0;
    int column_max = 0;

    for (int j = 0; j < matrix->cols; ++j) {
        int current_length = 1;
        int max_current_col = 1;

        for (int i = 1; i < matrix->rows; ++i) {
            if (matrix->data[i][j] == matrix->data[i - 1][j]) {
                current_length++;
            } else {
                if (current_length > max_current) {
                    max_current_col_ = current_length;
                }
                current_length = 1;
            }
        }
        
        if (current_length > max_current_col) {
            max_current_col = current_length;
            }
        if (max_current_col > max_length) {
            max_length = max_current_col;
            column_with_max = j + 1;
        }
    }
    
    return column_with_max;
}

bool validate_arguments(int argc, char ** argv, int & num, const char *& input, const char *& output) {
    if (argc != 4) {
        std::cerr << "Not enough arguments or too many arguments"<< std::endl;
        return false;
    }
    if (!dolenko::parse_num_arg(argv[1], num)) {
        std::cerr << "First parameter is not a number or first parameter is out of range" << std::endl;
        return false;
    }
    input = argv[2];
    output = argv[3];

    return true;
}

int main(int argc, char ** argv) {
    int num = 0;
    const char * input_filename = nullptr;
    const char * output_filename = nullptr;
    
    if (!validate_arguments(argc, argv, num, input, output)) {
        return 1;
    }
    petrov::Matrix * matrix = petrov::read_matrix(input, num);
    
    if (!matrix) {
        std::cerr << "Failed to read matrix from input" << std::endl;
        return 2;
    }
    
    petrov::free_dynamic_matrix(matrix);
    return 0;
}
