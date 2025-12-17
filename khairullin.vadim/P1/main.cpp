#include <iostream>
#include <cstddef>
#include "Maximums.hpp"
#include "Decrease.hpp"
namespace khair = khairullin;
int main()
{  
  int number =  0;
  khair::Maximums M;
  khair::Decrease D;
  while (std::cin >> number and number != 0)
    {
        if (number == 0)
        {
            break;
        }
        M(number);
        D(number);
    }
    if (std::cin.fail())
    {
        std::cerr << "Something goes wrong\n";
        return 1;
    }
    std::cout << M() << " " << D() << "\n";
}
