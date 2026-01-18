#include "transform.h"
#include <iostream>

int main()
{
  const ahrammev::Result result = ahrammev::compute();

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }

    std::cout << result.cntMin << '\n';

  if (!result.aftMaxValid)
  {
    std::cerr << "Cannot compute characteristic\n";
    return 2;
  }

  std::cout << result.aftMax << '\n';
  return 0;
}
