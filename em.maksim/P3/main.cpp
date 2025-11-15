#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace em {

bool validateArguments(int argc, char* argv[], int& taskNumber) {
    if (argc != 4) {
        std::cerr << "Invalid number of arguments" << std::endl;
        return false;
    }
    
    if (std::strlen(argv[1]) != 1 || (argv[1][0] != '1' && argv[1][0] != '2')) {
        std::cerr << "First parameter is out of range or not a number" << std::endl;
        return false;
    }
    
    taskNumber = argv[1][0] - '0';
    return true;
}

} // namespace em

int main(int argc, char* argv[]) {
    int taskNumber;
    if (!em::validateArguments(argc, argv, taskNumber)) {
        return 1;
    }
    
    std::cout << "Valid arguments received. Task: " << taskNumber << std::endl;
    std::cout << "Input: " << argv[2] << ", Output: " << argv[3] << std::endl;
    
    return 0;
}
