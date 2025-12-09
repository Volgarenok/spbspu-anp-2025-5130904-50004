#include "pythagor.h"

Pythagor::Pythagor(int a0, int b0, int c0): a(a0), b(b0), c(c0) {}

void Pythagor::next(int e)
{
  a = b;
  b = c;
  c = e;
}

bool Pythagor::operator()() const {
  return ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a));
}

