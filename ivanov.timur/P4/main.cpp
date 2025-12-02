#include <iostream>
#include "string_ideas.h"
int main() {
  size_t BASE = 10;
  char* content = new char[BASE];
  size_t size = 0;
  content = ivanov::get_line(std::cin, content, size, BASE);
  if (size == 0)
  {
    delete[] content;
    std::cerr << "No data provided" << "\n";
    return 2;
  }
  content = ivanov::del_lat(content, size);
  content = ivanov::spc_rmv(content, size);
  ivanov::output(content);
  std::cout << "\n";
  const char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 47;
  content = ivanov::merge(content, add_content, size, add_size);
  content = ivanov::get_find(content, size);
  ivanov::output(content);
  std::cout << "\n";
  delete[] content;
  return 0;
}