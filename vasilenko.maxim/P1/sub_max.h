#ifndef SUB_MAX_H
#define SUB_MAX_H

#include <cstddef>

namespace vasilenko
{
  class SubMax
  {
  public:
    SubMax();

    void operator()(int num);
    int operator()() const;
    bool isReady() const;

  private:
    int max1_;
    int max2_;
    size_t cnt_;
  };
}

#endif
