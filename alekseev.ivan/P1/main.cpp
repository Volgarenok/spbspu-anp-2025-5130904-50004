#include <iostream>
#include "Property.h"
#include "Pth_trp.h"


namespace alekseev {
  Property * make(int n);
  Property ** make_multiple(size_t k);
}

int main()
{
  constexpr size_t NUM_OF_PROPS = 2;
  alekseev::Property ** properties = alekseev::make_multiple(NUM_OF_PROPS);
  int a = 0;
  std::cin >> a;
  while (a && std::cin) {
    for (size_t i = 0; i < NUM_OF_PROPS; i++) {
      (*properties[i])(a);
    }
    std::cin >> a;
  }
  for (size_t i = 0; i < NUM_OF_PROPS; i++) {
    std::cout << properties[i]->name() << ": " << (*properties[i])() << "\n";
  }
}


alekseev::Property * alekseev::make(int n)
{
  if (n == 0) {
    return new Pth_trp();
  }
  // if (n == 1) {
  //   return new Sum_dup();
  // }
  return nullptr;
}