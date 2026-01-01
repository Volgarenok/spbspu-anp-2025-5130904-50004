#include "LocMin.hpp"

aydogan::LocMin::LocMin() :
  k_(0),
  a_(0),
  b_(0),
  has_a_(false),
  has_b_(false)
{
}

void aydogan::LocMin::operator()(int n)
{
  if (!has_a_)
  {
    a_ = n;
    has_a_ = true;
    return;
  }

  if (!has_b_)
  {
    b_ = n;
    has_b_ = true;
    return;
  }

  if ((b_ < a_) && (b_ < n))
  {
    ++k_;
  }

  a_ = b_;
  b_ = n;
}

size_t aydogan::LocMin::operator()() const
{
  return k_;
}
