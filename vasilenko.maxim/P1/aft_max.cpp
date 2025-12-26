#include "aft_max.h"

vasilenko::Aft_max::Aft_max():
  max_value_(0),
  count_after_max_(0),
  max_found_(false),
  has_elements_(false)
{
}

void vasilenko::Aft_max::update(int a)
{
  if (!has_elements_) {
    max_value_ = a;
    has_elements_ = true;
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
  return has_elements_;
}
