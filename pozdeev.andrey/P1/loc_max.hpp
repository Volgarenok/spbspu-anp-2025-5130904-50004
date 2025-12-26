#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP

#include <cstddef>

namespace pozdeev {

  struct LocalMax {
  public:
    LocalMax();
    void operator()(int number);
    size_t getResult() const;
    bool hasResult() const;

  private:
    size_t m_count;
    int m_left;
    int m_middle;
    bool m_hasLeft;
    bool m_hasMiddle;
    bool m_processedAny;
  };

}

#endif
