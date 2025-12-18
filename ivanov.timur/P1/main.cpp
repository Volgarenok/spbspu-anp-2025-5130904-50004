#include <iostream>
#include "pythagor.h"
#include "after.h"

int main() {
  int tmp = 0;
  bool init = false;
  size_t cnt = 0;
  std::cin >> tmp;
  ivanov::After ans1 = ivanov::After();
  ivanov::Pythagor ans2 = ivanov::Pythagor();
  while (tmp != 0) {
    init = true;
    if (std::cin.fail() || std::cin.eof()) {
      break;
    }
    ans1(tmp);
    ans2(tmp);
    if (++cnt >= 3)
    {
      ans2.take();
    }
    std::cin >> tmp;
  }
  if (std::cin.fail() ||std::cin.eof()) {
    return 1;
  }
  if (!init) {
    return 2;
  }
  std::cout << ans1() << "\n" << ans2() << "\n";
  return 0;
}
