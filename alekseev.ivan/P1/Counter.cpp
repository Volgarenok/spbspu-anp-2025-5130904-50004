#include "Counter.h"


alekseev::Counter::Counter(): k(0)
{
}


void alekseev::Counter::update(int a)
{
  ++k;
}


size_t alekseev::Counter::value() const
{
  return k;
}


const char * alekseev::Counter::my_name() const
{
  return "Counter";
}
