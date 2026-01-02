#ifndef EQL_SEQ_HPP
#define EQL_SEQ_HPP
#include <cstddef>

namespace kuchukbaeva
{
  struct EqlSeq
  {
    EqlSeq();
    void operator()(int v);
    size_t operator()() const;
  private:
    size_t max_;
    size_t cur_;
    size_t cnt_;
    int last_;
  };
}

#endif

