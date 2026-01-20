#include "local_max.hpp"
#include <stdexcept>

velizade::LocalMax::LocalMax():
  hasPrev_(false),
  hasNext_(false),
  prev_(0),
  next_(0),
  count_(0)
{}

void velizade::LocalMax::operator()(int cur)
{
  if (hasPrev_ && hasNext_)
  {
    if (next_ > prev_ && next_ > cur)
    {
      ++count_;
    }
  }
  prev_ = next_;
  hasPrev_ = hasNext_;
  next_ = cur;
  hasNext_ = true;
}

void velizade::LocalMax::check() const
{
  if (!hasPrev_ || !hasNext_)
  {
    throw std::runtime_error("Too short");
  }
}

size_t velizade::LocalMax::operator()() const
{
  check();
  return count_;
}
