#include <iostream>
#include "aft_max.h"
#include "sub_max.h"

int main()
{
  vasilenko::AftMax aftCounter;
  vasilenko::SubMax subFinder;

  int input = 0;
  size_t total = 0;

  while (std::cin >> input && input != 0)
  {
    aftCounter(input);
    subFinder(input);
    total++;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input error\n";
    return 1;
  }

  if (total == 0)
  {
    std::cerr << "Empty sequence\n";
    return 2;
  }

  std::cout << aftCounter() << "\n";

  if (subFinder.isReady())
  {
    std::cout << subFinder() << "\n";
  }
  else
  {
    std::cerr << "Not enough elements for SubMax\n";
    return 2;
  }

  return 0;
}
