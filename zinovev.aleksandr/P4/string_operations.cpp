#include "string_operations.hpp"
#include <cstdlib>
#include <iomanip>

char* zinovev::setLine(std::istream& in, size_t& size, size_t& number_of_letters)
{
  if (in >> std::skipws)
  {
    in >> std::noskipws;
  }

  const size_t INITIAL_BUFFER_SIZE = 10;
  size_t number = INITIAL_BUFFER_SIZE;
  char* buffer = static_cast< char* >(malloc(number * sizeof(char)));

  if (buffer == nullptr)
  {
    return buffer;
  }

  size = 0;
  number_of_letters = 0;

  while (in >> buffer[size] && buffer[size] != '\n')
  {
    ++size;

    if (std::isalpha(buffer[size - 1]))
    {
      number_of_letters++;
    }

    if (size == number)
    {
      number += number;
      char* new_buffer = static_cast< char* >(malloc(number * sizeof(char)));

      if (new_buffer == nullptr)
      {
        free(buffer);
        return new_buffer;
      }

      for (size_t k = 0; k < size; ++k)
      {
        new_buffer[k] = buffer[k];
      }

      free(buffer);

      buffer = new_buffer;
      new_buffer = nullptr;
    }
  }

  in >> std::skipws;

  char* result = static_cast< char* >(malloc((size + 1) * sizeof(char)));

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

char* zinovev::cutLetters(const char* arr, char* arr_ptr, size_t& size, size_t& size_ptr)
{
  size_t skip = 0;

  for (size_t i = 0; arr[i] != '\0'; ++i)
  {
    if (std::isalpha(arr[i]))
    {
      ++skip;
    }
    else
    {
      arr_ptr[i - skip] = arr[i];
    }
  }

  size_ptr = size - skip;
  return arr_ptr;
}

void zinovev::printLine(std::ostream& out, const char* array, size_t size)
{
  if (array == nullptr)
  {
    return;
  }

  for (size_t i = 0; i < size; ++i)
  {
    out << array[i];
  }
}

int zinovev::getRepetitions(const char* arr, size_t size)
{
  int counter = 0;

  for (size_t i = 0; i < size; ++i)
  {
    for (size_t k = i + 1; k < size; ++k)
    {
      if (arr[i] == arr[k])
      {
        ++counter;
        break;
      }
    }
  }

  return counter;
}
