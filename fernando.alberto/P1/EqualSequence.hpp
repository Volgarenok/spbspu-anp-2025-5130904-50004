#ifndef EQUALSEQUENCE_HPP
#define EQUALSEQUENCE_HPP

#include <cstddef>

namespace alberto {

class EqualSequence {
public:
  EqualSequence();
  void operator()(int);
  size_t operator()() const;

private:
  size_t max_count_;
  size_t current_count_;
};

}

#endif
