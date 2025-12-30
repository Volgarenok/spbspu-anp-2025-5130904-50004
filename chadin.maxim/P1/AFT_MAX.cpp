#include "AFT_MAX.h"

namespace chadin
{

int countAftMax(const int* sequence,int size)
{
  if (size <= 1)
  {
    return 0;
  }
  int max_value = sequence[0];
  int max_index = 0;
  for (int i = 1; i < size; ++i)
  {
    if (sequence[i] > max_value)
    {
      max_value = sequence[i];
      max_index = i;
    }
  }
  return size - max_index - 1;
}

}
