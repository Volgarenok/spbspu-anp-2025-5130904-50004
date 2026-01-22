#include <iostream>
#include "GRT_LSS.h"
#include "AFT_MAX.h"

int main()
{
  const int initial_capacity = 8;
  int* data = new (std::nothrow) int[initial_capacity];
  if (!data)
  {
    std::cerr << "Memory allocation failed." << std::endl;
    return 2;
  }

  int size = 0;
  int capacity = initial_capacity;
  int value = 0;

  while (std::cin >> value)
  {
    if (value == 0)
    {
      break;
    }

    if (size >= capacity)
    {
      int new_capacity = capacity * 2;
      int* new_data = new (std::nothrow) int[new_capacity];
      if (!new_data)
      {
        delete[] data;
        std::cerr << "Memory allocation failed." << std::endl;
        return 2;
      }
      for (int i = 0; i < size; ++i)
      {
        new_data[i] = data[i];
      }
      delete[] data;
      data = new_data;
      capacity = new_capacity;
    }

    data[size] = value;
    ++size;
  }

  if (std::cin.bad() || (std::cin.fail() && !std::cin.eof()) || size == 0)
  {
    delete[] data;
    std::cerr << "Input is not a valid sequence." << std::endl;
    return 1;
  }

  int result1 = chadin::countGrtLss(data, size);
  int result2 = chadin::countAftMax(data, size);

  std::cout << result1 << std::endl;
  std::cout << result2 << std::endl;

  delete[] data;
  return 0;
}
