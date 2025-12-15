#ifndef COUNTER_H
#define COUNTER_H
#include "Property.h"


namespace alekseev {
  struct Counter: Property {
    explicit Counter();

    void update(int a) override;
    size_t value() const override;
    const char * my_name() const override;

    private:
      size_t k;
  };
}


#endif
