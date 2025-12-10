#include <iostream>
#include "string_ideas.h"
int main()
{
  size_t BASE = 10;
  char *content = ivanov::get_line(std::cin, BASE, '\n');
  if (content[0] == '\0') {
    delete[] content;
    std::cerr << "No data provided\n";
    return 2;
  }
  char *tmpx = new char[10000];
  char *result1 = ivanov::del_lat(content, tmpx);
  delete[] content;

  char *result2 = ivanov::spc_rmv(result1);
  ivanov::output(result2);
  std::cout << "\n";
  const char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 47;
  char *merged = new char[10000];
  char *result3 = ivanov::merge(result2, add_content, merged, add_size);
  char *found = new char[27];
  char *result4 = ivanov::get_find(result3, found);
  ivanov::output(result4);
  std::cout << "\n";
  delete[] merged;
  delete[] found;
  delete[] tmpx;

  return 0;
}
