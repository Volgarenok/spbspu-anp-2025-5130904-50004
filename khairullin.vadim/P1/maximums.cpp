#include "maximums.hpp"

khairullin::Maximums::Maximums():
  k{0},
  maximum{0}
{}

void khairullin::Maximums::operator()(int a)
{
  if (a > maximum)
  {
    k = 1;
    maximum = a;
  }
  else if (a == maximum)
  {
    k++;
  }
}

size_t khairullin::Maximums::operator()()
{
  return k;
}
