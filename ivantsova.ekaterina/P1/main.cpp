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

  while (std::cin >> a && a != 0)
  {
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

  try
  {
    std::cout << countMax() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << "\n";
    error = 2;
  }

  try
  {
    std::cout << countDiv() << "\n";
  }
  catch(const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    error = 2;
  }

  return error;
}
