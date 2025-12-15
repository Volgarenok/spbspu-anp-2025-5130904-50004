#include "Property.h"


void alekseev::Property::operator()(int a)
{
  update(a);
}


size_t alekseev::Property::operator()() const
{
  return value();
}


const char * alekseev::Property::name() const
{
  return my_name();
}




