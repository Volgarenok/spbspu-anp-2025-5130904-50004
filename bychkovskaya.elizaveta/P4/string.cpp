#include "string.hpp"
#include <cctype>
#include <iomanip>
#include <fstream>

char* bychkovskaya::getline(std::istream& in, size_t& size)
{
  char elem = '\0';
  size = 0;
  size_t workSize = 1;
  size_t cap = 1;
  size_t extendedCap = 0;
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char* data = reinterpret_cast< char* >(malloc(sizeof(char) * cap));
  if (data == nullptr) {
    return nullptr;
  }
  while (in >> elem && elem != '\n') {
    if (workSize == cap) {
      extendedCap = 2 * cap;
      char* tmp = reinterpret_cast< char* >(malloc(sizeof(char) * extendedCap));
      if (tmp == nullptr) {
        free(data);
        return nullptr;
      }
      cap = extendedCap;
      for (size_t i = 0; i < workSize - 1; ++i) {
        tmp[i] = data[i];
      }
      free(data);
      data = tmp;
    }
    data[workSize - 1] = elem;
    ++workSize;
  }
  data[workSize - 1] = '\0';
  if (is_skipws) {
    in >> std::skipws;
  }
  size = workSize;
  return data;
}

void bychkovskaya::latrmv(const char* str, char* result)
{
  size_t k = 0;
  for (size_t i = 0; str[i] != '\0'; ++i) {
    if (!std::isalpha(str[i])) {
      result[k] = str[i];
      ++k;
    }
  }
  result[k] = '\0';
}


void bychkovskaya::excsnd(const char* str1, const char* str2, char* result)
{
  size_t countRepeat = 0;
  size_t k = 0;
  for (size_t i = 0; str1[i] != '\0'; ++i) {
    countRepeat = 0;
    for (size_t j = 0; str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j] && str1[i] != ' ') {
        ++countRepeat;
      }
    }
    if (countRepeat == 0) {
      result[k] = str1[i];
      ++k;
    }
  }
  result[k] = '\0';
}
