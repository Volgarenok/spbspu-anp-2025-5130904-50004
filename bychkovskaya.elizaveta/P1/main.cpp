#include <iostream>

struct Counter {
	Counter(): c_(0) {}
	void operator()(int) {
		++c_;
	}
	size_t operator()() const {
		return c_;
	}
	private:
	size_t c_;
};

struct Max {
	Max();
	void operator()(int num);
	size_t operator()() const;
	private:
	size_t k_;
	size_t res_;
  int max_;
};

Max::Max():
  k_(0),
	res_(0),
	max_(0)
{}

void Max::operator()(int num) {
	  ++k_;
		if (k_ == 1) {
			max_ = num;
			res_ = 1;
		}
    if (num > max_ && k_ != 1) {
      res_ = 1;
    }
		if (num == max_ && k_ != 1) {
			++res_;
		}
}

size_t Max::operator()() const {
	return res_;
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
	Counter c;
  Max max;
	int num = 0;
  while (std::cin >> num && num != 0) {
    c(num);
		max(num);
  }
	if (num == 0 && c() == 0) {
		std::cerr << "Not enough elements" << "\n";
		return 2;
	}
  if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
  std::cout << max() << "\n";
}