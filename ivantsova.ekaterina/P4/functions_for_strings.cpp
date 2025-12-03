#include "functions_for_strings.hpp"
#include <cstdlib>
#include <cctype>
#include <cstddef>

char * ivantsova::readLine(std::istream & in, size_t & size)
{
  std::ios_base::fmtflags flags = in.flags();
  in >> std::noskipws;
  size_t c = 10;
  char * buffer = reinterpret_cast<char *>(malloc(c * sizeof(char)));
  if (buffer == nullptr)
  {
    in.flags(flags);
    return buffer;
  }
  size = 0;
  char current_char = '\0';
  while (in >> current_char && current_char != '\n')
  {
    if (size == c - 1)
    {
      size_t new_c = c * 2;
      char * new_buffer = reinterpret_cast<char *>(malloc(new_c * sizeof(char)));
      if (new_buffer == nullptr)
      {
        free(buffer);
        in.flags(flags);
        return new_buffer;
      }
      c = new_c;
      for (size_t i = 0; i < size; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      free(buffer);
      buffer = new_buffer;
    }
    buffer[size++] = current_char;
  }
  char * result = reinterpret_cast<char *>(malloc((size + 1) * sizeof(char)));
  if (result == nullptr)
  {
    free(buffer);
    in.flags(flags);
    return result;
  }
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = buffer[i];
  }
  result[size] = '\0';
  free(buffer);
  in.flags(flags);
  return result;
}

void ivantsova::interleaveStrings(const char * str1, const char * str2, size_t size1, char * result)
{
  size_t size2 = 0;
  while (str2[size2] != '\0')
  {
    ++size2;
  }
  size_t max_size = (size1 > size2) ? size1 : size2;
  size_t index = 0;
  for (size_t i = 0; i < max_size; ++i)
  {
    if (i < size1)
    {
      result[index++] = str1[i];
    }
    if (i < size2)
    {
      result[index++] = str2[i];
    }
  }
  result[index] = '\0';
}

void ivantsova::addDigits(const char * str1, const char * str2, size_t size1, char * result, size_t & result_size)
{
  size_t size2 = 0;
  while (str2[size2] != '\0')
  {
    ++size2;
  }
  for (size_t i = 0; i < size1; ++i)
  {
    result[i] = str1[i];
  }
  size_t index = size1;
  for (size_t i = 0; i < size2; ++i)
  {
    if (std::isdigit(static_cast<unsigned char>(str2[i])))
    {
      result[index++] = str2[i];
    }
  }
  result_size = index;
  result[index] = '\0';
}

void ivantsova::printString(std::ostream & out, const char * str, size_t size)
{
  out << str << "\n";
}
