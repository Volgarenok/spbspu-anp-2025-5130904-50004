#include "eql_seq.hpp"
#include <iostream>

void zinovev::EQL_SEQ::doOutput() const
{
  std::cout << "EQL_SEQ: " << eql_seq_ << "\n";
}

void zinovev::EQL_SEQ::doProcess(int x)
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
