#ifndef STRING_HPP
#define STRING_HPP

#include <fstream>

namespace bychkovskaya {
  char* getline(std::istream& in, size_t& size);
  void latrmv(const char* str, char* result);
  void excsnd(const char* str1, const char* str2, char* result);
}

#endif
