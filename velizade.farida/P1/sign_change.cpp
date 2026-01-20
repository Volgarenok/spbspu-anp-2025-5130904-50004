#include "sign_change.hpp"
#include <stdexcept>

velizade::SignChange::SignChange():
  hasPrev_(false),
  prev_(0),
  count_(0)
{}

void velizade::SignChange::operator()(int cur)
{
  if (hasPrev_)
  {
    if ((prev_ > 0 && cur < 0) || (prev_ < 0 && cur > 0))
    {
      ++count_;
    }
  }
  prev_ = cur;
  hasPrev_ = true;
}

void velizade::SignChange::check() const
{
  if (!hasPrev_)
  {
    throw std::runtime_error("Too short");
  }
}

size_t velizade::SignChange::operator()() const
{
  check();
  return count_;
}
