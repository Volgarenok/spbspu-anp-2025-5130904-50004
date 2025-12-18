#include "rth_trp.hpp"
#include <iostream>

zinovev::RTH_TRP::RTH_TRP() :
  Base(),
  a_(0),
  b_(0),
  c_(0),
  pth_trp_(0)
{}

void zinovev::RTH_TRP::operator()() const
{
  if (a_ == 0)
  {
    std::cerr << "ERROR: few numbers for RTH_TRP\n";
  }
  else
  {
    std::cout << "RTH_TRP: " << pth_trp_ << "\n";
  }
}

void zinovev::RTH_TRP::operator()(int const x)
{
  a_ = b_;
  b_ = c_;
  c_ = x;

  if (a_ * a_ + b_ * b_ == c_ * c_ || a_ * a_ + c_ * c_ == b_ * b_ || b_ * b_ + c_ * c_ == a_ * a_)
  {
    ++pth_trp_;
  }
}

bool zinovev::RTH_TRP::few_numbers()
{
  return a_ == 0;
}
