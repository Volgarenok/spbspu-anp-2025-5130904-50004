#ifndef STRING_IDEAS_H
#define STRING_IDEAS_H
#include <cstddef>
#include <iosfwd>
namespace ivanov {
  char * spc_rmv(char *content, size_t &size);
  char * del_lat(char *content, size_t &size);
  void output(const char *content);
  char * merge(char *content1, const char *content2, size_t &size1, size_t size2);
  char * get_find(char *content, size_t &size);
  bool find(char symbol, const char *content);
  size_t count(char *content, char symbol);
  char * get_line(std::istream &in, size_t &size, size_t &length, char stop);
}
#endif
