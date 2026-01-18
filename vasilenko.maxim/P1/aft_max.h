#ifndef AFT_MAX_H
#define AFT_MAX_H

#include <cstddef>

namespace vasilenko
{
  class AfterMaxCounter
  {
  public:
    AfterMaxCounter();

    void analyze(int number);
    size_t getCountAfterMax() const;

  private:
    int currentMaximum_;
    size_t elementsSinceMax_;
    bool isFirstElement_;
  };
}

#endif
