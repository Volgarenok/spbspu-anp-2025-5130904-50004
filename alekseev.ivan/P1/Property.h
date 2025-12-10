#ifndef PROPERTY_H
#define PROPERTY_H
#include <cstddef>

namespace alekseev {
  struct Property {
    void operator()(int a);
    size_t operator()() const;
    char * name();

    virtual ~Property() = default;

    private:
      size_t k;
      int * data;

      virtual void update(int a) = 0;
      virtual size_t value() const = 0;
      virtual char * my_name() = 0;
  };
}
#endif