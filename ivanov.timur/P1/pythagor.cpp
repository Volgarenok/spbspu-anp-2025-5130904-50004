#include "pythagor.h"

void ivanov::Pythagor::operator()(int e)
{
  a = b;
  b = c;
  c = e;
}

bool ivanov::Pythagor::get() const
{
  return ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a));
}
void ivanov::Pythagor::take()
{
  if (get()) count++;
}

size_t ivanov::Pythagor::operator()() const
{
  return count;
}
