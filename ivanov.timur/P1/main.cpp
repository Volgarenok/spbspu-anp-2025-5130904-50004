#include <iostream>

#include "after.h"
#include "pythagor.h"

int main() {
  int tmp = 0;
  bool init = false;
  size_t cnt = 0;
  std::cin >> tmp;
  After ans1 = After();
  Pythagor ans2 = Pythagor();
  while (tmp != 0) {
    init = true;
    if (std::cin.fail() || std::cin.eof()) {
      break;
    }

    ans1.next(tmp);
    ans2.next(tmp);
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
