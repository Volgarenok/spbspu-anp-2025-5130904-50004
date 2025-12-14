#include <iostream>
#include "rth_trp.hpp"
#include "eql_seq.hpp"

int main()
{
  zinovev::EQL_SEQ e;
  zinovev::RTH_TRP r;

  int x = 0;

  while (std::cin >> x && x != 0)
  {
    r(x);
    e(x);
  }

  if (std::cin.fail())
  {
    std::cerr << "ERROR: bad number\n";
    return 1;
  }

  r();
  e();

  if (r.few_numbers())
  {
    return 2;
  }

  return 0;
}
