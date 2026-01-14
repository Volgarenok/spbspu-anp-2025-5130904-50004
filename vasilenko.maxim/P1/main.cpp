#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include "aft_max.h"
#include "sub_max.h"

enum ReadStatus {
  kReadSuccess,
  kReadZero,
  kReadError
};

ReadStatus TryReadInt(int& result) {
  char buffer[128];
  if (!(std::cin >> buffer)) {
    return kReadError;
  }

  char* end_ptr = nullptr;
  long val = std::strtol(buffer, &end_ptr, 10);

  if (end_ptr == buffer || *end_ptr != '\0') {
    return kReadError;
  }

  if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
    return kReadError;
  }

  if (val == 0) {
    return kReadZero;
  }

  result = static_cast<int>(val);
  return kReadSuccess;
}

int main() {
  AftMaxProcessor aft_proc;
  SubMaxProcessor sub_proc;
  bool has_calc_error = false;

  while (true) {
    int current_val = 0;
    ReadStatus status = TryReadInt(current_val);

    if (status == kReadError) {
      std::cerr << "Error: Invalid input sequence.\n";
      return 1;
    }

    if (status == kReadZero) {
      break;
    }

    aft_proc.Process(current_val);
    sub_proc.Process(current_val);
  }

  if (aft_proc.CanCalculate()) {
    std::cout << aft_proc.GetResult() << "\n";
  } else {
    has_calc_error = true;
  }

  if (sub_proc.CanCalculate()) {
    std::cout << sub_proc.GetResult() << "\n";
  } else {
    has_calc_error = true;
  }

  if (has_calc_error) {
    std::cerr << "Cannot calculate at least one property\n";
    return 2;
  }

  return 0;
}
