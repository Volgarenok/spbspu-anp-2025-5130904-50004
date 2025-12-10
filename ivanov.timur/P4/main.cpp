#include <iostream>
#include "string_ideas.h"
int main()
{
  size_t BASE = 10;
  char *content = ivanov::get_line(std::cin, BASE, '\n');
  if (content[0] == '\0')
  {
    delete[] content;
    std::cerr << "No data provided" << "\n";
    return 2;
  }
  char * tmpx = new char[10000];
  content = ivanov::del_lat(content, tmpx);
  content = ivanov::spc_rmv(content, tmpx);
  ivanov::output(content);
  std::cout << "\n";
  const char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 47;
  content = ivanov::merge(content, add_content, tmpx, add_size);
  content = ivanov::get_find(content, tmpx);
  ivanov::output(content);
  std::cout << "\n";
  delete[] content;
  return 0;
}
