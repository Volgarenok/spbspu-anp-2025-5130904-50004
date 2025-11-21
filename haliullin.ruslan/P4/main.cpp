#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
namespace haliullin
{
  char *getline(std::istream &in, size_t &size);
  size_t DIF_LAT(const char *arr, size_t size);
  char *RMV_VOW(char *new_arr, const char *arr, size_t size);
  void writeString(const char *arr, size_t size);
}
int main()
{
  char *arr = nullptr;
  size_t size = 0;
  
  arr = haliullin::getline(std::cin, size);
  if (arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  haliullin::writeString(arr, size);
  std::cout << size << "\n";
  free(arr);
  return 0;
}

char *haliullin::getline(std::istream &in, size_t &size)
{
  char symb = '\0';
  char *arr = nullptr;
  size = 0;
  
  in >> symb;
  ++size;
  arr = static_cast < char* >(malloc(sizeof(char)));
  if (arr == nullptr)
  {
    return nullptr;
  }
  arr[0] = symb;
  while (in >> symb && symb != '\0')
  {
    char *temp = nullptr;
    temp = static_cast < char* >(malloc((size + 1) * sizeof(char)));
    if (temp == nullptr)
    {
      return nullptr;
    }
    for (size_t i = 0; i < size; ++i)
    {
      temp[i] = arr[i];
    }
    temp[size] = symb;
    
    free(arr);
    arr = temp;
    ++size;
  }
  return arr;
}

void haliullin::writeString(const char *arr, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arr[i];
  }
  std::cout << "\n";
}

