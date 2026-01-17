#ifndef MON_DEC_HPP
#define MON_DEC_HPP

#include <cstddef>

namespace pozdeev {

  struct MonotoneDecreasing {
    MonotoneDecreasing();
    void operator()(int number);
    size_t operator()() const;

  private:
    size_t m_maxLength;
    size_t m_currentLength;
    int m_lastValue;
  };

}

#endif
