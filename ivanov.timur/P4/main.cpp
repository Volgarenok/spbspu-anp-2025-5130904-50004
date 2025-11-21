#include <iostream>
#include "string_ideas.h"
void get_line(std::istream & in, char* data, size_t size) {
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char tmp;
  in >> tmp;
  while (tmp != '\n') {
    data[size] = tmp;
    size++;
    in >> tmp;
  }
  data[size] = 0;
  size++;
  if (is_skipws) {
    in >> std::skipws;
  }
}
int main() {
  return 0;
}