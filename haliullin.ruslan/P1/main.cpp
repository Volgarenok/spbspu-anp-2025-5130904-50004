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
      int a = 0, b = 0, c = 0;
  };

  struct DivRem
  {
    DivRem();
    void operator()(int n);
    size_t operator()() const;
    private:
      size_t k_;
      int prev = 0, cur = 0;
  };
}

haliullin::PythagorTriple():
  k_(0)
{
}

void haliullin::PythagorTriple()(int n)
{
  a = b;
  b = c;
  c = n;
  k_ += (a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a);
}

void haliullin::PythagorTriple()() const
{
  return k_;
}


int main()
{
  namespace hal = haliullin;

  int num = 0;
  hal::PythagorTriple count_pth = hal::PythagorTriple();
  hal::DivRem count_div_rem = hal::DivRem();

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
    std::cout << count_div_rem << "\n";
    return 2;
  }

  std::cout << count_pth() << "\n" << count_div_rem() << "\n";
  return 0;
}
