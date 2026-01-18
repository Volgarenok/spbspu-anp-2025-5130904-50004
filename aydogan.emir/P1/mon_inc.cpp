#include "mon_inc.hpp"
#include <limits>

aydogan::MonInc::MonInc():
  max_len_(0),
  cur_len_(0),
  prev_(std::numeric_limits< int >::max())
{}

void aydogan::MonInc::operator()(int n)
{
  if (n > prev_)
  {
    ++cur_len_;
  }
  else
  {
    cur_len_ = 1;
  }

  if (cur_len_ > max_len_)
  {
    max_len_ = cur_len_;
  }

  prev_ = n;
}

size_t aydogan::MonInc::operator()() const
{
  return max_len_;
}
