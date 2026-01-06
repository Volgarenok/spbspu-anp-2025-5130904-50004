#ifndef SUM_DUP_H
#define SUM_DUP_H
#include "iProperty.h"
#include "Int_array.h"

namespace alekseev {
  struct Sum_dup final: iProperty {
    Sum_dup();

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
