#include "eql_seq.hpp"
#include "mon_inc.hpp"
#include <iostream>

int main() {
  aushev::eql_seq eql;
  aushev::mon_inc mon;
  aushev::sequence_metric* metrics[] = {&eql, &mon};
  const size_t metric_count = sizeof(metrics) / sizeof(metrics[0]);

  int value;
  bool has_input = false;

  while (std::cin >> value) {
    if (value == 0) {
      break;
    }
    has_input = true;
    for (size_t i = 0; i < metric_count; ++i) {
      (*metrics[i])(value);
    }
  }

  if (!has_input) {
    std::cerr << "Invalid input\n";
    return 1;
  }

  for (size_t i = 0; i < metric_count; ++i) {
    std::cout << (*metrics[i])() << '\n';
  }

  return 0;
}
