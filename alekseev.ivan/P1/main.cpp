#include <iostream>


int main()
{
  constexpr size_t NUM_OF_PROPS = 2;
  Property * properties[NUM_OF_PROPS]{&Pth_trp, &Sum_dup};
  int a = 0;
  std::cin >> a;
  while (a && std::cin) {
    for (size_t i = 0; i < NUM_OF_PROPS; i++) {
      properties[i](a);
    }
    std::cin >> a;
  }
  for (size_t i = 0; i < NUM_OF_PROPS; i++) {
    std::cout << properties[i].name() << ": " << properties[i]() << "\n";
  }
}