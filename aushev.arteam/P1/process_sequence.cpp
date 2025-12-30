#include "process_sequence.hpp"
#include <iostream>

namespace aushev {

bool process_sequence(int& eql_result, int& mon_result) {
  int current;
  if (!(std::cin >> current)) {
    return false;
  }
  if (current == 0) {
    return false;
  }

  int prev = current;
  int eql_run = 1;
  int mon_run = 1;
  eql_result = 1;
  mon_result = 1;

  while (std::cin >> current) {
    if (current == 0) {
      break;
    }

    if (current == prev) {
      ++eql_run;
    } else {
      if (eql_run > eql_result) {
        eql_result = eql_run;
      }
      eql_run = 1;
    }

    if (current >= prev) {
      ++mon_run;
    } else {
      if (mon_run > mon_result) {
        mon_result = mon_run;
      }
      mon_run = 1;
    }

    prev = current;
  }

  if (eql_run > eql_result) {
    eql_result = eql_run;
  }
  if (mon_run > mon_result) {
    mon_result = mon_run;
  }
  return true;
}
}
