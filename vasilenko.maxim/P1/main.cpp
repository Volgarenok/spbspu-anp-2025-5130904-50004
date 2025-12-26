#include <iostream>
#include "iProperty.h"

int main()
{
  vasilenko::iProperty * aft_max_counter = nullptr;
  vasilenko::iProperty * sub_max_counter = nullptr;

  try {
    aft_max_counter = vasilenko::make(vasilenko::aft_max_id);
    sub_max_counter = vasilenko::make(vasilenko::sub_max_id);
  } catch (const std::bad_alloc & e) {
    delete aft_max_counter;
    delete sub_max_counter;
    return 3;
  }

  int a = 0;
  std::cin >> a;

  while (a != 0 && std::cin) {
    (*aft_max_counter)(a);
    (*sub_max_counter)(a);
    std::cin >> a;
  }

  if (!std::cin && a != 0) {
    std::cerr << "Cannot identify input as a sequence\n";
    delete aft_max_counter;
    delete sub_max_counter;
    return 1;
  }

  bool aft_max_counted = aft_max_counter->countered();
  bool sub_max_counted = sub_max_counter->countered();

  int ret = 0;
  if (!aft_max_counted || !sub_max_counted) {
    std::cerr << "Cannot calculate at least one property\n";
    ret = 2;
  }

  aft_max_counter->print(std::cout);
  sub_max_counter->print(std::cout);

  delete aft_max_counter;
  delete sub_max_counter;

  return ret;
}
