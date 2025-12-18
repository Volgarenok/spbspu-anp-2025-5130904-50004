#ifndef PYTHAGORTRIPLE_HPP
#define PYTHAGORTRIPLE_HPP
#include <cstddef>

namespace haliullin
{
  struct PythagorTriple
  {
    PythagorTriple();
    void operator()(int n);
    size_t operator()() const;
   private:
    size_t k_;
    int a_, b_, c_;
  };
}
#endif
