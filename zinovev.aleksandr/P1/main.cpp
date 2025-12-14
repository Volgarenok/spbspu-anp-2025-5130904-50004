#include <iostream>

namespace zinovev
{
  void process_rth_trp(int& a, int& b, int& c, size_t& pth_trp, bool& few_numbers, int x)
  {
    a = b;
    b = c;
    c = x;

    if (a != 0 && b != 0 && c != 0)
    {
      few_numbers = false;
      if (a * a + b * b == c * c ||
          a * a + c * c == b * b ||
          b * b + c * c == a * a)
      {
        ++pth_trp;
      }
    }
  }

  void process_eql_seq(int& max, size_t& eql_seq, int x)
  {
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

  void print_rth_trp_result(bool few_numbers, size_t pth_trp)
  {
    if (few_numbers)
    {
      std::cerr << "ERROR: few numbers for RTH_TRP\n";
    }
    else
    {
      std::cout << "RTH_TRP: " << pth_trp << "\n";
    }
  }

  void print_eql_seq_result(size_t eql_seq)
  {
    std::cout << "EQL_SEQ: " << eql_seq << "\n";
  }
}

int main()
{
  int a = 0, b = 0, c = 0;
  size_t pth_trp = 0;
  bool few_numbers = true;

  int max = 0;
  size_t eql_seq = 0;

  int x = 0;

  while (std::cin >> x && x != 0)
  {
    zinovev::process_rth_trp(a, b, c, pth_trp, few_numbers, x);
    zinovev::process_eql_seq(max, eql_seq, x);
  }

  if (std::cin.fail())
  {
    std::cerr << "ERROR: bad number\n";
    return 1;
  }

  zinovev::print_rth_trp_result(few_numbers, pth_trp);
  zinovev::print_eql_seq_result(eql_seq);

  if (few_numbers)
  {
    return 2;
  }

  return 0;
}
