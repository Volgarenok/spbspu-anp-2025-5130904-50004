#include "sub_max.h"

namespace vasilenko
{
  SecondMaxFinder::SecondMaxFinder():
    primaryMax_(0),
    secondaryMax_(0),
    processedCount_(0)
  {}

  void SecondMaxFinder::update(int number)
  {
    processedCount_++;

    if (processedCount_ == 1)
    {
      primaryMax_ = number;
    }
    else if (number > primaryMax_)
    {
      secondaryMax_ = primaryMax_;
      primaryMax_ = number;
    }
    else if (processedCount_ == 2 || number > secondaryMax_)
    {
      secondaryMax_ = number;
    }
  }

  bool SecondMaxFinder::isReady() const
  {
    return processedCount_ >= 2;
  }

  int SecondMaxFinder::getSecondMax() const
  {
    return secondaryMax_;
  }
}
