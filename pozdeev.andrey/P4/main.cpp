#include "string_utils.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

namespace {
  constexpr size_t initialBufferSize = 16;
  constexpr size_t resizeFactor = 2;
}

int main()
{
  try {
    size_t currentCapacity = initialBufferSize;
    size_t currentSize = 0;

    char * inputString = static_cast <char *> (std::malloc(currentCapacity * sizeof(char)));
    if (inputString == nullptr) {
      throw std::bad_alloc();
    }

    std::ios_base::fmtflags originalFlags = std::cin.flags();
    std::cin >> std::noskipws;

    char inputChar = 0;

    while (std::cin >> inputChar) {
      if (currentSize + 1 >= currentCapacity) {
        size_t newCapacity = currentCapacity * resizeFactor;
        char * newBuffer = static_cast <char *> (std::malloc(newCapacity * sizeof(char)));

        if (newBuffer == nullptr) {
          std::free(inputString);
          std::cin.flags(originalFlags);
          throw std::bad_alloc();
        }

        for (size_t i = 0; i < currentSize; ++i) {
          newBuffer[i] = inputString[i];
        }

        std::free(inputString);
        inputString = newBuffer;
        currentCapacity = newCapacity;
      }

      inputString[currentSize] = inputChar;
      currentSize = currentSize + 1;
    }

    std::cin.flags(originalFlags);

    if (!pozdeev::checkStream(std::cin)) {
      std::free(inputString);
      throw std::runtime_error("Input stream error");
    }

    inputString[currentSize] = '\0';

    char * spaceRemovedResult = static_cast <char *> (std::malloc((currentSize + 1) * sizeof(char)));
    char * latinRemovedResult = static_cast <char *> (std::malloc((currentSize + 1) * sizeof(char)));

    if (spaceRemovedResult == nullptr) {
      std::free(inputString);
      if (latinRemovedResult != nullptr) {
        std::free(latinRemovedResult);
      }
      throw std::bad_alloc();
    }

    if (latinRemovedResult == nullptr) {
      std::free(inputString);
      std::free(spaceRemovedResult);
      throw std::bad_alloc();
    }
  }
}
