#include <iostream>
#include "string_ideas.h"
int main()
{
  size_t BASE = 10;
  char *content = nullptr;
  char *tmpx = nullptr;
  try
  {
    content = ivanov::get_line(std::cin, BASE, '\n');
  }
  catch (const std::bad_alloc &m)
  {
    std::cerr << "Failed to allocate memory\n";
    return 1;
  }
  if (content[0] == '\0') {
    delete[] content;
    std::cerr << "No data provided\n";
    return 2;
  }
  try
  {
    tmpx = new char[10000];
  }
  catch (const std::bad_alloc &s)
  {
    delete[] content;
    std::cerr << "Failed to allocate memory\n";
    return 1;
  }
  char *result1 = ivanov::del_lat(content, tmpx);
  delete[] content;

  char *result2 = ivanov::spc_rmv(result1);
  ivanov::output(result2);
  std::cout << "\n";
  const char add_content[] = "And I think to myself - what a wonderful world!0";
  size_t add_size = 47;
  char *merged = nullptr;
  char *found = nullptr;
  try
  {
    merged = new char[BASE + add_size];
  }
  catch (const std::bad_alloc &z)
  {
    delete[] content;
    delete[] tmpx;
    return 1;
  }
  try
  {
    found = new char[27];
  }
  catch (const std::bad_alloc &z) {
    delete[] content;
    delete[] tmpx;
    delete[] merged;
    return 1;
  }
  char *result3 = ivanov::merge(result2, add_content, merged, add_size);
  char *result4 = ivanov::get_find(result3, found);
  ivanov::output(result4);
  std::cout << "\n";
  delete[] merged;
  delete[] found;
  delete[] tmpx;

  return 0;
}
