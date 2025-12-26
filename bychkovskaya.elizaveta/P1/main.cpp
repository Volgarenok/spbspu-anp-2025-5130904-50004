#include <iostream>
#include "max.hpp"
#include "previous.hpp"

int main() {
  size_t count = 0;
  bychkovskaya::Max max;
  bychkovskaya::MoreThanPrevious prev;
  int num = 0;
  while (std::cin >> num && num != 0) {
    ++count;
    prev(num);
    max(num);
  }
  if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
  if (num == 0 && count == 0) {
    std::cout << prev() << "\n";
    std::cerr << "Not enough elements to count quantity of max" << "\n";
    return 2;
  }
  std::cout << prev() << "\n";
  std::cout << max() << "\n";
  return 0;
}
