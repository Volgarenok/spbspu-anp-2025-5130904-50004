#ifndef SUB_MAX_HPP
#define SUB_MAX_HPP
#include <cstddef>

namespace kuchukbaeva
{
  struct SubMax
  {
    SubMax();
    void operator()(int v);
    int operator()() const;
  private:
    int max_, sec_;
    size_t cnt_;
  };
}

#endif

