#include "after.h"

After::After() {}
void After::operator()(int e)
{
  if (e > elem)
  {
    elem = e;
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
