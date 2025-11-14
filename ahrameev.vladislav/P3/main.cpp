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

    std::cout << "Matrix size: " << rows << "x" << cols << "\n";

    if (rows == 0 || cols == 0) {
        input.close();
        std::cout << "Empty matrix\n";
        return 0;
    }

    int element;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(input >> element)) {
                std::cerr << "Error: Wrong matrix data\n";
                return 2;
            }
            std::cout << element << " ";
        }
        std::cout << "\n";
    }

    input.close();
    return 0;
}
