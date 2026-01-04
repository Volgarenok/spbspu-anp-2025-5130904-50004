#ifndef COUNT_MAX_HPP
#define COUNT_MAX_HPP
#include <cstddef>

namespace ivantsova
{
  struct CountMax
  {
    CountMax();
    void operator()(int a);
    size_t operator()() const;

  private:
    void isValid() const;
    bool maxInit_;
    int max_;
    size_t count_;
  };
}

#endif
