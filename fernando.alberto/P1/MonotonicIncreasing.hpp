#ifndef MONOTONICINCREASING_HPP
#define MONOTONICINCREASING_HPP

#include <cstddef>

namespace alberto {

class MonotonicIncreasing {
public:
  MonotonicIncreasing();
  void operator()(int);
  std::size_t operator()() const;

private:
  std::size_t max_length_;
  std::size_t current_length_;
  int previous_value_;
  bool first_element_;
};

}

#endif
