#include "Sum_dup.h"

alekseev::Sum_dup::Sum_dup(): iProperty(), k_(0), data_(new int[3]{0})
{
}

alekseev::Sum_dup::~Sum_dup()
{
  delete[] data_;
}

void alekseev::Sum_dup::update(int a)
{
  data_[0] = data_[1];
  data_[1] = data_[2];
  data_[2] = a;
  k_ += (data_[0] + data_[1] == data_[2]);
}

size_t alekseev::Sum_dup::value() const
{
  return k_;
}

const char * alekseev::Sum_dup::my_name() const
{
  return "Sum_dup";
}

bool alekseev::Sum_dup::cnted() const noexcept
{
  return data_[0] && data_[1] && data_[2];
}
