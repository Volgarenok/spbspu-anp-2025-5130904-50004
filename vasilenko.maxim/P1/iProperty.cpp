#include "iProperty.h"
#include "aft_max.h"
#include "sub_max.h"

void vasilenko::iProperty::operator()(int a)
{
  update(a);
}

size_t vasilenko::iProperty::operator()() const
{
  return value();
}

const char * vasilenko::iProperty::name() const
{
  return my_name();
}

bool vasilenko::iProperty::countered() const noexcept
{
  return cnted();
}

std::ostream & vasilenko::iProperty::print(std::ostream & out) const noexcept
{
  if (!countered()) {
    return out;
  }
  out << (*this)() << "\n";
  return out;
}

vasilenko::iProperty * vasilenko::make(IDS id)
{
  switch (id) {
    case aft_max_id: return new vasilenko::Aft_max();
    case sub_max_id: return new vasilenko::Sub_max();
    default: throw std::invalid_argument("Unknown id");
  }
}
