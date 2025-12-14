#include "MonotonicIncreasing.hpp"
#include <climits>

alberto::MonotonicIncreasing::MonotonicIncreasing():
  max_length_(0),
  current_length_(0),
  previous_value_(INT_MIN),
  first_element_(true)
{
}

void alberto::MonotonicIncreasing::operator()(int n)
{
  if (first_element_)
  {
    previous_value_ = n;
    current_length_ = 1;
    max_length_ = 1;
    first_element_ = false;
    return;
  }
  if (n >= previous_value_)
  {
    current_length_++;
  }
  else
  {
    current_length_ = 1;
  }
  if (current_length_ > max_length_)
  {
    max_length_ = current_length_;
  }
  previous_value_ = n;
}

size_t alberto::MonotonicIncreasing::operator()() const
{
  return max_length_;
}
