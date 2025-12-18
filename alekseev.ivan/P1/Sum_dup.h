#ifndef SUM_DUP_H
#define SUM_DUP_H
#include "Property.h"

namespace alekseev {
  struct Sum_dup: iProperty {
    Sum_dup();
    ~Sum_dup() override;

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
