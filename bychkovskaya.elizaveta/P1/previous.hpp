#ifndef PREVIOUS_HPP
#define PREVIOUS_HPP

#include <cstddef>

namespace bychkovskaya {

  struct MoreThanPrevious {
    MoreThanPrevious();
    void operator()(int num);
    size_t operator()() const;
  private:
    int prevNum_;
    int k_;
    int res_;
  };

}

#endif

