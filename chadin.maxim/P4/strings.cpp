#include "strings.h"

namespace chadin
{
int hasSameSymbols(const char* str1, const char* str2)
{
  if (str1 == nullptr || str2 == nullptr) {
    return 0;
  }

  for (const char* p1 = str1; *p1 != '\0'; ++p1) {
    for (const char* p2 = str2; *p2 != '\0'; ++p2) {
      if (*p1 == *p2) {
        return 1;
      }
    }
  }
  return 0;
}

int digitSnd(const char* str1, const char* str2, char* result, size_t bufferSize)
{
}
}

