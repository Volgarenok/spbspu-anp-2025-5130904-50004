#include "lab.hpp"
#include <iostream>
#include <stdexcept>

namespace aydogan {

std::istream& readMatrix(std::istream& input, int* arr, int count) {
  for (int i = 0; i < count; ++i) {
    if (!(input >> arr[i])) {
      std::cerr << "Incorrect matrix input\n";
      return input;
    }
  }
  return input;
}

int numColLsr(int r, int c, const int* a) {
  if (r <= 0 || c <= 0) {
    return 0;
  }

  std::size_t bestCol = 1;
  std::size_t bestLen = 0;

  for (std::size_t col = 0; col < static_cast<std::size_t>(c); ++col) {
    std::size_t cur = 1;
    std::size_t maxHere = 1;

    for (std::size_t row = 1; row < static_cast<std::size_t>(r); ++row) {
      int prev = a[(static_cast<int>(row) - 1) * c + static_cast<int>(col)];
      int now  = a[static_cast<int>(row) * c + static_cast<int>(col)];

      if (now == prev) {
        ++cur;
        if (cur > maxHere) {
          maxHere = cur;
        }
      } else {
        cur = 1;
      }
    }

    if (maxHere > bestLen) {
      bestLen = maxHere;
      bestCol = col + 1;
    }
  }

  return static_cast<int>(bestCol);
}

long long minSumMDG(int r, int c, const int* a) {
  if (r <= 0 || c <= 0) {
    return 0;
  }

  long long best = 0;
  bool first = true;

  for (int s = 0; s <= (r - 1) + (c - 1); ++s) {
    long long sum = 0;
    bool hasElement = false;

    for (int i = 0; i < r; ++i) {
      int j = s - i;
      if (j >= 0 && j < c) {
        sum += a[i * c + j];
        hasElement = true;
      }
    }

    if (hasElement) {
      if (first) {
        best = sum;
        first = false;
      } else if (sum < best) {
        best = sum;
      }
    }
  }

  return best;
}

int processMatrix(int r, int c, const int* a, int variant) {
  if (variant == 1) {
    return numColLsr(r, c, a);
  }

  long long value = minSumMDG(r, c, a);
  return static_cast<int>(value);
}

void work_static(int r, int c, std::istream& in, std::ostream& out, int variant) {
  constexpr int MAX = 10000;
  if (r * c > MAX) {
    throw std::runtime_error("Too big for static array");
  }

  int a[MAX];

  if (!readMatrix(in, a, r * c)) {
    throw std::logic_error("Input error");
  }

  int result = processMatrix(r, c, a, variant);
  out << result << "\n";
}

void work_dynamic(int r, int c, std::istream& in, std::ostream& out, int variant) {
  int* a = new int[r * c];

  if (!readMatrix(in, a, r * c)) {
    delete[] a;
    throw std::logic_error("Input error");
  }

  int result = processMatrix(r, c, a, variant);
  out << result << "\n";

  delete[] a;
}

}