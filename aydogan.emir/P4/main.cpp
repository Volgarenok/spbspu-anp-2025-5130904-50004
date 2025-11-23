#include "string.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
  char * first = aydogan::readString(std::cin);
  if (first == nullptr)
  {
    std::cerr << "Input error\n";
    return 1;
  }

  char * second = aydogan::readString(std::cin);
  if (second == nullptr)
  {
    std::free(first);
    std::cerr << "Input error\n";
    return 1;
  }

  std::size_t len1 = 0;
  while (first[len1] != '\0')
  {
    ++len1;
  }

  std::size_t len2 = 0;
  while (second[len2] != '\0')
  {
    ++len2;
  }

  char * no_vowels = static_cast<char *>(std::malloc(len1 + 1));
  if (no_vowels == nullptr)
  {
    std::free(first);
    std::free(second);
    std::cerr << "Memory allocation error\n";
    return 1;
  }

  aydogan::removeVowels(first, no_vowels);
  aydogan::writeString(no_vowels);

  char * with_digits = static_cast<char *>(std::malloc(len1 + len2 + 1));
  if (with_digits == nullptr)
  {
    std::free(first);
    std::free(second);
    std::free(no_vowels);
    std::cerr << "Memory allocation error\n";
    return 1;
  }

  aydogan::appendDigits(first, second, with_digits);
  aydogan::writeString(with_digits);

  std::free(first);
  std::free(second);
  std::free(no_vowels);
  std::free(with_digits);

  return 0;
}