#include <iostream>
#include "PythagorTriple.hpp"
#include "DivRem.hpp"

int main()
{
  int num = 0;
  haliullin::PythagorTriple count_pth;
  haliullin::DivRem count_div_rem;
  size_t count = 0;

  while (std::cin >> num && num != 0)
  {
    count_pth(num);
    count_div_rem(num);
    ++count;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }

  if (count < 2)
  {
    std::cerr << "Too short a sequence for both characteristics" << "\n";
    return 2;
  }
  else if (count < 3)
  {
    std::cerr << "Too short a sequence for pyfagor" << "\n";
    std::cout << "DIV_REM: " << count_div_rem() << "\n";
    return 2;
  }

  std::cout << "PTH_TRP: " << count_pth() << "\n";
  std::cout << "DIV_REM: " << count_div_rem() << "\n";
  return 0;
}
