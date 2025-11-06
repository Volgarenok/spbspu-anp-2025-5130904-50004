#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  std::ifstream input(argv[2]);
  size_t m = 0ull, n = 0ull;
  input >> m >> n;
  int matrix[10000];
  for (size_t i = 0ull; i < m; ++i) {
    for (size_t j = 0ull; j < n; ++j) {
      input >> matrix[i * n + j];
    }
  }

  std::ofstream output(argv[3]);
  for (size_t i = 0ull; i < m; ++i) {
    for (size_t j = 0ull; j < n; ++j) {
      output << matrix[i * n + j] << " ";
    }
    output << "\n";
  }
}
