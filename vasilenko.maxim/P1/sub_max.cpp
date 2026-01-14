#include "sub_max.h"

SubMaxProcessor::SubMaxProcessor()
  : max1_(0), max2_(0), total_count_(0), initialized_(false) {
}

void SubMaxProcessor::Process(int value) {
  if (total_count_ == 0) {
    max1_ = value;
    total_count_ = 1;
  } else if (total_count_ == 1) {
    if (value > max1_) {
      max2_ = max1_;
      max1_ = value;
    } else {
      max2_ = value;
    }
    total_count_ = 2;
    initialized_ = true;
  } else {
    if (value > max1_) {
      max2_ = max1_;
      max1_ = value;
    } else if (value > max2_) {
      max2_ = value;
    }
  }
}

bool SubMaxProcessor::CanCalculate() const {
  return initialized_;
}

int SubMaxProcessor::GetResult() const {
  return max2_;
}
