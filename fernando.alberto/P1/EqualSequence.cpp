#include "EqualSequence.hpp"
#include <limits>
#include <cstddef>

alberto::EqualSequence::EqualSequence():
  max_count_(0),
  current_count_(0)
{}

void alberto::EqualSequence::operator()(int value)
{
  static int previous_value = 0;
  static bool first = true;
  if (first) {
    first = false;
    previous_value = value;
    current_count_ = 1;
    max_count_ = 1;
    return;
  }
  if (value == previous_value) {
    ++current_count_;
    if (current_count_ > max_count_) {
      max_count_ = current_count_;
    }
  } else {
    current_count_ = 1;
  }
  previous_value = value;
}

size_t alberto::EqualSequence::operator()() const
{
  return max_count_;
}
