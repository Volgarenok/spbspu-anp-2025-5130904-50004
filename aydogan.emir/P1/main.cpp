#include <iostream>
#include "MonInc.hpp"
#include "LocMin.hpp"

int main()
{
  int num = 0;
  aydogan::MonInc mon_inc;
  aydogan::LocMin loc_min;

  while (std::cin >> num && num != 0)
  {
    mon_inc(num);
    loc_min(num);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }

  std::cout << mon_inc() << "\n";
  std::cout << loc_min() << "\n";
  return 0;
}
