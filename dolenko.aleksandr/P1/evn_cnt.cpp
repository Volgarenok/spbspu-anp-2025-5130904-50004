#include "evn_cnt.hpp"

namespace dolenko {

int EvnCnt::calculate(const int* seq, size_t count)
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
