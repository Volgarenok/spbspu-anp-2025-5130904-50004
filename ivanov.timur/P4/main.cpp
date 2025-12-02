#include <iostream>
#include "string_ideas.h"
int main() {
  char* content = new char[100000];
  size_t size = 0;
  ivanov::get_line(std::cin, content, size);
  if (size == 1)
  {
    delete[] content;
    std::cerr << "No data provided" << "\n";
    return 2;
  }
  if (!ivanov::del_lat(content, size))
  {
    delete[] content;
    return 1;
  }
  if (!ivanov::spc_rmv(content, size))
  {
    delete[] content;
    return 1;
  }
  ivanov::output(content, size);
  char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 48;
  if (!ivanov::merge(content, add_content, size, add_size))
  {
    delete[] content;
    return 1;
  }
  if (!ivanov::get_find(content, size))
  {
    delete[] content;
    return 1;
  }
  ivanov::output(content, size);
  delete[] content;
  return 0;
}
