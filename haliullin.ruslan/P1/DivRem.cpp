#include "DivRem.hpp"

haliullin::DivRem::DivRem():
  k_(0),
  prev_(0),
  cur_(0)
{
}

void haliullin::DivRem::operator()(int n)
{
  prev_ = cur_;
  cur_ = n;
  if ((prev_ != 0) && (cur_ % prev_ == 0))
  {
    ++k_;
  }
}

size_t haliullin::DivRem::operator()() const
{
  return k_;
}
