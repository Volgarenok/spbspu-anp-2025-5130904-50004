#include "Int_array.h"
#include <memory>

alekseev::Int_array::Int_array():
  data_(nullptr),
  counter_(0),
  size_(0)
{
}

alekseev::Int_array::Int_array(const Int_array & rhs):
  data_(new int[rhs.size()]),
  counter_(rhs.counter_),
  size_(rhs.size_)
{
  for (size_t i = 0; i < rhs.size(); ++i) {
    data_[i] = rhs.get(i);
  }
}

alekseev::Int_array & alekseev::Int_array::operator=(const Int_array & rhs)
{
  if (this == std::addressof(rhs)) {
    return *this;
  }
  int * temp = new int[rhs.size()];
  for (size_t i = 0; i < rhs.size(); ++i) {
    temp[i] = rhs.get(i);
  }
  delete[] data_;
  data_ = temp;
  counter_ = rhs.counter_;
  size_ = rhs.size_;

  return *this;
}

alekseev::Int_array::Int_array(Int_array && rhs) noexcept:
  data_(rhs.data_),
  counter_(rhs.counter_),
  size_(rhs.size_)
{
  rhs.data_ = nullptr;
}

alekseev::Int_array & alekseev::Int_array::operator=(Int_array && rhs) noexcept
{
  if (this == std::addressof(rhs)) {
    return *this;
  }
  data_ = rhs.data_;
  counter_ = rhs.number();
  size_ = rhs.size();
  rhs.data_ = nullptr;
  return *this;
}

alekseev::Int_array::Int_array(size_t s):
  data_(new int[s]{0}),
  counter_(0),
  size_(s)
{
}

alekseev::Int_array::~Int_array()
{
  delete[] data_;
}

void alekseev::Int_array::add(int a) noexcept
{
  for (size_t i = 0; i < size() - 1; ++i) {
    data_[i] = get(i + 1);
  }
  data_[size() - 1] = a;
  ++counter_;
}

int alekseev::Int_array::get(size_t id) const
{
  return data_[id];
}

size_t alekseev::Int_array::number() const noexcept
{
  return counter_;
}

size_t alekseev::Int_array::size() const noexcept
{
  return size_;
}
