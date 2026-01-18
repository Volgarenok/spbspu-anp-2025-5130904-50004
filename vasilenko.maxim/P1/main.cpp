#include <iostream>
#include "aft_max.h"
#include "sub_max.h"

int main()
{
  vasilenko::AfterMaxCounter afterMaxTracker;
  vasilenko::SecondMaxFinder secondMaxTracker;

  int currentInput = 0;
  size_t totalCount = 0;

  while (std::cin >> currentInput && currentInput != 0)
  {
    afterMaxTracker.analyze(currentInput);
    secondMaxTracker.update(currentInput);
    totalCount++;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: Input format is invalid\n";
    return 1;
  }

  if (totalCount == 0)
  {
    std::cerr << "Error: Sequence is empty\n";
    return 2;
  }

  std::cout << afterMaxTracker.getCountAfterMax() << "\n";

  if (secondMaxTracker.isReady())
  {
    std::cout << secondMaxTracker.getSecondMax() << "\n";
  }
  else
  {
    std::cerr << "Error: Not enough elements for second maximum\n";
    return 2;
  }

  return 0;
}
