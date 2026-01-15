#include "sub_max.hpp"
#include <limits>
#include <stdexcept>

kuchukbaeva::SubMax::SubMax():
  max_(std::numeric_limits< int >::min()),
  sec_(std::numeric_limits< int >::min()),
  cnt_(0)
{
}

void kuchukbaeva::SubMax::operator()(int v)
{
  if (cnt_ == 0)
  {
    max_ = v;
  }
  else if (v > max_)
  {
    sec_ = max_;
    max_ = v;
  }
  else if (v > sec_)
  {
    sec_ = v;
  }
  ++cnt_;
}

int kuchukbaeva::SubMax::operator()() const
{
  if (cnt_ < 2)
  {
    throw std::logic_error("Not enough elements");
  }
  return sec_;
}

