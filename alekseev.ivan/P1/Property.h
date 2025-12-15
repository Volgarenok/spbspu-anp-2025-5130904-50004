#ifndef PROPERTY_H
#define PROPERTY_H
#include <cstddef>

namespace alekseev {
  struct Property {
    void operator()(int a);
    size_t operator()() const;
    const char * name() const;

    virtual ~Property() = default;

    private:
      virtual void update(int a) = 0;
      virtual size_t value() const = 0;
      virtual const char * my_name() const = 0;
  };
}
#endif