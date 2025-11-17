#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <iosfwd>

namespace vasilenko {

  int cntcolnsm(const int* matrix, int rows, int cols);
  int maxsumsdg(const int* matrix, int rows, int cols);

  int input_array(std::istream& in, int* matrix, size_t size);
}

#endif
