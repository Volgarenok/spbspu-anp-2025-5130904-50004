#ifndef PYTHAGOR_H
#define PYTHAGOR_H
#include <cstddef>
namespace ivanov
{
  struct Pythagor {
    Pythagor() = default;
    void operator()(int e);
    size_t operator()() const;
    bool get() const;
    void take();
  private:
    int a = 0;
    int b = 0;
    int c = 0;

    size_t count = 0;
  };
}
#endif
