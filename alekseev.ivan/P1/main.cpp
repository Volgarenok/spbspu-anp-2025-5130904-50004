#include <iostream>
#include "iProperty.h"

int main()
{
  alekseev::iProperty * pth_trp_counter = nullptr;
  alekseev::iProperty * sum_dup_counter = nullptr;
  try {
    pth_trp_counter = alekseev::make(alekseev::pth_trp_id);
    sum_dup_counter = alekseev::make(alekseev::sum_dup_id);
  } catch (const std::bad_alloc & e) {
    delete pth_trp_counter;
    return 3;
  }
  int a = 0;
  std::cin >> a;
  while (a && std::cin) {
    (*pth_trp_counter)(a);
    (*sum_dup_counter)(a);
    std::cin >> a;
  }
  if (!std::cin) {
    std::cerr << "Bad input" << "\n";
    return 1;
  }

  pth_trp_counter->print(std::cout);
  sum_dup_counter->print(std::cout);
  int ret = 0;
  if (!pth_trp_counter->countered() || !sum_dup_counter->countered()) {
    ret = 2;
  }
  delete pth_trp_counter;
  delete sum_dup_counter;
  return ret;
}
