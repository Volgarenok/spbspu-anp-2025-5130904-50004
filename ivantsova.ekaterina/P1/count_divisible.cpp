#include "count_divisible.hpp"

namespace ivantsova
{
  CountDivisible::CountDivisible():
  prev_(0),
  count_(0),
  hasPrev_(false)
  {}

  void CountDivisible::operator()(int a)
  {
    if (hasPrev_ && prev_ != 0)
    {
      if (prev_ > 0)
      {
        if (a % prev_ == 0)
        {
          ++count_;
        }
      }
      else
      {
        if (a % (-prev_) == 0)
        {
          ++count_;
        }
      }
    }
    prev_ = a;
    hasPrev_ = true;
  }

  size_t CountDivisible::operator()()const
  {
    return count_;
  }

  bool CountDivisible::isValid()const
  {
    return hasPrev_;
  }
}
