#include "aft_max.h"

AftMaxProcessor::AftMaxProcessor()
  : max_value_(0), count_after_(0), total_count_(0), has_max_(false) {
}

void AftMaxProcessor::Process(int value) {
  if (!has_max_ || value > max_value_) {
    if (!has_max_) {
      has_max_ = true;
    }
    max_value_ = value;
  }

  if (has_max_) {
    total_count_++;
  }
}

bool AftMaxProcessor::CanCalculate() const {
  return has_max_ && total_count_ > 1;
}

size_t AftMaxProcessor::GetResult() const {
  return total_count_ - 1;
}
