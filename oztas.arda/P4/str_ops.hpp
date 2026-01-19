#ifndef STR_OPS_HPP
#define STR_OPS_HPP

#include <cstddef>

namespace oztas {

  size_t cstrLen(const char* s) noexcept;

  size_t replaceSymbol(
    const char* src,
    int fromCh,
    int toCh,
    char* dst,
    size_t dstSize
  ) noexcept;

  size_t latinTwo(
    const char* s1,
    const char* s2,
    char* dst,
    size_t dstSize
  ) noexcept;

}

#endif
