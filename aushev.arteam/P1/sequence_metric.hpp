#ifndef AUSHEV_ARTeam_P1_SEQUENCE_METRIC_HPP
#define AUSHEV_ARTeam_P1_SEQUENCE_METRIC_HPP

#include <cstddef>

namespace aushev {

class sequence_metric {
public:
  virtual ~sequence_metric() = default;
  virtual void operator()(int value) = 0;
  virtual size_t operator()() const = 0;
  virtual const char* name() const = 0;
};

}

#endif
