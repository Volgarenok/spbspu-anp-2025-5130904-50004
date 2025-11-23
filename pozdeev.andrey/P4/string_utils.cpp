#include "string_utils.hpp"
#include <cctype>
#include <cstddef>

char * pozdeev::removeExtraSpaces(char * destination, const char * source)
{
  size_t readIndex = 0;
  size_t writeIndex = 0;
  int isSpaceFound = 0;

  while (source[readIndex] != '\0') {
    if (std::isspace(source[readIndex]) != 0) {
      if (writeIndex > 0) {
        if (isSpaceFound == 0) {
          destination[writeIndex] = ' ';
          writeIndex = writeIndex + 1;
          isSpaceFound = 1;
        }
      }
    } else {
      destination[writeIndex] = source[readIndex];
      writeIndex = writeIndex + 1;
      isSpaceFound = 0;
    }
    readIndex = readIndex + 1;
  }

  if (writeIndex > 0) {
    if (std::isspace(destination[writeIndex - 1]) != 0) {
      writeIndex = writeIndex - 1;
    }
  }

  destination[writeIndex] = '\0';
  return destination;
}

char * pozdeev::removeLatin(char * destination, const char * source)
{
  size_t readIndex = 0;
  size_t writeIndex = 0;

  while (source[readIndex] != '\0') {
    if (std::isalpha(source[readIndex]) == 0) {
      destination[writeIndex] = source[readIndex];
      writeIndex = writeIndex + 1;
    }
    readIndex = readIndex + 1;
  }

  destination[writeIndex] = '\0';
  return destination;
}

bool pozdeev::checkStream(std::istream & stream)
{
  if (!stream.fail()) {
    return true;
  }
  if (stream.eof()) {
    return true;
  }
  return false;
}
