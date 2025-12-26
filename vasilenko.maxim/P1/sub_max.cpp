#include "sub_max.h"

vasilenko::Sub_max::Sub_max():
  max_value_(0),
  second_max_value_(0),
  count_(0)
{
}

void vasilenko::Sub_max::update(int a)
{
  if (count_ == 0) {
    max_value_ = a;
    count_ = 1;
    return;
  }

  if (count_ == 1) {
    if (a > max_value_) {
      second_max_value_ = max_value_;
      max_value_ = a;
    } else if (a < max_value_) {
      second_max_value_ = a;
    }
    count_ = 2;
    return;
  }

  if (a > max_value_) {
    second_max_value_ = max_value_;
    max_value_ = a;
  } else if ((a > second_max_value_ || second_max_value_ == max_value_) && a < max_value_) {
    second_max_value_ = a;
  }
}

size_t vasilenko::Sub_max::value() const
{
  return second_max_value_;
}

const char * vasilenko::Sub_max::my_name() const
{
  return "SUB-MAX";
}

bool vasilenko::Sub_max::cnted() const noexcept
{
  return count_ >= 2;
}
