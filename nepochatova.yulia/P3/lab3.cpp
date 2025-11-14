#include <iostream>
#include <fstream>
#include <stdexcept>

namespace nepochatova {
    std::istream& readMatrix(std::istream& input, int** m, size_t rows, size_t cols) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                if (!(input >> m[i][j])) {
                    throw std::runtime_error("Incorrect matrix input");
                }
            }
        }
        return input;
    }
