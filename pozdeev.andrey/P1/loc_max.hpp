#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP

#include <cstddef>

namespace pozdeev {

  struct LocalMax {
    LocalMax();
    void operator()(int number);
    size_t operator()() const;

  private:
    size_t m_countResult;
    size_t m_elementsCount;
    int m_left;
    int m_middle;
  };

}

#endif
