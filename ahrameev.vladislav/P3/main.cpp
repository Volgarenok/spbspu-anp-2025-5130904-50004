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
}

int main(int argc, char* argv[]) {
    if (!ahrameev::checkArguments(argc, argv)) {
        return 1;
    }

    std::cout << "Arguments are OK\n";
    return 0;
}
