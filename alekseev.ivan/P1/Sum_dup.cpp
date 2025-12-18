#include "Sum_dup.h"

alekseev::Sum_dup::Sum_dup(): iProperty(), k(0), data(new int[3]{0})
{
}

alekseev::Sum_dup::~Sum_dup()
{
  delete[] data;
}

void alekseev::Sum_dup::update(int a)
{
  data[0] = data[1];
  data[1] = data[2];
  data[2] = a;
  k += (data[0] + data[1] == data[2]);
}

size_t alekseev::Sum_dup::value() const
{
  return k;
}

const char * alekseev::Sum_dup::my_name() const
{
  return "Sum_dup";
}

bool alekseev::Sum_dup::cnted() const noexcept
{
  return data[0] && data[1] && data[2];
}
