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

  char* inputString = pozdeev::readString(std::cin, inputSize, '\n', kInitialBufferSize);

  if (inputString == nullptr) {
    std::cerr << "Error: Failed to read input or allocate memory\n";
    return 1;
  }

  if (inputSize == 0) {
    std::free(inputString);
    std::cerr << "Error: Empty input\n";
    return 1;
  }

  if (!std::cin.eof() && std::cin.fail()) {
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

  std::cout << pozdeev::removeExtraSpaces(spaceRemovedResult, inputString) << '\n';
  std::cout << pozdeev::removeLatin(latinRemovedResult, inputString) << '\n';

  std::free(inputString);
  std::free(spaceRemovedResult);
  std::free(latinRemovedResult);

  return 0;
}
