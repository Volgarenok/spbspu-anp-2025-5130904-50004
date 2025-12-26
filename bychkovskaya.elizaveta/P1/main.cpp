#include <iostream>

struct Counter {
	Counter(): c_(0) {}
	void operator()(int a) {
		++c_;
	}
	size_t operator()() const {
		return c_;
	}
	private:
	size_t c_;
}

struct Max {
	Max();
	void operator()(int num);
	size_t operator()() const {
		return c_;
	}
	private:
  int max_;
  size_t c_;
  size_t k_;
};

Max::Max():
  k_(0),
	res_(0),
	max_(0)
{}

void Max::operator()(int a) {
	  ++k_;
		if (k == 1) {
			max_ = num;
			c_ = 1;
		}
    if (num > max_ && k_ != 1) {
      c_ = 1;
    }
		if (num == max_ && k_ != 1) {
			++c_;
		}
}

size_t operator()() const {
	return res;
}


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