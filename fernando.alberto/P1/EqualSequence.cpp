#include "EqualSequence.hpp"
#include <limits>

alberto::EqualSequence::EqualSequence():
  max_count_(0),
  current_count_(0),
  previous_value_(std::numeric_limits<int>::min()),
  first_element_(true)
{
}

void alberto::EqualSequence::operator()(const int n)
{
  if (first_element_)
  {
    previous_value_ = n;
    current_count_ = 1;
    max_count_ = 1;
    first_element_ = false;
    return;
  }
  if (n == previous_value_)
  {
    current_count_++;
  }
  else
  {
    current_count_ = 1;
  }
  if (current_count_ > max_count_)
  {
    max_count_ = current_count_;
  }
  previous_value_ = n;
}

size_t alberto::EqualSequence::operator()() const
{
  return max_count_;
}
