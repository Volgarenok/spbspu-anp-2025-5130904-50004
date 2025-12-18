#include "after.h"

void ivanov::After::operator()(int e)
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
size_t ivanov::After::operator()() const
{
  return count;
}
