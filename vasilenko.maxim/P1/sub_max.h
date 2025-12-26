#ifndef SUB_MAX_H
#define SUB_MAX_H

#include "iProperty.h"
#include "Int_array.h"

namespace vasilenko {
  struct Sub_max final: iProperty {
    Sub_max();

    void update(int a) override;
    size_t value() const override;
    const char * my_name() const override;
    bool cnted() const noexcept override;

  private:
    int max_value_;
    int second_max_value_;
    size_t count_;
  };
}

#endif
