#include "string_utils.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <new>

namespace {
  constexpr size_t kInitialBufferSize = 16;
}

int main()
{
  size_t inputSize = 0;

  char* inputString = pozdeev::readString(std::cin, inputSize, kInitialBufferSize);

  if (inputString == nullptr) {
    std::cerr << "Error: Failed to read input or allocate memory\n";
    return 1;
  }

  if (inputSize == 0) {
    std::free(inputString);
    std::cerr << "Error: Empty input\n";
    return 1;
  }

  if (!pozdeev::checkStream(std::cin)) {
    std::free(inputString);
    std::cerr << "Error: Input stream error\n";
    return 1;
  }

  const size_t result = inputSize + 1;

  char* spaceRemovedResult = reinterpret_cast < char* > (std::malloc(result * sizeof(char)));
  char* latinRemovedResult = reinterpret_cast < char* > (std::malloc(result * sizeof(char)));

  if (spaceRemovedResult == nullptr || latinRemovedResult == nullptr) {
    std::free(inputString);
    std::free(spaceRemovedResult);
    std::free(latinRemovedResult);
    std::cerr << "Error: Memory allocation failed\n";
    return 1;
  }

  pozdeev::removeExtraSpaces(spaceRemovedResult, inputString);
  std::cout << spaceRemovedResult << '\n';

  pozdeev::removeLatin(latinRemovedResult, inputString);
  std::cout << latinRemovedResult << '\n';

  std::free(inputString);
  std::free(spaceRemovedResult);
  std::free(latinRemovedResult);

  return 0;
}
