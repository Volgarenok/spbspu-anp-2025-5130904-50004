#ifndef AFTER_H
#define AFTER_H
#include <cstddef>
namespace ivanov
{
  struct After {
    After() = default;
    void operator()(int e);
    size_t operator()() const;
  private:
    int elem = 0;
    size_t count = 0;
  };
}
#endif
