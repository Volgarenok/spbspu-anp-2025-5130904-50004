#include <iostream>
#include <stdexcept>
#include "sub_max.hpp"
#include "eql_seq.hpp"

int main()
{
  kuchukbaeva::SubMax sub_max;
  kuchukbaeva::EqlSeq eql_seq;

  int val = 0;
  while (std::cin >> val && val != 0)
  {
    sub_max(val);
    eql_seq(val);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }

  int ret = 0;
  try
  {
    std::cout << sub_max() << "\n";
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    ret = 2;
  }

  try
  {
    std::cout << eql_seq() << "\n";
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    ret = 2;
  }
  return ret;
}

