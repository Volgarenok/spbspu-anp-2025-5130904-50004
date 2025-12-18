#include "eql_seq.hpp"
#include <iostream>

zinovev::EQL_SEQ::EQL_SEQ() :
  Base(),
  max_(0),
  eql_seq_(0)
{}

void zinovev::EQL_SEQ::operator()() const
{
  std::cout << "EQL_SEQ: " << eql_seq_ << "\n";
}

void zinovev::EQL_SEQ::operator()(int const x)
{
  if (max_ < x)
  {
    max_ = x;
    eql_seq_ = 1;
  }
  else if (max_ == x)
  {
    ++eql_seq_;
  }
}
