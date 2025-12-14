#include <iostream>

namespace zinovev {

struct Base
{
  virtual void operator()() const = 0;
  virtual void operator()(int const) = 0;
  virtual ~Base() = default;
};

struct RTH_TRP : Base
{
  RTH_TRP():
    Base(),
    pth_trp(0),
    a(0),
    b(0),
    c(0)
  {}

  void operator()() const override;
  void operator()(int const x) override;
  bool few_numbers();

private:
  int a = 0, b = 0, c = 0;
  size_t pth_trp;
};

struct EQL_SEQ : Base
{
  EQL_SEQ() :
    Base(),
    max(0),
    eql_seq(0)
  {}

  void operator()() const override;
  void operator()(int const x) override;

private:
  int max;
  size_t eql_seq;
};

void RTH_TRP::operator()() const
{
  if (a == 0)
  {
    std::cerr << "ERROR: few numbers for RTH_TRP\n";
  }
  else
  {
    std::cout << "RTH_TRP: " << pth_trp << "\n";
  }
}

void RTH_TRP::operator()(int const x)
{
  a = b;
  b = c;
  c = x;

  if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
  {
    ++pth_trp;
  }
}

bool RTH_TRP::few_numbers()
{
  return a == 0 ? true : false;
}

void EQL_SEQ::operator()() const
{
  std::cout << "EQL_SEQ: " << eql_seq << "\n";
}

void EQL_SEQ::operator()(int const x)
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

} // namespace zinovev

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
}
