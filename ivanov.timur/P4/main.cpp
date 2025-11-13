#include<iostream>
#include<iomanip>

size_t get_line(std::istream & in, char * data, size_t size) {
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  size_t i = 0;
  for (; i < size; ++i) {
    in >> data[i];
  }
  data[i] = 0;
  if (is_skipws) {
    in >> std::skipws;
  }
  return i;
}

int main() {
  return 0;
}