#include "previous.hpp"

bychkovskaya::MoreThanPrevious::MoreThanPrevious():
  prevNum_(0),
  k_(0),
  res_(0)
{}

void bychkovskaya::MoreThanPrevious::operator()(int num)
{
  ++k_;
  if (num > prevNum_ && k_ != 1) {
    ++res_;
  }
  prevNum_ = num;
}

size_t bychkovskaya::MoreThanPrevious::operator()() const
{
  return res_;
}

