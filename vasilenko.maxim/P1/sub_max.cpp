#include "sub_max.h"
#include <limits>

vasilenko::Sub_max::Sub_max():
  max_value_(0),
  second_max_value_(std::numeric_limits<int>::min()),
  data_(Int_array(2))
{}

void vasilenko::Sub_max::operator()(int a)
{
  data_.add(a);

  if (data_.number() == 1) {
    max_value_ = a;
    return;
  }

  if (a > max_value_) {
    second_max_value_ = max_value_;
    max_value_ = a;
  } else if (a > second_max_value_ || second_max_value_ == std::numeric_limits<int>::min()) {
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
  return data_.number() >= 2;
}
