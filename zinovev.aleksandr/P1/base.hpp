#ifndef BASE_HPP
#define BASE_HPP

namespace zinovev {

struct Base
{
  virtual void operator()() const = 0;
  virtual void operator()(int const) = 0;
  virtual ~Base() = default;
};
}

#endif
