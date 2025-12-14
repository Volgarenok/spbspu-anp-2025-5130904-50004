#ifndef STRING_IDEAS_H
#define STRING_IDEAS_H
#include <cstddef>
#include <iosfwd>
namespace ivanov {
  char *spc_rmv(char *content);
  char *del_lat(char *content, char *tmpx);
  void output(const char *content);
  char *merge(char *content1, const char *content2, char *tmp, size_t size2);
  char *get_find(char *content, char *tmp);
  bool find(char symbol, const char *content);
  size_t count(const char *content, char symbol);
  char *get_line(std::istream &in, size_t &length, char stop);

  char *dataGen(char tmp, char stop, std::istream &in, size_t size&, size_t &capacity);
}
#endif
