#include <iostream>
#include <cstring>
#include <cstdlib>
#include "file_operations.h"
#include "matrix_operations.h"
#include "memory_management.h"

using namespace std;

int main(int argc, char *argv[]) {
   
    if (argc != 4) {
        cerr << "Usage: /lab <num> <input> <output>" << endl;
        cerr << "num: 1 (fixed array) or 2 (dynamic array)" << endl;
        return 1;
    }

   
    int num = atoi(argv[1]);
    if (num != 1 && num != 2) {
        cerr << "Error: num must be 1 or 2" << endl;
        return 1;
    }

    const char* input_file = argv[2];
    const char* output_file = argv[3];

   
    int rows, cols;
    int* matrix = fernando::read_matrix(input_file, rows, cols);
    if (matrix == nullptr) {
        return 2;
    }

    
    int result;
    if (num == 1) {
        
        const int MAX_SIZE = 10000;
        if (rows * cols > MAX_SIZE) {
            cerr << "Error: Matrix too large for fixed array" << endl;
            fernando::free_matrix(matrix);
            return 2;
        }
        
        int static_matrix[MAX_SIZE];
        memcpy(static_matrix, matrix, rows * cols * sizeof(int));
        result = fernando::process_fixed_matrix(static_matrix, rows, cols);
    } else {
        
        result = fernando::process_dynamic_matrix(matrix, rows, cols);
    }

    
    if (!fernando::write_result(output_file, result)) {
        cerr << "Error writing to output file" << endl;
        fernando::free_matrix(matrix);
        return 2;
    }

    fernando::free_matrix(matrix);
    return 0;
}
