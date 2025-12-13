#include "EqlSeq.hpp"
#include <cstddef>

namespace kuchukbaeva
{
  EqlSeq::EqlSeq() :
    max_(0),
    cur_(0),
    cnt_(0),
    last_(0)
  {}

  void EqlSeq::operator()(int val)
  {
    if (cnt_ == 0 || val != last_)
    {
      cur_ = 1;
      last_ = val;
    }
    else
    {
      cur_++;
    }
    if (cur_ > max_)
    {
      max_ = cur_;
    }
    cnt_++;
  }

  size_t EqlSeq::res() const
  {
    return max_;
  }
}

