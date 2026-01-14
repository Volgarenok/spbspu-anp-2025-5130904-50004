#include <iostream>
#include <cstddef>
#include "maximums.hpp"
#include "decrease.hpp"
namespace khair = khairullin;
int main()
{
  int number =  0;
  size_t counter = 0;
  khair::Maximums max;
  khair::Decrease count;
  while (std::cin >> number && number != 0)
  {
    max(number);
    count(number);
    counter++;
  }
  if (std::cin.fail())
  {
    std::cerr << "Something goes wrong\n";
    return 1;
  }
  if (counter == 0)
  {
    std::cerr << "Not enough numbers\n";
    return 1;
  }
  std::cout << max() << " " << count() << "\n";
}
