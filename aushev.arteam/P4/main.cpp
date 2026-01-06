#include "string_utils.hpp"
#include <iostream>
#include <new>

int main() {
  char* buf = aushev::read_line();
  if (!buf) {
    std::cerr << "Input error\n";
    return 1;
  }

  const char* second = "abc_ef";
  int result1 = aushev::has_sam(buf, second);
  std::printf("%d\n", result1);

  size_t len = 0;
  while (buf[len] != '\0') {
    ++len;
  }

  char* clean = nullptr;
  try {
    clean = new char[len + 1];
  } catch (const std::bad_alloc&) {
    delete[] buf;
    std::cerr << "Allocation error\n";
    return 1;
  }
  aushev::spc_rmv(clean, buf);
  std::puts(clean);

  delete[] buf;
  delete[] clean;
  return 0;
}
