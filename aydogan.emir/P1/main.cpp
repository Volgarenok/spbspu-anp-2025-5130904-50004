#include <iostream>
#include <stdexcept>
#include "mon_inc.hpp"
#include "loc_min.hpp"

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

  try
  {
    std::cout << mon_inc() << "\n";
    std::cout << loc_min() << "\n";
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }

  return 0;
}
