#include "Pth_trp.h"

alekseev::Pth_trp::Pth_trp():
  iProperty(),
  k_(0),
  data_(Int_array(3))
{
}

void alekseev::Pth_trp::update(int a)
{
  data_.add(a);
  k_ += (data_.get(0) * data_.get(0) + data_.get(1) * data_.get(1) == data_.get(2) * data_.get(2));
}

size_t alekseev::Pth_trp::value() const
{
  return k_;
}

const char * alekseev::Pth_trp::name_impl() const
{
  return "Pth_trp";
}

bool alekseev::Pth_trp::cnted() const noexcept
{
  return data_.number() >= 3;
}
