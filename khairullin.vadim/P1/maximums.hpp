#ifndef MAXIMUMS_HPP
#define MAXIMUMS_HPP
#include <cstddef>
namespace khairullin
{
  struct Maximums
  {
    Maximums();
    void operator()(int a);
    size_t operator()();
  private:
    size_t k;
    int maximum;
  };
}
#endif
