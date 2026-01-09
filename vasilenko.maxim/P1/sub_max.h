#ifndef SUB_MAX_H
#define SUB_MAX_H

#include "iProperty.h"
#include "Int_array.h"
#include <limits>

namespace vasilenko {
  struct Sub_max final: iProperty {
    Sub_max();

    void operator()(int a) override;
    size_t value() const override;
    const char * my_name() const override;
    bool cnted() const noexcept override;

  private:
    int max_value_;
    int second_max_value_;
    bool second_found_;
    Int_array data_;
  };
}

#endif
