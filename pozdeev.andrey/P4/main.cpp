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
}
