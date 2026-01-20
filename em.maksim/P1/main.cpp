#include "inc_seq.hpp"
#include <iostream>

int main() {
    em::IncSeq s;
    int x;
    while (std::cin >> x && x != 0) {
        s(x);
    }
    std::cout << s() << '\n';
    return 0;
}
