#ifndef AUSHEV_ARTeam_P1_EQL_SEQ_HPP
#define AUSHEV_ARTeam_P1_EQL_SEQ_HPP

#include "sequence_metric.hpp"

namespace aushev {

class eql_seq : public sequence_metric {
public:
  eql_seq();
  void operator()(int value) override;
  size_t operator()() const override;
  const char* name() const override;

private:
  int prev_;
  size_t current_run_;
  size_t max_run_;
  bool first_;
};

}

#endif
