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
  size_t size2 = 0;
  while (str2[size2] != '\0')
  {
    ++size2;
  }
  size_t max_size = (size1 > size2) ? size1 : size2;
  result_size = size1 + size2;
  char * result = static_cast<char *>(malloc((result_size + 1) * sizeof(char)));
  if (result == nullptr)
  {
    return result;
  }
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
  result[result_size] = '\0';
  return result;
}

char * ivantsova::addDigits(const char * str1, const char * str2, size_t size1, size_t & result_size)
{
  size_t size2 = 0;
  while (str2[size2] != '\0')
  {
    ++size2;
  }
  size_t digit_count = 0;
  for (size_t i = 0; i < size2; ++i)
  {
    if (std::isdigit(static_cast<unsigned char>(str2[i])))
    {
      ++digit_count;
    }
  }
  result_size = size1 + digit_count;
  char * result = static_cast<char *>(malloc((result_size + 1) * sizeof(char)));
  if (result == nullptr)
  {
    return result;
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
  result[result_size] = '\0';
  return result;
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
  size_t size = 0;
  char * input_str = ivantsova::readLine(std::cin, size);
  if (input_str == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  if (size == 0)
  {
    std::cerr << "Empty input" << "\n";
    free(input_str);
    return 1;
  }

  const char * second_str_for_ils = "def ";
  size_t result_for_ils_size = 0;
  char * result_for_ils = ivantsova::interleaveStrings(input_str, second_str_for_ils, size, result_for_ils_size);
  if (result_for_ils == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    free(input_str);
    return 1;
  }
  ivantsova::printString(std::cout, result_for_ils, result_for_ils_size);

  const char * second_str_for_ad = "g1h2k";
  size_t result_for_ad_size = 0;
  char * result_for_ad = ivantsova::addDigits(input_str, second_str_for_ad, size, result_for_ad_size);
  if (result_for_ad == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    free(input_str);
    free(result_for_ils);
    return 1;
  }
  ivantsova::printString(std::cout, result_for_ad, result_for_ad_size);
  free(input_str);
  free(result_for_ils);
  free(result_for_ad);
  return 0;
}
