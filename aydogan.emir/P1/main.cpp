#include <iostream>
#include "MonInc.hpp"
#include "LocMin.hpp"

int main()
{
    int num = 0;
    aydogan::MonInc mon_inc;
    aydogan::LocMin loc_min;

    size_t count = 0;

    while ((std::cin >> num) && (num != 0))
    {
        mon_inc(num);
        loc_min(num);
        ++count;
    }

    if (std::cin.fail() && !std::cin.eof())
    {
        std::cerr << "Input error\n";
        return 1;
    }

    if (count == 0)
    {
        std::cout << mon_inc() << "\n";
        std::cerr << "Too short a sequence for LOC-MIN\n";
        return 2;
    }

    std::cout << mon_inc() << "\n";
    std::cout << loc_min() << "\n";
    return 0;
}
