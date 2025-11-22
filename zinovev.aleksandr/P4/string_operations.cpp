#include "string_operations.hpp"
#include <cstdlib>

char* zinovev::SetLine(std::istream & in, size_t& size, size_t& number_of_letters)
{
  size_t number = 10;
  char* Mass = (char*)malloc(number * sizeof(char));

  if (Mass == nullptr)
    return Mass;

  size = 0;
  number_of_letters = 0;

  while (in >> Mass[size] && Mass[size] != '\n')
  {
    ++size;

    if (std::isalpha(Mass[size - 1]))
      number_of_letters++;

    if (size == number)
    {
      number += number;
      char* Mass_ptr = (char*)malloc(number * sizeof(char));

      if (Mass_ptr == nullptr)
      {
        free(Mass);
        return Mass_ptr;
      }

      for (size_t k = 0; k < size; ++k)
        Mass_ptr[k] = Mass[k];

      free(Mass);

      Mass = Mass_ptr;
      Mass_ptr = nullptr;
    }
  }

  char* Arr = (char*)malloc((size + 1) * sizeof(char));

  if (Arr == nullptr)
  {
    free(Mass);
    return Arr;
  }

  for (size_t k = 0; k < size; ++k)
    Arr[k] = Mass[k];

  Arr[size] = '\0';

  free(Mass);

  return Arr;
}

void zinovev::CutLetters(char* arr, char* arr_ptr, size_t& size, size_t& size_ptr)
{
  size_t skip = 0;

  for (size_t i = 0; i < size; ++i)
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
}

void zinovev::GetLine(std::ostream & out, char* array, const size_t size)
{
  if (array == nullptr)
    return;

  for (size_t i = 0; i < size; ++i)
    out << array[i];

  out << "\n";
}

int zinovev::GetRepetitions(const char* arr, const size_t size)
{
  int counter = 0;

  for (size_t i = 0; i < size; ++i)
    for (size_t k = i + 1; k < size; ++k)
      if (arr[i] == arr[k])
      {
        ++counter;
        break;
      }

  return counter;
}
