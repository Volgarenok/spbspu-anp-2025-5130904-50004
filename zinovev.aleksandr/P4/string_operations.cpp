#include "string_operations.hpp"
#include <cstdlib>
#include <iomanip>

char* zinovev::resizeBuffer(char* buffer, size_t old_capacity, size_t& new_capacity)
{
  new_capacity = old_capacity * 2;
  char* new_buffer = reinterpret_cast< char* >(malloc(new_capacity * sizeof(char)));

  if (new_buffer == nullptr)
  {
    free(buffer);
    return nullptr;
  }

  for (size_t k = 0; k < old_capacity; ++k)
  {
    new_buffer[k] = buffer[k];
  }

  free(buffer);
  return new_buffer;
}

char* zinovev::setLine(std::istream& in, size_t& size, size_t& number_of_letters)
{
  std::ios_base::fmtflags original_flags = in.flags();
  in >> std::noskipws;

  const size_t INITIAL_BUFFER_SIZE = 10;
  size_t capacity = INITIAL_BUFFER_SIZE;
  char* buffer = reinterpret_cast< char* >(malloc(capacity * sizeof(char)));

  if (buffer == nullptr)
  {
    in.flags(original_flags);
    return buffer;
  }

  size = 0;
  number_of_letters = 0;
  char current_char = '\0';

  while (in >> current_char && current_char != '\n')
  {
    buffer[size] = current_char;
    ++size;

    if (std::isalpha(buffer[size - 1]))
    {
      number_of_letters++;
    }

    if (size == capacity)
    {
      char* new_buffer = resizeBuffer(buffer, capacity, capacity);
      if (new_buffer == nullptr)
      {
        in.flags(original_flags);
        return nullptr;
      }
      buffer = new_buffer;
    }
  }

  in.flags(original_flags);

  if (size == 0 && in.eof())
  {
    free(buffer);
    return nullptr;
  }

  char* result = reinterpret_cast< char* >(malloc((size + 1) * sizeof(char)));

  if (result == nullptr)
  {
    free(buffer);
    return result;
  }

  for (size_t k = 0; k < size; ++k)
  {
    result[k] = buffer[k];
  }

  result[size] = '\0';
  free(buffer);

  return result;
}

char* zinovev::cutLetters(const char* arr, char* arr_ptr, size_t& size_ptr)
{
  size_t skip = 0;
  size_t i = 0;

  while (arr[i] != '\0')
  {
    if (std::isalpha(arr[i]))
    {
      ++skip;
    }
    else
    {
      arr_ptr[i - skip] = arr[i];
    }
    ++i;
  }

  size_ptr = i - skip;
  return arr_ptr;
}

int zinovev::getRepetitions(const char* arr)
{
  int counter = 0;
  size_t i = 0;

  while (arr[i] != '\0')
  {
    size_t k = i + 1;
    while (arr[k] != '\0')
    {
      if (arr[i] == arr[k])
      {
        ++counter;
        break;
      }
      ++k;
    }
    ++i;
  }

  return counter;
}
