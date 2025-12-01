#include "velizade.hpp"
#include <cstdlib>

char* read_string(std::istream& input, size_t size)
{
  char* str = static_cast<char*>(malloc(size + 1));
  if (!str)
  {
    return nullptr;
  }
  size_t i = 0;
  inr ch = input.get();
  while (i < size && ch != EOF && ch != '\n')
  {
    str[i++] = static_cast<char>(ch);
    ch = input.get();
  }
  str[i] = '\0';
  return str;
}

void print_string(std::ostream& output, const char* str)
{
  if (str)
  {
    output << str;
  }
}
