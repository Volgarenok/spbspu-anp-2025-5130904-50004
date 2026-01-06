#include "process_sequence.hpp"
#include <iostream>

int main() {
  int eql_out;
  int mon_out;

  if (!aushev::process_sequence(eql_out, mon_out)) {
    std::cerr << "Invalid input\n";
    return 1;
  }

  std::cout << eql_out << '\n';
  std::cout << mon_out << '\n';
  return 0;
}
