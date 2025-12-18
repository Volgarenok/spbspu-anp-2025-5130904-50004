#ifndef RTH_TRP_HPP
#define RTH_TRP_HPP

#include "base.hpp"
#include <cstddef>

namespace zinovev {

struct RTH_TRP : Base
{
  RTH_TRP();
  void operator()() const override;
  void operator()(int const x) override;
  bool few_numbers();

 private:
  int a_ = 0, b_ = 0, c_ = 0;
  size_t pth_trp_;
};
}

#endif
