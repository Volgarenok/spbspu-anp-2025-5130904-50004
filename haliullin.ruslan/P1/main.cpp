#include <iostream>

namespace haliullin
{
  struct PythagorTriple
  {
    PythagorTriple();
    void operator()(int n);
    size_t operator()() const;
    private:
      size_t k_;
      int a, b, c;
  };

  struct DivRem
  {
    DivRem();
    void operator()(int n);
    size_t operator()() const;
    private:
      size_t k_;
      int prev, cur;
  };
}

haliullin::PythagorTriple::PythagorTriple():
  k_(0),
  a(0),
  b(0),
  c(0)
{
}

void haliullin::PythagorTriple::operator()(int n)
{
  a = b;
  b = c;
  c = n;

  int a2 = a * a;
  int b2 = b * b;
  int c2 = c * c;

  if ((a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2))
  {
    ++k_;
  }
}

size_t haliullin::PythagorTriple::operator()() const
{
  return k_;
}


haliullin::DivRem::DivRem():
  k_(0),
  prev(0),
  cur(0)
{
}

void haliullin::DivRem::operator()(int n)
{
  prev = cur;
  cur = n;
  if ((prev != 0) && (cur % prev == 0))
  {
    ++k_;
  }
}

size_t haliullin::DivRem::operator()() const
{
  return k_;
}



int main()
{
  namespace hal = haliullin;

  int num = 0;
  hal::PythagorTriple count_pth;
  hal::DivRem count_div_rem;

  size_t count = 0;

  while (std::cin >> num && num != 0)
  {
    if (std::cin.fail() || std::cin.eof())
    {
      break;
    }

    count_pth(num);
    count_div_rem(num);
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
    std::cout << count_div_rem() << "\n";
    return 2;
  }

  std::cout << count_pth() << "\n" << count_div_rem() << "\n";
  return 0;
}
