#include <iostream>
#include <cstddef>

#include "EqualSequence.hpp"
#include "MonotonicIncreasing.hpp"

int main()
{
  int num = 0;
  alberto::EqualSequence count_equal;
  alberto::MonotonicIncreasing count_monotonic;
  std::size_t element_count = 0;

  while (std::cin >> num && num != 0)
  {
    if (std::cin.fail() && !std::cin.eof())
    {
      std::cerr << "Error: invalid input." << "\n";
      return 1;
    }

    count_equal(num);
    count_monotonic(num);
    ++element_count;
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Error: invalid input." << "\n";
    return 1;
  }

  if (element_count == 0)
  {
    std::cout << 0 << "\n" << 0 << "\n";
    return 0;
  }

  std::cout << count_equal() << "\n" << count_monotonic() << "\n";
  return 0;
}
