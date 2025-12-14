#include <iostream>

namespace zinovev
{

class RTH_TRP
{
public:
  RTH_TRP() :
    a(0),
    b(0),
    c(0),
    pth_trp(0)
  {}

  void process(int x)
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
  }

  void print_result() const
  {
    if (few_numbers())
    {
      std::cerr << "ERROR: few numbers for RTH_TRP\n";
    }
    else
    {
      std::cout << "RTH_TRP: " << pth_trp << "\n";
    }
  }

  bool few_numbers() const
  {
    return a == 0;
  }

private:
  int a, b, c;
  size_t pth_trp;
};

class EQL_SEQ
{
public:
  EQL_SEQ() :
    max(0),
    eql_seq(0)
  {}

  void process(int x)
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

  void print_result() const
  {
    std::cout << "EQL_SEQ: " << eql_seq << "\n";
  }

private:
  int max;
  size_t eql_seq;
};

}

int main()
{
  zinovev::RTH_TRP r;
  zinovev::EQL_SEQ e;

  int x = 0;

  while (std::cin >> x && x != 0)
  {
    r.process(x);
    e.process(x);
  }

  if (std::cin.fail())
  {
    std::cerr << "ERROR: bad number\n";
    return 1;
  }

  r.print_result();
  e.print_result();

  if (r.few_numbers())
  {
    return 2;
  }

  return 0;
}
