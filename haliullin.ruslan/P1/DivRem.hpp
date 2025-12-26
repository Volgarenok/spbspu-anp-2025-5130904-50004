#ifndef DIVREM_HPP
#define DIVREM_HPP
#include <cstddef>

namespace haliullin
{
  struct DivRem
  {
    DivRem();
    void operator()(int n);
    size_t operator()() const;
   private:
    size_t k_;
    int prev_, cur_;
  };
}
#endif
