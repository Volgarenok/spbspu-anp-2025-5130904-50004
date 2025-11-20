#include "io.h"
#include "io.cpp"
#include "process.cpp"
#include <stdexcept>

int main(int argc, char **argv) {
    try {
        Nepochatova::checkArgs(argc, argv);

        int n, m;
        int* arr = Nepochatova::readMatrix(argv[2], n, m);

        if (argv[1][0] == '1') {
            Nepochatova::transformMatrixSpiral(arr, n, m);
        } else if (argv[1][0] == '2') {
            Nepochatova::transformMatrixCircular(arr, n, m);
        } else {
            throw std::invalid_argument("Invalid transformation choice");
        }

        std::ofstream out(argv[3]);
        writeMatrix(out, arr, n, m);

        delete[] arr;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

