#include <cctype>
#include <iomanip>
#include <fstream>
#include "string.hpp"

char* bychkovskaya::create(size_t size)
{
  char* array = reinterpret_cast<char*>(malloc(sizeof(char) * size));
  return array;
}

char* bychkovskaya::getline(std::istream& in, size_t& size)
{
  char elem = '\0';
  size = 1;
  size_t cap = 1;
  size_t extendedCap = 0;
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char* data = create(cap);
  if (data == nullptr) {
    throw std::runtime_error("Not enough memory");
  }
  while (in >> elem && elem != '\n') {
    if (size == cap) {
      extendedCap = 2 * cap;
      char* tmp = create(extendedCap);
      if (tmp == nullptr) {
        free(data);
        throw std::runtime_error("Not enough memory");
      }
      cap = extendedCap;
      for (size_t i = 0; i < size - 1; ++i) {
        tmp[i] = data[i];
      }
      free(data);
      data = tmp;
    }
    data[size - 1] = elem;
    ++size;
  }
  if (in.eof() || in.bad()) {
    free(data);
    throw std::invalid_argument("Input failed");
  }
  data[size - 1] = '\0';
  if (is_skipws) {
    in >> std::skipws;
  }
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
