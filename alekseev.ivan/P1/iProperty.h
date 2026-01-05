#ifndef IPROPERTY_H
#define IPROPERTY_H
#include <cstddef>
#include <iostream>

namespace alekseev {
  enum IDS {
    pth_trp_id,
    sum_dup_id
  };

  struct iProperty {
    virtual ~iProperty() = default;

    void operator()(int a);
    size_t operator()() const;
    const char * name() const;
    bool countered() const noexcept;
    std::ostream & print(std::ostream & out) const noexcept;

    private:
      virtual void update(int a) = 0;
      virtual size_t value() const = 0;
      virtual const char * name_impl() const = 0;
      virtual bool cnted() const noexcept = 0;
  };

  iProperty * make(IDS id);
}
#endif
