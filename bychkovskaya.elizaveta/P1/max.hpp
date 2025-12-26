#ifndef MAX_HPP
#define MAX_HPP

#include <cstddef>

namespace bychkovskaya {

  struct Max {
    Max();
    void operator()(int num);
    size_t operator()() const;
  private:
    size_t k_;
    size_t res_;
    int max_;
  };
}

#endif
