#ifndef LOCMIN_HPP
#define LOCMIN_HPP

#include <cstddef>

namespace aydogan
{
  struct LocMin
  {
    LocMin();
    void operator()(int n);
    size_t operator()() const;

   private:
    size_t k_;
    int a_;
    int b_;
    bool has_a_;
    bool has_b_;
  };
}

#endif
