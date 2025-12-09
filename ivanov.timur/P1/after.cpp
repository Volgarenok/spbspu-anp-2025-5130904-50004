#include "after.h"

After::After() {}

void After::next(int e1)
{
  if (e1 > e0)
  {
    elem = e1;
    count = 0;
  }
  else
  {
    count++;
  }
}

size_t After::operator()() const
{
  return count;
}
