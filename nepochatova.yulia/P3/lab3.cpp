#include <iostream>
#include <fstream>
#include <stdexcept>

namespace nepochatova {
    std::istream& readMatrix(std::istream& input, int** m, size_t rows, size_t cols) {
        for (size_t i = 0; i < rows * cols; ++i) {
            if (!(input >> arr[i])) {
                    throw std::runtime_error("Incorrect matrix input");
                }
            }
        }
        return input;
    }
    std::ostream& writeResult(std::ostream& output, const int* arr, size_t rows, size_t cols, int result) {
        output << result;
        if (rows > 0 && cols > 0) {
            output << "\n";
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    output << arr[i * cols + j];
                    if (j < cols - 1) output << " ";
                }
                if (i < rows - 1) output << "\n";
            }
        }
        return output;
    }