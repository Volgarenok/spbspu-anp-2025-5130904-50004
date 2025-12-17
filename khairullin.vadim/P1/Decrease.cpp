#include "Decrease.hpp"
khairullin::Decrease::Decrease():
k{0},
temp{0}
{}

void khairullin::Decrease::operator()(int a)
{
  if (a <= temp)
  {
     k++;
     temp = a;
  }
  else if (a > temp)
  {
    k = 1;
    temp = a;
  }
}

size_t khairullin::Decrease::operator()()
{
  return k;
}
