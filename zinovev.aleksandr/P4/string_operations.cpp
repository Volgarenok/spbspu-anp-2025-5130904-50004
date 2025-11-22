#include "string_operations.hpp"
#include <cstdlib>

char* zinovev::SetLine(std::istream & in, size_t& size, size_t& number_of_letters)
{
  size_t number = 10;
  char* Mass = (char*)malloc(number * sizeof(char));

  size = 0;

  while (in >> Mass[size] && Mass[size] != '\n')
  {
    ++size;

    if (size == number)
    {
      number += number;
      char* Mass_ptr = (char*)malloc(number * sizeof(char));

      for (size_t k = 0; k < size; ++k)
        Mass_ptr[k] = Mass[k];

      free(Mass);

      Mass = Mass_ptr;
      Mass_ptr = nullptr;
    }
  }

  char* Arr = (char*)malloc((size + 1) * sizeof(char));

  for (size_t k = 0; k < size; ++k)
    Arr[k] = Mass[k];

  Arr[size] = '\0';

  free(Mass);

  return Arr;
}

void zinovev::CutLetters(char* arr, char* arr_ptr, size_t& size, size_t& size_ptr)
{

}

void zinovev::GetLine(std::ostream & out, char* array, const size_t size)
{
  for (size_t i = 0; i < size; ++i)
    out << array[i];

  out << "\n";
}

int zinovev::GetRepetitions(const char* arr, const size_t size)
{
  return 0;
}
