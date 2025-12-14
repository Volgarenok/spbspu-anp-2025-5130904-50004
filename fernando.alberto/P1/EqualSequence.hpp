#ifndef EQUALSEQUENCE_HPP
#define EQUALSEQUENCE_HPP

namespace alberto
{
  struct EqualSequence
  {
    EqualSequence();
    void operator()(int n);
    size_t operator()() const;
  private:
    size_t max_count_;
    size_t current_count_;
    int previous_value_;
    bool first_element_;
  };
}

#endif
