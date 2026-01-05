#include "count_max.hpp"
#include <stdexcept>

ivantsova::CountMax::CountMax():
  maxInit_(false),
  max_(0),
  count_(0)
{}

void ivantsova::CountMax::operator()(int a)
{
  if (!maxInit_)
  {
    max_ = a;
    count_ = 1;
    maxInit_ = true;
  }
  else if (a > max_)
  {
    max_ = a;
    count_ = 1;
  }
  else if (a == max_)
  {
    ++count_;
  }
}

void ivantsova::CountMax::isValid() const
{
  if (!maxInit_)
  {
    throw std::runtime_error("Cannot calculate the number of maximum elements");
  }
}

size_t ivantsova::CountMax::operator()() const
{
  isValid();
  return count_;
}
