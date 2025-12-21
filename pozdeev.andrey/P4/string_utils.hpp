#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <cstddef>
#include <iostream>

namespace pozdeev {
  char* readString(std::istream& in, size_t& size, char delimiter = '\n', size_t initialCapacity = 16);
  char* removeExtraSpaces(char* destination, const char* source);
  char* removeLatin(char* destination, const char* source);
  char* increaseCapacity(char* buffer, size_t& currentCapacity);
}

#endif
