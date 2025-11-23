#include "string.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>

namespace
{
  bool isLatinVowel(char c) noexcept
  {
    unsigned char uc = static_cast<unsigned char>(c);
    char lower = static_cast<char>(std::tolower(uc));
    return lower == 'a' || lower == 'e' || lower == 'i' ||
           lower == 'o' || lower == 'u' || lower == 'y';
  }
}

namespace aydogan
{
  char * readString(std::istream & in)
  {
    if (!in.good())
    {
      return nullptr;
    }

    int peek_char = in.peek();
    if (peek_char == std::char_traits<char>::eof())
    {
      return nullptr;
    }

    std::size_t capacity = 16;
    char * buffer = static_cast<char *>(std::malloc(capacity));
    if (buffer == nullptr)
    {
      return nullptr;
    }

    std::size_t length = 0;
    char c = '\0';
    while (in.get(c) && c != '\n')
    {
      if (length + 1 >= capacity)
      {
        std::size_t new_capacity = capacity * 2;
        char * new_buffer = static_cast<char *>(std::malloc(new_capacity));
        if (new_buffer == nullptr)
        {
          std::free(buffer);
          return nullptr;
        }
        for (std::size_t i = 0; i < length; ++i)
        {
          new_buffer[i] = buffer[i];
        }
        std::free(buffer);
        buffer = new_buffer;
        capacity = new_capacity;
      }
      buffer[length] = c;
      ++length;
    }

    if (length == 0 && !in.good() && c != '\n')
    {
      std::free(buffer);
      return nullptr;
    }

    if (length + 1 >= capacity)
    {
      char * new_buffer = static_cast<char *>(std::malloc(length + 1));
      if (new_buffer == nullptr)
      {
        std::free(buffer);
        return nullptr;
      }
      for (std::size_t i = 0; i < length; ++i)
      {
        new_buffer[i] = buffer[i];
      }
      std::free(buffer);
      buffer = new_buffer;
    }

    buffer[length] = '\0';
    return buffer;
  }

  void removeVowels(const char * src, char * dest) noexcept
  {
    std::size_t dest_index = 0;
    if (src == nullptr || dest == nullptr)
    {
      return;
    }
    for (std::size_t i = 0; src[i] != '\0'; ++i)
    {
      char c = src[i];
      if (std::isalpha(static_cast<unsigned char>(c)) && isLatinVowel(c))
      {
        continue;
      }
      dest[dest_index] = c;
      ++dest_index;
    }
    dest[dest_index] = '\0';
  }

  void appendDigits(const char * first, const char * second, char * dest) noexcept
  {
    if (first == nullptr || second == nullptr || dest == nullptr)
    {
      return;
    }

    std::size_t dest_index = 0;
    for (std::size_t i = 0; first[i] != '\0'; ++i)
    {
      dest[dest_index] = first[i];
      ++dest_index;
    }

    for (std::size_t i = 0; second[i] != '\0'; ++i)
    {
      unsigned char uc = static_cast<unsigned char>(second[i]);
      if (std::isdigit(uc))
      {
        dest[dest_index] = second[i];
        ++dest_index;
      }
    }

    dest[dest_index] = '\0';
  }

  void writeString(const char * str)
  {
    if (str == nullptr)
    {
      return;
    }
    for (std::size_t i = 0; str[i] != '\0'; ++i)
    {
      std::cout << str[i];
    }
    std::cout << '\n';
  }
}