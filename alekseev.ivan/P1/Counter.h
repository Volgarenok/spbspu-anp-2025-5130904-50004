#ifndef COUNTER_H
#define COUNTER_H
#include "Property.h"


namespace alekseev {
  struct Counter: Property {
    explicit Counter();
    ~Counter() override = default;

    void update(int) override;
    size_t value() const override;
    const char * my_name() const override;
    bool cnted() const override;

    private:
      size_t k;
  };
}


#endif
