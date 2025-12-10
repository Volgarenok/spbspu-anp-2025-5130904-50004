#include <iostream>
int main()
{
  int num = 0;
  size_t count_pth = 0, count_div_rem = 0, count = 0;

  while (std::cin >> num && num != 0)
  {
    if (std::cin.fail() || std::cin.eof())
    {
      break;
    }

    if (count)
    {
      ++count_pth;
      ++count_div_rem;
    }
    ++count;
  }


  if (std::cin.fail() || std::cin.eof())
  {
    std::cerr << "Input error" << "\n";
    return 1;
  }

  if (count < 2)
  {
    std::cerr << "Too short a sequence for both characteristics" << "\n";
    return 2;
  }
  else if (count < 3)
  {
    std::cerr << "Too short a sequence for pyfagor" << "\n";
    std::cout << count_div_rem << "\n";
    return 2;
  }

  std::cout << count_pth << "\n" << count_div_rem << "\n";
  return 0;
}
