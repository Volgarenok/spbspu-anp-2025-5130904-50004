#ifndef STRING_IDEAS_H
#define STRING_IDEAS_H
#include <cstddef>
namespace ivanov {
  bool spc_rmv(char* content, size_t size);
  bool del_lat(char* content, size_t size);
  void output(const char* content, size_t size);
  bool merge(char* content1, char* content2, size_t size1, size_t size2);
  bool get_find(char* content, size_t size);
  bool find(char symbol, const char* content, size_t size);
}
#endif
