#include "count_divisible.hpp"

namespace ivantsova
{
  struct CountDivisible
  {
    CountDivisible():
    prev_(0),
    count_(0),
    hasPrev_(false)
    {}

    void operator()(int a)
    {
      if (hasPrev_ && prev_ != 0)
      {
        if (prev_ > 0)
        {
          if (a % prev_ == 0)
          {
            ++count_;
          }
        }
        else
        {
          if (a % (-prev_) == 0)
          {
            ++count_;
          }
        }
      }
      prev_ = a;
      hasPrev_ = true;
    }

    size_t operator()()const
    {
      return count_;
    }

    bool isValid()const
    {
      return hasPrev_;
    }

  private:
    int prev_;
    size_t count_;
    bool hasPrev_;
  };
}
