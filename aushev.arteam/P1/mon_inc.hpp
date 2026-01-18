#ifndef AUSHEV_ARTeam_P1_MON_INC_HPP
#define AUSHEV_ARTeam_P1_MON_INC_HPP

#include "sequence_metric.hpp"

namespace aushev {

class mon_inc : public sequence_metric {
public:
  mon_inc();
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
