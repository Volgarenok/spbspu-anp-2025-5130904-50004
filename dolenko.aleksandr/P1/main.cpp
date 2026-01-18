#include <iostream>
#include <climits>

#include "functions.hpp"

int main()
{
  constexpr size_t max_sequence_size = 1000;
  int sequence[max_sequence_size];
  size_t count = 0;

  int value = 0;
  while (std::cin >> value)
  {
    if (value == 0)
    {
      break;
    }

    if (count >= max_sequence_size)
    {
      std::cerr << "Sequence too long" << "\n";
      return 2;
    }

    sequence[count] = value;
    count++;
  }

  return 0;
}