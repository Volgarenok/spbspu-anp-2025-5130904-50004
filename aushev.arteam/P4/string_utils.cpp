#include "string_utils.hpp"
#include <iostream>
#include <new>

int aushev::has_sam(const char* s1, const char* s2) {
  if (!s1 || !s2) {
    return 0;
  }
  for (size_t i = 0; s1[i] != '\0'; ++i) {
    for (size_t j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        return 1;
      }
    }
  }
  return 0;
}

char* aushev::spc_rmv(char* dst, const char* src) {
  if (!dst || !src) {
    return nullptr;
  }
  size_t out_idx = 0;
  size_t in_idx = 0;

  while (src[in_idx] == ' ') {
    ++in_idx;
  }

  bool space_pending = false;
  while (src[in_idx] != '\0') {
    if (src[in_idx] == ' ') {
      space_pending = true;
    } else {
      if (space_pending) {
        dst[out_idx] = ' ';
        ++out_idx;
        space_pending = false;
      }
      dst[out_idx] = src[in_idx];
      ++out_idx;
    }
    ++in_idx;
  }
  dst[out_idx] = '\0';
  return dst;
}

char* aushev::read_line() {
  char* buf = nullptr;
  size_t len = 0;
  size_t cap = 64;

  try {
    buf = new char[cap];
  } catch (const std::bad_alloc&) {
    return nullptr;
  }

  char ch;
  while (std::cin.get(ch) && ch != '\n') {
    if (len + 1 >= cap) {
      cap *= 2;
      char* tmp = nullptr;
      try {
        tmp = new char[cap];
      } catch (const std::bad_alloc&) {
        delete[] buf;
        return nullptr;
      }
      for (size_t i = 0; i <= len; ++i) {
        tmp[i] = buf[i];
      }
      delete[] buf;
      buf = tmp;
    }
    buf[len] = ch;
    ++len;
  }
  buf[len] = '\0';

  return buf;
}