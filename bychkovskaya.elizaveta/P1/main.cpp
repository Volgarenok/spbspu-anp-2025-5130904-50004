#include <iostream>

int main() {
    int num = 0;
    int prevNum = 0;
    size_t count = 0;
   size_t k = 0;
    while (std::cin >> num && num != 0) {
        ++k;
        if (num > prevNum && k != 1) {
            ++count;
        }
        prevNum = num;
    }
    if (!std::cin && !std::cin.eof()) {
        std::cerr << "Wrong input" << "\n";
        return 1;
    }
    std::cout << count << "\n";
}