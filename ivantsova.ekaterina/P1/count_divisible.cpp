#include "count_divisible.hpp"
#include <stdexcept>

ivantsova::CountDivisible::CountDivisible():
  prev_(0),
  count_(0),
  hasPrev_(false)
{}

void ivantsova::CountDivisible::operator()(int a)
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

void ivantsova::CountDivisible::isValid() const
{
  if (!hasPrev_)
  {
    throw std::runtime_error("Cannot calculate the number of numbers divisible by the previous element");
  }
}

size_t ivantsova::CountDivisible::operator()() const
{
  isValid();
  return count_;
}
