#include <iostream>
#include <stdexcept>
#include "rth_trp.hpp"
#include "eql_seq.hpp"

int main()
{
  zinovev::EQL_SEQ e;
  zinovev::RTH_TRP r;

  int x = 0;

  try
  {
    while (std::cin >> x && x != 0)
    {
      e(x);
      r(x);
    }

    if (std::cin.fail())
    {
      std::cerr << "ERROR: bad number\n";
      return 1;
    }

    e();
    r();
  }
  catch (const std::exception& ex)
  {
    std::cerr << "ERROR: " << ex.what() << "\n";
    return 2;
  }

  return 0;
}
