#ifndef SUBMAX_HPP
#define SUBMAX_HPP
#include <cstddef>

namespace kuchukbaeva
{
  struct SubMax
  {
    SubMax();
    void operator()(int v);
    int res() const;
    bool has() const;
  private:
    int max_, sec_;
    size_t cnt_;
  };
}

#endif

