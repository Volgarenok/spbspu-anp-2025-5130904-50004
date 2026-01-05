#include "transform.h"
#include <iostream>
#include <limits>

namespace ahrammev {

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

    Result compute()
    {
        Result res{};
        res.aftMaxValid = true;

        int num;
        bool first = true;

        int minVal = 0;
        int maxVal = 0;
        int countMin = 0;
        int maxPos = 0;
        int pos = 0;

        while (true)
        {
            if (!readInt(num))
            {
                return res;
            }

            if (num == 0) {
                break;
            }

            ++pos;

            if (first)
            {
                minVal = maxVal = num;
                countMin = 1;
                maxPos = 1;
                first = false;
            }
            else
            {
                if (num < minVal) {
                    minVal = num;
                    countMin = 1;
                }
                else if (num == minVal) {
                    ++countMin;
                }

                if (num > maxVal) {
                    maxVal = num;
                    maxPos = pos;
                }
            }
        }

        res.cntMin = first ? 0 : countMin;

        if (first)
        {
            res.aftMaxValid = false;
        }
        else
        {
            res.aftMax = pos - maxPos;
        }

        return res;
    }

}
