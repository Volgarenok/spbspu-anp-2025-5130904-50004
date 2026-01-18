#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cstddef>

namespace ahrameev
{
  int count_diff_latin_letters(const char* str);
  char* to_lower_latin(char* dest, size_t dest_size, const char* src);
}

#endif
