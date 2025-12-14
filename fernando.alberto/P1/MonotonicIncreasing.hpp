#ifndef MONOTONICINCREASING_HPP
#define MONOTONICINCREASING_HPP

namespace alberto
{
  struct MonotonicIncreasing
  {
    MonotonicIncreasing();
    void operator()(int n);
    size_t operator()() const;
  private:
    size_t max_length_;
    size_t current_length_;
    int previous_value_;
    bool first_element_;
  };
}

#endif
