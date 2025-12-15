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

int main()
{
  int error = 0;
  int a = 0;
  bool sequenceStart = false;

  ivantsova::CountMax countMax;
  ivantsova::CountDivisible countDiv;

  while (std::cin >> a)
  {
    if (a == 0)
    {
      break;
    }
    sequenceStart = true;
    countMax(a);
    countDiv(a);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Bad input" << "\n";
    return 1;
  }

  if (!sequenceStart)
  {
    std::cerr << "Empty sequence" << "\n";
    return 2;
  }

  if (countMax.isValid())
  {
    std::cout << countMax() << "\n";
  }

  else
  {
    std::cerr << "Cannot calculate the number of maximum elements" << "\n";
    error = 2;
  }

  if (countDiv.isValid())
  {
    std::cout << countDiv() << "\n";
  }

  else
  {
    std::cerr << "Cannot calculate the number of numbers divisible by the previous element" << "\n";
    error = 2;
  }
  return error;
}
