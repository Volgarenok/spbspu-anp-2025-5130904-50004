#ifndef SUB_MAX_H
#define SUB_MAX_H

#include <cstddef>

namespace vasilenko
{
  class SecondMaxFinder
  {
  public:
    SecondMaxFinder();

    void update(int number);
    int getSecondMax() const;
    bool isReady() const;

  private:
    int primaryMax_;
    int secondaryMax_;
    size_t processedCount_;
  };
}

#endif
