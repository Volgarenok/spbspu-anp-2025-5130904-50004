#include "mon_inc.hpp"

namespace aushev {

mon_inc::mon_inc()
  : prev_(0)
  , current_run_(1)
  , max_run_(1)
  , first_(true) {}

void mon_inc::operator()(int value) {
  if (first_) {
    prev_ = value;
    first_ = false;
    return;
  }

  if (value >= prev_) {
    ++current_run_;
  } else {
    if (current_run_ > max_run_) {
      max_run_ = current_run_;
    }
    current_run_ = 1;
  }
  prev_ = value;
}

size_t mon_inc::operator()() const {
  if (current_run_ > max_run_) {
    return current_run_;
  }
  return max_run_;
}

const char* mon_inc::name() const {
  return "mon_inc";
}

}
