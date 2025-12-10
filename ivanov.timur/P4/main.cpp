#include <iostream>
#include "string_ideas.h"
int main()
{
  size_t BASE = 10;
  size_t size = 0;
  char *content = ivanov::get_line(std::cin, size, BASE, '\n');
  if (size == 0)
  {
    delete[] content;
    std::cerr << "No data provided" << "\n";
    return 2;
  }
  char * ncontent = ivanov::del_lat(content, size);
  content = ivanov::spc_rmv(ncontent, size);
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
