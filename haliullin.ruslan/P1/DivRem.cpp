#include "DivRem.hpp"

haliullin::DivRem::DivRem():
  k_(0),
  prev(0),
  cur(0)
{
}

void haliullin::DivRem::operator()(int n)
{
  prev = cur;
  cur = n;
  if ((prev != 0) && (cur % prev == 0))
  {
    ++k_;
  }
}

size_t haliullin::DivRem::operator()() const
{
  return k_;
}
