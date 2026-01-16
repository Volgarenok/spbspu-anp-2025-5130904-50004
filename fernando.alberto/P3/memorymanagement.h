#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

namespace fernando
{
  int* allocate_matrix(int rows, int cols);
  void free_matrix(int* matrix);
}

#endif
