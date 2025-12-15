#include <iostream>
#include "count_max.hpp"
#include "count_divisible.hpp"

int main()
{
  int error = 0;
  int a = 0;
  bool sequenceStart = false;

  ivantsova::CountMax countMax;
  ivantsova::CountDivisible countDiv;

  while (std::cin >> a)
  {
    if (a == 0)
    {
      break;
    }
    sequenceStart = true;
    countMax(a);
    countDiv(a);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input" << "\n";
    return 1;
  }

  if (!sequenceStart)
  {
    std::cerr << "Empty sequence" << "\n";
    return 2;
  }

  if (countMax.isValid())
  {
    std::cout << countMax() << "\n";
  }

  else
  {
    std::cerr << "Cannot calculate the number of maximum elements" << "\n";
    error = 2;
  }

  if (countDiv.isValid())
  {
    std::cout << countDiv() << "\n";
  }

  else
  {
    std::cerr << "Cannot calculate the number of numbers divisible by the previous element" << "\n";
    error = 2;
  }
  return error;
}
