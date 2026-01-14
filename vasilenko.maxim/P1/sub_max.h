#ifndef SUB_MAX_H
#define SUB_MAX_H

#include <cstddef>

class SubMaxProcessor {
public:
  SubMaxProcessor();

  void Process(int value);
  bool CanCalculate() const;
  int GetResult() const;

private:
  int max1_;
  int max2_;
  size_t total_count_;
  bool initialized_;
};

#endif
