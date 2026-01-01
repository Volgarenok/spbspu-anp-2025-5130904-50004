#include "MonInc.hpp"

aydogan::MonInc::MonInc() :
  max_len_(0),
  cur_len_(0),
  prev_(0),
  has_prev_(false)
{
}

void aydogan::MonInc::operator()(int n)
{
  if (!has_prev_)
  {
    has_prev_ = true;
    prev_ = n;
    cur_len_ = 1;
    max_len_ = 1;
    return;
  }

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