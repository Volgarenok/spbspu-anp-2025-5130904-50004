#include "decrease.hpp"
khairullin::Decrease::Decrease():
  k{0},
  temp{0},
  max_mean{0}
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
    if (max_mean < k)
    {
      max_mean = k;
    }
    k = 1;
    temp = a;
  }
}

size_t khairullin::Decrease::operator()()
{
  return max_mean;
}
