#ifndef SIGN_CHANGE_HPP
#define SIGN_CHANGE_HPP
#include <cstddef>

namespace velizade
{
  struct SignChange
  {
    SignChange();
    void operator()(int cur);
    size_t operator()() const;
  private:
    void check() const;
    bool hasPrev_;
    int prev_;
    size_t count_;
  };
}

#endif
