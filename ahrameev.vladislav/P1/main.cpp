#include "transform.h"
#include <iostream>

int main()
{
    auto res = ahrammev::compute();

    if (std::cin.fail())
    {
        std::cerr << "Error\n";
        return 1;
    }

    std::cout << res.cntMin << '\n';
    std::cout << res.aftMax << '\n';
    return 0;
}
