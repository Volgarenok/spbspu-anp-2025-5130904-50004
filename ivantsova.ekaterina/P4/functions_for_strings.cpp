#include "functions_for_strings.hpp"
#include <cstdlib>
#include <cctype>
#include <cstddef>

char * ivantsova::readLine(std::istream & in, size_t & size)
{
  std::ios_base::fmtflags flags = in.flags();
  in >> std::noskipws;
  size_t c = 10;
  char * buffer = reinterpret_cast< char * >(malloc(c * sizeof(char)));
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
      char * new_buffer = reinterpret_cast< char * >(malloc(new_c * sizeof(char)));
      if (new_buffer == nullptr)
      {
        free(buffer);
        in.flags(flags);
        size = 0;
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
  char * result = reinterpret_cast< char * >(malloc((size + 1) * sizeof(char)));
  if (result == nullptr)
  {
    free(buffer);
    in.flags(flags);
    size = 0;
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

const char * ivantsova::interleaveStrings(const char * str1, const char * str2, char * result)
{
  size_t i = 0;
  size_t j = 0;
  size_t index = 0;
  while (str1[i] != '\0' || str2[j] != '\0')
  {
    if (str1[i] != '\0')
    {
      result[index++] = str1[i++];
    }
    if (str2[j] != '\0')
    {
      result[index++] = str2[j++];
    }
  }
  result[index] = '\0';
  return result;
}

const char * ivantsova::addDigits(const char * str1, const char * str2, char * result, size_t * result_size)
{
  size_t i = 0;
  size_t j = 0;
  size_t index = 0;
  while (str1[i] != '\0')
  {
    result[index++] = str1[i++];
  }
  while (str2[j] != '\0')
  {
    if (std::isdigit(static_cast< unsigned char >(str2[j])))
    {
      result[index++] = str2[j];
    }
    j++;
  }
  *result_size = index;
  result[index] = '\0';
  return result;
}
