#include "string_utils.hpp"
#include <cstdlib>
#include <cctype>
#include <iostream>

namespace {
  constexpr size_t kResizeFactor = 2;
}

char* pozdeev::readString(std::istream& in, size_t& size, size_t initialCapacity)
{
  size_t currentCapacity = initialCapacity;
  size_t currentSize = 0;
  char* buffer = reinterpret_cast < char* > (std::malloc(currentCapacity * sizeof(char)));
  if (buffer == nullptr) {
    return nullptr;
  }

  std::ios_base::fmtflags originalFlags = in.flags();
  in >> std::noskipws;

  char inputChar = 0;

  while (in.get(inputChar) && inputChar != '\n') {
    if (currentSize + 1 >= currentCapacity) {
      size_t newCapacity = currentCapacity * kResizeFactor;
      char* newBuffer = reinterpret_cast < char* > (std::malloc(newCapacity * sizeof(char)));

      if (newBuffer == nullptr) {
        std::free(buffer);
        in.flags(originalFlags);
        return nullptr;
      }

      for (size_t i = 0; i < currentSize; ++i) {
        newBuffer[i] = buffer[i];
      }

      std::free(buffer);
      buffer = newBuffer;
      currentCapacity = newCapacity;
    }

    buffer[currentSize] = inputChar;
    ++currentSize;
  }

  in.flags(originalFlags);

  if (currentSize == 0 && in.fail() && !in.eof()) {
    std::free(buffer);
    return nullptr;
  }

  buffer[currentSize] = '\0';
  size = currentSize;
  return buffer;
}

char* pozdeev::removeExtraSpaces(char* destination, const char* source)
{
  size_t readIndex = 0;
  size_t writeIndex = 0;
  bool isSpaceFound = false;

  while (source[readIndex] != '\0' && std::isspace(source[readIndex])) {
    ++readIndex;
  }

  while (source[readIndex] != '\0') {
    if (std::isspace(source[readIndex])) {
      if (writeIndex > 0 && !isSpaceFound) {
        destination[writeIndex] = ' ';
        ++writeIndex;
        isSpaceFound = true;
      }
    } else {
      destination[writeIndex] = source[readIndex];
      ++writeIndex;
      isSpaceFound = false;
    }
    ++readIndex;
  }

  if (writeIndex > 0 && std::isspace(destination[writeIndex - 1])) {
    --writeIndex;
  }

  destination[writeIndex] = '\0';
  return destination;
}

char* pozdeev::removeLatin(char* destination, const char* source)
{
  size_t readIndex = 0;
  size_t writeIndex = 0;

  while (source[readIndex] != '\0') {
    if (!std::isalpha(source[readIndex])) {
      destination[writeIndex] = source[readIndex];
      ++writeIndex;
    }
    ++readIndex;
  }

  destination[writeIndex] = '\0';
  return destination;
}
