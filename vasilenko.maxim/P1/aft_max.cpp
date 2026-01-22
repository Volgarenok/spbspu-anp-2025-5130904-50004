#include "aft_max.h"

namespace vasilenko
{
  AftMax::AftMax():
    max_(0),
    count_(0),
    isFirst_(true)
  {}

  void AftMax::operator()(int num)
  {
    if (isFirst_)
    {
      max_ = num;
      isFirst_ = false;
      return;
    }

    if (num > max_)
    {
      max_ = num;
      count_ = 0;
    }
    else
    {
      count_++;
    }
  }

  size_t AftMax::operator()() const
  {
    return count_;
  }
}
