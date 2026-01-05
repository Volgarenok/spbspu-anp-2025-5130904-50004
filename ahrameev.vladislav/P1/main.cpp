#include "transform.h"
#include <iostream>

int main()
{
    auto res = ahrammev::compute();

    if (std::cin.fail()) {
        std::cerr << "Error\n";
        return 1;
    }

    std::cout << res.cntMin << '\n';

    if (res.aftMaxValid) {
        std::cout << res.aftMax << '\n';
        return 0;
    }
    else {
        std::cerr << "Error\n";
        return 2;
    }
}
