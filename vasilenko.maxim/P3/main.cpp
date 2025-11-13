#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

namespace vasilenko {

    struct Dynamic {
        int rows, cols;
        int* matrix = nullptr;

        void make_free();
        int cntcolnsm() const;
        int maxsumsdg() const;
    };

    struct Static {
        int rows, cols;
        int matrix[10000] = {};

        int cntcolnsm() const;
        int maxsumsdg() const;
    };
}

int main(int argc, char** argv) {

    if (argc != 4) {
        std::cerr << "Invalid number of arguments\n";
        return 1;
    }

    if (strcmp(argv[1], "1") != 0 && strcmp(argv[1], "2") != 0) {
        std::cerr << "First parameter is invalid (must be 1 or 2)\n";
        return 1;
    }

    std::ifstream input(argv[2]);
    if (!input.is_open()) {
        std::cerr << "Cannot open input file\n";
        return 2;
    }

    if (strcmp(argv[1], "1") == 0) {
        vasilenko::Static s;
        input >> s.rows >> s.cols;

        if (input.fail() || s.rows < 0 || s.cols < 0) {
            std::cerr << "Cannot read matrix dimensions\n";
            return 2;
        }

        if (s.rows * s.cols > 10000) {
            std::cerr << "Static matrix size exceeds limit (10000)\n";
            return 2;
        }

        for (int i = 0; i < s.rows * s.cols; ++i) {
            input >> s.matrix[i];

            if (input.fail()) {
                std::cerr << "Invalid matrix element data\n";
                return 2;
            }
        }
        input.close();

        std::ofstream output(argv[3]);
        if (!output.is_open()) {
            std::cerr << "Cannot open output file\n";
            return 1;
        }

        output << s.cntcolnsm() << "\n";
        output << s.maxsumsdg() << "\n";
        output.close();

    }

    else {
        vasilenko::Dynamic d;
        input >> d.rows >> d.cols;

        if (input.fail() || d.rows < 0 || d.cols < 0) {
            std::cerr << "Cannot read matrix dimensions\n";
            return 2;
        }

        if (d.rows * d.cols > 0) {
            d.matrix = static_cast<int*>(std::malloc(sizeof(int) * d.rows * d.cols));

            if (!d.matrix) {
                std::cerr << "Memory allocation failed\n";
                return 1;
            }
        }
        else {
            d.matrix = nullptr;
        }

        for (int i = 0; i < d.rows * d.cols; ++i) {
            input >> d.matrix[i];

            if (input.fail()) {
                std::cerr << "Invalid matrix element data\n";
                d.make_free();
                return 2;
            }
        }

        input.close();

        std::ofstream output(argv[3]);
        if (!output.is_open()) {
            std::cerr << "Cannot open output file\n";
            d.make_free();
            return 1;
        }

        output << d.cntcolnsm() << "\n";
        output << d.maxsumsdg() << "\n";
        output.close();

        d.make_free();
    }

    return 0;
}

void vasilenko::Dynamic::make_free() {
    std::free(matrix);
    matrix = nullptr;
}

int vasilenko::Static::cntcolnsm() const {
    int count = 0;

    if (rows < 2) {
        return cols;
    }

    for (int j = 0; j < cols; ++j) {
        bool has_consecutive = false;
        for (int i = 0; i < rows - 1; ++i) {

            if (matrix[i * cols + j] == matrix[(i + 1) * cols + j]) {
                has_consecutive = true;
                break;
            }
        }

        if (!has_consecutive) {
            count++;
        }
    }
    return count;
}

int vasilenko::Dynamic::cntcolnsm() const {
    int count = 0;
    if (rows < 2) {
        return cols;
    }

    for (int j = 0; j < cols; ++j) {
        bool has_consecutive = false;
        for (int i = 0; i < rows - 1; ++i) {
            if (matrix[i * cols + j] == matrix[(i + 1) * cols + j]) {
                has_consecutive = true;
                break;
            }
        }
        if (!has_consecutive) {
            count++;
        }
    }
    return count;
}

int vasilenko::Static::maxsumsdg() const {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int max_sum = 0;
    bool first_diag = true;

    for (int k = 1 - cols; k < rows; ++k) {
        int current_sum = 0;
        for (int i = 0; i < rows; ++i) {
            int j = i - k;

            if (j >= 0 && j < cols) {
                current_sum += matrix[i * cols + j];
            }
        }

        if (first_diag) {
            max_sum = current_sum;
            first_diag = false;
        }
        else {
            max_sum = std::max(max_sum, current_sum);
        }
    }
    return max_sum;
}

int vasilenko::Dynamic::maxsumsdg() const {
    if (rows == 0 || cols == 0) {
        return 0;
    }

    int max_sum = 0;
    bool first_diag = true;

    for (int k = 1 - cols; k < rows; ++k) {
        int current_sum = 0;
        for (int i = 0; i < rows; ++i) {
            int j = i - k;

            if (j >= 0 && j < cols) {
                current_sum += matrix[i * cols + j];
            }
        }

        if (first_diag) {
            max_sum = current_sum;
            first_diag = false;
        }
        else {
            max_sum = std::max(max_sum, current_sum);
        }
    }
    return max_sum;
}
