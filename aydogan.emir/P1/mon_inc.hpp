#ifndef MON_INC_HPP
#define MON_INC_HPP

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
  };
}

#endif
