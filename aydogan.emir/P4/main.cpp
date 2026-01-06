#include "string.hpp"
#include <iostream>
#include <cstdlib>
#include <cstddef>

int main()
{
  char* first = aydogan::readString(std::cin);
  if (!first)
  {
    std::cerr << "Input error\n";
    return 1;
  }

  const char* second = "g1h2k";

  size_t len1 = 0;
  while (first[len1] != '\0')
  {
    ++len1;
  }

  size_t len2 = 0;
  while (second[len2] != '\0')
  {
    ++len2;
  }

  char* buffer = reinterpret_cast< char* >(std::malloc(len1 + len2 + 1));
  if (!buffer)
  {
    std::free(first);
    std::cerr << "Memory allocation error\n";
    return 1;
  }

  aydogan::removeVowels(first, buffer);
  std::cout << buffer << '\n';

  aydogan::appendDigits(first, second, buffer);
  std::cout << buffer << '\n';

  std::free(buffer);
  std::free(first);

  return 0;
}
