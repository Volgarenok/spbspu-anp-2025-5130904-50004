#include "div_rem.hpp"

namespace dolenko {

int DivRem::calculate(const int* seq, size_t count, bool& can_calculate)
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

}
