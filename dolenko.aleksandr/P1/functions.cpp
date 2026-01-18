#include "functions.hpp"

namespace dolenko {

int count_divisible_by_previous(const int* seq, size_t count, bool& can_calculate)
{
  can_calculate = true;
  if (count < 2)
  {
    can_calculate = false;
    return 0;
  }

  int result = 0;
  for (size_t i = 1; i < count; ++i)
  {
    int prev = seq[i - 1];
    int curr = seq[i];

    if (prev != 0 && curr % prev == 0)
    {
      result++;
    }
  }

  return result;
}

int max_consecutive_even(const int* seq, size_t count)
{
  if (count == 0)
  {
    return 0;
  }

  int max_consecutive = 0;
  int current_consecutive = 0;

  for (size_t i = 0; i < count; ++i)
  {
    if (seq[i] % 2 == 0)
    {
      current_consecutive++;
      if (current_consecutive > max_consecutive)
      {
        max_consecutive = current_consecutive;
      }
    }
    else
    {
      current_consecutive = 0;
    }
  }

  return max_consecutive;
}

}
