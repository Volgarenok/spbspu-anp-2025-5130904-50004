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

  if (!std::cin.eof() && !std::cin.good())
  {
    std::cerr << "Error reading sequence" << "\n";
    return 1;
  }

  bool div_rem_can_calculate = true;
  int div_rem_result = dolenko::count_divisible_by_previous(sequence, count, div_rem_can_calculate);
  int evn_cnt_result = dolenko::max_consecutive_even(sequence, count);

  return 0;
}