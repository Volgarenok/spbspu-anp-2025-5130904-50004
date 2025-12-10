#include <iostream>
#ifndef PYTHAGORTRIPLE_HPP
#define PYTHAGORTTIPLE_CPP

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
}
#endif
