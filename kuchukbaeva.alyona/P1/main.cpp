#include "SubMax.hpp"
#include "EqlSeq.hpp"
#include <iostream>

int main()
{
  kuchukbaeva::SubMax sub_max;
  kuchukbaeva::EqlSeq eql_seq;

  int val = 0;
  while (std::cin >> val && val != 0) {
    sub_max(val);
    eql_seq(val);
  }

  if (std::cin.fail() && !std::cin.eof()) {
    std::cerr << "Input error" << "\n";
    return 1;
  }

  int ret = 0;

  if (sub_max.has()) {
    std::cout << sub_max.res() << "\n";
  } else {
    std::cerr << "Error: not enough elements for SUB-MAX" << "\n";
    ret = 2;
  }

  std::cout << eql_seq.res() << "\n";
  return ret;
}


