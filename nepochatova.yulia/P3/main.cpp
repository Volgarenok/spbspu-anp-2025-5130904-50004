#include <iostream>
#include <stdexcept>
#include "io.h"

int main(int argc, char **argv)
{
  try {
    nepochatova::checkArgs(argc, argv);

    size_t n = 0, m = 0;
    bool useDynamic = false;

    if (argv[1][0] == '1')
      useDynamic = false;
    else if (argv[1][0] == '2')
      useDynamic = true;
    else
      throw std::invalid_argument("Invalid memory choice");

    int** arr = nepochatova::readMatrix(argv[2], n, m, useDynamic);

    nepochatova::transformMatrixSpiral(arr, n, m);

    std::ofstream out("output.txt");

    nepochatova::writeMatrix(out, arr, n, m);

    if (useDynamic) {
      for (size_t i = 0; i < n; ++i)
        delete[] arr[i];
      delete[] arr;
    }
  }
  catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
