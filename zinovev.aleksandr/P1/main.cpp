#include <iostream>

int main()
{
  int a = 0, b = 0, c = 0;
  size_t pth_trp = 0;

  int max = 0;
  size_t eql_seq = 0;

  int x = 0;

  while (std::cin >> x && x != 0)
  {
    a = b;
    b = c;
    c = x;

    if (a != 0 && b != 0 && c != 0)
    {
      if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
      {
        ++pth_trp;
      }
    }

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

  if (std::cin.fail())
  {
    std::cerr << "ERROR: bad number\n";
    return 1;
  }

  if (a == 0)
  {
    std::cerr << "ERROR: few numbers for RTH_TRP\n";
  }
  else
  {
    std::cout << "RTH_TRP: " << pth_trp << "\n";
  }

  std::cout << "EQL_SEQ: " << eql_seq << "\n";

  if (a == 0)
  {
    return 2;
  }

  return 0;
}
