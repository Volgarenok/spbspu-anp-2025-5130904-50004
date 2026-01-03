#include <iostream>
#include "max.hpp"
#include "previous.hpp"

int main()
{
  bychkovskaya::Max max;
  bychkovskaya::MoreThanPrevious prev;
  int num = 0;
  while (std::cin >> num && num != 0) {
    prev(num);
    max(num);
  }
  if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
  std::cout << prev() << "\n";
  try {
    std::cout << max() << "\n";
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << "\n";
    return 2;
  }
  return 0;
}
