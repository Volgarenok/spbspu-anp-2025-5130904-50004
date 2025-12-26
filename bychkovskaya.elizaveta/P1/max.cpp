#include "max.hpp"

bychkovskaya::Max::Max():
  k_(0),
  res_(0),
  max_(0)
{}

void bychkovskaya::Max::operator()(int num)
{
  ++k_;
  if (k_ == 1 || (num > max_ && k_ != 1)) {
    max_ = num;
    res_ = 1;
  } else if (num == max_ && k_ != 1) {
    ++res_;
  }
}

size_t bychkovskaya::Max::operator()() const
{
  return res_;
}
