#include "pythagor.h"
#include <cstddef>

Pythagor::Pythagor() {}

void Pythagor::operator()(int e)
{
  a = b;
  b = c;
  c = e;
}

bool Pythagor::get() const
{
  return ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a));
}
void Pythagor::take()
{
  if (get()) count++;
}

size_t Pythagor::operator()() const
{
  return count;
}
