#include "string_ideas.h"
#include <iostream>
#include <cctype>

bool ivanov::del_lat(char* content, size_t size) {
  char* tmp = new char[100000];
  size_t c = 0;
  for (size_t i = 0; i < size; ++i) {
    if (!isalpha(content[i])) {
      tmp[i - c] = content[i];
    } else {
      c++;
    }
  }
  delete[] content;
  content = tmp;
  size-=c;
}
void ivanov::output(const char* content, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    std::cout << content[i];
  }
  std::cout << "\n";
}
bool ivanov::spc_rmv(char *content, size_t size) {
  char* tmp = new char[100000];
  bool flag = false;
  size_t c = 0;
  for (size_t i = 0; i < size; ++i) {
    if ((!flag || content[i - 1] == ' ') && content[i] == ' ') {
      tmp[i - c] = content[i];
      flag = true;
    } else {
      c++;
    }
  }
  delete[] content;
  size-=c;
}
bool ivanov::merge(char *content1, char *content2, size_t size1, size_t size2) {
  char* tmp = new char[100000];
  for (size_t i = 0; i < size1; ++i) {
    tmp[i] = content1[i];
  }
  for (size_t i = size1; i < size1 + size2; ++i) {
    tmp[i] = content2[i - size1];
  }
  delete[] content1;
  delete[] content2;
  content1 = tmp;
  size1+=size2;
}
