#include "PythagorTriple.hpp"

haliullin::PythagorTriple::PythagorTriple():
  k_(0),
  a(0),
  b(0),
  c(0)
{
}

void haliullin::PythagorTriple::operator()(int n)
{
  a = b;
  b = c;
  c = n;

  int a2 = a * a;
  int b2 = b * b;
  int c2 = c * c;

  if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2))
  {
    ++k_;
  }
}

size_t haliullin::PythagorTriple::operator()() const
{
  return k_;
}
