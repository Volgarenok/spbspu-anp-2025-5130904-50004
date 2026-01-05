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
  for(;;)
  {
    if(!(std::cin >> val))
    {
      break;
    }
    if(val == 0)
    {
      break;
    }
    got_any = true;
    lm(val);
    sc(val);
  }
  if(std::cin.fail())
  {
    if(!std::cin.eof())
    {
      std::cerr << "bad input" << "\n";
      return 1;
    }
  }
  if(!got_any)
  {
    std::cerr << "empty" << "\n";
    return 2;
  }
  try
  {
    std::cout << "locmax = " << lm() << "\n";
  }
  catch(...)
  {
    std::cerr << "locmax error" << "\n";
    rc = 2;
  }
  try
  {
    std::cout << "sgnchg = " << sc() << "\n";
  }
  catch(...)
  {
    std::cerr << "sgnchg error" << "\n";
    rc = 2;
  }
  return rc;
}
