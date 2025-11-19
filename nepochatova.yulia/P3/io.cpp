#include "io.h"
#include <iostream>
#include <stdexcept>

int Nepochatova::checkArgs(int argc, char **argv) {
    if (argc < 4) { throw std::invalid_argument("Not enough arguments"); }
    if (argc > 4) { throw std::invalid_argument("Too many argumenst"); }

    const char *p = argv[1];
    if (*p > 2) { throw std::invalid_argument("First parametr is out of range"); }

    if (*p == '\0') { throw std::invalid_argument("First parametr is not a number"); }
    while (*p) {
        if (*p < '0' || *p > '9')
            throw std::invalid_argument("First parametr is not a number");
        ++p;

    }
    return 0;
}


int * Nepochatova::readMatrix(const std::string &filename, int &n, int &m) {
    std::ifstream in(filename);
    if (!in)
        throw std::runtime_error("Input file can't be opened");

    if (!(in >> n >> m))
        throw std::runtime_error("invalid matrix format");

    if (n == 0 || m == 0)
        return nullptr;

    int *arr = new int [n * m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!(in >> arr[i * m + j])) {
                delete[] arr;
                throw std::runtime_error("invalid matrix data");
            }
    return arr;
}
void writeMatrix(std::ofstream& out, const int* arr, int n, int m) {
    if (arr == nullptr || n == 0 || m == 0) {
        out << "0 0\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            out << arr[i * m + j] << " ";
            out << "\n";
        }

    }
}
