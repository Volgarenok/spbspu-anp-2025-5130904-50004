#include "eql_seq.hpp"
#include <iostream>

zinovev::EQL_SEQ::EQL_SEQ() :
  Base(),
  max(0),
  eql_seq(0)
{}

void zinovev::EQL_SEQ::operator()() const
{
  std::cout << "EQL_SEQ: " << eql_seq << "\n";
}

void zinovev::EQL_SEQ::operator()(int const x)
{
  if (max < x)
  {
    max = x;
    eql_seq = 1;
  }
  else if (max == x)
  {
    ++eql_seq;
  }
}
