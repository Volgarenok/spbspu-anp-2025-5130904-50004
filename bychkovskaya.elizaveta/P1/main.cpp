#include <iostream>

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
		if (k_ == 1 || (num > max_ && k_ != 1)) {
			max_ = num;
			res_ = 1;
    }
		else if (num == max_ && k_ != 1) {
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
	size_t count = 0;
  Max max;
	MoreThanPrevious prev;
	int num = 0;
  while (std::cin >> num && num != 0) {
    ++count;
		prev(num);
		max(num);
  }
	if (!std::cin) {
    std::cerr << "Wrong input" << "\n";
    return 1;
  }
	if (num == 0 && count == 0) {
		std::cout << prev() << "\n";
		std::cerr << "Not enough elements to count quantity of max" << "\n";
		return 2;
	}
	std::cout << prev() << "\n";
  std::cout << max() << "\n";
	return 0;
}