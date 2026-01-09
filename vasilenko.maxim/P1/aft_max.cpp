#include "aft_max.h"

vasilenko::Aft_max::Aft_max():
  max_value_(0),
  count_after_max_(0),
  max_found_(false),
  data_(Int_array(10000))
{}

void vasilenko::Aft_max::operator()(int a)
{
  data_.add(a);

  if (data_.number() == 1) {
    max_value_ = a;
    return;
  }

  if (a > max_value_) {
    max_value_ = a;
    count_after_max_ = 0;
    max_found_ = true;
  } else if (max_found_) {
    ++count_after_max_;
  }
}

size_t vasilenko::Aft_max::value() const
{
  return count_after_max_;
}

const char * vasilenko::Aft_max::my_name() const
{
  return "AFT-MAX";
}

bool vasilenko::Aft_max::cnted() const noexcept
{
  return data_.number() > 0 && max_found_;
}
