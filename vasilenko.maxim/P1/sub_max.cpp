#include "sub_max.h"

namespace vasilenko
{
  SubMax::SubMax():
    max1_(0),
    max2_(0),
    cnt_(0)
  {}

  void SubMax::operator()(int num)
  {
    cnt_++;

    if (cnt_ == 1)
    {
      max1_ = num;
    }
    else if (num > max1_)
    {
      max2_ = max1_;
      max1_ = num;
    }
    else if (cnt_ == 2 || num > max2_)
    {
      max2_ = num;
    }
  }

  bool SubMax::isReady() const
  {
    return cnt_ >= 2;
  }

  int SubMax::operator()() const
  {
    return max2_;
  }
}
