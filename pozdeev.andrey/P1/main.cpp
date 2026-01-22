#include <iostream>
#include <stdexcept>
#include "mon_dec.hpp"
#include "loc_max.hpp"

int main()
{
  pozdeev::MonotoneDecreasing monDec;
  pozdeev::LocalMax locMax;
  int currentNumber = 0;

  while (std::cin >> currentNumber && currentNumber != 0) {
    monDec(currentNumber);
    locMax(currentNumber);
  }

  if (!std::cin.eof() && std::cin.fail()) {
    std::cerr << "Error: Input data is not a valid sequence\n";
    return 1;
  }

  std::cout << monDec() << "\n";

  try {
    std::cout << locMax() << "\n";
  } catch (const std::logic_error&) {
    std::cerr << "Error: Sequence is too short for local maxima calculation\n";
    return 2;
  }

  return 0;
}
