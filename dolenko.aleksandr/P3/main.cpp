#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char ** argv) {
    if (argc > 4) {
        std::cerr <<"Too many arguments\n";
        return 1;
    }
    else if (argc < 4) {
        std::cerr <<"Not enough arguments\n";
        return 1;
    }

    
    return 0;
}
