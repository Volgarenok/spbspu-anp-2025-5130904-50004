#include <iostream>
#include <new>
#include "str_ops.hpp"

namespace {

  char* readLineDynamic() noexcept
  {
    const size_t kInitialCap = 64;

    size_t cap = kInitialCap;
    size_t len = 0;

    char* buf = new (std::nothrow) char[cap];
    if (buf == nullptr) {
      return nullptr;
    }

    while (true) {
      const int ch = std::cin.get();
      if ((ch == '\n') || (ch == EOF)) {
        break;
      }

      if ((len + 1) >= cap) {
        const size_t newCap = cap * 2;
        char* newBuf = new (std::nothrow) char[newCap];
        if (newBuf == nullptr) {
          delete[] buf;
          return nullptr;
        }

        for (size_t i = 0; i < len; ++i) {
          newBuf[i] = buf[i];
        }

        delete[] buf;
        buf = newBuf;
        cap = newCap;
      }

      buf[len] = static_cast<char>(ch);
      ++len;
    }

    buf[len] = '\0';
    return buf;
  }

}

int main()
{
  char* input = readLineDynamic();
  if (input == nullptr) {
    std::cerr << "error: cannot allocate memory\n";
    return 1;
  }

  const size_t inputLen = oztas::cstrLen(input);

  char* out1 = new (std::nothrow) char[inputLen + 1];
  if (out1 == nullptr) {
    delete[] input;
    std::cerr << "error: cannot allocate memory\n";
    return 1;
  }

  oztas::replaceSymbol(input, 'c', 'b', out1, inputLen + 1);
  std::cout << out1 << "\n";

  const char* second = "def_ghk";

  char* out2 = new (std::nothrow) char[27];
  if (out2 == nullptr) {
    delete[] out1;
    delete[] input;
    std::cerr << "error: cannot allocate memory\n";
    return 1;
  }

  oztas::latinTwo(input, second, out2, 27);
  std::cout << out2 << "\n";

  delete[] out2;
  delete[] out1;
  delete[] input;
  return 0;
}
