#include <iostream>

namespace ivantsova
{
  struct CountMax
  {
    CountMax():
    maxInit_(false),
    max_(0),
    count_(0)
    {}

    void operator()(int a)
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

    size_t operator()()const
    {
      return count_;
    }

    bool isValid()const
    {
      return maxInit_;
    }

  private:
    bool maxInit_;
    int max_;
    size_t count_;
  };

  struct CountDivisible
  {
    CountDivisible():
    prev_(0),
    count_(0),
    hasPrev_(false)
    {}

    void operator()(int a)
    {
      if (hasPrev_ && prev_ != 0 && a % prev_ == 0)
      {
        ++count_;
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

int main()
{
}
