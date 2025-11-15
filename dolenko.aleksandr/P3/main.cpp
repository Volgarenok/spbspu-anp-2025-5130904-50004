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
    const char * input = nullptr;
    const char * output = nullptr;

    if (!validate_arguments(argc, argv, num, input, output)) {
        return 1;
    }

        return 0;
    }
