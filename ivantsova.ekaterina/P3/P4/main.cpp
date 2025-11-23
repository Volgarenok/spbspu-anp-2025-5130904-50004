#include <iostream>

namespace ivantsova
{
  char * readLine(std::istream & in, size_t & size);
  char * interleaveStrings(const char * str1, const char * str2, size_t size1, size_t & result_size);
  char * addDigits(const char * str1, const char * str2, size_t size1, size_t & result_size);
  void printString(std::ostream & out, const char * str, size_t size);
}

char * ivantsova::readLine(std::istream & in, size_t & size)
{
  in >> std::noskipws;
  size_t c = 10;
  char * buffer = static_cast<char *>(malloc(c * sizeof(char)));
  if (buffer == nullptr)
  {
    return buffer;
  }
  size = 0;
  char current_char = '\0';
  while (in >> current_char && current_char != '\n')
  {
    if (size == c - 1)
    {
      c *= 2;
      char * new_buffer = static_cast<char *>(malloc(c * sizeof(char)));
      if (new_buffer == nullptr)
      {
        free(buffer);
        return new_buffer;
      }
      for (size_t i = 0; i < size; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      free(buffer);
      buffer = new_buffer;
    }
    buffer[size++] = current_char;
  }
  char * result = static_cast<char *>(malloc((size + 1) * sizeof(char)));
  if (result == nullptr)
  {
    free(buffer);
    return result;
  }
  for (size_t i = 0; i < size; ++i)
  {
    result[i] = buffer[i];
  }
  result[size] = '\0';
  free(buffer);
  in >> std::skipws;
  return result;
}

char * ivantsova::interleaveStrings(const char * str1, const char * str2, size_t size1, size_t & result_size)
{
}

char * ivantsova::addDigits(const char * str1, const char * str2, size_t size1, size_t & result_size)
{
}

void ivantsova::printString(std::ostream & out, const char * str, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    out << str[i];
  }
  out << "\n";
}

int main()
{
}
