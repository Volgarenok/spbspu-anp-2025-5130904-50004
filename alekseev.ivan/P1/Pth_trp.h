#ifndef PTH_TRP_H
#define PTH_TRP_H
#include "Property.h"

namespace alekseev {
  struct Pth_trp: iProperty {
    Pth_trp();
    ~Pth_trp() override;

    void update(int a) override;
    size_t value() const override;
    const char * my_name() const override;
    bool cnted() const noexcept override;

    private:
      size_t k;
      int * data;
  };
}

#endif
