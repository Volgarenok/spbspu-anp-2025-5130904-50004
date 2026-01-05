#include "Sum_dup.h"

alekseev::Sum_dup::Sum_dup():
  iProperty(),
  k_(0),
  data_(Int_array(3))
{
}

void alekseev::Sum_dup::update(int a)
{
  data_.add(a);
  k_ += (data_.get(0) + data_.get(1) == data_.get(2));
}

size_t alekseev::Sum_dup::value() const
{
  return k_;
}

const char * alekseev::Sum_dup::name_impl() const
{
  return "Sum_dup";
}

bool alekseev::Sum_dup::cnted() const noexcept
{
  return data_.number() >= 3;
}
