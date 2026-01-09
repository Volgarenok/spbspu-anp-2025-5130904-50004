#ifndef AFT_MAX_H
#define AFT_MAX_H

#include "iProperty.h"
#include "Int_array.h"

namespace vasilenko {
  struct Aft_max final: iProperty {
    Aft_max();

    void operator()(int a) override;
    size_t value() const override;
    const char * my_name() const override;
    bool cnted() const noexcept override;

  private:
    int max_value_;
    size_t count_after_max_;
    bool max_found_;
    Int_array data_;
  };
}

#endif
