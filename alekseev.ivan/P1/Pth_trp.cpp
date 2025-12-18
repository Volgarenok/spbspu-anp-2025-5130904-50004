#include "Pth_trp.h"

alekseev::Pth_trp::Pth_trp(): iProperty(), k(0), data(new int[3]{0})
{
}

void alekseev::Pth_trp::update(int a)
{
  data[0] = data[1];
  data[1] = data[2];
  data[2] = a;
  k += (data[0] * data[0] + data[1] * data[1] == data[2] * data[2]);
}

size_t alekseev::Pth_trp::value() const
{
  return k;
}

const char * alekseev::Pth_trp::my_name() const
{
  return "Pth_trp";
}

bool alekseev::Pth_trp::cnted() const noexcept
{
  return data[0] && data[1] && data[2];
}

alekseev::Pth_trp::~Pth_trp()
{
  delete[] data;
}
