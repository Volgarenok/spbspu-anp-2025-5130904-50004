#include "max.hpp"
#include <stdexcept>

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
  if (k_ == 0) {
    throw std::invalid_argument("Not enough elements to count quantity of max");
  }
  return res_;
}
