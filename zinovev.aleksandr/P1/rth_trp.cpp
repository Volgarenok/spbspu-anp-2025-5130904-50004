#include "rth_trp.hpp"
#include <iostream>

void zinovev::RTH_TRP::doOutput() const
{
  if (a_ == 0)
  {
    throw std::runtime_error("few numbers for RTH_TRP");
  }
  std::cout << "RTH_TRP: " << pth_trp_ << "\n";
}

void zinovev::RTH_TRP::doProcess(int x)
{
  a_ = b_;
  b_ = c_;
  c_ = x;

  if (a_ * a_ + b_ * b_ == c_ * c_ || a_ * a_ + c_ * c_ == b_ * b_ || b_ * b_ + c_ * c_ == a_ * a_)
  {
    ++pth_trp_;
  }
}
