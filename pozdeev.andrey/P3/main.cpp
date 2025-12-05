#include "pozdeev.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <new>

int main(int argc, char * argv[])
{
  if (argc < 4) {
    std::cerr << "Not enough arguments" << std::endl;
    return 1;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments" << std::endl;
    return 1;
  }

  try {
    int taskNum = pozdeev::numAnalysis(argv[1]);

    std::ifstream fin(argv[2]);
    if (!fin.is_open()) {
      std::cerr << "ERROR: Could not open input file" << std::endl;
      return 2;
    }

    std::ofstream fout(argv[3]);
    if (!fout.is_open()) {
      std::cerr << "ERROR: Could not open output file" << std::endl;
      return 2;
    }

    int tempRows = 0;
    int tempCols = 0;
    if (!(fin >> tempRows >> tempCols)) {
      std::cerr << "ERROR: Invalid matrix dimensions format or file is empty" << std::endl;
      return 2;
    }

    if (tempRows < 0 || tempCols < 0) {
      std::cerr << "ERROR: Matrix dimensions cannot be negative" << std::endl;
      return 2;
    }

    size_t rows = static_cast < size_t > (tempRows);
    size_t cols = static_cast < size_t > (tempCols);
    const size_t numElements = rows * cols;

    if (taskNum == 1) {
      if (numElements > static_cast < size_t > (pozdeev::MAX_SIZE)) {
        std::cerr << "ERROR: Matrix too large for static array" << std::endl;
        return 2;
      }

      int staticMatrix[pozdeev::MAX_SIZE];

      if (numElements > 0) {
        pozdeev::inputMatrix(fin, staticMatrix, numElements);
      }

      const int result = pozdeev::countNonSequentialRows(staticMatrix, rows, cols);
      fout << result << "\n";

    } else {
      int * dynamicMatrix = nullptr;
      try {
        dynamicMatrix = new int[numElements];

        if (numElements > 0) {
          pozdeev::inputMatrix(fin, dynamicMatrix, numElements);
        }

        pozdeev::spiral(dynamicMatrix, rows, cols);

        fout << rows << " " << cols;
        for (size_t i = 0; i < numElements; ++i) {
          fout << " " << dynamicMatrix[i];
        }
        fout << "\n";

        delete[] dynamicMatrix;

      } catch (...) {
        delete[] dynamicMatrix;
        throw;
      }
    }

  } catch (const std::invalid_argument & e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (const std::out_of_range & e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (const std::bad_alloc &) {
    std::cerr << "ERROR: Memory allocation failed" << std::endl;
    return 2;
  } catch (const std::runtime_error & e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 2;
  } catch (...) {
    std::cerr << "ERROR: Unknown error" << std::endl;
    return 2;
  }

  return 0;
}
