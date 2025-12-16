#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <cstddef>

namespace aydogan {

std::istream& readMatrix(std::istream& input, int* arr, int count) {
  for (int i = 0; i < count; ++i) {
    if (!(input >> arr[i])) {
      return input;
    }
  }
  return input;
}

int numColLsr(int r, int c, const int* a) {
  if (r <= 0 || c <= 0) return 0;

  size_t bestCol = 1;
  size_t bestLen = 0;

  for (int col = 0; col < c; ++col) {
    size_t cur = 1;
    size_t maxHere = 1;

    for (int row = 1; row < r; ++row) {
      int prev = a[(row - 1) * c + col];
      int now  = a[row * c + col];

      if (now == prev) {
        ++cur;
        if (cur > maxHere) maxHere = cur;
      } else {
        cur = 1;
      }
    }

    if (maxHere > bestLen) {
      bestLen = maxHere;
      bestCol = static_cast< size_t >(col + 1);
    }
  }

  return static_cast< int >(bestCol);
}

long long minSumMDG(int r, int c, const int* a) {
  if (r <= 0 || c <= 0) return 0;

  long long best = 0;
  bool first = true;

  for (int s = 0; s <= (r - 1) + (c - 1); ++s) {
    long long sum = 0;
    bool has = false;

    for (int i = 0; i < r; ++i) {
      int j = s - i;
      if (j >= 0 && j < c) {
        sum += a[i * c + j];
        has = true;
      }
    }

    if (has) {
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

static long long solveTask(int r, int c, const int* a, int task) {
  if (task == 1) return numColLsr(r, c, a);
  if (task == 2) return static_cast< int >(minSumMDG(r, c, a));
  throw std::logic_error("Task out of range");
}

void work_static(int r, int c, std::istream& in, std::ostream& out, int task) {
  constexpr int MAX = 10000;

  size_t count = static_cast< size_t >(r) * static_cast< size_t >(c);
  if (count > static_cast< size_t >(MAX)) {
    throw std::runtime_error("Too big for static array");
  }

  int a[MAX];

  readMatrix(in, a, static_cast< int >(count));
  if (!in) {
    throw std::logic_error("Input error");
  }

  out << solveTask(r, c, a, task) << "\n";
}

void work_dynamic(int r, int c, std::istream& in, std::ostream& out, int task) {
  size_t count = static_cast< size_t >(r) * static_cast< size_t >(c);
  int* a = new int[count];

  readMatrix(in, a, static_cast< int >(count));
  if (!in) {
    delete[] a;
    throw std::logic_error("Input error");
  }

  out << solveTask(r, c, a, task) << "\n";
  delete[] a;
}

}
