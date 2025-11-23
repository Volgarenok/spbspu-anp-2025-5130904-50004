#ifndef STRING_HPP
#define STRING_HPP
#include <cstddef>
#include <iosfwd>

namespace aydogan
{
  char * readString(std::istream & in);
  void removeVowels(const char * src, char * dest) noexcept;
  void appendDigits(const char * first, const char * second, char * dest) noexcept;
  void writeString(const char * str);
}

#endif