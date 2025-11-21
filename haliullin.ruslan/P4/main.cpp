#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cctype>
namespace haliullin
{
  char *getline(std::istream &in, size_t &size);
  size_t DIF_LAT(const char *arr, size_t str_size);
  char *RMV_VOW(char *new_arr, const char *arr, size_t str_size);
  void writeString(const char *arr, size_t str_size);
}
int main()
{
  namespace hal = haliullin;
  char *arr = nullptr;
  size_t size = 0;
  size_t count = 0;

  arr = hal::getline(std::cin, size);
  if (arr == nullptr)
  {
    std::cerr << "Memory allocation error" << "\n";
    return 1;
  }
  size_t str_size = size - 1;
  hal::writeString(arr, str_size);
  count = hal::DIF_LAT(arr, str_size);
  std::cout << count << "\n";
  free(arr);
  return 0;
}

char *haliullin::getline(std::istream &in, size_t &size)
{
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws)
  {
    in >> std::noskipws;
  }
  char symb = '\0';
  char *arr = nullptr;
  size = 0;

  in >> symb;
  if (in)
  {
    ++size;
    arr = static_cast < char* >(malloc(sizeof(char)));
    if (arr == nullptr)
    {
      if (is_skipws)
      {
        in >> std::skipws;
      }
      return nullptr;
    }
    arr[0] = symb;
    while (in >> symb && symb != '\0')
    {
      char *temp = nullptr;
      temp = static_cast < char* >(malloc((size + 1) * sizeof(char)));
      if (temp == nullptr)
      {
        if (is_skipws)
        {
          in >> std::skipws;
        }
        free(arr);
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
    arr[size] = 0;
  }
  if (is_skipws)
  {
    in >> std::skipws;
  }
  return arr;
}

size_t haliullin::DIF_LAT(const char *arr, size_t str_size)
{
  size_t count = 0;
  size_t ind = 0;
  bool info[26] = {};
  for (size_t i = 0; i < str_size; ++i)
  {
    if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
    {
      ind = char(std::tolower(arr[i])) - 'a';
      if (!info[ind])
      {
        info[ind] = true;
        ++count;
      }
    }
  }
  return count;
}

void haliullin::writeString(const char *arr, size_t str_size)
{
  for (size_t i = 0; i < str_size; ++i)
  {
    std::cout << arr[i];
  }
  std::cout << "\n";
}

