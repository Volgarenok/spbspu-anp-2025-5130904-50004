#include "string_utils.hpp"
#include <cstdlib>
#include <cctype>
#include <iostream>

namespace {
  constexpr size_t kResizeFactor = 2;
}

char* pozdeev::increaseCapacity(char* buffer, size_t& currentCapacity)
{
  size_t newCapacity = currentCapacity * kResizeFactor;
  char* newBuffer = reinterpret_cast< char* >(malloc(newCapacity * sizeof(char)));

  if (newBuffer == nullptr) {
    return nullptr;
  }

  for (size_t i = 0; i < currentCapacity; ++i) {
    newBuffer[i] = buffer[i];
  }

  free(buffer);
  currentCapacity = newCapacity;
  return newBuffer;
}

char* pozdeev::readString(std::istream& in, size_t& size, char delimiter, size_t initialCapacity)
{
  size_t currentCapacity = initialCapacity;
  size_t currentSize = 0;
  char* buffer = reinterpret_cast< char* >(malloc(currentCapacity * sizeof(char)));

  if (buffer == nullptr) {
    size = 0;
    return nullptr;
  }

  std::ios_base::fmtflags originalFlags = in.flags();
  in >> std::noskipws;

  char inputChar = 0;

  while ((in >> inputChar) && inputChar != delimiter) {
    if (currentSize + 1 >= currentCapacity) {
      char* newBuffer = pozdeev::increaseCapacity(buffer, currentCapacity);

      if (newBuffer == nullptr) {
        free(buffer);
        size = 0;
        in.flags(originalFlags);
        return nullptr;
      }

      buffer = newBuffer;
    }

    buffer[currentSize] = inputChar;
    ++currentSize;
  }

  in.flags(originalFlags);

  if (currentSize == 0 && in.fail() && !in.eof()) {
    free(buffer);
    size = 0;
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

  while (source[readIndex] != '\0' && std::isspace(source[readIndex])) {
    ++readIndex;
  }

  while (source[readIndex] != '\0') {
    if (!std::isspace(source[readIndex])) {
      destination[writeIndex] = source[readIndex];
      ++writeIndex;
    } else if (writeIndex > 0 && destination[writeIndex - 1] != ' ') {
      destination[writeIndex] = ' ';
      ++writeIndex;
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
