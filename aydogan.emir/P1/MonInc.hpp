#ifndef MONINC_HPP
#define MONINC_HPP

#include <cstddef>

namespace aydogan
{
  struct MonInc
  {
    MonInc();
    void operator()(int n);
    size_t operator()() const;

   private:
    size_t max_len_;
    size_t cur_len_;
    int prev_;
    bool has_prev_;
  };
}

#endif