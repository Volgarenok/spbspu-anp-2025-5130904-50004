#include <iostream>

// int main() {
//   int num = 0;
//   int prevNum = 0;
//   size_t count = 0;
//   size_t k = 0;
// 	while (std::cin >> num && num != 0) {
// 		++k;
// 		if (num > prevNum && k != 1) {
// 			++count;
// 		}
// 		prevNum = num;
// 	}
// 	if (!std::cin && !std::cin.eof()) {
// 		std::cerr << "Wrong input" << "\n";
// 		return 1;
// 	}
// 	std::cout << count << "\n";
// }

int main() {
  int num = 0;
  int max = 0;
  size_t count = 0;
  size_t k = 0;
  while (std::cin >> num && num != 0) {
    ++k;
		if (k == 1) {
			max = num;
			count = 1;
		}
    if (num > max && k != 1) {
      count = 1;
    }
		if (num == max && k != 1) {
			++count;
		}
  }
	if (num == 0 && k == 0) {
		std::cerr << "Not enough elements" << "\n";
		return 2;
	}
  if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }

  std::cout << count << "\n";
}