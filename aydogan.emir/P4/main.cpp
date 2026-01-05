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

  char* second = aydogan::readString(std::cin);
  if (!second)
  {
    second = reinterpret_cast< char* >(std::malloc(1));
    if (!second)
    {
      std::free(first);
      std::cerr << "Memory allocation error\n";
      return 1;
    }
    second[0] = '\0';
  }

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

  char* no_vowels = reinterpret_cast< char* >(std::malloc(len1 + 1));
  if (!no_vowels)
  {
    std::free(first);
    std::free(second);
    std::cerr << "Memory allocation error\n";
    return 1;
  }

  aydogan::removeVowels(first, no_vowels);
  std::cout << no_vowels << '\n';

  char* with_digits = reinterpret_cast< char* >(std::malloc(len1 + len2 + 1));
  if (!with_digits)
  {
    std::free(first);
    std::free(second);
    std::free(no_vowels);
    std::cerr << "Memory allocation error\n";
    return 1;
  }

  aydogan::appendDigits(first, second, with_digits);
  std::cout << with_digits << '\n';

  std::free(first);
  std::free(second);
  std::free(no_vowels);
  std::free(with_digits);

  return 0;
}
