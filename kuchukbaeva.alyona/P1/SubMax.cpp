#include "SubMax.hpp"
#include <limits>
#include <stdexcept>

namespace kuchukbaeva
{
  SubMax::SubMax() :
    max_(std::numeric_limits<int>::min()),
    sec_(std::numeric_limits<int>::min()),
    cnt_(0)
  {}

  void SubMax::operator()(int v)
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

  int SubMax::res() const
  {
    return sec_;
  }

  bool SubMax::has() const
  {
    return cnt_ >= 2;
  }
}
