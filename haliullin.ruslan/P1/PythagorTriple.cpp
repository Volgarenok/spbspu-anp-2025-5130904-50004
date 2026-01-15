#include "PythagorTriple.hpp"

haliullin::PythagorTriple::PythagorTriple():
  k_(0),
  a_(0),
  b_(0),
  c_(0)
{
}

void haliullin::PythagorTriple::operator()(int n)
{
  a_ = b_;
  b_ = c_;
  c_ = n;

  if (a_ > 0 && b_ > 0 && c_ > 0)
  {
    int a2 = a_ * a_;
    int b2 = b_ * b_;
    int c2 = c_ * c_;

    if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2))
    {
      ++k_;
    }
  }
}

size_t haliullin::PythagorTriple::operator()() const
{
  return k_;
}
