#include "GRT_LSS.h"

namespace chadin
{

int countGrtLss(
    const int* sequence,
    int size)
{
  if (size < 3)
  {
    return 0;
  }

  int count = 0;
  for (int i = 1; i < size - 1; ++i)
  {
    if (sequence[i] < sequence[i - 1] && sequence[i] > sequence[i + 1])
    {
      ++count;
    }
  }

  return count;
}

}
