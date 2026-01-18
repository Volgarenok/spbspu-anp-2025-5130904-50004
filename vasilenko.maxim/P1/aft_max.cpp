#include "aft_max.h"

namespace vasilenko
{
  AfterMaxCounter::AfterMaxCounter():
    currentMaximum_(0),
    elementsSinceMax_(0),
    isFirstElement_(true)
  {}

  void AfterMaxCounter::analyze(int number)
  {
    if (isFirstElement_)
    {
      currentMaximum_ = number;
      isFirstElement_ = false;
      return;
    }

    if (number > currentMaximum_)
    {
      currentMaximum_ = number;
      elementsSinceMax_ = 0;
    }
    else
    {
      elementsSinceMax_++;
    }
  }

  size_t AfterMaxCounter::getCountAfterMax() const
  {
    return elementsSinceMax_;
  }
}
