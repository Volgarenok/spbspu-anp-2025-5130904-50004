#ifndef PTH_TRP_H
#define PTH_TRP_H
#include "iProperty.h"
#include "Int_array.h"

namespace alekseev {
  struct Pth_trp final: iProperty {
    Pth_trp();

    void update(int a) override;
    size_t value() const override;
    const char * name_impl() const override;
    bool cnted() const noexcept override;

    private:
      size_t k_;
      Int_array data_;
  };
}

#endif
