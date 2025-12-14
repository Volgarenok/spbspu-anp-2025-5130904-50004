#include "rth_trp.hpp"
#include <iostream>

zinovev::RTH_TRP::RTH_TRP() :
  Base(),
  a(0),
  b(0),
  c(0),
  pth_trp(0)
{}

void zinovev::RTH_TRP::operator()() const
{
  if (a == 0)
  {
    std::cerr << "ERROR: few numbers for RTH_TRP\n";
  }
  else
  {
    std::cout << "RTH_TRP: " << pth_trp << "\n";
  }
}

void zinovev::RTH_TRP::operator()(int const x)
{
  a = b;
  b = c;
  c = x;

  if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
  {
    ++pth_trp;
  }
}

bool zinovev::RTH_TRP::few_numbers()
{
  return a == 0;
}
