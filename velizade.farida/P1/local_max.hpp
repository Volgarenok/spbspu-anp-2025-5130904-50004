#ifndef LOCAL_MAX_HPP
#define LOCAL_MAX_HPP
#include <cstddef>

namespace velizade
{
  struct LocalMax
  {
    LocalMax();
    void operator()(int cur);
    size_t operator()() const;
  private:
    void check() const;
    bool hasPrev_;
    bool hasNext_;
    int prev_;
    int next_;
    size_t count_;
  };
}

#endif
