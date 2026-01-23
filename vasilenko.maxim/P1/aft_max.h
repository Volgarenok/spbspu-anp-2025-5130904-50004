#ifndef AFT_MAX_H
#define AFT_MAX_H

#include <cstddef>

namespace vasilenko
{
  class AftMax
  {
  public:
    AftMax();

    void operator()(int num);
    size_t operator()() const;

  private:
    int max_;
    size_t count_;
    bool isFirst_;
  };
}

#endif
