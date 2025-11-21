#include <iostream>
#include "string_ideas.h"
void get_line(std::istream & in, char*& data, size_t& size) {
  bool is_skipws = in.flags() & std::ios_base::skipws;
  if (is_skipws) {
    in >> std::noskipws;
  }
  char tmp = '\n';
  in >> tmp;
  while (tmp != '\n' && std::cin) {
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
  char* content = new char[100000];
  size_t size = 0;
  get_line(std::cin, content, size);
  if (!ivanov::del_lat(content, size)) {
    delete[] content;
    return 1;
  }
  if (!ivanov::spc_rmv(content, size)) {
    delete[] content;
    return 1;
  }
  ivanov::output(content, size);
  char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 48;
  if (!ivanov::merge(content, add_content, size, add_size)) {
    delete[] content;
    return 1;
  }
  if (!ivanov::get_find(content, size)) {
    delete[] content;
    return 1;
  }
  ivanov::output(content, size);
  delete[] content;
  return 0;
}
