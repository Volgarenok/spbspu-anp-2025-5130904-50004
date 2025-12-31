#ifndef STRING_HPP
#define STRING_HPP
#include <cstddef>
#include <iosfwd>

namespace aydogan
{
  char * readString(std::istream & in);
  char * removeVowels(const char * src, char * dest) noexcept;
  char * appendDigits(const char * first, const char * second, char * dest) noexcept;
}

#endif