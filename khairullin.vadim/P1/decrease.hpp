#ifndef DECREASE_HPP
#define DECREASE_HPP
#include <cstddef>
namespace khairullin
{
  struct Decrease
  {
    Decrease();
    void operator()(int a);
    size_t operator()();
  private:
    size_t k;
    size_t max_mean;
    int temp;
  };
}
#endif
