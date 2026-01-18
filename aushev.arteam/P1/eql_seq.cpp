#include "eql_seq.hpp"

namespace aushev {

eql_seq::eql_seq()
  : prev_(0)
  , current_run_(1)
  , max_run_(1)
  , first_(true) {}

void eql_seq::operator()(int value) {
  if (first_) {
    prev_ = value;
    first_ = false;
    return;
  }

  if (value == prev_) {
    ++current_run_;
  } else {
    if (current_run_ > max_run_) {
      max_run_ = current_run_;
    }
    current_run_ = 1;
  }
  prev_ = value;
}

size_t eql_seq::operator()() const {
  if (current_run_ > max_run_) {
    return current_run_;
  }
  return max_run_;
}

const char* eql_seq::name() const {
  return "eql_seq";
}

}
