#include "Pth_trp.h"

alekseev::Pth_trp::Pth_trp(): iProperty(), k_(0), data_(new int[3]{0})
{
}

alekseev::Pth_trp::~Pth_trp()
{
  delete[] data_;
}

void alekseev::Pth_trp::update(int a)
{
  data_[0] = data_[1];
  data_[1] = data_[2];
  data_[2] = a;
  k_ += (data_[0] * data_[0] + data_[1] * data_[1] == data_[2] * data_[2]);
}

size_t alekseev::Pth_trp::value() const
{
  return k_;
}

const char * alekseev::Pth_trp::my_name() const
{
  return "Pth_trp";
}

bool alekseev::Pth_trp::cnted() const noexcept
{
  return data_[0] && data_[1] && data_[2];
}
