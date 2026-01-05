#ifndef COUNT_DIVISIBLE_HPP
#define COUNT_DIVISIBLE_HPP
#include <cstddef>

namespace ivantsova
{
  struct CountDivisible
  {
    CountDivisible();

    void operator()(int a);
    size_t operator()() const;

  private:
    int prev_;
    size_t count_;
    bool hasPrev_;
    void isValid() const;
  };
}

#endif
