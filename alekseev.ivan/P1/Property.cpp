#include "Property.h"


void alekseev::Property::operator()(int a)
{
  update(a);
}


size_t alekseev::Property::operator()() const
{
  return value();
}


char * alekseev::Property::name()
{
  return my_name();
}




