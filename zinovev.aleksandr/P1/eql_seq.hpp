#ifndef EQL_SEQ_HPP
#define EQL_SEQ_HPP

#include "base.hpp"
#include <cstddef>

namespace zinovev {

struct EQL_SEQ : Base
{
  EQL_SEQ();
  void operator()() const override;
  void operator()(int const x) override;

 private:
  int max_;
  size_t eql_seq_;
};
}

#endif
