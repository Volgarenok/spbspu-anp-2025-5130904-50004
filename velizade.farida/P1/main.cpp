#include <iostream>
#include "local_max.hpp"
#include "sign_change.hpp"

int main()
{
  velizade::LocalMax lm;
  velizade::SignChange sc;
  int val;
  bool got_any = false;
  int rc = 0;
  while (std::cin >> val && val != 0)
  {
    lm(val);
    sc(val);
  }
  if (std::cin.fail())
  {
    if (std::cin.eof() && !got_any)
    {
      std::cerr << "bad input" << "\n";
      return 1;
    }
    else if (std::cin.eof() && got_any)
    {
      std::cerr << "bad input" << "\n";
      return 1;
    }
    else if (!std::cin.eof())
    {
      std::cerr << "bad input" << "\n";
      return 1;
    }
  }
  try
  {
    std::cout << "locmax = " << lm() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "locmax error" << "\n";
    rc = 2;
  }
  try
  {
    std::cout << "sgnchg = " << sc() << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "sgnchg error" << "\n";
    rc = 2;
  }
  return rc;
}
