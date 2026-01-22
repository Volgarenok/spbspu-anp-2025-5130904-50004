#include "strings.hpp"
#include <cctype>

namespace dolenko
{

size_t dif_lat(const char* arr)
{
  size_t count = 0;
  size_t ind = 0;
  char symb = '\0';
  const size_t alp = 26;
  bool info[alp] = {};

  for (size_t i = 0; arr[i] != '\0'; ++i)
  {
    symb = std::tolower(arr[i]);
    if (std::isalpha(symb))
    {
      ind = symb - 'a';
     
    }
  }

  return count;
}

} 