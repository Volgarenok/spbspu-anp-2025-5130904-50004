#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
namespace haliullin
{
  char *getline(std::istream &in, size_t &s);
  size_t DIF_LAT(const char *arr, size_t size);
  char *RMV_VOW(char *new_arr, const char *arr, size_t size);
  void writeString(const char *arr, size_t size);
}
int main()
{
  char symb = '\0';
  size_t size = 0;
  char *arr = nullptr;
  std::cin >> symb;
  ++size;
  if (!std::cin)
  {
    std::cerr << "Unexpected input" << "\n";
    return 2;
  }
  arr = static_cast < char* >(malloc((size) * sizeof(char)));
  if (arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  arr[0] = symb;
  while (std::cin >> symb && symb != '\0')
  {
    if(!std::cin)
    {
      std::cerr << "Unexpected input" << "\n";
      return 2;
    }
    char *temp = nullptr;
    temp = static_cast < char* >(malloc((size + 1) * sizeof(char)));
    if (temp == nullptr)
    {
      std::cerr << "Memory allocation error" << "\n";
      return 1;
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
  haliullin::writeString(arr, size);
  free(arr);
  return 0;
}

void haliullin::writeString(const char *arr, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arr[i];
  }
  std::cout << "\n";
}

