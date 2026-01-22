#include "transform.h"
#include <iostream>

namespace ahrammev
{

  Result compute()
  {
    Result result{};
    result.aftMaxValid = true;

    int num = 0;
    int pos = 0;

    bool first = true;

    int minValue = 0;
    int maxValue = 0;
    int minCount = 0;
    int lastMaxPos = 0;

    while (std::cin >> num && num != 0)
    {
      ++pos;

      if (first)
      {
        minValue = num;
        maxValue = num;
        minCount = 1;
        lastMaxPos = pos;
        first = false;
      }

      else
      {
        if (num < minValue)
        {
          minValue = num;
          minCount = 1;
        }
        else if (num == minValue)
        {
          ++minCount;
        }

        if (num >= maxValue)
        {
          maxValue = num;
          lastMaxPos = pos;
        }
      }
    }

    if (first)
    {
      result.cntMin = 0;
      result.aftMaxValid = false;
      return result;
    }

    result.cntMin = minCount;
    result.aftMax = pos - lastMaxPos;

    return result;
  }

}
