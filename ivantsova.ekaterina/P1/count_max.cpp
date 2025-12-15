#include "count_max.hpp"

namespace ivantsova
{
  struct CountMax
  {
    CountMax::CountMax():
    maxInit_(false),
    max_(0),
    count_(0)
    {}

    void CountMax::operator()(int a)
    {
      if (!maxInit_)
      {
        max_ = a;
        count_ = 1;
        maxInit_ = true;
      }
      else if (a > max_)
      {
        max_ = a;
        count_ = 1;
      }
      else if (a == max_)
      {
        ++count_;
      }
    }

    size_t CountMax::operator()()const
    {
      return count_;
    }

    bool CountMax::isValid()const
    {
      return maxInit_;
    }

  private:
    bool maxInit_;
    int max_;
    size_t count_;
  };
}
