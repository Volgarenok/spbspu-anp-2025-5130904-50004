#include "transform.h"
#include <iostream>
#include <limits>

namespace ahrammev
{

    static bool readInt(int& out)
{
        if (!(std::cin >> out))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        return true;
    }

    Result compute() {
        Result res{};
        int num;

        while (true) {
            if (!readInt(num)) {
                return res;
            }
            if (num == 0) break;
        }

        return res;
    }

}
