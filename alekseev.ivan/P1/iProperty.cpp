#include "iProperty.h"

#include "Pth_trp.h"
#include "Sum_dup.h"

void alekseev::iProperty::operator()(int a)
{
  update(a);
}

size_t alekseev::iProperty::operator()() const
{
  return value();
}

const char * alekseev::iProperty::name() const
{
  return name_impl();
}

bool alekseev::iProperty::countered() const noexcept
{
  return cnted();
}

std::ostream & alekseev::iProperty::print(std::ostream & out) const noexcept
{
  if (!countered()) {
    out << "Cannot counter " << name() << "\n";
  } else {
    out << name() << ": " << (*this)() << "\n";
  }
  return out;
}

alekseev::iProperty * alekseev::make(IDS id)
{
  switch (id) {
    case pth_trp_id: return new Pth_trp();
    case sum_dup_id: return new Sum_dup();
    default: throw std::invalid_argument("Unknown id");
  }
}
