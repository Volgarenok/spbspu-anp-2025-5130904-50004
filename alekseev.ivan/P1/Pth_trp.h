#ifndef PTH_TRP_H
#define PTH_TRP_H
#include "Property.h"


namespace alekseev {
  struct Pth_trp: Property {
    explicit Pth_trp();

    void update(int a);
    size_t value() const;
    char * my_name();

    private:
      size_t k;
      int * data;
  };
}

#endif
