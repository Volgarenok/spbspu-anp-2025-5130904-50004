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

struct MoreThanPrevious {
	MoreThanPrevious();
	void operator()(int num);
	size_t operator()() const;
	private:
	int prevNum_;
	int k_;
	int res_;
};

MoreThanPrevious::MoreThanPrevious():
  prevNum_(0),
	k_(0),
	res_(0)
{}

void MoreThanPrevious::operator()(int num) {
		++k_;
		if (num > prevNum_ && k_ != 1) {
			++res_;
		}
		prevNum_ = num;
}

size_t MoreThanPrevious::operator()() const {
	return res_;
}

int main() {
	Counter c;
  Max max;
	MoreThanPrevious prev;
	int num = 0;
  while (std::cin >> num && num != 0) {
    c(num);
		prev(num);
		max(num);
  }
	if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
	if (num == 0 && c() == 0) {
		std::cout << prev() << "\n";
		std::cerr << "Not enough elements to count quantity of max" << "\n";
		return 2;
	}
	std::cout << prev() << "\n";
  std::cout << max() << "\n";
	return 0;
}