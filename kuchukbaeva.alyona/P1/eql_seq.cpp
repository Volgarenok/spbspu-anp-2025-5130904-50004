#include "eql_seq.hpp"
#include <cstddef>
#include <stdexcept>

kuchukbaeva::EqlSeq::EqlSeq():
  max_(0),
  cur_(0),
  cnt_(0),
  last_(0)
{
}

void kuchukbaeva::EqlSeq::operator()(int val)
{
  if (cnt_ == 0 || val != last_)
  {
    cur_ = 1;
    last_ = val;
  }
  else
  {
    cur_++;
  }
  if (cur_ > max_)
  {
    max_ = cur_;
  }
  cnt_++;
}

size_t kuchukbaeva::EqlSeq::operator()() const
{
  if (cnt_ == 0)
  {
    throw std::logic_error("No elements");
  }
  return max_;
}
